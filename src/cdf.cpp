//#############################################################################
//#                           Copyright Paripath, Inc.
//#                            All Rights Reserved
//#############################################################################
//# Created by: Rohit Sharma
//#
//# Revision $Revision: 1.28 $, last checked in by $Author: srohit $ on $Date: 2017/11/03 01:12:50 $.
//#
//# CVS ID: $Id: cdf.cpp,v 1.28 2017/11/03 01:12:50 srohit Exp $
//#############################################################################
//#
//# Description:
//
//
#ifndef _CDF_WRITER
#define _CDF_WRITER

#include "cktCommon.h"
#include "cdf.h"
#include "message.h"
//#include "configManager.h"
#include <iostream>
#include <fstream>

using namespace std;

// NOTE: these are kept constant in cdf and separate from config bus_syntax 
// to map empty bus_syntax in spice. Example "cdf A[0]" -> "spice A0", here spice has no
// bus-syntax.
const char cdf::bus_open      = '[' ;
const char cdf::bus_close     = ']' ;
const char cdf::bus_delimiter = ':' ;

extern string map_function(map<string, string>&, string); //in equation_parser.cpp

cdf::CHAR_TYPE
cdf::getCharType(string token) 
{
    if (token == "delay")          return DELAY;
    else if (token == "tristate")  return TRISTATE;
    else if (token == "incap")     return INCAP;
    else if (token == "rcap")      return RCAP;
    else if (token == "ipower")    return IPOWER;
    else if (token == "dpower")    return DPOWER;
    else if (token == "apower")    return APOWER;
    else if (token == "lpower")    return LPOWER;
    else if (token == "maxcap")    return MAXCAP;
    else if (token == "setup")     return SETUP;
    else if (token == "hold")      return HOLD;
    else if (token == "recovery")  return RECOVERY;
    else if (token == "removal")   return REMOVAL;
    else if (token == "mpw")       return MPW;
    else if (token == "ccsn_vivo") return CCSN_VIVO;
    else if (token == "ccsn_prop") return CCSN_PROP;
    else if (token == "ccsn_volt") return CCSN_VOLT;
    else if (token == "ccsn_mcap") return CCSN_MCAP;
    return UNDEFINED_CHAR;
}

string
cdf::charTypeStr(CHAR_TYPE type)
{
    if (type == cdf::DELAY)          return "delay";
    else if (type == cdf::TRISTATE)  return "tristate";
    else if (type == cdf::INCAP)     return "incap";
    else if (type == cdf::RCAP)      return "rcap";
    else if (type == cdf::IPOWER)    return "ipower";
    else if (type == cdf::DPOWER)    return "dpower";
    else if (type == cdf::APOWER)    return "apower";
    else if (type == cdf::LPOWER)    return "lpower";
    else if (type == cdf::MAXCAP)    return "maxcap";
    else if (type == cdf::SETUP)     return "setup";
    else if (type == cdf::HOLD)      return "hold";
    else if (type == cdf::RECOVERY)  return "recovery";
    else if (type == cdf::REMOVAL)   return "removal";
    else if (type == cdf::MPW)       return "mpw";
    else if (type == cdf::CCSN_VIVO) return "ccsn_vivo";
    else if (type == cdf::CCSN_PROP) return "ccsn_prop";
    else if (type == cdf::CCSN_VOLT) return "ccsn_volt";
    else if (type == cdf::CCSN_MCAP) return "ccsn_mcap";
    return "";
}

cdf::MODEL_TYPE
cdf::getModelType(string token) 
{
    if (token == "delay")             return MODEL_DELAY;
    else if (token == "delay_var")    return MODEL_DELAY_VAR;
    else if (token == "tristate")     return MODEL_TRISTATE;
    else if (token == "tristate_var") return MODEL_TRISTATE_VAR;
    else if (token == "incap")        return MODEL_INCAP;
    else if (token == "ipower")       return MODEL_IPOWER;
    else if (token == "dpower")       return MODEL_DPOWER;
    else if (token == "apower")       return MODEL_APOWER;
    else if (token == "lpower")       return MODEL_LPOWER;
    else if (token == "maxcap")       return MODEL_MAXCAP;
    else if (token == "setup")        return MODEL_SETUP;
    else if (token == "setup_var")    return MODEL_SETUP_VAR;
    else if (token == "hold")         return MODEL_HOLD;
    else if (token == "hold_var")     return MODEL_HOLD_VAR;
    else if (token == "recovery")     return MODEL_RECOVERY;
    else if (token == "recovery_var") return MODEL_RECOVERY_VAR;
    else if (token == "removal")      return MODEL_REMOVAL;
    else if (token == "removal_var")  return MODEL_REMOVAL_VAR;
    else if (token == "mpw")          return MODEL_MPW;
    else if (token == "ccs_driver")   return MODEL_CCS_DRIVER;
    else if (token == "rcap")         return MODEL_CCS_RECEIVER;
    else if (token == "pg_dcurrent")  return MODEL_PG_DCURRENT;
    else if (token == "pg_icurrent")  return MODEL_PG_ICURRENT;
    else if (token == "lcurrent")     return MODEL_LCURRENT;
    else if (token == "vivo")         return MODEL_VIVO;
    else if (token == "prop")         return MODEL_PROP;
    else if (token == "volt")         return MODEL_VOLT;
    else if (token == "mcap")         return MODEL_MCAP;
    return UNDEFINED_MODEL;
}

