//#############################################################################
//#                           Copyright Paripath, Inc.
//#                            All Rights Reserved
//#############################################################################
//# Created by: Rohit Sharma
//#
//# Revision $Revision: 1.20 $, last checked in by $Author: srohit $ on $Date: 2017/06/23 01:38:05 $.
//#
//# CVS ID: $Id: cdfCommands.cpp,v 1.20 2017/06/23 01:38:05 srohit Exp $
//#############################################################################
//#
//# Description:
//
//
#include <sys/stat.h>
#include <unistd.h>
#include "macros.h"
#include "cdfCommands.h"
#include "cdf.h"
#include "message.h"
#include "equationParser.h" //required for output function.

extern string get_function(const char*);

map<const char*, cdfCommand*, ltstr> cdfCommand::commands;

class cdfPorts : public cdfCommand {
    string _type;
public:
    cdfPorts(const char* name, const char* format) :
      cdfCommand(name, format), _type(name) {}
    char* fire(cdf::table* table, cdf::stimulus* stim) 
    {
        return fire(table);
    }
    char* fire(cdf::table* table)
    {
        vector<cdf::port*> cdf_ports = table->ports(_type != "outputs");
        string ins="";
        for(size_t index=0; index<cdf_ports.size(); index++) {
            if ( _type == "clocks" && !cdf_ports[index]->is_clock() ) continue;
            if ( _type == "data" && cdf_ports[index]->is_clock() ) continue;
            ins += (ins.empty()?"":" ") + cdf_ports[index]->name();
        }
        return Tcl_STR(ins);
    }
};

class cdfPortProperties : public cdfCommand {
public:
    cdfPortProperties(const char* name, const char* format) :
      cdfCommand(name, format) {}
    char* fire(cdf::table* table, cdf::stimulus* stim, char* portname) 
    {
        return fire(table, portname);
    }
    char* fire(cdf::table* tbl, char* port_name)
    {
        cdf::port* pOut = tbl->findPort(port_name);
        if (!pOut) return "";
        cdf::port::property* prop = pOut->get_relations() ;
        if (!prop) return "";
        return Tcl_STR(prop->print());
    }
};

class cdfTableType : public cdfCommand {
public:
    cdfTableType(const char* name, const char* format) :
      cdfCommand(name, format) {}
    char* fire(cdf::table* tbl) {
        return Tcl_STR(tbl->cell_type().c_str());
    }
};

class cdfCCB : public cdfCommand {
public:
    cdfCCB(const char* name, const char* format) :
      cdfCommand(name, format) {}
    char* fire(cdf::table* tbl) {
        cdf::ccb* ccBlock = tbl->getCCB() ;
        return Tcl_STR(ccBlock ? ccBlock->info().c_str() : "") ;
    }
};

class cdfFunction : public cdfCommand {
public:
    cdfFunction(const char* name, const char* format) :
      cdfCommand(name, format) {}
    char* fire(cdf::table* tbl, char* out) {
        cdf::port* pOut = tbl->findPort(out);
        if (!pOut) return "";
        string expr = get_function(tbl->getFunction(pOut).c_str());
        return Tcl_STR(expr);
    }
};

class cdfTables : public cdfCommand {
public:
    cdfTables(const char* name, const char* format) :
      cdfCommand(name, format) {}
    char* fire(cdf* theCDF) {
        vector<cdf::table*> tables = theCDF->get_tables();
        string table_str;
        for (size_t index=0; index<tables.size(); index++) {
            if ( tables[index] == 0x0 )
                continue;
            table_str += (index?" ":"") + swigPtr(tables[index]) + "_p_cdf__table";
        }
        return Tcl_STR(table_str);
    }
};

class cdfStimulus : public cdfCommand {
public:
    cdfStimulus(const char* name, const char* format) :
      cdfCommand(name, format) {}
      char* fire(cdf::table* table) {
          return fire(table, 0x0);
      }
      char* fire(cdf::table* table, char* type = 0x0) {
        cdf::CHAR_TYPE ct = (type == 0x0) ? cdf::UNDEFINED_CHAR : cdf::getCharType(type);
        string stim_str = "";
        vector<cdf::stimulus*> stim_list = table->getStimulus();
        for(size_t index=0; index<stim_list.size(); index++) {
            if ( ct != cdf::UNDEFINED_CHAR && !stim_list[index]->is_type(ct) ) continue;
            stim_str += (index?" ":"") + swigPtr(stim_list[index]) + "_p_cdf__stimulus";
        }
        return Tcl_STR(stim_str);
    }
};

