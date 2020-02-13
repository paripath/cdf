//#############################################################################
//#                           Copyright Paripath, Inc.
//#                            All Rights Reserved
//#############################################################################
//# Created by: Rohit Sharma
//#
//# Revision $Revision: 1.24 $, last checked in by $Author: srohit $ on $Date: 2016/11/08 17:56:00 $.
//#
//# CVS ID: $Id: cdfReader.cpp,v 1.24 2016/11/08 17:56:00 srohit Exp $
//#############################################################################
//#
//# Description:
//
//
#ifndef CDF_READER
#define CDF_READER

#include "cdf.h"
#include "fstream"
#include "message.h"
//#include "configManager.h"
#include <sys/stat.h> //for stat call

using namespace std;

class cdf_reader {
private:
    bool checkBusRule(tokenizer& tokens,
                      short int& bus_start,
                      short int& bus_end);
public:
    enum state {UNKNOWN_STATE, START_CDF, SUPPLY0, SUPPLY1, START_TABLE, COMMENT, 
        INPUTS, OUTPUTS, CLOCKS, FUNCTION, CCB, ACTIVITY, CHAR, SIM_FEED, SIM_ARC, MODEL_ARC,
        STATE, VECTOR, END_FUNCTION, END_TABLE, END_CDF };
    cdf_reader(string filename, bool quiet=false);
    ~cdf_reader();
    cdf* getCDF() { return _cdf; }
    void lexon(string filename);
    state checkRules(tokenizer&);
    void checkCDFStartRule(tokenizer&);
    void checkSupply1Rule(tokenizer&);
    void checkSupply0Rule(tokenizer&);
    void checkTableRule(tokenizer&);
    void checkPortsRule(tokenizer&);
    void checkFunctionRule();
    void checkCCBRule(tokenizer&);
    void checkActivityRule(tokenizer&);
    void checkCharTypeRule(tokenizer&);
    void checkSimFeedRule(tokenizer&);
    void checkSimArcRule(tokenizer&);
    void checkModelArcRule(tokenizer&);
    void checkStateRule(tokenizer&);
    void checkVectorRule(tokenizer&);
    void checkEndTableRule(tokenizer&);
    void checkEndCDFRule(tokenizer&);
    state getState(string& token);
    string msg(const string&);
    bool checkSanctity();

protected:
    short          _line_number;
    //temporary holders.
    vector<string> function_section;
    cdf*           _cdf;
    cdf::table*    _table;
    cdf::stimulus* _section;
    char*          _cmsg;
    string         _bus_syntax;
};

string
cdf_reader::msg(const string& info)
{
    sprintf(_cmsg, " line number %d: %s", _line_number, info.c_str());
    return _cmsg;
}

cdf_reader::cdf_reader(string filename, bool quiet)
: _line_number(0), _cdf(0x0), _table(0x0), _section(0x0)
{
    _cmsg = new char[4096];
    _bus_syntax = getenv("bus_syntax") ; ;
    _bus_syntax = _bus_syntax.size() && _bus_syntax.size() != 2 ? "[]" : _bus_syntax ; // silent error correction.

    if ( !quiet )
        pbs_msg(string("reading cdf " + filename).c_str());
    lexon(filename);
    checkSanctity() ;
}

cdf_reader::~cdf_reader()
{
    delete [] _cmsg;
}

void
cdf_reader::lexon(string filename)
{
    string mline;

    filebuf buf;
    buf.open(filename.c_str(), ios::in);
    if ( !buf.is_open() ) {
        pbs_error("CDF-101", filename.c_str());
        return; // ERROR.
    }

    istream cdf_stream(&buf);
    int fsize = cdf_stream.tellg();
    cdf_stream.seekg(0, ios::end);
    fsize = static_cast<int>(cdf_stream.tellg()) - fsize ;

    cdf_stream.seekg(0, ios::beg);

    char* line = new char[fsize];

    while(++_line_number) { //This is an infinite loop. terminating condition is in the loop.
        cdf_stream.getline(line, fsize);

        if ( cdf_stream.eof() )
            break; // terminating condition.

        size_t len = strlen(line) ;
        if ( len && line[len - 1] == '\r' )
            line[len - 1] = '\0' ;

        string sline = line;
        size_t end = sline.find_first_of(";"); //find semicolon.
        if (end != string::npos) 
            sline = sline.substr(0, end);

        // take care of line continuation character.
        mline += sline;
        len = mline.length();
        if ( len && mline[len-1] == '\\' ) { //line  continuation character.
            mline[len-1] = ' '; // weed out line continuation character.
            continue;
        }

        tokenizer tokens(mline);

        if ( checkRules(tokens) == cdf_reader::END_CDF )
            break;

        mline = "";
    }

    buf.close();
    delete [] line;
}