string
cdf::modelTypeStr(MODEL_TYPE type)
{
    if (type == cdf::MODEL_DELAY) return "delay";
    else if (type == cdf::MODEL_DELAY_VAR)    return "delay_var";
    else if (type == cdf::MODEL_TRISTATE)     return "tristate";
    else if (type == cdf::MODEL_TRISTATE)     return "tristate_var";
    else if (type == cdf::MODEL_INCAP)        return "incap";
    else if (type == cdf::MODEL_IPOWER)       return "ipower";
    else if (type == cdf::MODEL_DPOWER)       return "dpower";
    else if (type == cdf::MODEL_APOWER)       return "apower";
    else if (type == cdf::MODEL_LPOWER)       return "lpower";
    else if (type == cdf::MODEL_MAXCAP)       return "maxcap";
    else if (type == cdf::MODEL_SETUP)        return "setup";
    else if (type == cdf::MODEL_SETUP_VAR)    return "setup_var";
    else if (type == cdf::MODEL_HOLD)         return "hold";
    else if (type == cdf::MODEL_HOLD_VAR)     return "hold_var";
    else if (type == cdf::MODEL_RECOVERY)     return "recovery";
    else if (type == cdf::MODEL_RECOVERY_VAR) return "recovery_var";
    else if (type == cdf::MODEL_REMOVAL)      return "removal";
    else if (type == cdf::MODEL_REMOVAL_VAR)  return "removal_var";
    else if (type == cdf::MODEL_MPW)          return "mpw";
    else if (type == cdf::MODEL_CCS_DRIVER)   return "ccs_driver";
    else if (type == cdf::MODEL_CCS_RECEIVER) return "rcap";
    else if (type == cdf::MODEL_PG_DCURRENT)  return "pg_dcurrent";
    else if (type == cdf::MODEL_PG_ICURRENT)  return "pg_icurrent";
    else if (type == cdf::MODEL_LCURRENT)     return "lcurrent";
    else if (type == cdf::MODEL_VIVO)         return "vivo";
    else if (type == cdf::MODEL_PROP)         return "prop";
    else if (type == cdf::MODEL_VOLT)         return "volt";
    else if (type == cdf::MODEL_MCAP)         return "mcap";
    return "";
}

cdf::CHAR_TYPE
cdf::modelToCharType(MODEL_TYPE mtype)
{
    if      (mtype == cdf::MODEL_DELAY)        return DELAY ;
    else if (mtype == cdf::MODEL_DELAY_VAR)    return DELAY ;
    else if (mtype == cdf::MODEL_TRISTATE)     return TRISTATE;
    else if (mtype == cdf::MODEL_TRISTATE_VAR) return TRISTATE;
    else if (mtype == cdf::MODEL_INCAP)        return INCAP;
    else if (mtype == cdf::MODEL_IPOWER)       return IPOWER;
    else if (mtype == cdf::MODEL_DPOWER)       return DPOWER;
    else if (mtype == cdf::MODEL_APOWER)       return APOWER;
    else if (mtype == cdf::MODEL_LPOWER)       return LPOWER;
    else if (mtype == cdf::MODEL_MAXCAP)       return MAXCAP;
    else if (mtype == cdf::MODEL_SETUP)        return SETUP;
    else if (mtype == cdf::MODEL_SETUP_VAR)    return SETUP;
    else if (mtype == cdf::MODEL_HOLD)         return HOLD;
    else if (mtype == cdf::MODEL_HOLD_VAR)     return HOLD;
    else if (mtype == cdf::MODEL_RECOVERY)     return RECOVERY;
    else if (mtype == cdf::MODEL_RECOVERY_VAR) return RECOVERY;
    else if (mtype == cdf::MODEL_REMOVAL)      return REMOVAL;
    else if (mtype == cdf::MODEL_REMOVAL_VAR)  return REMOVAL;
    else if (mtype == cdf::MODEL_MPW)          return MPW;
    else if (mtype == cdf::MODEL_CCS_DRIVER)   return DELAY;
    else if (mtype == cdf::MODEL_CCS_RECEIVER) return RCAP;
    else if (mtype == cdf::MODEL_PG_DCURRENT)  return DPOWER;
    else if (mtype == cdf::MODEL_PG_ICURRENT)  return IPOWER;
    else if (mtype == cdf::MODEL_LCURRENT)     return LPOWER;
    else if (mtype == cdf::MODEL_VIVO)         return CCSN_VIVO;
    else if (mtype == cdf::MODEL_PROP)         return CCSN_PROP;
    else if (mtype == cdf::MODEL_VOLT)         return CCSN_VOLT;
    else if (mtype == cdf::MODEL_MCAP)         return CCSN_MCAP;
    return UNDEFINED_CHAR ;
}

cdf::MODEL_TYPE
cdf::charToModelType(CHAR_TYPE type)
{
    if      (type == cdf::DELAY)       return MODEL_DELAY ; // or MODEL_CCS_DRIVER
    else if (type == cdf::TRISTATE)    return MODEL_TRISTATE ;
    else if (type == cdf::INCAP)       return MODEL_INCAP ;
    else if (type == cdf::RCAP)        return MODEL_CCS_RECEIVER ;
    else if (type == cdf::IPOWER)      return MODEL_IPOWER ; // or MODEL_PG_ICURRENT
    else if (type == cdf::DPOWER)      return MODEL_DPOWER ; // or MODEL_PG_DCURRENT
    else if (type == cdf::APOWER)      return MODEL_APOWER ;
    else if (type == cdf::LPOWER)      return MODEL_LPOWER ; // or MODEL_LCURRENT
    else if (type == cdf::MAXCAP)      return MODEL_MAXCAP ;
    else if (type == cdf::SETUP)       return MODEL_SETUP ;
    else if (type == cdf::HOLD)        return MODEL_HOLD ;
    else if (type == cdf::RECOVERY)    return MODEL_RECOVERY ;
    else if (type == cdf::REMOVAL)     return MODEL_REMOVAL ;
    else if (type == cdf::MPW)         return MODEL_MPW ;
    else if (type == cdf::CCSN_VIVO)   return MODEL_VIVO ;
    else if (type == cdf::CCSN_PROP)   return MODEL_PROP ;
    else if (type == cdf::CCSN_VOLT)   return MODEL_VOLT;
    else if (type == cdf::CCSN_MCAP)   return MODEL_MCAP ;
    return UNDEFINED_MODEL ;
}

// This returns spiceBusName of the node.
// Example 1: spiceBusName("A[0]")  returns A, with bus_syntax "[]"
// Example 2: spiceBusName("A<31>") returns A, with bus_syntax "<>"
// Example 3: spiceBusName("A31")   returns A, with bus_syntax ""
// Example 4: spiceBusName("A")     returns A, with any bus_syntax.
string
cdf::spiceBusName(string& spiceNodeName)
{
    if ( spiceNodeName.size() == 0 )
        return spiceNodeName ;

    string bus_syntax = getenv("bus_syntax") ;
    if ( ! bus_syntax.empty() )
    {
        size_t idx = spiceNodeName.find_last_of(bus_syntax[0]);
        return
                idx == string::npos ?
                    spiceNodeName :
                    spiceNodeName.substr(0,idx);
    }
    else
    {
        size_t idx= spiceNodeName.size();
        for(; idx>0; idx--)
        {
            if ( ! isdigit(spiceNodeName[idx-1]) )
                break;
        }
        return idx > 0 ?
                    spiceNodeName.substr(0,idx) :
                    spiceNodeName ;
    }

    return spiceNodeName ;
}

