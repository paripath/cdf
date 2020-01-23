//#############################################################################
//#                           Copyright Paripath, Inc.
//#                            All Rights Reserved
//#############################################################################
//# Created by: Rohit Sharma
//#
//# Revision $Revision: 1.7 $, last checked in by $Author: srohit $ on $Date: 2015/06/27 18:56:12 $.
//#
//# CVS ID: $Id: message.h,v 1.7 2015/06/27 18:56:12 srohit Exp $
//#############################################################################
//#
//# Description:
//
//
#ifndef _PBS_PRINT
#define _PBS_PRINT

#include "common.h"
#include <fstream>
#include <map>
#include <iostream>

using namespace std;

class pbs_print {
public:
    enum msg_type {NOTAG, INFO, WARNING, ERROR, FATAL};
    pbs_print() { init(); }
    ~pbs_print() { 
        _outbuf.close();
        delete _out;
     }
    void init();
    static const pbs_print* const pbs_printer() {
        if (_pbs_printer == 0x0)
            _pbs_printer = new pbs_print();
        return _pbs_printer;
    }
    void print(msg_type type, char* msg_code, const char* info=0x0) const;

protected:
    struct message {
        string verbiage ;
        size_t times_printed ;

        message() : verbiage(""), times_printed(0)
        {}
        message(const char* txt) : verbiage(txt), times_printed(0)
        {}
        message& operator= (const char* txt)
        {
            verbiage = txt ;
            times_printed = 0 ;
            return *this;
        }
        message& operator=(const message& other)
        {
            // check for self-assignment
            if(&other != this)
            {
                verbiage = other.verbiage;
                times_printed = other.times_printed;
            }
            return *this ;
        }

        bool is_valid()
        {
            return verbiage.size();
        }
    } ;

    void     logstream() ;
    ostream* _out ;
    filebuf  _outbuf;

    static pbs_print* _pbs_printer;
    static map<const char*, message, ltstr> messages;
};

/*
#define pbs_info(code, msg) pbs_print::pbs_printer()->print(pbs_print::INFO, code, msg);
#define pbs_warning(code, msg) pbs_print::pbs_printer()->print(pbs_print::WARNING, code, msg);
#define pbs_error(code, msg) pbs_print::pbs_printer()->print(pbs_print::ERROR, code, msg);
#define pbs_fatal(code, msg) pbs_print::pbs_printer()->print(pbs_print::FATAL, code, msg);
#define pbs_msg(msg) pbs_print::pbs_printer()->print(pbs_print::NOTAG, 0x0, msg);
*/
void pbs_info(char* code, const char* msg=0x0) ;
void pbs_warning(char* code, const char* msg=0x0);
void pbs_error(char* code, const char* msg=0x0);
void pbs_fatal(char* code, const char* msg=0x0);
void pbs_msg(const char* msg);

#endif