bool
cdf_reader::checkSanctity()
{
    if (!_cdf)
        return false ;

    bool sanctity = true ;

    vector<cdf::port*> highSupplies, lowSupplies ;
    _cdf->supplies(highSupplies, lowSupplies) ;

    if ( highSupplies.size() == 0 )
    {
        string msg = "cdf " + _cdf->name() + " has no power supplies." ;
        pbs_error("CDF-121", msg.c_str()) ;
        sanctity = false ;
    }
    if ( lowSupplies.size() == 0 )
    {
        string msg = "cdf " + _cdf->name() + " has no ground supplies." ;
        pbs_warning ("CDF-121", msg.c_str()) ;
        sanctity = false ;
    }

    return sanctity;
}

cdf_reader::state
cdf_reader::checkRules(tokenizer & tokens) 
{
    static state prev_token1;
    if ( !tokens.size() ) return UNKNOWN_STATE;

    state token1 = getState(tokens[0]);

    if (token1 == COMMENT) return token1;

    if ( token1 != START_CDF && _cdf == 0x0 ) {
        pbs_error("CDF-103", msg(string("symbol name ") + tokens[0]).c_str());
        return token1;
    }
    if ( token1 != START_CDF && token1 != END_CDF && \
        token1 != SUPPLY0 && token1 != SUPPLY1 && \
        token1 != START_TABLE && _table == 0x0 ) 
    {
        pbs_error("CDF-104", msg(string("symbol name ") + tokens[0]).c_str());
        return token1;
    }
    // running function statement can give UNKNOWN STATE.
    if ( prev_token1 == FUNCTION || token1 == END_FUNCTION ) {
        if ( token1 != END_FUNCTION ) {
            function_section.push_back(tokens.join());
            return prev_token1;
        }
        checkFunctionRule();
        function_section.clear();
    }
    prev_token1 = token1;
    if ( token1 == UNKNOWN_STATE ) {
        pbs_error("CDF-105", msg(string("symbol name ") + tokens[0]).c_str());
        return token1;
    }

    if (token1 == START_CDF)         checkCDFStartRule(tokens);
    else if (token1 == SUPPLY1)      checkSupply1Rule(tokens);
    else if (token1 == SUPPLY0)      checkSupply0Rule(tokens);
    else if (token1 == START_TABLE)  checkTableRule(tokens);
    else if (token1 == INPUTS)       checkPortsRule(tokens);
    else if (token1 == OUTPUTS)      checkPortsRule(tokens);
    else if (token1 == CLOCKS)       checkPortsRule(tokens);
    else if (token1 == FUNCTION)     checkFunctionRule();
    else if (token1 == CCB)          checkCCBRule(tokens);
    else if (token1 == ACTIVITY)     checkActivityRule(tokens);
    else if (token1 == CHAR)         checkCharTypeRule(tokens);
    else if (token1 == SIM_FEED)     checkSimFeedRule(tokens);
    else if (token1 == SIM_ARC)      checkSimArcRule(tokens);
    else if (token1 == MODEL_ARC)    checkModelArcRule(tokens);
    else if (token1 == STATE)        checkStateRule(tokens);
    else if (token1 == VECTOR)       checkVectorRule(tokens);
    else if (token1 == END_TABLE)    checkEndTableRule(tokens);
    else if (token1 == END_CDF)      checkEndCDFRule(tokens);

    return token1;
}

void
cdf_reader::checkCDFStartRule(tokenizer& tokens)
{
    string cdf_name = tokens[1];
    _cdf = new cdf(cdf_name);
}

void
cdf_reader::checkTableRule(tokenizer& tokens)
{
    string name = tokens[1];
    if ( name.empty() ) {
        char cname[64];
        sprintf(cname, "table%d", (int)_cdf->get_tables().size());
        name = cname;
    }
    _table = _cdf->create_table(name);
}