string
cdf::getCondition(string& minterm, vector<cdf::port*>& ports)
{
//      when : "A & !B";
    string msum ;
    for(size_t index2=0; index2<minterm.size() && index2<ports.size(); index2++) {
        string name = ports[index2]->name();
        if ( minterm[index2] == '0' || minterm[index2] == '1' ) {
            if ( minterm[index2] == '0' ) name = "!" + name;
            msum += (msum.empty() ? "" : " & ") + name;
        }
    }
    return msum;
}

string
cdf::getSDFCondition(const string& minterm, vector<port*>& ports)
{
//      sdf_cond : "A == 1'b1 && B == 1'b0";
    string msum ;
    for(size_t index2=0; index2<minterm.size() && index2<ports.size(); index2++) {
        string name = ports[index2]->name();
        if ( minterm[index2] == '0' || minterm[index2] == '1' ) {
            string term = name + " == 1'b" + (minterm[index2] == '1' ? "1" : "0" ) ;
            msum += (msum.empty() ? "" : " && ") + term;
        }
    }
    return msum;
}

pair<float, float>
cdf::getArcScalarValue(string& in, cdf::CHAR_TYPE ctype, bool bit_blast)
{
    cdf::MODEL_TYPE mtype = cdf::charToModelType(ctype) ;
    float rise_scalar=FLOAT_MIN, fall_scalar=FLOAT_MIN;
    for(size_t i=0; i<_tables.size(); i++) {
        cdf::port* iport = bit_blast ? _tables[i]->findPort(in) : _tables[i]->findBus(in);
        vector<cdf::stimulus*> stims = _tables[i]->getStimulus();
        for(size_t j=0; j<stims.size(); j++) {
            cdf::model_feed* inscalar_model = stims[j]->getModelFeed(mtype, ctype);
            if ( inscalar_model == 0x0 ) 
                continue;
            vector<cdf::arc*> arcs = inscalar_model->get_arcs();
            for(size_t k=0; k<arcs.size(); k++) {
                cdf::port* pin1 = arcs[k]->pin1() ;
                if ( ! bit_blast && pin1 && pin1->get_bus() )
                    pin1 = pin1->get_bus() ;
                if ( pin1 == iport ) {
                    float *iscalar = &rise_scalar;
                    if ( arcs[k]->tran1() == cdf::FALL ) {
                        iscalar = &fall_scalar;
                    }
                    vector<cdf::arcValue*> values = arcs[k]->getArcValues();
                    for(size_t m=0; m<values.size(); m++)
                        *iscalar = max(*iscalar, values[m]->_values1[0]);
                }
            }
        }
    }
    if ( ctype==cdf::MPW && getenv("duplicate_mpw")!=0x0 ) {
        rise_scalar = rise_scalar == FLOAT_MIN ? fall_scalar : rise_scalar ;
        fall_scalar = fall_scalar == FLOAT_MIN ? rise_scalar : fall_scalar ;
    }
    return pair<float, float>(rise_scalar, fall_scalar);
}

string 
cdf::arcValue::values() {
    string text = _index1 > FLOAT_MIN ? (tokenizer::number(_index1) + " ") : "";
    text += _index2 > FLOAT_MIN ? (tokenizer::number(_index2) + " ") : "";
    text += _index3 > FLOAT_MIN ? (tokenizer::number(_index3) + " ") : "";
    text += _values1.size() && _values1[0] > FLOAT_MIN ? (" , " + tokenizer::number(_values1[0])) : "";
    text += _values2.size() && _values2[0] > FLOAT_MIN ? (" , " + tokenizer::number(_values2[0])) : "";
    text += "; #" + _deck + " " + _result_file;
    return text;
}

string 
cdf::arcWaveform::values() {
    string text = _index1 > FLOAT_MIN ? (tokenizer::number(_index1) + " ") : "";
    text += _index2 > FLOAT_MIN ? (tokenizer::number(_index2) + " ") : "";
    text += _index3 > FLOAT_MIN ? (tokenizer::number(_index3) + " ") : "";

    string xaxis, yaxis;
    size_t index=0;
    for (index=0; index<_values1.size() && index < _values2.size(); index++) {
        if ( _values1[index] <= FLOAT_MIN || _values2[index] <= FLOAT_MIN )
            continue ;
        xaxis += (index ? " " : "") + tokenizer::number(_values1[index]) ;
        yaxis += (index ? " " : "") + tokenizer::number(_values2[index]) ;
    }
    text += ", " + xaxis  ;
    text += ", " + yaxis  ;
    text += ", " + tokenizer::number(_refTime) ;
    text += _pgPin.empty() ? "" : (", " + _pgPin) ;
    text += "; #" + _deck + " " + _result_file;
    return text;
}

string
cdf::arc::tclPrint() {
    string arc, tran=" ";
    vector<string> fields ;
    if (_pin1) fields.push_back(_pin1->name());
    tran[0] = cdf::getTransition(_tran1); 
    if (_tran1!=cdf::UNDEFINED_TRANSITION) fields.push_back(tran);
    if (_pin2) fields.push_back(_pin2->name());
    tran[0] = cdf::getTransition(_tran2); 
    if (_tran2!=cdf::UNDEFINED_TRANSITION) fields.push_back(tran);
    if (_pin3) fields.push_back(_pin3->name());
    tran[0] = cdf::getTransition(_tran3); 
    if (_tran3!=cdf::UNDEFINED_TRANSITION) fields.push_back(tran);
    arc = tokenizer::join(fields, " ");

    return arc;
}

