//#############################################################################
//#                           Copyright Paripath, Inc.
//#                            All Rights Reserved
//#############################################################################
//# Created by: Rohit Sharma
//#
//# Revision $Revision: 1.3 $, last checked in by $Author: srohit $ on $Date: 2014/08/09 15:21:37 $.
//#
//# CVS ID: $Id: macros.h,v 1.3 2014/08/09 15:21:37 srohit Exp $
//#############################################################################
//#
//# Description:
//
//
#ifndef __PAR_MACROS_
#define __PAR_MACROS_

#define DEBUG_ME() atoi(configManager::get("debug", (char*)__FUNCTION__).c_str()) 

#define INTERPOLATE(x1, y1, x2, y2, x) (x2 == x1) ? y1 : y1 + ( ((y2-y1) / (x2-x1)) * (x-x1) )

#endif