void
cdf_reader::checkSupply1Rule(tokenizer& tokens)
{
    tokens.retokenize(", ");
    string supply1_name;
    size_t sz = tokens.size();
    for(size_t index=1; index<sz; index++) {
        supply1_name = tokens[index];
        if ( index == sz-1 && supply1_name[supply1_name.length()-1] == ';' ) {
            supply1_name = supply1_name.substr(0,supply1_name.length()-1);
        }
        cdf::port *pSupply1 = new cdf::port(supply1_name);
        pSupply1->set_supply1();
        _cdf->addSupply(pSupply1);
    }
}

void
cdf_reader::checkSupply0Rule(tokenizer& tokens)
{
    tokens.retokenize(", ");
    string supply0_name;
    size_t sz = tokens.size();
    for(size_t index=1; index<sz; index++) {
        supply0_name = tokens[index];
        if ( index == sz-1 && supply0_name[supply0_name.length()-1] == ';' ) {
            supply0_name = supply0_name.substr(0,supply0_name.length()-1);
        }
        cdf::port *pSupply0 = new cdf::port(supply0_name);
        pSupply0->set_supply0();
        _cdf->addSupply(pSupply0);
    }
}


// pass tokens after removing port keyword inputs, clocks, outputs
// parses and removes bus token (i.e. "[0:11]") from tokens.
// returns true, if it is a bus along with start and end indices.
bool
cdf_reader::checkBusRule(tokenizer& tokens, short int& bus_start, short int& bus_end)
{
    size_t sz = tokens.size();
    if ( sz == 0 )
        return false ;

    bool isBus = ( tokens[0][0] == cdf::bus_open ) ;
    bus_start = -1 ;
    bus_end   = -1 ;
    if ( isBus )
    {
        int index ;
        string bus_token = ""; // i.e. "[ 0 : 7 ]"
        for(index=0; index<sz; index++)
        {
            bus_token += tokens[index] ;
            if ( tokens[index].find_first_of(cdf::bus_close) != string::npos )
            {
                break ;
            }
        }
        if ( index < sz )
        {
            string delim = " ";
            delim[0] = cdf::bus_delimiter ;
            size_t tpos = bus_token.find_first_of(cdf::bus_open) ;
            if ( tpos != string::npos )
                bus_token.erase(tpos,1);
            tpos = bus_token.find_first_of(cdf::bus_close);
            if ( tpos != string::npos )
                bus_token.erase(tpos,1);
            tokenizer::trim(bus_token, " ");
            tokenizer busTokens(bus_token, delim);
            if ( busTokens.size() != 2 )
            {
                string cmsg = "bus range tokens are not exactly 2. Ignoring bus directive.";
                pbs_error("CDF-122", msg(cmsg).c_str());
                isBus = false;
            }
            else
            {
                bus_start = atoi(busTokens[0].c_str());
                bus_end   = atoi(busTokens[1].c_str());
                if ( bus_start < 0 || bus_end < 0 )
                {
                    string cmsg = "bus index is negative. Ignoring bus directive.";
                    pbs_error("CDF-122", msg(cmsg).c_str());
                    isBus = false ;
                }
                // swap, if order is reverse.
                if ( bus_start > bus_end )
                {
                    short int swap = bus_start ;
                    bus_start = bus_end ;
                    bus_end   = swap ;
                }
            }
            // erase bus tokens.
            while ( index-- >= 0 )
                tokens.erase(0);
        }
        else
        {
            string cmsg = "coud not find bus closing bracket (])";
            pbs_warning("CDF-122", msg(cmsg).c_str());
            isBus = false ;
        }
    }
    return isBus ;
}

