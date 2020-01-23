//#############################################################################
//#                           Copyright Paripath, Inc.
//#                            All Rights Reserved
//#############################################################################
//# Created by: Rohit Sharma
//#
//# Revision $Revision: 1.5 $, last checked in by $Author: srohit $ on $Date: 2017/06/07 21:02:13 $.
//#
//# CVS ID: $Id: common.h,v 1.5 2017/06/07 21:02:13 srohit Exp $
//#############################################################################
//#
//# Description:
//
//
#ifndef _COMMON
#define _COMMON
#include <limits.h>
#include <string.h>
#include <string>
#include <cmath>

#ifndef SWIG
class BDD;
class cdf;
typedef BDD* bdd_handle;

struct ltstr
{
  bool operator()(const char* s1, const char* s2) const
  {return strcmp(s1, s2) < 0;}
};

using namespace std;

struct ltSTR
{
   bool operator()(const string& s1, const string& s2) const
  {return strcmp(s1.c_str(), s2.c_str()) < 0;}
};
enum STATUS {INFO=0, WARN, ERROR, FATAL};
#define CAST_INT(expr) static_cast<int>(expr)
#endif

static const float EPSILON   = 1.0e-18;
static const float FLOAT_MIN = -1e+38;
static const float FLOAT_MAX =  1e+37;


struct ltFLOAT
{
    bool operator() (const float& num1, const float& num2) const
    {
        return (abs(num1 - num2) > EPSILON) && (num1 < num2);
    }
};
#endif