string
cdf::arc::print(string prefix) {
    string arc, tran=" ";
    vector<string> fields, values;
    if ( !prefix.empty() ) fields.push_back(prefix);
    if (_pin1) fields.push_back(_pin1->name());
    tran[0] = cdf::getTransition(_tran1); 
    if (_tran1!=cdf::UNDEFINED_TRANSITION) fields.push_back(tran);
    if (_pin2) fields.push_back(_pin2->name());
    tran[0] = cdf::getTransition(_tran2); 
    if (_tran2!=cdf::UNDEFINED_TRANSITION) fields.push_back(tran);
    if (_pin3) fields.push_back(_pin3->name());
    tran[0] = cdf::getTransition(_tran3); 
    if (_tran3!=cdf::UNDEFINED_TRANSITION) fields.push_back(tran);
    if ( _info ) fields.push_back(_info) ;
    arc = tokenizer::join(fields, " ");

    size_t index=0;
    for(index=0; index<_values.size(); index++)
        values.push_back(arc + " = " + _values[index]->values());
    for(index=0; index<_waveform.size(); index++)
        values.push_back(arc + " = " + _waveform[index]->values());
    arc = tokenizer::join(values, "\n");

    return arc;
};

string cdf::simulation_feed::get() {
    string text;
    for(size_t index=0; index<_ic.size(); index++) {
        text += (index?" ":"") + _ic[index];
    }
    return text;
}

string cdf::simulation_feed::print(vector<cdf::CHAR_TYPE> types) {
    string typesStr ;
    if ( _types != types ) {
        for(size_t index=0; index<_types.size(); index++)
            typesStr += cdf::charTypeStr(_types[index]) + " ";
    }
    return "\t\tsimfeed " + typesStr + get() + "\n";
}

cdf::model_feed::model_feed(const model_feed& other) { //copy constructor
    _type = other._type;
    for(size_t index=0; index<other._arcs.size(); index++) {
        _arcs.push_back(new cdf::arc(*(other._arcs[index])));
    }
}

cdf::stimulus::stimulus(const cdf::stimulus& other)
{
    _types = other._types;
    _condition = other._condition;
    _jobs = other._jobs;
    _sequence = other._sequence;
    size_t index=0;
    for(index=0; index<_sim.size(); index++)
        _sim.push_back(new simulation_feed(*other._sim[index]));
    for (index=0; index<other._model_arcs.size(); index++)
        _model_arcs.push_back(new model_feed(*other._model_arcs[index]));
}

cdf::ccb::ccb (cdf::port* port, string file) : 
    _ccbPort(port), _ccbFile(file)
{
    assert(port) ;
}

string
cdf::ccb::info()
{
    return _ccbPort->name() + " " + _ccbFile ;
}

string
cdf::ccb::print()
{
    string text = "\t\tccb " + this->info() + "\n" ;
    return text;
}

string 
cdf::print() 
{
    string text = "cdf " + _name + "\n";

    string supply0, supply1 ;
    for (size_t index=0; index<_supplies.size(); index++) {
        if ( _supplies[index]->is_supply0() )
            supply0 += (supply0.empty() ? "" : ", ") + _supplies[index]->name() ;
        else if ( _supplies[index]->is_supply1() )
            supply1 += (supply1.empty() ? "" : ", ") + _supplies[index]->name() ;
    }
    if ( supply0.size() ) text += "\tsupply0 " + supply0 + ";\n" ;
    if ( supply1.size() ) text += "\tsupply1 " + supply1 + ";\n" ;

    for (size_t index=0; index<_tables.size(); index++) {
        text += _tables[index]->print();
    }
    text += "end_cdf\n";
    return text;
}

void
cdf::changePortNames(map<string, string>& portMap)
{
    for(size_t i=0; i<_supplies.size(); i++)
    {
        string supplyName = _supplies[i]->name();
        map<string, string>::iterator miter = portMap.find(supplyName);
        if ( miter != portMap.end() )
        {
            string newSupplyName = miter->second ;
            _supplies[i]->setNewName(newSupplyName);
        }
    }

    for(size_t i=0; i<_tables.size(); i++)
        _tables[i]->changePortNames(portMap);

}

bool 
cdf::is_inout(string name) {
    bool in=false, out=false;
    for(size_t index=0; index<_tables.size(); index++) {
        cdf::port* tport = _tables[index]->findPort(name);
        if ( tport == 0x0 ) continue;
        in = tport->is_input() ? true : in;
        out = tport->is_output() ? true : out;
    }
    return in && out;
}

string
cdf::getFunction(string& cell_port, bool threestate) {
    for(size_t i=0; i<_tables.size(); i++) {
        cdf::port* out = _tables[i]->findPort(cell_port);
        if ( out ) {
            string eq = threestate ? _tables[i]->getThreeState(out) : _tables[i]->getFunction(out);
            if ( !eq.empty() ) return eq;
        }
    }
    return "";
}

static vector<cdf::port*>::iterator
cdfPortFind(vector<cdf::port*>::iterator first,
            vector<cdf::port*>::iterator last,
            cdf::port* thePort)
{
    while (first != last && (*first)->name() != thePort->name()) ++first;
    return first;
}


void
cdf::ports(vector<port*>& inputs, vector<port*>& clocks,
       vector<port*>& inouts, vector<port*>& outputs)
{
    vector<cdf::table*> tables = get_tables();
    size_t i,j;
    for(i=0; i<tables.size(); i++) {
        // CCB tables have internal nodes as ports.
        // do not use these tables to find cdf ports.
        if ( tables[i]->getCCB() )
            continue ;
        vector<cdf::port*> ports = tables[i]->ports();
        for(j=0; j<ports.size(); j++) {
            vector<cdf::port*>::iterator pos;
            bool in = ports[j]->is_input();
            cdf::port* cur = ports[j];

            if ( ports[j]->is_clock() && cdfPortFind(clocks.begin(), clocks.end(), cur) == clocks.end() ) clocks.push_back(cur);

            if ( cdfPortFind(inouts.begin(), inouts.end(), cur) != inouts.end() )
                continue;
            if ( in ) {
                if ( (pos = cdfPortFind(outputs.begin(), outputs.end(), cur)) != outputs.end() ) {
                    outputs.erase(pos);
                    inouts.push_back(cur);
                } else if ( cdfPortFind(inputs.begin(), inputs.end(), cur) == inputs.end() ) {
                    inputs.push_back(cur);
                }
            } else {
                if ( (pos = cdfPortFind(inputs.begin(), inputs.end(), cur)) != inputs.end() ) {
                    inputs.erase(pos);
                    inouts.push_back(cur);
                } else if ( cdfPortFind(outputs.begin(), outputs.end(), cur) == outputs.end() ) {
                    outputs.push_back(cur);
                }
            }
        }
    }
}