void
cdf_reader::checkPortsRule(tokenizer& tokens)
{
    state portType = getState(tokens[0]);
    if ( portType != INPUTS && portType != CLOCKS && portType != OUTPUTS )
        return ;

    tokens.erase(0);

    short int bus_start=-1, bus_end=-1 ;
    bool isBus = checkBusRule(tokens, bus_start, bus_end) ;

    tokens.retokenize(",");
    string port_name;
    size_t sz = tokens.size();
    for(size_t index=0; index<sz; index++)
    {
        cdf::bus* bus = 0x0 ;
        port_name = tokens[index];
        if ( index == sz-1 && port_name[port_name.length()-1] == ';' )
        {
            port_name = port_name.substr(0,port_name.length()-1);
        }
        cdf::port *preset=0x0, *clear=0x0; //latch, ff
        cdf::port *writeEnable=0x0, *readEnable=0x0; // memory
        cdf::port *address=0x0, *clock=0x0; // memory
        tokenizer props(port_name);
        port_name = props[0];
        props.erase(0);
        props.retokenize("\t =") ;
        for(size_t index1=0; index1<props.size(); index1=index1+2) {
            if ( props[index1] == "preset" ) { // latch, flop
                preset = _table->findPort(props[index1+1]) ;
            } else if ( props[index1] == "clear" ) { // latch, flop
                clear = _table->findPort(props[index1+1]) ;
            } else if ( props[index1] == "wenable" ) { // memory
                writeEnable = _table->findPort(props[index1+1]) ;
            } else if ( props[index1] == "renable" ) { // memory
                readEnable = _table->findPort(props[index1+1]) ;
            } else if ( props[index1] == "address" ) { // memory
                address = _table->findPort(props[index1+1]) ;
                if ( ! address )
                    address = _table->findBus(props[index1+1]) ;
            } else if ( props[index1] == "clock" ) { // memory
                clock = _table->findPort(props[index1+1]) ;
            } else {
                //Error
            }
        }
        if ( isBus )
        {
            // create bus
            bus = new cdf::bus(port_name, bus_start, bus_end);
            if ( portType == INPUTS )
            {
                bus->set_input();
            }
            else if ( portType == OUTPUTS )
            {
                bus->set_output();
            }
            else if ( portType == CLOCKS )
            {
                bus->set_input();
                bus->set_clock();
            }
            _table->addBus(bus);
            _table->set_relations(bus, preset, clear, readEnable, writeEnable, clock, address);

            // create individual port
            for (int bindex = bus_start; bindex <= bus_end; bindex++)
            {
                char index_str[8];
                if ( _bus_syntax.size() )
                    sprintf(index_str, "%c%d%c", _bus_syntax[0], bindex, 
                                     (_bus_syntax.size() > 1 ? _bus_syntax[1] : '\0'));
                else if ( _bus_syntax.empty() )
                    sprintf(index_str, "%d", bindex) ;

                string bport_name = port_name +  index_str ;
                cdf::port *pPort = new cdf::port(bport_name);
                if ( portType == INPUTS )
                {
                    pPort->set_input();
                }
                else if ( portType == OUTPUTS )
                {
                    pPort->set_output();
                }
                else if ( portType == CLOCKS )
                {
                    pPort->set_input();
                    pPort->set_clock();
                }
                pPort->set_part_of_bus(bus);
                bus->addPort(pPort);
                _table->set_relations(pPort, preset, clear, readEnable, writeEnable, clock, address);
                _table->addPort(pPort);
            }
        }
        else
        {
            cdf::port *pPort = new cdf::port(port_name);
            if ( portType == INPUTS )
            {
                pPort->set_input();
            }
            else if ( portType == OUTPUTS )
            {
                pPort->set_output();
            }
            else if ( portType == CLOCKS )
            {
                pPort->set_input();
                pPort->set_clock();
            }
            _table->set_relations(pPort, preset, clear, readEnable, writeEnable, clock, address);
            _table->addPort(pPort);
        }
    }
}

void
cdf_reader::checkFunctionRule()
{
    bool cell_defn = false;
    for(size_t index=0; index<function_section.size(); index++) {
        bool tri_enable = false;
        string line = function_section[index];
        tokenizer::trim(line, " ");
        tokenizer tokens(line);
        if (line.compare(0,2,"ff") == 0 ||
            line.compare(0,5,"latch") == 0 ||
            line.compare(0,6,"memory") == 0 ||
            line.compare(0,10,"statetable") == 0 )  {
            _table->set_cell_type(line);
            cell_defn = true;
            continue;
        }
        if ( line == "}" ) {
            cell_defn = false;
            continue;
        }
        if ( cell_defn ) {
            tokenizer tokens(line, ":");
            string key = tokens[0];
            tokens.erase(0);
            string value = tokens.join(":");
            tokenizer::trim(key, " \";");
            tokenizer::trim(value, " \";");
            _table->set_cell_attribute(key, value);
            continue;
        }
        if ( tokens[1] == "Z" ) {
            tri_enable = true;
            tokens.erase(1);
        }
        // expect only output port equation from here on.
        if ( tokens[1] != "=" ) {
            pbs_error("CDF-106", msg("delimiter '=' not found in function equation.").c_str());
            continue;
        }
        // Check if output already exists in the table.
        cdf::port* out = _table->findPort(tokens[0]);
        if ( out == 0x0 ) {
            string msg = "output " + tokens[0] + " is not found in the list of outputs.";
            pbs_error("CDF-106", this->msg(msg).c_str());
            continue;
        }
        string equation ;
        for(size_t index1=2; index1<tokens.size(); index1++) {
            equation += (equation.empty() ? "" : " ") + tokens[index1];
        }
        if ( equation.empty() ) {
            string msg = "equation is empty for output " + tokens[0];
            pbs_error("CDF-106", this->msg(msg).c_str());
            continue;
        }
        if ( !_table->addFunction(out, equation, tri_enable) ) {
            string msg = "function cannot be added for output " + tokens[0];
            pbs_error("CDF-106", this->msg(msg).c_str());
        }
    }
}