class cdfSequence : public cdfCommand {
public:
    cdfSequence(const char* name, const char* format) :
      cdfCommand(name, format) {}
    char* fire(cdf::stimulus* stim) {
        cdf::stimulus::sequence sqnc = stim->getSequence();
        return Tcl_STR("{" + tokenizer::join(sqnc.first, ",") + "} "  + sqnc.second);
    }
};

class cdfNoise : public cdfCommand {
protected:
    bool avg_max(const vector<pair<float, float> > & values, float& average, float& max)
    {
        float sum = 0.0 ;
        for(size_t i=0; i<values.size(); i++)
        {
            // find peak current
            max = i == 0 || fabs(values[i].second) > fabs(max) ? values[i].second : max ;
            sum += values[i].second ;
        }

        if ( values.size() )
        {
            average = sum / values.size() ;
            return true ;
        }

        return false ;
    }
    bool avg_for_less_than_v (const vector<pair<float, float> > & values, float limit_v, float& average)
    {
        size_t sz = values.size() ;
        if ( sz == 0 )
            return false ;

        float before_v = values[0].first ;
        float before_i = values[0].second ;
        float after_v = values[sz-1].first ;
        float after_i = values[sz-1].second ;

        float sum = 0.0 ;
        size_t num = 0 ;
        for(size_t i=0; i<values.size(); i++)
        {
            float limit_v_diff  = fabs(values[i].first - limit_v) ;
            float before_v_diff = fabs(values[i].first - before_v) ;
            float after_v_diff  = fabs(values[i].first - after_v) ;

            if ( limit_v_diff < before_v_diff )
            {
                before_v = values[i].first ;
                before_i = values[i].second ;
            }

            if ( limit_v_diff > after_v_diff )
            {
                after_v = values[i].first ;
                after_i = values[i].second ;
            }

            if ( values[i].first >= EPSILON && limit_v_diff > EPSILON )
                continue ;
            sum += values[i].second ;
            num++;
        }
        if ( num )
        {
            sum += INTERPOLATE(before_v, before_i, after_v, after_i, limit_v) ;
            num++;
            average = sum / num ;
            return true ;
        }
        return false ;
    }