void
cdf::ports(vector<string>& inputs, vector<string>& clocks,
       vector<string>& inouts, vector<string>& outputs)
{
    vector<cdf::table*> tables = get_tables();
    size_t i,j;
    for(i=0; i<tables.size(); i++) {
        // CCB tables have internal nodes as ports.
        // do not use these tables to find cdf ports.
        if ( tables[i]->getCCB() )
            continue ;
        vector<cdf::port*> ports = tables[i]->ports();
        for(j=0; j<ports.size(); j++) {
            vector<string>::iterator pos;
            bool in = ports[j]->is_input();
            string cur = ports[j]->name();

            if ( ports[j]->is_clock() && find(clocks.begin(), clocks.end(), cur) == clocks.end() ) clocks.push_back(cur);

            if ( find(inouts.begin(), inouts.end(), cur) != inouts.end() )
                continue;
            if ( in ) {
                if ( (pos = find(outputs.begin(), outputs.end(), cur)) != outputs.end() ) {
                    outputs.erase(pos);
                    inouts.push_back(cur);
                } else if ( find(inputs.begin(), inputs.end(), cur) == inputs.end() ) {
                    inputs.push_back(cur);
                }
            } else {
                if ( (pos = find(inputs.begin(), inputs.end(), cur)) != inputs.end() ) {
                    inputs.erase(pos);
                    inouts.push_back(cur);
                } else if ( find(outputs.begin(), outputs.end(), cur) == outputs.end() ) {
                    outputs.push_back(cur);
                }
            }
        }
    }
}

cdf::bus*
cdf::getBus(string &portName)
{
    vector<cdf::table*> tables = get_tables();

    for(size_t i=0; i<tables.size(); i++)
    {
        // CCB tables have internal nodes as ports.
        // do not use these tables to find cdf ports.
        if ( tables[i]->getCCB() )
            continue ;
        cdf::port* pPort = tables[i]->findPort(portName);
        if ( pPort && pPort->name() == portName )
            return pPort->get_bus();
    }
    return 0x0 ;
}

void
cdf::buses(vector<string>& inputs, vector<string>& clocks,
       vector<string>& inouts, vector<string>& outputs)
{
    vector<cdf::table*> tables = get_tables();
    size_t i,j;
    for(i=0; i<tables.size(); i++) {
        // CCB tables have internal nodes as ports.
        // do not use these tables to find cdf ports.
        if ( tables[i]->getCCB() )
            continue ;
        vector<cdf::bus*> ports = tables[i]->buses();
        for(j=0; j<ports.size(); j++) {
            vector<string>::iterator pos;
            bool in = ports[j]->is_input();
            string cur = ports[j]->name();

            if ( ports[j]->is_clock() && find(clocks.begin(), clocks.end(), cur) == clocks.end() ) clocks.push_back(cur);

            if ( find(inouts.begin(), inouts.end(), cur) != inouts.end() )
                continue;
            if ( in ) {
                if ( (pos = find(outputs.begin(), outputs.end(), cur)) != outputs.end() ) {
                    outputs.erase(pos);
                    inouts.push_back(cur);
                } else if ( find(inputs.begin(), inputs.end(), cur) == inputs.end() ) {
                    inputs.push_back(cur);
                }
            } else {
                if ( (pos = find(inputs.begin(), inputs.end(), cur)) != inputs.end() ) {
                    inputs.erase(pos);
                    inouts.push_back(cur);
                } else if ( find(outputs.begin(), outputs.end(), cur) == outputs.end() ) {
                    outputs.push_back(cur);
                }
            }
        }
    }
}

void 
cdf::supplies(vector<port*>& highSupplies, vector<port*>& lowSupplies)
{
    for (size_t index=0; index<_supplies.size(); index++)
    {
        if ( _supplies[index]->is_supply0() )
            lowSupplies.push_back(_supplies[index]) ;
        else if ( _supplies[index]->is_supply1() )
            highSupplies.push_back(_supplies[index]) ;
    }
}

cdf::TRANSITION
cdf::getTransition(const char state1,
                   const char state2) 
{
    return ( state1 == '0' && state2 == '1' ) ? RISE :
           ((state1 == '1' && state2 == '0' ) ? FALL : UNDEFINED_TRANSITION) ;
}

cdf::TRANSITION
cdf::getTransition(const char transition)
{
    TRANSITION tran = UNDEFINED_TRANSITION;
    switch(transition) {
        case 'r' : tran = RISE; break;
        case 'f' : tran = FALL; break;
        case 'T' : tran = RISE2Z; break;
        case 't' : tran = FALL2Z; break;
        case 'Z' : tran = Z2ONE; break;
        case 'z' : tran = Z2ZERO; break;
        default  : tran = UNDEFINED_TRANSITION; break;
    }
    return tran;
}

char 
cdf::getTransition(TRANSITION tran)
{
    char transition = '-';
    switch(tran) {
        case RISE   : transition = 'r'; break;
        case FALL   : transition = 'f'; break;
        case RISE2Z : transition = 't'; break;
        case FALL2Z : transition = 'T'; break;
        case Z2ONE : transition = 'Z'; break;
        case Z2ZERO : transition = 'z'; break;
        default     : transition = '-'; break;
    }
    return transition;
}

vector<cdf::port*>
cdf::getActiveOutputs(cdf::stimulus::sequence sqnc,
                      vector<cdf::port*> outports)
{
    vector<cdf::port*> ports;
    string out_tran = sqnc.second;
    for(size_t index=0; index < out_tran.size(); index++) {
        TRANSITION otran = getTransition(out_tran[index]);
        if ( otran != UNDEFINED_TRANSITION ) { 
            ports.push_back(outports[index]);
        }
    }
    return ports;
}

vector<cdf::port*>
cdf::getActiveInputs(cdf::stimulus::sequence sqnc,
                     vector<cdf::port*> inports)
{
    vector<cdf::port*> ports;
    vector<string> in_sqnc = sqnc.first;
    size_t sz = in_sqnc.size() ;
    string lastTran = in_sqnc[sz-1];
    string lastButOneTran = in_sqnc[sz-2];
    size_t in_size = lastTran.size();
    for(size_t index=0; index < in_size; index++) {
        if ( lastTran[index] != lastButOneTran[index] ) {
            ports.push_back(inports[index]);
        }
    }
    return ports;
}