void
cdf_reader::checkActivityRule(tokenizer& tokens)
{
    if ( _section == 0x0 ) 
    {
        pbs_error("CDF-109", msg(tokens[0] + " " + tokens[1]).c_str());
        return ;
    }
    if ( tokens.size() != 2 )
    {
        // Error. insufficient number of tokens.
        pbs_error("CDF-124", msg("").c_str());
        return ;
    }
    string filename = tokens[1];
    struct stat activity_file_stat;
    if ( stat(filename.c_str(), &activity_file_stat ) == -1 )
    {
        pbs_error("CDF-101", msg(filename).c_str());
        return ;
    }
    _section->setActivityFile(filename);
}

void
cdf_reader::checkCCBRule(tokenizer& tokens)
{
    if ( _section != 0x0 ) 
    {
        _table->addStimulus(_section);
    }
    _section = 0x0;

    if ( tokens.size() != 3 )
    {
        // Error. insufficient number of tokens.
        pbs_error("CDF-119", msg("").c_str());
        return ;
    }

    cdf::port* port = _table->findPort(tokens[1]);
    if ( port == 0x0 ) 
    {
        string msg = "ccb port " + tokens[1] + " is not found in the list of table inputs/outputs.";
        pbs_error("CDF-106", this->msg(msg).c_str());
        return;
    }

    // format: ccb D DFFX1_D.cir
    struct stat ccb_file_stat;
    if ( stat(tokens[2].c_str(), &ccb_file_stat ) == -1 )
    {
        pbs_error("CDF-101", msg(tokens[2]).c_str());
        return ;
    }

    if ( _table->getCCB() )
    {
        pbs_error("CDF-107", msg("one table can have only one ccb.").c_str()) ;
        return ;
    }

    cdf::ccb* ccBlock = new cdf::ccb(port, tokens[2]) ;

    _table->addCCB(ccBlock) ;

    return ;
}

void
cdf_reader::checkCharTypeRule(tokenizer& tokens)
{
    if ( _section != 0x0 ) {
        _table->addStimulus(_section);
    }
    _section = 0x0;

    vector<cdf::CHAR_TYPE> char_types;
    string token;
    while(tokens.next(token)) {
        cdf::CHAR_TYPE type = cdf::getCharType(token);
        if ( type == cdf::UNDEFINED_CHAR ) {
            pbs_error("CDF-108", msg(token).c_str());
            continue;
        }
        char_types.push_back(type);
    }
    _section = new cdf::stimulus(char_types);
    return ;
}

void
cdf_reader::checkSimFeedRule(tokenizer& tokens)
{
    if ( _section == 0x0 ) {
        // ERROR: simfeed definition found outside of stimulus.
        pbs_error("CDF-109", msg("simfeed").c_str());
        return ;
    }
    tokens.erase(0);
    cdf::CHAR_TYPE type = cdf::getCharType(tokens[1]);

    // second token can be a circuit node OR a CHAR_TYPE.
    // If it's a node, then type is assumed to be that of section.
    if ( type != cdf::UNDEFINED_CHAR )
        tokens.erase(0);

    string nodes = tokens.join();
    cdf::simulation_feed* sfeed = _section->createSimFeed(type);
    sfeed->set(nodes);
}

