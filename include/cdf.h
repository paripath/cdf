//#############################################################################
//#                           Copyright Paripath, Inc.
//#                            All Rights Reserved
//#############################################################################
//# Created by: Rohit Sharma
//#
//# Revision $Revision: 1.29 $, last checked in by $Author: srohit $ on $Date: 2017/11/09 05:46:44 $.
//#
//# CVS ID: $Id: cdf.h,v 1.29 2017/11/09 05:46:44 srohit Exp $
//#############################################################################
//#
//# Description:
//
//
#ifndef _CDF
#define _CDF
// Circuit/Characterization Description/Definition Format
#include "utils.h"
#include <algorithm>
#include <map>

using namespace std;

template<typename T1, typename T2, typename T3>
struct triplet {
    T1 first;
    T2 second;
    T3 third;
    triplet(T1 e1, T2 e2, T3 e3) : first(e1), second(e2), third(e3) {}
    bool operator<(const triplet& other) const { 
        bool first_equal  = (first  == other.first) ;
        bool second_equal = (second == other.second) ;
        if ( first_equal && second_equal )
            return third < other.third ;
        if ( first_equal )
            return second < other.second ;
        return first < other.first ;
    }
    bool operator==(const triplet& other) const { return first == other.first && second == other.second && third == other.third ; }
    bool operator!=(const triplet& other) const { return ! this->operator==(other) ; }
};

class cdf {
public:
    enum TRANSITION {UNDEFINED_TRANSITION, RISE, FALL, RISE2Z, FALL2Z, Z2ONE, Z2ZERO}; //R,F,t,T,Z,z
    enum CHAR_TYPE  {UNDEFINED_CHAR=0, DELAY, DELAY_VAR, TRISTATE, TRISTATE_VAR, INCAP, RCAP, \
                     IPOWER, DPOWER, APOWER, LPOWER, SETUP, SETUP_VAR, HOLD, HOLD_VAR, RECOVERY, \
                     RECOVERY_VAR, REMOVAL, REMOVAL_VAR, MPW, MPW_VAR,  MAXCAP, CCSN_VIVO, CCSN_PROP, \
                     CCSN_VOLT, CCSN_MCAP};
    // MODEL_TYPE is subset of CHAR_TYPE. e.g. MODEL_CCS_DRIVER and MODEL_DELAY are nothing but
    // CHAR_TYPE delay. CDF format forces these two to become different.
    enum MODEL_TYPE {UNDEFINED_MODEL=0, MODEL_DELAY, MODEL_DELAY_VAR, MODEL_TRISTATE, \
                     MODEL_TRISTATE_VAR, MODEL_INCAP, MODEL_IPOWER, MODEL_DPOWER, MODEL_APOWER, \
                     MODEL_LPOWER, MODEL_SETUP, MODEL_SETUP_VAR, MODEL_HOLD, MODEL_HOLD_VAR, \
                     MODEL_RECOVERY, MODEL_RECOVERY_VAR, MODEL_REMOVAL, MODEL_REMOVAL_VAR, \
                     MODEL_MPW, MODEL_MAXCAP, MODEL_CCS_DRIVER, MODEL_CCS_RECEIVER, \
                     MODEL_PG_DCURRENT, MODEL_PG_ICURRENT, MODEL_LCURRENT, \
                     MODEL_VIVO, MODEL_PROP, MODEL_VOLT, MODEL_MCAP};
    enum STATE {INIT, FUNCTION_READY, VECTOR_READY, CHAR_READY, MODEL_READY, END};

    // NOTE: these are kept constant in cdf and separate from config bus_syntax 
    // to map empty bus_syntax in spice. Example "cdf A[0]" -> "spice A0", here spice has no
    // bus-syntax.
    static const char bus_open ;
    static const char bus_close ;
    static const char bus_delimiter ;

    // forward declaration.
    class table;
    class bus;