    // Determine voltage from VIVO table, when out voltage is fixed to VDD/VSS.
    // Method - interpolation.
    bool in_voltage_height (const vector<pair<float, float> >& viVfixed_currents,
                const float& ref_current, float& ref_voltage)
    {

        if ( viVfixed_currents.size() < 2 )
            return false ;

        for (size_t i=1; i<viVfixed_currents.size(); i++)
        {
            float voltage      = viVfixed_currents[i].first ;
            float current      = viVfixed_currents[i].second ;
            float last_voltage = viVfixed_currents[i-1].first ;
            float last_current = viVfixed_currents[i-1].second ;

            if ( ( current > ref_current && last_current < ref_current ) ||
                 ( current < ref_current && last_current > ref_current )
               )
            {
                ref_voltage = INTERPOLATE(last_current, last_voltage, current, voltage, ref_current) ;
                return true ;
            }
        }

        return false ;
    }
    bool voltage_heights ( const vector<pair<float, float> >& viVfixed_currents, 
                const float& viVdd_Imax1, const float& viVdd_Imax2, 
                const float& viVdd_Imax3, float& vi1Vdd, float& vi2Vdd, float& vi3Vdd )
    {
        return 
            in_voltage_height (viVfixed_currents, viVdd_Imax1, vi1Vdd) &&
            in_voltage_height (viVfixed_currents, viVdd_Imax2, vi2Vdd) &&
            in_voltage_height (viVfixed_currents, viVdd_Imax3, vi3Vdd) ;
    }
    bool get_time_for_delta_voltage(vector<cdf::arc*>& volt_arcs, float& slope, float& time_deltaV1, 
                float& time_deltaV2, float low_v, float high_v)
    {
        const float v_factor1 = 0.30 ;
        const float v_factor2 = 0.50 ;

        bool success = false ;

        vector<cdf::arc*>::iterator pos = volt_arcs.begin();
        for(; pos != volt_arcs.end(); pos++) 
        {
            float voltage1 = (v_factor1 * (high_v-low_v)) + low_v ;
            float voltage2 = (v_factor2 * (high_v-low_v)) + low_v ;

            success = false ;
            vector<cdf::arcWaveform*> v_arcs = (*pos)->getArcVectors() ;
            for(size_t j=0; j<v_arcs.size(); j++) 
            {
                vector<pair<float, float> > v_waveforms ;
                size_t min_size = v_arcs[j]->_values1.size() < v_arcs[j]->_values2.size() ? 
                                         v_arcs[j]->_values1.size() : v_arcs[j]->_values2.size() ;

                if ( min_size < 2 )
                    continue ;

                for (size_t sz=0; sz<min_size; sz++) 
                    v_waveforms.push_back(make_pair<float, float> (v_arcs[j]->_values1[sz], v_arcs[j]->_values2[sz]) ) ;

                slope = v_arcs[j]->_index1 ;
                if ( in_voltage_height(v_waveforms, voltage1, time_deltaV1) &&
                     in_voltage_height(v_waveforms, voltage2, time_deltaV2) )
                {
                    success = true ;
                    break ;
                }
            }
            if ( success )
                break ;
        }
        return success ;
    }
public:
    cdfNoise(const char* name, const char* format) :
      cdfCommand(name, format)
    {}
    char* fire(cdf::table* table, float high_v, float low_v) 
    {
        const float i_factor1 = 0.20 ;
        const float i_factor2 = 0.35 ;
        const float i_factor3 = 0.50 ;

        char *tcl_list = new char[512] ;
        tcl_list[0] = '\0' ;

        if ( !table )
        {
            return tcl_list ;
        }

        cdf::port* ccbPort = table->getCCB() ? table->getCCB()->getPort() : 0x0 ;
        if ( !ccbPort )
        {
            return tcl_list ;
        }

        // Find VIVO_models and VOLT_models from table 
        cdf::model_feed* vivo_mfeed = 0x0 ;
        cdf::model_feed* out_rise_volt_mfeed = 0x0 ;
        cdf::model_feed* out_fall_volt_mfeed = 0x0 ;
        vector<cdf::stimulus*> sections = table->getStimulus() ;
        for (size_t index=0; index < sections.size(); index++) 
        {
            vivo_mfeed = vivo_mfeed ? vivo_mfeed : sections[index]->getModelFeed(cdf::MODEL_VIVO, cdf::CCSN_VIVO) ;
            cdf::stimulus::sequence sqnc = sections[index]->getSequence() ;
            string out_trans = sqnc.second ;
            if ( out_trans.size() && out_trans[0] == 'r' )
                out_rise_volt_mfeed = out_rise_volt_mfeed ? out_rise_volt_mfeed : 
                    sections[index]->getModelFeed(cdf::MODEL_VOLT, cdf::CCSN_VOLT) ;
            if ( out_trans.size() && out_trans[0] == 'f' )
                out_fall_volt_mfeed = out_fall_volt_mfeed ? out_fall_volt_mfeed : 
                    sections[index]->getModelFeed(cdf::MODEL_VOLT, cdf::CCSN_VOLT) ;
        }

        if ( !vivo_mfeed || (!out_rise_volt_mfeed && !out_fall_volt_mfeed) )
            return (tcl_list);

       vector<cdf::arc*> vivo_arcs = vivo_mfeed->get_arcs() ;
       vector<cdf::arc*> r_volt_arcs = out_rise_volt_mfeed->get_arcs() ;
       vector<cdf::arc*> f_volt_arcs = out_fall_volt_mfeed->get_arcs() ;

       if ( !vivo_arcs.size() || (!r_volt_arcs.size() && !f_volt_arcs.size()) )
           return (tcl_list);


       vector<pair<float, float> > viVdd_currents, viVss_currents ;
       // Find Imax and Iavg from VIVO table.
       vector<cdf::arc*>::iterator pos = vivo_arcs.begin();
       for(; pos != vivo_arcs.end(); pos++) 
       {
           vector<cdf::arcValue*> values = (*pos)->getArcValues();
           size_t j=0;
           for(j=0; j<values.size(); j++) 
           {
               if ( values[j]->_values1.size() )
               {
                   float oCurrent = values[j]->_values1[0] ;
                   float iVoltage = values[j]->_index1 ;
                   float oVoltage = values[j]->_index2 ;

                   // disregard values below/beyond VSS/VDD 
                   if ( (iVoltage < low_v && fabs(low_v - iVoltage) > EPSILON) || 
                        (iVoltage > high_v && fabs(high_v - iVoltage) > EPSILON)
                      )
                   {
                       continue;
                   }
                   if ( fabs(high_v - oVoltage) < EPSILON )
                   {
                       viVdd_currents.push_back( make_pair<float, float>(iVoltage, oCurrent) ) ;
                   }
                   if ( fabs(low_v - oVoltage) < EPSILON )
                   {
                       viVss_currents.push_back( make_pair<float, float>(iVoltage, oCurrent) ) ;
                   }
               }
           }
       }

       if ( !viVdd_currents.size() || !viVss_currents.size() )
       {
           return (tcl_list);
       }

       float viVdd_Imax, viVdd_Iavg ; // below_high noise region
       float viVss_Imax, viVss_Iavg ; // above_low  noise region
       if ( ! avg_max(viVdd_currents, viVdd_Iavg, viVdd_Imax) ||
            ! avg_max(viVss_currents, viVss_Iavg, viVss_Imax) )
       {
           return (tcl_list);
       }

       float vi1Vdd, vi2Vdd, vi3Vdd ;
       float vi1Vss, vi2Vss, vi3Vss ;

       if (  !voltage_heights ( viVdd_currents, 
                    i_factor1*viVdd_Imax, i_factor2*viVdd_Imax,
                    i_factor3*viVdd_Imax, vi1Vdd, vi2Vdd, vi3Vdd ) 
           ||
             !voltage_heights ( viVss_currents, 
                    i_factor1*viVss_Imax, i_factor2*viVss_Imax,
                    i_factor3*viVss_Imax, vi1Vss, vi2Vss, vi3Vss )
          )
       {
           return (tcl_list);
       }

       float Iavg_vi1Vdd, Iavg_vi2Vdd, Iavg_vi3Vdd ;
       if ( ! avg_for_less_than_v(viVdd_currents, vi1Vdd, Iavg_vi1Vdd) ||
            ! avg_for_less_than_v(viVdd_currents, vi2Vdd, Iavg_vi2Vdd) ||
            ! avg_for_less_than_v(viVdd_currents, vi3Vdd, Iavg_vi3Vdd) )
       {
           return (tcl_list);
       }

       float Iavg_vi1Vss, Iavg_vi2Vss, Iavg_vi3Vss ;
       if ( ! avg_for_less_than_v(viVss_currents, vi1Vss, Iavg_vi1Vss) ||
            ! avg_for_less_than_v(viVss_currents, vi2Vss, Iavg_vi2Vss) ||
            ! avg_for_less_than_v(viVss_currents, vi3Vss, Iavg_vi3Vss) )
       {
           return (tcl_list);
       }

       // Assumption - input output relationship is negative unate.
       float r_slope; // input slope for rising output.
       float f_slope; // input slope for falling output.
       float r_time_deltaV1, r_time_deltaV2; // time point, when rising out voltage is deltaV1/deltaV2
       float f_time_deltaV1, f_time_deltaV2; // time point, when falling out voltage is deltaV1/deltaV2

       bool success = get_time_for_delta_voltage(r_volt_arcs, r_slope, r_time_deltaV1, r_time_deltaV2, low_v, high_v) &&
                      get_time_for_delta_voltage(f_volt_arcs, f_slope, f_time_deltaV1, f_time_deltaV2, low_v, high_v) ;


       if ( !success ) 
           return (tcl_list) ;

       float r_Q_deltaV1 = (viVdd_Iavg * r_slope) + ( viVdd_Imax * (r_time_deltaV1-r_slope) ) ; // output charge.
       float r_Q_deltaV2 = (viVdd_Iavg * r_slope) + ( viVdd_Imax * (r_time_deltaV2-r_slope) ) ;
       float r_W1 = r_Q_deltaV1 / Iavg_vi1Vdd ;
       float r_W2 = r_Q_deltaV1 / Iavg_vi2Vdd ;
       float r_W3 = r_Q_deltaV1 / Iavg_vi3Vdd ;
       float r_W4 = r_Q_deltaV2 / Iavg_vi1Vdd ;
       float r_W5 = r_Q_deltaV2 / Iavg_vi2Vdd ;
       float r_W6 = r_Q_deltaV2 / Iavg_vi3Vdd ;

       float f_Q_deltaV1 = (viVss_Iavg * f_slope) + ( viVss_Imax * (f_time_deltaV1-f_slope) ) ; // output charge.
       float f_Q_deltaV2 = (viVss_Iavg * f_slope) + ( viVss_Imax * (f_time_deltaV2-f_slope) ) ;
       float f_W1 = f_Q_deltaV1 / Iavg_vi1Vss ;
       float f_W2 = f_Q_deltaV1 / Iavg_vi2Vss ;
       float f_W3 = f_Q_deltaV1 / Iavg_vi3Vss ;
       float f_W4 = f_Q_deltaV2 / Iavg_vi1Vss ;
       float f_W5 = f_Q_deltaV2 / Iavg_vi2Vss ;
       float f_W6 = f_Q_deltaV2 / Iavg_vi3Vss ;

       sprintf (tcl_list, "{{%f %f %f} {%f %f %f %f %f %f}} {{%f %f %f} {%f %f %f %f %f %f}}", 
            vi1Vdd, vi2Vdd, vi3Vdd, r_W1, r_W2, r_W3, r_W4, r_W5, r_W6,
            vi1Vss, vi2Vss, vi3Vss, f_W1, f_W2, f_W3, f_W4, f_W5, f_W6) ;

       return (tcl_list);
    }
};