void
cdf_reader::checkModelArcRule(tokenizer& tokens)
{
    if ( _section == 0x0 ) {
        // ERROR: model arc definition found outside of stimulus.
        pbs_error("CDF-109", msg("model arc").c_str());
        return ;
    }
    cdf::MODEL_TYPE type = cdf::getModelType(tokens[1]);
    if ( type == cdf::UNDEFINED_MODEL ) {
        // ERROR : undefined model type found in the model definition.
        pbs_error("CDF-110", msg("").c_str()) ;
        return;
    }
    tokens.erase(0); // erase token "model"

    tokens.retokenize("=");
    if ( tokens.size() != 2 ) {
        // ERROR : illegal number of tokens (more or less than 2 w.r.t. =) found in model definition.
        pbs_error("CDF-111", msg("").c_str()) ;
        return;
    }

    cdf::arc* theArc = cdf::get_or_create_arc(_cdf, _table, _section, tokens[0]);
    if ( theArc == 0x0 ) {
        // ERROR: could not create arc.
        pbs_error("CDF-112", msg(tokens[0]).c_str()) ;
        return;
    }

    float index1=FLOAT_MIN, index2=FLOAT_MIN, index3=FLOAT_MIN, 
        value1=FLOAT_MIN, value2=FLOAT_MIN;
    string deck, result_file, token;

    tokenizer rhs(tokens[1], ",");
    for(size_t i=0; i<rhs.size(); i++)
        tokenizer::trim(rhs[i], " \t");

    if ( rhs.size() < 2 )
    {
        // ERROR. could not get sufficient values for the arc.
        pbs_error("CDF-113", msg(tokens[1]).c_str()) ;
        return;
    }
    size_t count = 0;
    tokenizer index(rhs[count++]); //0
    if ( index.size() < 1 ) { // at least one index is required.
        // ERROR: could not get valid index of arc.
        pbs_error("CDF-114", msg(tokens[1]).c_str()) ;
        return;
    }
    if ( index.size() > 0 ) index1 = atof(index[0].c_str());
    if ( index.size() > 1 ) index2 = atof(index[1].c_str());
    if ( index.size() > 2 ) index3 = atof(index[2].c_str()); 

    if ( type == cdf::MODEL_CCS_DRIVER  || 
         type == cdf::MODEL_PG_DCURRENT || 
         type == cdf::MODEL_PG_ICURRENT ||
         type == cdf::MODEL_PROP        ||
         type == cdf::MODEL_VOLT )
    {
        // waveforms

        tokenizer time_index(rhs[count++]) ;
        if ( time_index.size() == 0 ) {
            // ERROR: could not get time index of ccs waveform
            pbs_error("CDF-115", msg("").c_str()) ;
            return;
        }

        vector<float> time_vec, current_vec ;
        float token, refTime=FLOAT_MIN;
        string pgPin ="" ;
        while (time_index.next(token)) 
            time_vec.push_back(token) ;

        tokenizer current_index(rhs[count++]) ;
        while (current_index.next(token)) 
            current_vec.push_back(token) ;

        if ( rhs.size() > count ) refTime = atof(rhs[count++].c_str()); //2 or 3
        if ( rhs.size() > count ) pgPin = rhs[count++];//3 or 4
        if ( rhs.size() > count ) deck = rhs[count++]; //4 or 5
        if ( rhs.size() > count ) result_file = rhs[count++];//5 or 6
        cdf::arcWaveform* theWaveform = new 
            cdf::arcWaveform (index1, index2, index3, refTime, time_vec, current_vec, deck, result_file, pgPin);
        theArc->addArcWaveform(theWaveform);
    } else {
        value1 = atof(rhs[count++].c_str()); // 1
        if ( rhs.size() > count && tokenizer::is_double(rhs[count]) )
            value2 = atof(rhs[count++].c_str()); //2
        if ( rhs.size() > count ) deck = rhs[count++]; //2 or 3
        if ( rhs.size() > count ) result_file = rhs[count++];//3 or 4
        cdf::arcValue* theArcValue = new 
            cdf::arcValue(index1, value1, deck, result_file, index2, index3, value2);

        theArc->addArcValue(theArcValue);
    }

}

void
cdf_reader::checkSimArcRule(tokenizer& tokens)
{
}

void
cdf_reader::checkStateRule(tokenizer& tokens)
{
    tokens.erase(0); // get rid of first token- "state"
    tokens.retokenize("+");

    size_t n_inputs = _table->n_inputs();
    string token;
    vector<string> condition;
    while(tokens.next(token)) {
        if ( token.size() != n_inputs ) {
            //ERROR
            pbs_error("CDF-116", msg("wrong state specification.").c_str());
            return;
        }
        condition.push_back(token);
    }
    if ( !_section->setCondition(condition) ) {
        //ERROR
        pbs_error("CDF-120", msg("state has already been specified.").c_str());
        return;
    }
}