    class port {
    public:
        class property {
            port* _preset;
            port* _clear;
            port* _renable; // memory
            port* _wenable; // memory
            port* _clock; // memory
            port* _address_bus; // memory
        public:
            property() : _preset(0x0), _clear(0x0), _renable(0x0),
              _wenable(0x0), _clock(0x0), _address_bus(0x0)
            {}
            ~property() {}
            void  set_preset(port* in)       { _preset = in; }
            port* get_preset()               { return _preset; }
            void  set_clear(port* in)        { _clear = in; }
            port* get_clear()                { return _clear; }
            void  set_renable(port* in)      { _renable = in ; }
            port* get_renable()              { return _renable ;}
            void  set_wenable(port* in)      { _wenable = in; }
            port* get_wenable()              { return _wenable; }
            void  set_clock(port* in)        { _clock = in; }
            port* get_clock()                { return _clock ; }
            void  set_address_bus (port* in) { _address_bus = in; }
            port* get_address_bus ()         { return _address_bus; }
            string print() {
                string text = _preset ? " preset="    + _preset->name() : "" ;
                text += _clear        ? " clear="     + _clear->name()   : "" ;
                text += _renable      ? " renable="   + _renable->name() : "" ;
                text += _wenable      ? " wenable="   + _wenable->name() : "" ;
                text += _clock        ? " clock="     + _clock->name()   : "" ;
                text += _address_bus  ? " address="   + _address_bus->name()   : "" ;
                return text;
            }
        };
    public:
        enum port_type {nodirection=0, input=1, output=2, clock=3, supply0=4, supply1=5, internal=6, last=15};
        port(string name) : _name(name), _id(0), _relations(0x0), _bus(0x0) {}
        ~port() { delete _relations; }
        void set_input() { _id.set(input); }
        void set_output() { _id.set(output); }
        void set_clock() { _id.set(clock); }
        void set_supply1() { _id.set(supply1); }
        void set_supply0() { _id.set(supply0); }
        void set_internal() { _id.set(internal); }
        bool is_input() const { return _id.get(input); }
        bool is_output() const { return _id.get(output); }
        bool is_clock() const { return _id.get(clock); }
        bool is_supply0() const { return _id.get(supply0); }
        bool is_supply1() const { return _id.get(supply1); }
        bool is_internal() const {return _id.get(internal); }
        void set_part_of_bus(bus* b) { _bus = b; }
        bool is_part_of_bus() const { return (bool)_bus ; }
        bus* get_bus() { return _bus; }
        bool is_bus() { return false; }
        property* get_relations() {
            if ( _relations == 0x0 ) 
                _relations = new property();
            return _relations;
        }
        string name() { return _name; }
        void setNewName(string n) { _name = n; }
        bool operator< (const port &other) const { return _name <  other._name; }
        bool operator==(const port& other) const { return _name == other._name; }
        bool operator!=(const port& other) const { return _name != other._name; }
        string print() {
            string text = name();
            text += _relations ? _relations->print() : "";
            return text;
        }
    protected:
        string    _name;
        flag      _id;
        property* _relations;
        bus*      _bus; //not owner
    };
    class bus : public port {
        short int     _sindex;
        short int     _eindex;
        vector<port*> _ports ;
    public:
        bus(string name, short int si, short int ei) :
            port(name), _sindex(si), _eindex(ei)
        {}
        vector<port*> ports() { return _ports ; }
        short int start()     { return _sindex; }
        short int end()       { return _eindex; }
        void addPort(port* p) { _ports.push_back(p); }
        bool isBus()          { return true;    }
        string print() {
            char range[32] ;
            sprintf(range, "%c%d%c%d%c", cdf::bus_open, _sindex, cdf::bus_delimiter, _eindex, cdf::bus_close);
            string text = range + string(" ") ;
            text += name() + (_relations ? _relations->print() : "");
            return text;
        }
    };

    struct ltPort {
        bool operator() (const cdf::port* p1, const port* p2) const { 
            return (*p1) < (*p2) ;
        }
    };