class cdfActivity : public cdfCommand {
public:
    cdfActivity(const char* name, const char* format) :
      cdfCommand(name, format)
    {}
    char* fire(cdf::stimulus* stim, char* filename)
    {
        assert(stim) ;
        if ( stim && fileExists(filename) )
        {
            stim->setActivityFile(filename) ;
            return "0" ;
        }
        return "1" ;
    };
    char* fire(cdf::stimulus* stim)
    {
        if ( stim )
        {
            string fileName = stim->getActivityFile() ;
            return Tcl_STR(fileName.c_str()) ;
        }
        return "";
    }
} ;

class cdfActivePorts : public cdfCommand {
    bool _isInput; //port type. input = true, output false.
public:
    cdfActivePorts(const char* name, const char* format) :
      cdfCommand(name, format), _isInput(!strcmp(name,"active_inputs")) {}
    char* fire(cdf::table* table, cdf::stimulus* stim) {
        vector<cdf::port*> activePorts = _isInput ?
            cdf::getActiveInputs(stim->getSequence(), table->ports(true)) :
            cdf::getActiveOutputs(stim->getSequence(), table->ports(false));
        string cdf_ports = "";
        for(size_t index=0; index<activePorts.size(); index++)
            cdf_ports += (index?" ":"") + activePorts[index]->name();
        return Tcl_STR(cdf_ports);
    }
};