void
cdf_reader::checkVectorRule(tokenizer& tokens)
{
    string input_vector;
    string output_transition;
    tokens.retokenize("=");
    if (tokens.size() != 2) {
        pbs_error("CDF-111", msg("").c_str());
        return;
    }
    input_vector = tokens[0];
    tokenizer::trim(input_vector, " ");
    output_transition = tokens[1];
    tokenizer::trim(output_transition, "; ");

    size_t n_inputs = _table->n_inputs();
    size_t n_outputs = _table->n_outputs();

    string sqnc;
    vector<string> in_sqnc;
    tokenizer input_sequence(input_vector, ", ");
    while(input_sequence.next(sqnc)) {
        if ( sqnc.length() != n_inputs ) {
            //ERROR. number of states are not equal to number of inputs.
            pbs_error("CDF-116", msg("").c_str());
            return;
        }
        in_sqnc.push_back(sqnc);
    }
    if ( in_sqnc.size() < 2 ) {
        //Error. number of input states is less than 2. No input transtion possible.
        pbs_error("CDF-117",  msg("").c_str());
        return;
    }
    if ( output_transition.length() != n_outputs ) {
        //ERROR. number of states are not equal to number of inputs.
        pbs_error("CDF-118",  msg("").c_str());
        return;
    }
    cdf::stimulus::sequence stim_sqnc(in_sqnc, output_transition);
    // If _section already has a sequence, create a new section for this sequence
    // Rule is one _section can only have one sequence.
    // This is for the sake of brevity.
    if ( _section->getSequence().first.size() ) {
        _table->addStimulus(_section);
        _section = new cdf::stimulus(*_section);
    }

    _section->setSequence(stim_sqnc);
}

void cdf_reader::checkEndTableRule(tokenizer& tokens)
{
    if ( _section != 0x0 ) {
        _table->addStimulus(_section);
    }
    _section = 0x0;
    _table = 0x0;
}

void
cdf_reader::checkEndCDFRule(tokenizer& tokens)
{
}


cdf_reader::state
cdf_reader::getState(string& token)
{
    if (token[0] == '#') return COMMENT;
    else if (token == "cdf") return START_CDF;
    else if (token == "supply0") return SUPPLY0;
    else if (token == "supply1") return SUPPLY1;
    else if (token == "table") return START_TABLE;
    else if (token == "inputs") return INPUTS;
    else if (token == "outputs") return OUTPUTS;
    else if (token == "clocks") return CLOCKS;
    else if (token == "function") return FUNCTION;
    else if (token == "delay") return CHAR;
    else if (token == "tristate") return CHAR;
    else if (token == "ipower") return CHAR;
    else if (token == "dpower") return CHAR;
    else if (token == "lpower") return CHAR;
    else if (token == "incap") return CHAR;
    else if (token == "setup") return CHAR;
    else if (token == "hold") return CHAR;
    else if (token == "recovery") return CHAR;
    else if (token == "removal") return CHAR;
    else if (token == "mpw") return CHAR;
    else if (token == "ccsn_vivo") return CHAR;
    else if (token == "ccsn_prop") return CHAR;
    else if (token == "ccsn_volt") return CHAR;
    else if (token == "ccsn_mcap") return CHAR;
    else if (token == "simfeed") return SIM_FEED;
    else if (token == "sim_arc") return SIM_ARC;
    else if (token == "model") return MODEL_ARC;
    else if (token == "state") return STATE;
    else if (token[0] == '0' || token[0] == '1') return VECTOR;
    else if (token == "end_function") return END_FUNCTION;
    else if (token == "activity_file") return ACTIVITY;
    else if (token == "ccb") return CCB;
    else if (token == "end_table") return END_TABLE;
    else if (token == "end_cdf") return END_CDF;
    return UNKNOWN_STATE;
}

cdf* read_cdf_int(const char* file_name, bool quiet=true)
{
    cdf_reader parse(file_name, quiet);
    cdf* theCDF = parse.getCDF();
    return theCDF;
};

cdf*
read_cdf(const char* file_name)
{
    return read_cdf_int(file_name, false);
}

int
destroy_cdf(cdf* theCDF)
{
    if ( theCDF != 0x0 ) {
        delete theCDF;
        return 0;
    }
    return 1;
}

#endif