    class function {
    protected:
        string _cell_type;
        vector<string> _states; // state variable holder. e.g. IQ, IQN
        vector<pair<string, string> > _attributes;
        // unique associated container of output and equation.
        vector<port*> _outputs;
        vector<pair<string, string> > _equations; // first: onset, second: three_state_enable
    public:
        function () {}
        int find(cdf::port* out) {
            for(size_t index=0; index<_outputs.size(); index++)
                if ( _outputs[index] == out )
                    return index;
            return -1;
        }
        bool set(port* out, string equation, bool tri_enable) {
            if (out == 0x0)
                return false;
            int index = find(out);
            if ( index == -1 ) {
                _outputs.push_back(out);
                pair<string, string> func("","");
                if (tri_enable) func.second = equation;
                else func.first = equation;
                _equations.push_back(func);
            } else {
                if (tri_enable) _equations[index].second = equation;
                else _equations[index].first = equation;
            }
            return true;
        }
        string get(port* out, bool tri_enable=false) {
            for(size_t index=0; index<_outputs.size(); index++) {
                if ( _outputs[index] == out )
                    return tri_enable ? _equations[index].second : _equations[index].first;
            }
            return "";
        }
        vector<string> stateVariables() {
            return _states;
        }
        void set_cell_type(string type) { 
            _cell_type = type;
            tokenizer tokens(type,"(");
            if ( tokens.size() < 2 ) return ;
            tokenizer fields(tokens[1], ")");
            if ( fields.size() < 1 ) return ;
            tokenizer vars(fields[0],",");
            if ( vars.size() < 2 );
            if ( cell_type() == "ff" || cell_type() == "latch" ) {
                tokenizer::trim(vars[0], " "); _states.push_back(vars[0]);
                tokenizer::trim(vars[1], " "); _states.push_back(vars[1]);
            } else if ( cell_type() == "statetable" ) {
                tokenizer::trim(vars[1],"\"");
                tokenizer states(vars[1]);
                _states = states.tokens();
            }
        }
        void set_cell_attribute(pair<string, string> attr) { _attributes.push_back(attr); }
        string cell_type() {
            if ( _cell_type.compare(0,2,"ff") == 0 ) return "ff";
            if ( _cell_type.compare(0,5,"latch") == 0 ) return "latch";
            if ( _cell_type.compare(0,6,"memory") == 0 ) return "memory";
            if ( _cell_type.compare(0,10,"statetable") == 0 ) return "statetable";
            return "comb";
        }
        string get_attribute(string key) {
            for(size_t index=0; index<_attributes.size(); index++)
                if ( _attributes[index].first == key )
                    return _attributes[index].second;
            return "";
        }
        vector<pair<string, string> > get_attributes() { return _attributes; }
        string print() {
            string text = "\t\tfunction\n";
            if ( !_cell_type.empty() ) {
                text += "\t\t\t" + _cell_type + "\n";
                for(size_t index=0; index<_attributes.size(); index++)
                    text += "\t\t\t\t" + _attributes[index].first + " : " + _attributes[index].second + "\n";
                text += "\t\t\t}\n";
            }
            size_t index;
            for(index=0; index<_outputs.size(); index++) {
                text += "\t\t\t" + _outputs[index]->name() + " = " + _equations[index].first + "\n";
                if (!_equations[index].second.empty())
                    text += "\t\t\t" + _outputs[index]->name() + " Z = " + _equations[index].second + "\n";
            }
            text += "\t\tend_function\n";
            return text;
        }
        void changePortNames(map<string, string> &portMap);
    };
    ////////////////////////////////////////////////////////////
    // Simulation Feed Start.
    // This structure to feed additional data for the simulator.
    //
    class simulation_feed {
    private:
        vector<CHAR_TYPE> _types;
        vector<string> _ic;
    public:
        simulation_feed(vector<CHAR_TYPE> types) : _types(types) { _ic.clear(); }
        simulation_feed(const simulation_feed& other) { //copy constructor
            _types = other._types;
            _ic = other._ic;
        }
        bool is_type(CHAR_TYPE type) { return find(_types.begin(), _types.end(), type) != _types.end() ; }
        vector<CHAR_TYPE> types() { return _types; }
        string get();
        void set(string node_value_pair) { _ic.push_back(node_value_pair); }
        string print(vector<CHAR_TYPE>);
    };

    ////////////////////////////////////////////////////////////
    // Modeling related structures.
    //