class cdfQueueJob : public cdfCommand {
public:
    cdfQueueJob (const char* name, const char* format) :
      cdfCommand(name, format) {}
      char* fire(cdf::stimulus* stim, char* inFile, char* command, char* outFile) {
          stim->queueJob(inFile, command, outFile);
          return "0";
      }
};

class cdfListDecks : public cdfCommand {
public:
    cdfListDecks(const char* name, const char* format) :
      cdfCommand(name, format) {}
      char* fire(cdf::stimulus* stim) {
          string decks;
          vector<triplet<string, string, string> > job_list = stim->listJobs();
          for(size_t index=0; index<job_list.size(); index++) {
              decks += (index?" {":"{") + job_list[index].first + " {" + job_list[index].second + "} " + job_list[index].third + "}";
          }
          return Tcl_STR(decks);
      }
};

class cdfRemoveDecks : public cdfCommand {
public:
    cdfRemoveDecks(const char* name, const char* format) :
      cdfCommand(name, format) {}
      char* fire(cdf::stimulus* stim) {
          stim->removeJobs();
          return Tcl_STR("0");
      }
};

class cdfTransitions : public cdfCommand {
public:
    cdfTransitions(const char* name, const char* format) :
      cdfCommand(name, format) {}
      char* fire(cdf::table* tbl, cdf::stimulus* stim, char* portname) {
          vector<cdf::port*> inputs = tbl->ports(true);
          vector<cdf::port*> outputs = tbl->ports(false);

          size_t index1=0, index2=0;
          string transitions="";
          for(index1=0; index1<inputs.size(); index1++) {
              if ( inputs[index1]->name() == portname ) {
                  vector<string> tran_list = stim->getSequence().first;
                  for(index2=0; index2<tran_list.size(); index2++)
                      transitions += tran_list[index2][index1];
                  return Tcl_STR(transitions);
              }
          }
          for(index1=0; index1<outputs.size(); index1++) {
              if ( outputs[index1]->name() == portname ) {
                  transitions = stim->getSequence().second[index1];
                  return Tcl_STR(transitions);
              }
          }
          return "";
      }
};

class cdfInOutArc : public cdfCommand {
public:
    cdfInOutArc(const char* name, const char* format) :
      cdfCommand(name, format) {}
    char* fire(cdf::table* tbl, cdf::stimulus* stim) {
        string arcs_str;
        vector<cdf::arc*> arcs = cdf::getInOutArc(stim->getSequence(), tbl);
        for(size_t index=0; index<arcs.size(); index++) {
            arcs_str += (index?" {":"{") + arcs[index]->print("") + "}";
            delete arcs[index];
        }
        return Tcl_STR(arcs_str);
    }
};