// Given a table and sequence, 
// it returns input ports transitions.
vector<cdf::TRANSITION>
cdf::getInPortTransitions(cdf::table* tbl, cdf::stimulus::sequence& sqnc)
{
    assert(tbl) ;

    vector<cdf::TRANSITION> inTrans;

    vector<string> in_sqnc = sqnc.first;
    size_t sq_sz = in_sqnc.size() ;
    assert (sq_sz > 1) ;
    string lastTran = in_sqnc[sq_sz-1];
    string lastButOneTran = in_sqnc[sq_sz-2];

    for(size_t index=0; index < lastTran.size(); index++) {
        if ( lastTran[index] != lastButOneTran[index] ) {
            cdf::TRANSITION itran = getTransition(lastButOneTran[index], lastTran[index]);
            if ( itran != UNDEFINED_TRANSITION ) { 
                inTrans.push_back(itran) ;
            }
        }
    }
    return inTrans;
}

// Given a table and sequence, 
// it returns switching input output ports and their transitions.
vector<cdf::TRANSITION>
cdf::getOutPortTransitions(cdf::table* tbl, cdf::stimulus::sequence& sqnc)
{
    assert(tbl) ;

    vector<cdf::TRANSITION> outTrans;

    string out_tran = sqnc.second;

    for(size_t index=0; index < out_tran.size(); index++) {
        TRANSITION otran = getTransition(out_tran[index]);
        if ( otran != UNDEFINED_TRANSITION ) { 
            outTrans.push_back(otran);
        }
    }
    return outTrans;
}

// Note: caller need to delete these arcs.
vector<cdf::arc*> 
cdf::getInOutArc(const stimulus::sequence& sqnc, table* theTable)
{
    vector<cdf::arc*> model_arcs;
    vector<port*> inports  = theTable->ports(true/*inputs*/);
    vector<port*> outports = theTable->ports(false/*inputs*/);
    vector<string> in_sqnc = sqnc.first;
    string out_tran        = sqnc.second;
    size_t sz = in_sqnc.size();
    string lastTran = in_sqnc[sz-1];
    string lastButOneTran = in_sqnc[sz-2];
    size_t in_size = lastTran.size();
    for(size_t index1=0; index1 < in_size; index1++) {
        TRANSITION itran = getTransition(lastButOneTran[index1], lastTran[index1]);
        if ( itran == UNDEFINED_TRANSITION ) { continue; }
        port* in = inports[index1];
        for(size_t index2=0; index2<out_tran.size(); index2++) {
            TRANSITION otran = getTransition(out_tran[index2]);
            if ( otran == UNDEFINED_TRANSITION ) { continue; }
            port* out = outports[index2];
            arc* theArc = new arc(in, itran, out, otran);
            model_arcs.push_back(theArc);
        }
    }
    return model_arcs;
}

unsigned char
cdf::ttable::get(size_t out_index, size_t in_index) 
{
    char unateness = '\0'; // +:positive, -:negative and *:non
    if ( out_index >= _io_trans.size() ||
         in_index >= _io_trans[out_index].size() )
         return unateness;
    flag io = _io_trans[out_index][in_index];
    if ( io.get(0) && io.get(1) && io.get(2) && io.get(3) )
        unateness = '*';
    else if ( (io.get(0) && io.get(3)) || (io.get(4) && io.get(6)) || (io.get(8) && io.get(10)) ) // pos unate
        unateness = '+';
    else if ( (io.get(1) && io.get(2)) || (io.get(5) && io.get(7)) || (io.get(9) && io.get(11)) ) // neg unate
        unateness = '-';
    else if (io.get(0) && io.get(2)) // clk r
        unateness = '^';
    else if (io.get(1) && io.get(3)) // clk f
        unateness = 'v';
    else if (io.get(0)) // These 4 clauses must be at the end.
        unateness = '0';
    else if (io.get(1)) 
        unateness = '1';
    else if (io.get(2)) 
        unateness = '2';
    else if (io.get(3)) 
        unateness = '3';
    return unateness;
}

void 
cdf::ttable::get_space(size_t insize, size_t outsize) {
        // Make sure that there is enough space.
    if (!_io_trans.size()) {
        for(size_t index1=0; index1<outsize; index1++) {
            vector<flag> in;
            for(size_t index2=0; index2<insize; index2++) {
                in.push_back(flag());
            }
            _io_trans.push_back(in);
        }
    }
}

// This checks if supplies sequence is proper subset of transition
// table or not.
bool 
cdf::ttable::is_proper_subset(pair<vector<string>, string>& sequence)
{
    size_t sz = sequence.first.size();
    if ( sz < 2 ) {
        return false;
    }
    string in1 = sequence.first[sz-2];
    string in2 = sequence.first[sz-1];
    string out = sequence.second;

    get_space(in1.size(), out.size());

    size_t index1, index2;
    for(index1=0; index1<out.size(); index1++) {
        TRANSITION ot = cdf::getTransition(out[index1]);
        for(index2=0; index2<in1.size(); index2++) {
            TRANSITION it = cdf::getTransition(in1[index2],in2[index2]);
            short id = index(ot, it);
            if ( id == -1 )
                continue;
            if ( ! _io_trans[index1][index2].get(id) )
                return false;
        }
    }
    return true;
}

void 
cdf::ttable::analyze(pair<vector<string>, string>& sequence)
{
    size_t sz = sequence.first.size();
    if ( sz < 2 ) {
        return;
    }
    string in1 = sequence.first[sz-2];
    string in2 = sequence.first[sz-1];
    string out = sequence.second;
    size_t index1, index2;

    get_space(in1.size(), out.size());

    for(index1=0; index1<out.size(); index1++) {
        TRANSITION ot = cdf::getTransition(out[index1]);
        for(index2=0; index2<in1.size(); index2++) {
            TRANSITION it = cdf::getTransition(in1[index2],in2[index2]);
            short id = index(ot, it);
            if ( id != -1 ) _io_trans[index1][index2].set(id);
        }
    }
}