    struct arcValue {
        arcValue();
        float         _index1; //slope
        float         _index2; // slope or load
        float         _index3; // load
        string        _deck;
        string        _result_file;
        vector<float> _values1; // delay, slew, power, setup etc.
        vector<float> _values2; // delay, slew, power, setup, hold etc.
        arcValue(float index1, float value1, string deck="",
            string result_file="", float index2=FLOAT_MIN,
            float index3=FLOAT_MIN, float value2=FLOAT_MIN)
            : _index1(index1), _index2(index2), _index3(index3),
              _deck(deck), _result_file(result_file)
        {
            if ( value1 > FLOAT_MIN ) _values1.push_back(value1);
            if ( value2 > FLOAT_MIN ) _values2.push_back(value2);
        }
        string values();
        arcValue(const arcValue& other) {
            _index1 = other._index1;
            _index2 = other._index2;
            _index3 = other._index3;
            _deck   = other._deck;
            _result_file = other._result_file;
            _values1 = other._values1;
            _values2 = other._values2;
        }
    };

    // In this structre, _values1 and _values2 are used as time and current
    // vectors respectively.
    struct arcWaveform : public arcValue {
        float  _refTime ;
        string _pgPin ;
        arcWaveform (float index1, float index2, float index3,
            float refTime, vector<float> xVec, vector<float> yVec,
            string deck="", string result_file="", string pgPin="")
             : arcValue (index1, FLOAT_MIN, deck, result_file, index2,
            index3, FLOAT_MIN) 
            {
                _values1 = xVec ;
                _values2 = yVec ;
                _refTime = refTime ;
                _pgPin   = pgPin ;
            }
        string values();
        arcWaveform(const arcWaveform& other) : arcValue(other) {
            _refTime = other._refTime ;
            _pgPin = other._pgPin ;
        }
    };