class cdfGetArcs : public cdfCommand {
public:
    cdfGetArcs(const char* name, const char* format) :
      cdfCommand(name, format) {}
    char* fire(cdf::stimulus* stim, char* type) {
        string arcs_str;
        cdf::CHAR_TYPE  ctype = cdf::getCharType  (type) ;
        cdf::MODEL_TYPE mtype = cdf::getModelType (type) ;
        cdf::model_feed* mfeed = stim->getModelFeed(mtype, ctype) ;
        if ( mfeed ) 
        {
            vector<cdf::arc*> arcs = mfeed->get_arcs() ;
            for (size_t i=0; i<arcs.size(); i++)
            {
                arcs_str += " {" + arcs[i]->tclPrint() + "}" ;
            }
        }
        return Tcl_STR(arcs_str.c_str());
    }
};


class cdfStimulusTypes : public cdfCommand {
public:
    cdfStimulusTypes(const char* name, const char* format) :
      cdfCommand(name, format) {}
    char* fire(cdf::stimulus* stim) {
        string typeStr ;
        vector<cdf::CHAR_TYPE> types = stim->getTypes();
        for (size_t index=0; index<types.size(); index++) {
            typeStr += (typeStr.empty()?"":" ") + cdf::charTypeStr(types[index]);
        }
        return Tcl_STR(typeStr);
    }
};
class cdfSimFeed : public cdfCommand {
public:
    cdfSimFeed(const char* name, const char* format) :
      cdfCommand(name, format) {}
    char* fire(cdf::stimulus* stim, char* type, char* node_value_pair) {
        cdf::CHAR_TYPE ctype = cdf::getCharType(type);

        cdf::simulation_feed* sim = stim->createSimFeed(ctype); //This can return 0x0
        if ( sim != 0x0 ) 
            sim->set(node_value_pair);
        return sim != 0x0 ? Tcl_STR("0") : Tcl_STR("1");
    }
    char* fire(cdf::stimulus* stim, char* type) {
        cdf::CHAR_TYPE ctype = cdf::getCharType(type);
        cdf::simulation_feed* sim = stim->getSimFeed(ctype);
        return sim == 0x0 ? Tcl_STR("") : Tcl_STR(sim->get());
    }
};

class cdfAddArc : public cdfCommand {
public:
    cdfAddArc(const char* name, const char* format) :
      cdfCommand(name, format) {}
    char* fire(cdf* theCDF, cdf::table* tbl, cdf::stimulus* stim, char* type, char* deck,
        char* result_file, char* arcStr, float index1, float value1, 
        float index2=FLOAT_MIN, float value2=FLOAT_MIN,
        float index3=FLOAT_MIN)
    {
        cdf::arc* theArc = cdf::get_or_create_arc(theCDF, tbl, stim, type+string(" ")+arcStr);
        if ( theArc == 0x0 )
            return "1";
        cdf::arcValue* theArcValue = new 
            cdf::arcValue(index1, value1, deck, result_file, index2, index3, value2);
        theArc->addArcValue(theArcValue);
        return "0";
    }
};

class cdfAddWaveform : public cdfCommand {
public:
    cdfAddWaveform(const char* name, const char* format) :
      cdfCommand(name, format) {}
    char* fire(cdf* theCDF, cdf::table* tbl, cdf::stimulus* stim, char* type, char* deck,
        char* result_file, char* arcStr, float refTime, float index1, char* xVecStr, 
        float index2=FLOAT_MIN, char* yVecStr=0x0, float index3=FLOAT_MIN,
        char* pgPin=0x0)
    {
        cdf::arc* theArc = cdf::get_or_create_arc(theCDF, tbl, stim, type+string(" ")+arcStr);
        if ( theArc == 0x0 )
            return "1";

        vector<float> xVec, yVec ;

        float token;
        tokenizer xTokens(xVecStr) ;
        while (xTokens.next(token)) 
            xVec.push_back(token) ;

        tokenizer yTokens(yVecStr) ;
        while (yTokens.next(token)) 
            yVec.push_back(token) ;

        cdf::arcWaveform* theArcVector = new 
            cdf::arcWaveform(index1, index2, index3, refTime, xVec, yVec, deck, result_file, pgPin?pgPin:"");
        theArc->addArcWaveform(theArcVector);

        return "0";
    }
};

class cdfMapNames : public cdfCommand {
public:
    cdfMapNames(const char* name, const char* format) :
      cdfCommand(name, format)
    {}