void cdf::ttable::analyze(const vector<cdf::arc*> arcs)
{
        // Make sure that there is enough space.
    get_space(1,1);
    for(size_t i=0; i<arcs.size(); i++) {
        TRANSITION it = arcs[i]->tran1();
        TRANSITION ot = arcs[i]->tran2();
        short id = index(ot, it);
        if ( id != -1 ) _io_trans[0][0].set(id);
    }
}

short 
cdf::ttable::index(TRANSITION ot, TRANSITION it) 
{
    if (it != RISE && it != FALL)
        return -1;

    if (ot == RISE)
        return (it == RISE) ? 0 : 1 ;
    else if ( ot == FALL )
        return (it == RISE) ? 2 : 3 ;
    else if ( ot == RISE2Z )
        return (it == RISE) ? 4 : 5 ;
    else if ( ot == FALL2Z )
        return (it == RISE) ? 6 : 7 ;
    else if ( ot == Z2ONE )
        return (it == RISE) ? 8 : 9 ;
    else if ( ot == Z2ZERO )
        return (it == RISE) ? 10 : 11 ;
    return -1;
}

cdf::model_feed*
cdf::stimulus::getModelFeed(MODEL_TYPE mtype, CHAR_TYPE ctype) {
    if ( !is_type(ctype) )
        return 0x0;
    for(size_t index=0; index<_model_arcs.size(); index++) {
        if ( _model_arcs[index]->type() == mtype )
            return _model_arcs[index];
    }
    return 0x0;
}

cdf::model_feed*
cdf::stimulus::getOrCreateModelFeed(MODEL_TYPE mtype, CHAR_TYPE ctype, 
        cdf::TRANSITION out_tran ) {

    if ( ctype == cdf::DELAY && (out_tran == cdf::Z2ZERO || out_tran == cdf::Z2ONE) ) {
        ctype = cdf::TRISTATE;
    }
    // check, if legal.
    if ( !is_type(ctype) )
        return 0x0;
    // find model feed.
    cdf::model_feed* mfeed = getModelFeed(mtype, ctype);
    if ( mfeed != 0x0 )
        return mfeed;
    //create model feed.
    mfeed = new cdf::model_feed(mtype);
    _model_arcs.push_back(mfeed);
    return mfeed;
}

string
cdf::stimulus::getSDFCondition(cdf::table* tbl) {
    // return pos equation.
    vector<cdf::port*> ports = tbl->ports();
    vector<string> minterms;
    for(size_t index1=0; index1<_condition.size(); index1++) {
        string msum = cdf::getSDFCondition(_condition[index1], ports);
        if ( !msum.empty() ) minterms.push_back(msum);
    }
    return tokenizer::join(minterms, " | ");
}

// stimulus printer.
string
cdf::stimulus::getCondition(cdf::table* tbl) {
    // return pos equation.
    vector<cdf::port*> ports = tbl->ports();
    vector<string> minterms;
    for(size_t index1=0; index1<_condition.size(); index1++) {
        string msum = cdf::getCondition(_condition[index1], ports);
        if ( !msum.empty() ) minterms.push_back(msum);
    }
    return tokenizer::join(minterms, " | ");
}

// stimulus printer.
string
cdf::stimulus::print() {
    string text="\t\t";
    size_t index;
    for(index=0; index<_types.size(); index++) {
        string type_str = cdf::charTypeStr(_types[index]);
        if ( type_str != "" ) text += type_str + " ";
    }
    text += "\n";
    if ( _activity_file.length() )
    {
        text += "\t\t\tactivity_file " + _activity_file + "\n";
    }
    for(index=0; index<_condition.size(); index++) {
        text += index==0 ? "\t\t\tstate " : " + " ;
        text += _condition[index];
    }
    if ( _condition.size() ) text += "\n";
    for(index=0; index<_sim.size(); index++) text += _sim[index]->print(_types);
    for(index=0; index< _model_arcs.size(); index++) text += _model_arcs[index]->print();
    text += "\t\t\t" + tokenizer::join(_sequence.first, " , ") +
                " = " + _sequence.second + " ;\n";
    return text;
}

cdf::arc*
cdf::get_or_create_arc(cdf* theCDF, cdf::table* tbl, cdf::stimulus* stim, string arcStr) {
    tokenizer tokens(arcStr);
    cdf::MODEL_TYPE mtype = cdf::getModelType(tokens[0]);
    if ( mtype == cdf::UNDEFINED_MODEL )
        return 0x0;
    tokens.erase(0);
    cdf::port* pin[3] = {0x0, 0x0, 0x0};
    cdf::TRANSITION tran[3] = { cdf::UNDEFINED_TRANSITION,
                                cdf::UNDEFINED_TRANSITION,
                                cdf::UNDEFINED_TRANSITION };
    const char* info = 0x0;
    // leakage power arcs
    if ( tokens.size() == 1 && mtype == cdf::MODEL_LPOWER ) {
        info = tokens[0].c_str();
    // leakage current arcs
    } else if ( tokens.size() == 1 && mtype == cdf::MODEL_VIVO ) {
        pin[0] = tbl->findPort(tokens[0]);
    } else if ( tokens.size() == 2 && mtype == cdf::MODEL_LCURRENT ) {
        cdf::port* pPort = theCDF->findSupply(tokens[0]) ;
        pin[0] = pPort ? pPort : tbl->findPort(tokens[0]);
        info = tokens[1].c_str();
    } else if ( tokens.size() == 2 && mtype == cdf::MODEL_PROP ) {
        pin[0]  = tbl->findPort(tokens[0]); // port
        tran[0] = cdf::getTransition(tokens[1][0]); // ccb out tran
    } else {
        if ( tokens.size() % 2 || tokens.size() > 6) // unable to create arc without couplet.
            return 0x0;

        for(size_t index=0; index<tokens.size()/2; index++) {
            pin[index] = tbl->findPort(tokens[2*index]);
            tran[index] = cdf::getTransition(tokens[2*index+1][0]);
        }
    }

    cdf::CHAR_TYPE ctype = cdf::modelToCharType(mtype) ;

    cdf::model_feed* mfeed = stim->getOrCreateModelFeed(mtype, ctype, tran[1]);

    if ( !mfeed ) {
        // ERROR: could not find model feed for arc.
        pbs_error("CDF-203", arcStr.c_str());
        return 0x0 ;
    }

    return mfeed->get_or_create_arc(pin[0], tran[0], pin[1], tran[1], pin[2], tran[2], info);
}