    class arc {
    private:
        port*      _pin1;
        TRANSITION _tran1;
        port*      _pin2;
        TRANSITION _tran2;
        port*      _pin3;
        TRANSITION _tran3;
        char*      _info; // state information for leakage power. zero-dimension arc.
        // TODO: _values and _waveform should be in a union to save memory.
        vector<arcValue*> _values; //owner.
        vector<arcWaveform*> _waveform; //owner.
        arc() ;
    public:
        arc(port* pin1, TRANSITION tran1, 
            port* pin2=0x0, TRANSITION tran2=UNDEFINED_TRANSITION,
            port* pin3=0x0, TRANSITION tran3=UNDEFINED_TRANSITION,
            const char* info=0x0) 
            : _pin1(pin1), _tran1(tran1),
              _pin2(pin2), _tran2(tran2),
              _pin3(pin3), _tran3(tran3)
        {
            copy_info(info);
        }
        arc(const arc& other) {
            _pin1 = other._pin1; _tran1 = other._tran1;
            _pin2 = other._pin2; _tran2 = other._tran2;
            _pin3 = other._pin3; _tran3 = other._tran3;
            size_t index=0;
            for(index=0; index<other._values.size(); index++)
                _values.push_back(new arcValue(*other._values[index]));
            for(index=0; index<other._waveform.size(); index++)
                _values.push_back(new arcWaveform(*other._waveform[index]));
            copy_info(other._info);
        }
        bool operator==(const arc& other) const {
            if ( this == &other ) return true ;
            return _pin1 == other._pin1 && _tran1 == other._tran1 &&
                _pin2 == other._pin2 && _tran2 == other._tran2 &&
                _pin3 == other._pin3 && _tran3 == other._tran3 &&
                (_info == other._info || (_info && other._info && !strcmp(_info, other._info)));
        }
        bool operator<(const arc& other) const {
            if ( this == &other ) return false ;
            return ( (_pin1 && other._pin1) ? *_pin1 < *other._pin1 : _pin1 <=other._pin1) &&
                    _tran1 < other._tran1 &&
                    ( (_pin2 && other._pin2) ? *_pin2 < *other._pin2 : _pin2 <=other._pin2) &&
                    _pin3 < other._pin3 && _tran3 < other._tran3 &&
                    ( (_pin3 && other._pin3) ? *_pin3 < *other._pin3 : _pin3 <=other._pin3)
                ;
        }
        ~arc() {
            size_t index=0;
            for(index=0; index<_values.size(); index++)
                delete _values[index];
            for(index=0; index<_waveform.size(); index++)
                delete _waveform[index];
            delete [] _info;
        }
        void copy_info(const char* info) {
            _info = 0x0 ;
            if ( info == 0x0 ) return;
            _info = new char[strlen(info) + 1];
            strcpy(_info, info);
        }
        cdf::TRANSITION tran1() { return _tran1; }
        cdf::TRANSITION tran2() { return _tran2; }
        cdf::TRANSITION tran3() { return _tran3; }
        cdf::port*      pin1() { return _pin1; }
        cdf::port*      pin2() { return _pin2; }
        cdf::port*      pin3() { return _pin3; }
        const char*     info() { return _info; }
        void addArcValue(arcValue* val) { if ( val != 0x0 ) _values.push_back(val); }
        void addArcWaveform(arcWaveform* val) { if ( val != 0x0 ) _waveform.push_back(val); }
        const vector<arcValue*>& getArcValues() { return _values; }
        const vector<arcWaveform*>& getArcVectors() { return _waveform; }
        string tclPrint();
        string print(string prefix);
    };
    class model_feed {
    private:
        MODEL_TYPE _type;
        vector<arc*> _arcs;
    public:
        model_feed(MODEL_TYPE type) : _type(type) {}
        model_feed(const model_feed& other);//copy constructor
        string print() {
            string text = "";
            for(size_t index=0; index<_arcs.size(); index++)
                text +=  _arcs[index]->print("\t\t\tmodel " + cdf::modelTypeStr(_type)) + "\n";
            return text;
        }
        MODEL_TYPE type() { return _type; }
        vector<arc*> get_arcs() { return _arcs; }
        int find_arc(arc* theArc) {
            for(size_t index=0; index<_arcs.size(); index++) {
                if ( theArc->operator==(*_arcs[index]) ) {
                    return index;
                }
            }
            return -1;
        }
        arc* const get_arc(port* pin1, TRANSITION tran1, 
            port* pin2=0x0, TRANSITION tran2=UNDEFINED_TRANSITION,
            port* pin3=0x0, TRANSITION tran3=UNDEFINED_TRANSITION,
            const char* info=0x0) {
            arc theArc(pin1, tran1, pin2, tran2, pin3, tran3, info);
            int index = find_arc(&theArc);
            if ( index != -1 )
                return _arcs[index];
            return 0x0;
        }
        arc* const create_arc(port* pin1, TRANSITION tran1, 
            port* pin2=0x0, TRANSITION tran2=UNDEFINED_TRANSITION,
            port* pin3=0x0, TRANSITION tran3=UNDEFINED_TRANSITION,
            const char* info=0x0) {
            arc* theArc = new arc(pin1, tran1, pin2, tran2, pin3, tran3, info);
            _arcs.push_back(theArc);
            return theArc;
        }
        arc* get_or_create_arc(port* pin1, TRANSITION tran1, 
            port* pin2=0x0, TRANSITION tran2=UNDEFINED_TRANSITION,
            port* pin3=0x0, TRANSITION tran3=UNDEFINED_TRANSITION,
            const char* info=0x0) {
            arc* theArc = get_arc(pin1, tran1, pin2, tran2, pin3, tran3, info);
            if (theArc==0x0) theArc = create_arc(pin1, tran1, pin2, tran2, pin3, tran3, info);
            return theArc;
        }
    };
    // This class can analyze unateness of all the sequences or sequence
    // like structures. One can feed all the sequences, before asking 
    // the answer. Example-
    // ttable sense;
    // while (sequences.next(sqnc))
    //        sense.analyze(sqnc1);
    // sense.get(2,3); //unateness for second output and third input.
    class ttable {
        vector<vector<flag> > _io_trans; //out->in relation. rr, rf, fr, ff
        short index(TRANSITION ot, TRANSITION it) ;
        void get_space(size_t, size_t);
    public:
        ttable() {}
        bool is_proper_subset(pair<vector<string>, string>& sequence);
        void analyze(pair<vector<string>, string>& sequence);
        void analyze(const vector<arc*>);
        unsigned char get(size_t out_index, size_t in_index);
    };
    class stimulus {
    public:
        typedef pair<vector<string>, string> sequence;
    protected:
        short               _id;
        vector<CHAR_TYPE>   _types;
        vector<simulation_feed*>
                            _sim;
        vector<string>      _condition; // POS form of boolean equation.
        sequence            _sequence;
        vector<model_feed*> _model_arcs;
        vector<triplet<string, string, string> >
                            _jobs;
        string              _activity_file ;
    public:
        stimulus(vector<CHAR_TYPE> types) : _id(0), _types(types) { }
        stimulus(const stimulus& other) ;
        bool setCondition(vector<string> state) {
            if ( _condition.size() ) return false;
            _condition = state;
            return true;
        }
        void setSequence(sequence sqnc) { _sequence = sqnc; }
        void setID(short id) { _id = id; }
        void setActivityFile (string actFile) { _activity_file = actFile ; }
        void queueJob(string inFile, string command, string outFile) {
            _jobs.push_back(triplet<string, string, string>(inFile, command, outFile));
        }
        vector<triplet<string, string, string> >& listJobs() {return _jobs;}
        void removeJobs() { _jobs.clear(); }
        model_feed* getModelFeed(MODEL_TYPE, CHAR_TYPE) ; // one model_feed per type.
        model_feed* getOrCreateModelFeed(MODEL_TYPE, CHAR_TYPE, cdf::TRANSITION tran=cdf::UNDEFINED_TRANSITION) ;
        sequence getSequence() { return _sequence; }
        short getID () { return _id; }
        string getActivityFile() { return _activity_file ; }
        simulation_feed* createSimFeed(CHAR_TYPE ctype) {
            // Note: This can support "one" or "all" char types. You cannot
            // have a simfeed of of type delay first and power incap next.
            if ( !is_type(ctype) && ctype != cdf::UNDEFINED_CHAR) return 0x0;
            simulation_feed* sim = getSimFeed(ctype);
            if ( sim == 0x0 ) {
                vector<CHAR_TYPE> types ;
                if (ctype == UNDEFINED_CHAR) 
                    types = _types;
                else
                    types.push_back(ctype);
                sim = new simulation_feed(types);
                _sim.push_back(sim);
            }
            return sim;
        }
        simulation_feed* getSimFeed(CHAR_TYPE ctype) {
            for(size_t index=0; index<_sim.size(); index++)
                if ((ctype == cdf::UNDEFINED_CHAR && _types == _sim[index]->types()) ||
                    _sim[index]->is_type(ctype) )
                    return _sim[index];
            return 0x0; 
        }
        vector<string> getCondition() { return _condition; }
        string getCondition(table*) ;
        string getSDFCondition(table*) ;
        bool is_type(CHAR_TYPE type) { return find(_types.begin(), _types.end(), type) != _types.end() ; }
        vector<CHAR_TYPE> getTypes() { return _types; }
        string print();
    };
    class ccb {
    protected:
        cdf::port* _ccbPort ;
        string     _ccbFile ;
    public:
        ccb(cdf::port* port, string file) ;
        cdf::port* getPort() { return _ccbPort; }
        string info() ;
        string print() ;
    };