    char* fire(cdf* theCDF, char* cdfNameMap, char* cdfNewName)
    {
       if ( theCDF == 0x0 )
       {
           pbs_error("CDF-204", "");
           return 0x0 ;
       }
    
       map<string, string> cdfPinMap ;
       string name1, name2 ;
       tokenizer pin_pair(cdfNameMap) ;
       while ( pin_pair.next(name1) && pin_pair.next(name2) ) 
       {
           cdfPinMap[name2] = name1; 
       }
           
       if (theCDF)
       {
           string cdfNewNameStr = cdfNewName;
           theCDF->name(cdfNewNameStr) ;
           theCDF->changePortNames(cdfPinMap);
           return Tcl_STR(swigPtr(theCDF) + "_p_cdf") ;
       }
       return 0x0 ;
    }
} ;

static cdfPorts            cdfInputsObj("inputs", "table:p");
static cdfPorts            cdfOutputsObj("outputs", "table:p");
static cdfPorts            cdfClocksObj("clocks", "table:p");
static cdfPorts            cdfDataObj("data", "table:p");
static cdfTableType        cdfCellType("cell_type", "table:p");
static cdfCCB              cdfCCB("ccb", "table:p");
static cdfTables           cdfTablesObj("tables", "cdf:p");
static cdfStimulus         cdfStimulusObj("stimulus", "table:p char:p");
static cdfSequence         cdfSequenceObj("sequence", "stimulus:p");
static cdfActivePorts      cdfActiveInputs("active_inputs", "table:p stimulus:p");
static cdfActivePorts      cdfActiveOutputs("active_outputs", "table:p stimulus:p");
static cdfQueueJob         cdfQueueJobObj("queue_job", "stimulus:p char:p char:p char:p");
static cdfListDecks        cdfListDecksObj("list_jobs", "stimulus:p");
static cdfRemoveDecks      cdfRemoveDecksObj("remove_jobs", "stimulus:p");
static cdfTransitions      cdfTransitionsObj("transitions", "table:p stimulus:p char:p");
static cdfSimFeed          cdfSimFeedObj("simfeed", "stimulus:p char:p [char:p]");
static cdfStimulusTypes    cdfStimulusTypesObj("types", "stimulus:p");
static cdfAddArc           cdfAddArcObj("add_arc", "stimulus:p sequence:p type:enum deck:file result:file val1:dbl [val2:dbl]");
static cdfAddWaveform      cdfAddWaveformObj("add_waveform", "stimulus:p sequence:p type:enum deck:file result:file arc:str refTime:dbl inSlope:dbl timeVec:str outLoad:dbl currentVec:str out2Load:dbl pgPin=str") ;
//static cdfInArc       cdfInArc("in_arcs", "stimulus:p");
static cdfInOutArc         cdfInOutArcObj("in_out_arcs", "table:p stimulus:p");
static cdfGetArcs          cdfGetArcsObj("get_arcs", "stimulus:p ctype:str");
//static cdfInClkArc    cdfInClkArc("in_clk_arcs", "table:p stimulus:p");
static cdfFunction         cdfFunctionObj("function", "table:p output:s");
static cdfNoise            cdfNoisePropObj("noise", "table:p float:high_v float:low_v");
static cdfActivity         cdfActivityObj("activity", "sequence:p [filename:str]");
static cdfMapNames         cdfMapNamesObj("map_names", "char* char*") ;
static cdfPortProperties   cdfPortPropertiesObj("property", "table:p char*") ;

char*
cdfiMsg(char* name)
{
    string matches = "*" + string(name) + "* = " + cdfCommand::match(name);
    pbs_error("CDF-201", matches.c_str());
    return "";
}

char*
cdfi(char* name)
{
    // gnureadline sends --- as command completion string
    if ( !name || !strlen(name) || !strcmp(name, "----") ) {
        return 0x0 ;
    }

    map<const char*, cdfCommand*, ltstr>::iterator
        iter = cdfCommand::commands.find(name);
    return iter != cdfCommand::commands.end() ? 
        iter->second->fire() :  
        cdfiMsg(name);
}

char*
cdfi()
{ 
    string match = cdfCommand::match("") ;
    return Tcl_STR(match);
}

char*
cdfi(char* name,
     cdf::stimulus* stim,
     char* str1)
{
    map<const char*, cdfCommand*, ltstr>::iterator
        iter = cdfCommand::commands.find(name);
    return iter != cdfCommand::commands.end() ? 
        iter->second->fire(stim, str1) :  
        cdfiMsg(name);
}
char*
cdfi(char* name,
     cdf::stimulus* stim)
{
    map<const char*, cdfCommand*, ltstr>::iterator
        iter = cdfCommand::commands.find(name);
    return iter != cdfCommand::commands.end() ? 
        iter->second->fire(stim) :  
        cdfiMsg(name);
}