vector<cdf::port*> 
cdf::table::ports(bool inputs) {
    vector<cdf::port*> port_list;
    for(size_t index=0; index<_ports.size(); index++) {
        port* thePort = _ports[index];
        if (inputs ? thePort->is_input() : thePort->is_output() )
            port_list.push_back(thePort);
    }
    return port_list;
}

vector<cdf::bus*>
cdf::table::buses(bool inputs) {
    vector<cdf::bus*> bus_list;
    for(size_t index=0; index<_buses.size(); index++) {
        bus* theBus = _buses[index];
        if (inputs ? theBus->is_input() : theBus->is_output() )
            bus_list.push_back(theBus);
    }
    return bus_list;
}

cdf::port*
cdf::findSupply(string name) {
    for(size_t index=0; index<_supplies.size(); index++)
        if ( _supplies[index]->name() == name )
            return _supplies[index];
    return 0x0;
}

cdf::port*
cdf::table::findPort(string name) {
    for(size_t index=0; index<_ports.size(); index++)
        if ( _ports[index]->name() == name )
            return _ports[index];
    return 0x0;
}

cdf::bus*
cdf::table::findBus(string name) {
    for(size_t index=0; index<_buses.size(); index++)
        if ( _buses[index]->name() == name )
            return _buses[index];
    return 0x0;
}

string 
cdf::table::getStateStr(vector<string>& state) {
    string pos = "";
    vector<port*> inputs = ports(true);
    for(size_t index1=0; index1<state.size(); index1++) {
        string min_term = "";
        for(size_t index2=0; index2<state[index1].size(); index2++) {
            char logic = state[index1][index2];
            string in = logic == '0' ? ("!"+ inputs[index2]->name()) : 
                (logic == '1' ? inputs[index2]->name() : "");
            min_term += in.empty() ? "" : (min_term.empty() ? "" : " & ") + in;
        }
        if ( ! min_term.empty() ) {
            pos += pos.empty() ? "" : " + " ;
            pos += "(" + min_term + ")";
        }
    }
    return pos;
}

void
cdf::function::changePortNames(map<string, string>& portMap)
{
    for(size_t index=0; index<_attributes.size(); index++)
    {
        _attributes[index].first  = map_function(portMap, _attributes[index].first);
        _attributes[index].second = map_function(portMap, _attributes[index].second);
    }
    for(size_t index=0; index<_equations.size(); index++)
    {
        _equations[index].first  = map_function(portMap, _equations[index].first) ;
        _equations[index].second = map_function(portMap, _equations[index].second);
    }
    return ;
}

void
cdf::table::changePortNames(map<string, string>& portMap)
{
    map<string, string> busMap;
    for(size_t i=0; i<_ports.size(); i++)
    {
        string portName = _ports[i]->name();
        map<string, string>::iterator miter = portMap.find(portName);
        if ( miter != portMap.end() )
        {
            string newPortName = miter->second ;
            busMap[cdf::spiceBusName(portName)] = cdf::spiceBusName(newPortName);
            _ports[i]->setNewName(newPortName);
        } 
        else
        {
            busMap[cdf::spiceBusName(portName)] = HANNGING_BUS;
            _ports[i]->setNewName(HANNGING_NODE) ;
        }
    }

    for(size_t i=0; i<_buses.size(); i++)
    {
        map<string, string>::iterator miter = busMap.find(_buses[i]->name());
        if ( miter != busMap.end() )
        {
            _buses[i]->setNewName(miter->second);
        }
    }
    _functions.changePortNames(portMap);
}

bool
cdf::table::hasClocks() {
    for(size_t index=0; index<_ports.size(); index++)
        if ( _ports[index]->is_clock() )
            return true;
    return false;
}

void
cdf::table::destroyStimulus()
{
    for(size_t i=0; i<_sections.size(); i++)
        delete _sections[i];
    _sections.clear();
}

// table printer.
string 
cdf::table::print() {
    size_t index;
    vector<string> in, clk, out;

    string text = "\ttable " + _name + "\n";

    bool bit_blast = getenv("expand_buses") != 0x0 ;

    for (index=0; index<_ports.size(); index++)
    {
        if ( !bit_blast && _ports[index]->is_part_of_bus() )
            continue;
        if ( _ports[index]->is_clock() )
        {
            clk.push_back(_ports[index]->print());
        }
        else if ( _ports[index]->is_input() )
        {
            in.push_back(_ports[index]->print());
        }
        else if ( _ports[index]->is_output() )
        {
            out.push_back(_ports[index]->print());
        }
    }
    text += in.size() ?
        string("\t\tinputs ") + tokenizer::join(in, " , ") + ";\n" : "";
    text += clk.size() ?
        string("\t\tclocks ") + tokenizer::join(clk, " , ") + ";\n" : "";
    text += out.size() ?
        string("\t\toutputs ") + tokenizer::join(out, " , ") + ";\n" : "";

    if ( ! bit_blast )
    {
        for (index=0; index<_buses.size(); index++)
        {
            if ( _buses[index]->is_clock() )
            {
                text += "\t\tclocks " + _buses[index]->print() + ";\n";
            }
            else if ( _buses[index]->is_input() )
            {
                text += "\t\tinputs " + _buses[index]->print() + ";\n";
            }
            else if ( _buses[index]->is_output() )
            {
                text += "\t\toutputs " + _buses[index]->print() + ";\n";
            }
        }
    }


    text += _functions.print();
    if ( _ccBlock )
        text += _ccBlock->print();

    for (index=0; index<_sections.size(); index++) {
        text += _sections[index]->print();
    }
    text += "\tend_table\n";
    return text;
}


// external commands.
extern int 
write_cdf(cdf* theCDF, const char* filename)
{
    if ( theCDF == 0x0 )
        return 1;

    ofstream outfile;
    outfile.open(filename, ofstream::out);

    if ( ! outfile.is_open() ) {
        pbs_error("CDF-101", filename);
        return 1;
    }

    outfile << theCDF->print();
    outfile.close();

    return 0;
}
#endif