    class table {
    protected:
        string            _name;
        ccb*              _ccBlock ; // channel connected block.
        vector<port*>     _ports;
        vector<bus*>      _buses;
        vector<stimulus*> _sections;
        function          _functions;
    public:
        table(string& name) : _name(name), _ccBlock(0x0) {}
        ~table() {
            size_t i=0;
            for(i=0; i<_ports.size(); i++) delete _ports[i];
            for(i=0; i<_buses.size(); i++) delete _buses[i] ;
            for(i=0; i<_sections.size(); i++) delete _sections[i];
            delete _ccBlock ;
        }
        string name() { return _name; }
        void addPort(port* pPort) { _ports.push_back(pPort); }
        void addBus(bus* pBus) { _buses.push_back(pBus); }
        vector<port*> ports(bool);
        vector<port*> ports() { return _ports; }
        vector<bus*> buses(bool);
        vector<bus*> buses() { return _buses; }
        port* findPort(string name);
        bus* findBus(string busName);
        size_t n_inputs() { return ports(true).size(); }
        size_t n_outputs() { return ports(false).size(); }
        void changePortNames(map<string, string> &);
        bool hasClocks();
        string getStateStr(vector<string>&) ;
        string print();
        vector<stimulus*> getStimulus() { return _sections; }
        void destroyStimulus();
        void addStimulus(stimulus* section) { 
            section->setID(_sections.size());
            _sections.push_back(section); 
        }
        bool addFunction(port* out, string equation, bool tri_enable) { return _functions.set(out,equation,tri_enable); }
        bool addCCB(cdf::ccb* block) { _ccBlock = block; return true; }
        void set_cell_type(string type) {_functions.set_cell_type(type);}
        string cell_type() { return _functions.cell_type();}
        vector<string> outStates() { return _functions.stateVariables(); }
        void set_cell_attribute(string key, string value) { _functions.set_cell_attribute(pair<string, string>(key, value)); }
        vector<pair<string, string> > cell_attributes() { return _functions.get_attributes(); }
        string cell_attribute(string key) { return _functions.get_attribute(key); }
        string getFunction(port* out) { return _functions.get(out); }
        ccb* getCCB() { return _ccBlock; }
        string getThreeState(port* out) { return _functions.get(out, true); }
        void set_relations(port* pPort, port* preset,
                           port* clear, port* renable,
                           port* wenable, port* clock,
                           port* address)
        {
            if ( !pPort )
                return ;
            if ( !preset && !clear && !renable && !wenable && !clock && !address)
                return ;

            port::property* port2port_relations = pPort->get_relations(); // must be non-null.
            if ( !port2port_relations )
                return ;

            if ( preset )   port2port_relations->set_preset(preset);
            if ( clear )    port2port_relations->set_clear(clear);
            if ( wenable )  port2port_relations->set_wenable(wenable);
            if ( renable )  port2port_relations->set_renable(renable);
            if ( address )  port2port_relations->set_address_bus(address);
            if ( clock )    port2port_relations->set_clock(clock);

            return ;
        }
    };
protected:
    string         _name;
    STATE          _current_state;
    vector<port*>  _supplies; // power and ground
    vector<table*> _tables;
public:
    bool is_inout(string name) ;
    void ports(vector<string>& inputs, vector<string>& clocks,
           vector<string>& inouts, vector<string>& outputs);
    void buses(vector<string>& inputs, vector<string>& clocks,
           vector<string>& inouts, vector<string>& outputs);
    void ports(vector<port*>& inputs, vector<port*>& clocks,
           vector<port*>& inouts, vector<port*>& outputs);
    bus* getBus(string& portName) ;
    void supplies(vector<port*>& highSupplies, vector<port*>& lowSupplies) ;
    void addSupply(port* pPort) { if ( pPort ) _supplies.push_back(pPort); }
    port* findSupply(string name);
    string getFunction(string& cell_port, bool threestate=false);
    cdf(string name) : _name(name) {}
    ~cdf() { 
        for(size_t i=0; i<_supplies.size(); i++) 
            delete _supplies[i]; 
        for(size_t i=0; i<_tables.size(); i++) 
            delete _tables[i]; 
    }
    string name() { return _name; }
    void   name(string& name) { _name = name; }
    table* create_table(string name) {
        table* tbl = new table(name);
        _tables.push_back(tbl);
        return tbl;
    }
    vector<table*> get_tables() { return _tables; }
    void changePortNames(map<string, string> &);