char*
cdfi(char* name,
     cdf::stimulus* stim,
     char* str1,
     char* str2)
{
    map<const char*, cdfCommand*, ltstr>::iterator
        iter = cdfCommand::commands.find(name);
    return iter != cdfCommand::commands.end() ? 
        iter->second->fire(stim, str1, str2) :  
        cdfiMsg(name);
}

char*
cdfi(char* name,
     cdf::stimulus* stim,
     char* str1,
     char* str2,
     char* str3)
{
    map<const char*, cdfCommand*, ltstr>::iterator
        iter = cdfCommand::commands.find(name);
    return iter != cdfCommand::commands.end() ? 
        iter->second->fire(stim, str1, str2, str3) :  
        cdfiMsg(name);
}

char*
cdfi(char* name,
     cdf* theCDF,
     char* str1,
     char* str2)
{
    map<const char*, cdfCommand*, ltstr>::iterator
        iter = cdfCommand::commands.find(name);
    return iter != cdfCommand::commands.end() ? 
        iter->second->fire(theCDF, str1, str2) :  
        cdfiMsg(name);
}

char*
cdfi(char* name, 
     cdf::table* table,
     char* type)
{
    map<const char*, cdfCommand*, ltstr>::iterator
        iter = cdfCommand::commands.find(name);
    return iter != cdfCommand::commands.end() ? 
        iter->second->fire(table, type) :  
        cdfiMsg(name);
}

char*
cdfi(char* name, 
     cdf::table* table,
     cdf::stimulus* stim,
     char* str1)
{
    map<const char*, cdfCommand*, ltstr>::iterator
        iter = cdfCommand::commands.find(name);
    return iter != cdfCommand::commands.end() ? 
        iter->second->fire(table, stim, str1) :  
        cdfiMsg(name);
}

char*
cdfi(char* name, 
     cdf::table* table,
     cdf::stimulus* stim)
{
    map<const char*, cdfCommand*, ltstr>::iterator
        iter = cdfCommand::commands.find(name);
    return iter != cdfCommand::commands.end() ? 
        iter->second->fire(table, stim) :  
        cdfiMsg(name);
}


char*
cdfi(char* name, 
     cdf::table* table)
{
    map<const char*, cdfCommand*, ltstr>::iterator
        iter = cdfCommand::commands.find(name);
    return iter != cdfCommand::commands.end() ? 
        iter->second->fire(table) : 
        cdfiMsg(name);
}

char*
cdfi(char* name, 
     cdf::table* table,
     float high_v, float low_v)
{
    map<const char*, cdfCommand*, ltstr>::iterator
        iter = cdfCommand::commands.find(name);
    return iter != cdfCommand::commands.end() ? 
        iter->second->fire(table, high_v, low_v) : 
        cdfiMsg(name);
}


char*
cdfi(char* name, 
     cdf* theCDF)
{
    map<const char*, cdfCommand*, ltstr>::iterator
    iter = cdfCommand::commands.find(name);
    return iter != cdfCommand::commands.end() ? 
        iter->second->fire(theCDF) : 
        cdfiMsg(name);
}

char* cdfi(char* name, cdf* theCDF, 
           cdf::table* tbl, cdf::stimulus* stim,
           char* str1, char* str2,
           char* str3, char* str4,
           float index1, float val1,
           float index2=FLOAT_MIN, float val2=FLOAT_MIN,
           float index3=FLOAT_MIN)
{
    map<const char*, cdfCommand*, ltstr>::iterator
    iter = cdfCommand::commands.find(name);
    return iter != cdfCommand::commands.end() ? 
        iter->second->fire(theCDF, tbl, stim, str1, str2, str3, str4, index1, val1,
        index2, val2, index3) : 
        cdfiMsg(name);
}

char* cdfi(char* name, cdf* theCDF, 
           cdf::table* tbl, cdf::stimulus* stim,
           char* str1, char* str2,
           char* str3, char* str4,
           float refTime, float index1,
           char* xVec, float index2, 
           char* yVec, float index3=FLOAT_MIN,
           char* pgPin=0x0)
{
    map<const char*, cdfCommand*, ltstr>::iterator
    iter = cdfCommand::commands.find(name);
    return iter != cdfCommand::commands.end() ? 
        iter->second->fire(theCDF, tbl, stim, str1, str2, str3, str4, refTime, index1, xVec, index2, yVec, index3, pgPin) : 
        cdfiMsg(name);
}
