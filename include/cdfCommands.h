//#############################################################################
//#                           Copyright Paripath, Inc.
//#                            All Rights Reserved
//#############################################################################
//# Created by: Rohit Sharma
//#
//# Revision $Revision: 1.12 $, last checked in by $Author: srohit $ on $Date: 2016/08/14 16:24:53 $.
//#
//# CVS ID: $Id: cdfCommands.h,v 1.12 2016/08/14 16:24:53 srohit Exp $
//#############################################################################
//#
//# Description:
//
//
#ifndef _CDF_COMMAND
#define _CDF_COMMAND

#include "cdf.h"
#include "utils.h"
#include "message.h"
#include <assert.h>
#include <map>

//#define USE_PDA_SWIG

class arguments {
protected:
    string _format;
public:
    arguments(const char* format) : _format(format)
    { }
    string format() { return _format; }
};

class cdfCommand;
class cdfCommand : public arguments {
    string _name;
public:
    cdfCommand(const char* name, const char* args=0x0) 
        : arguments(args) , _name(name)
    {
        map<const char*, cdfCommand*, ltstr>::iterator
            iter = commands.find(name);
        assert( iter == commands.end() ) ;
        commands[name] = this;
    }
    virtual ~cdfCommand() {}
    char* syntax() 
    { 
        pbs_error("CDF-202", string(" cdfi " + _name + " " + format()).c_str());
        return "";
    }
    bool fileExists(string fileName)
    {
        struct stat sb;
        if ( stat(fileName.c_str(), &sb) != -1 )
        {
            return ( sb.st_mode & S_IFREG ) ;
        }
        return false ;
    }
    virtual char* fire(cdf::table*, cdf::stimulus*, char*) { return syntax(); }
    virtual char* fire(cdf::table*, cdf::stimulus*) { return syntax(); }
    virtual char* fire(cdf::table*, char*) { return syntax(); }
    virtual char* fire(cdf::table*) { return syntax(); }
    virtual char* fire(cdf::table*, float, float) { return syntax(); }
    virtual char* fire(cdf::stimulus*) { return syntax(); }
    virtual char* fire(cdf*) { return syntax(); }
    virtual char* fire() { return syntax(); }
    virtual char* fire(cdf::stimulus*, char*) { return syntax(); }
    virtual char* fire(cdf::stimulus*, char*, char*) { return syntax(); }
    virtual char* fire(cdf::stimulus*, char*, char*, char*) { return syntax(); }
    virtual char*  fire(cdf*, char*, char*) { return syntax(); }
    virtual char* fire(cdf* theCDF, cdf::table* tbl, cdf::stimulus* stim,
        char* str1, char* str2, char* str3, char* str4,
        float index1, float val1, float index2=FLOAT_MIN,
        float val2=FLOAT_MIN, float index3=FLOAT_MIN)
    { return syntax(); }
    virtual char* fire(cdf* theCDF, cdf::table* tbl, cdf::stimulus* stim, 
        char* str1, char* str2, char* str3, char* str4,
        float refTime, float index1, char* xVecStr, 
        float index2=FLOAT_MIN, char* yVecStr=0x0, 
        float index3=FLOAT_MIN, char* pgPin=0x0)
    { return syntax(); }

#ifdef USE_PDA_SWIG
    // verbatim copy of SWIG_PackData defined in guna_main.cpp
    string swigPtr(void* ptr) 
    {
                static size_t sz = sizeof(void*);
        int idx = 0;
        char c[18] ;
        c[0] = '_';
        c[17] = '\0';
                static const char hex[17] = "0123456789abcdef";
                register const unsigned char *u = (unsigned char *) ptr;
                register const unsigned char *eu =  u + sz;
                for (; u != eu; ++u) {
                  register unsigned char uu = *u;
                  idx++;
                  *(c+idx) = hex[(uu & 0xf0) >> 4];
                  idx++;
                  *(c+idx) = hex[uu & 0xf];
                }
                return c;
    }
#else
    string swigPtr(void* ptr) 
    {
                string swg_ptr = "_";
        char sptr[18]; 
        sprintf(sptr, "%p", ptr);
        short int pointer_sz = sizeof(void*) ;
        short int pointer_index = pointer_sz ;
        short int index = strlen(sptr) ;
        for(; index>0 && pointer_index>0; index-=2, pointer_index-=2) {
            char hex_1 = sptr[index-1] ;
            char hex_2 = sptr[index-2] ;
#ifdef _WIN32
            swg_ptr += tolower(hex_2) ;
            swg_ptr += tolower(hex_1) ;
#else
            swg_ptr += (hex_2=='x'?'0':tolower(hex_2)) ;
            swg_ptr += (hex_1=='x'?'0':tolower(hex_1)) ;
#endif
        }
        for(pointer_index=pointer_sz; pointer_index>0; pointer_index--)
            swg_ptr += '0' ;
        return swg_ptr;
    }
#endif
    static string match(const char* key) 
    { //TODO: duplicate code in configManager.h
        string match_list = "";
        map<const char*, cdfCommand*, ltstr>::iterator pos = commands.begin();
        for(; pos != commands.end(); pos++) {
            string rkey = pos->first;
            if ( rkey.find(key) != string::npos )
                match_list += rkey + " ";
        }
        return match_list;
    }
    static map<const char*, cdfCommand*, ltstr> commands;
};
#endif