    // utility functions for all clients.
    string print();
    static vector<cdf::TRANSITION> getInPortTransitions( \
                cdf::table* tbl, cdf::stimulus::sequence& sqnc) ;
    static vector<cdf::TRANSITION> getOutPortTransitions( \
                cdf::table* tbl, cdf::stimulus::sequence& sqnc) ;
    static vector<port*> getActiveInputs(stimulus::sequence, vector<port*>);
    static vector<port*> getActiveOutputs(stimulus::sequence, vector<port*>);
    static vector<arc*> getInOutArc(const stimulus::sequence&, table*);
    static arc* get_or_create_arc(cdf*, table*, stimulus*, string arcStr);
    static string getCondition(string& minterm, vector<port*>& ports);
    static string getSDFCondition(const string& minterm, vector<port*>& ports);
    static char getTransition(TRANSITION);
    static TRANSITION getTransition(char, char);
    static TRANSITION getTransition(char);
    static string charTypeStr(CHAR_TYPE);
    static CHAR_TYPE getCharType(string);
    static string modelTypeStr(MODEL_TYPE);
    static MODEL_TYPE getModelType(string);
    static CHAR_TYPE modelToCharType(MODEL_TYPE) ;
    static MODEL_TYPE charToModelType(CHAR_TYPE) ; // TODO: delete
    static string spiceBusName(string& spiceNodeName);
    pair<float, float> getArcScalarValue(string&, cdf::CHAR_TYPE ctype=cdf::INCAP,
                                         bool bit_blast=false);
};
#endif
