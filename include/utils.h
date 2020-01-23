//#############################################################################
//#                           Copyright Paripath, Inc.
//#                            All Rights Reserved
//#############################################################################
//# Created by: Rohit Sharma
//#
//# Revision $Revision: 1.13 $, last checked in by $Author: srohit $ on $Date: 2016/08/09 02:02:42 $.
//#
//# CVS ID: $Id: utils.h,v 1.13 2016/08/09 02:02:42 srohit Exp $
//#############################################################################
//#
//# Description:
//
//
#ifndef _UTILS
#define _UTILS
#include <time.h>
#include <sys/resource.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <fstream>
#include "common.h"

using namespace std;

// This is a string tokenizer
// Example 1.
//        tokenizer tokens(my_str);
//        string token;
//        while(tokens.next(token)) {
//            // use token here.
//        }
// Example 2.
//        tokenizer tokens(my_str);
//        for(size_t index=0; index<tokens.size(); index++) {
//            string token = tokens[index];
//            // use token here.
//        }
class tokenizer {
protected:
    vector<string> _tokens;
    short _index;
    string empty_string; // This can be static.

    void tokenize(const string& str,
                  const string& delimiters = " \t")
    {
        // Skip delimiters at beginning.

        string::size_type lastPos = str.find_first_not_of(delimiters, 0);
        // Find first "non-delimiter".
        string::size_type pos     = str.find_first_of(delimiters, lastPos);

        while (string::npos != pos || string::npos != lastPos)
        {

            // Found a token, add it to the vector.
            _tokens.push_back(str.substr(lastPos, pos - lastPos));
            // Skip delimiters.  Note the "not_of"
            lastPos = str.find_first_not_of(delimiters, pos);
            // Find next "non-delimiter"
            pos = str.find_first_of(delimiters, lastPos);
        }
        _index=0;
    }
public:
    tokenizer(const string& str,
              const string& delimiters = " \t")
    {
        tokenize(str, delimiters);
        empty_string = "";
    }

    inline size_t size() const { return _tokens.size(); }
    inline string back() const { return _tokens.back(); }
#ifndef SWIG
    string& operator[](size_t index) { return (index >= size()) ? empty_string : _tokens[index]; } //unsafe.
#endif
    vector<string> tokens() { return _tokens; }
    bool exists(string token)
    {
        return find(_tokens.begin(), _tokens.end(), token) != _tokens.end() ;
    }

    void reset() { _index = 0; } // start all over.
    bool next(string& token) {
        if ( _index > static_cast<int>(size()-1) )
            return false;
        token = _tokens[_index++];
        return true;
    }
    bool next(float& token) {
        if ( _index > static_cast<int>(size()-1) )
            return false;
        token = atof(_tokens[_index++].c_str());
        return true;
    }
    bool erase(size_t pos) { // unsafe during iteration
        if ( pos >= size() ) return false;
        for (size_t index=pos+1; index<size(); index++) {
            _tokens[index-1] = _tokens[index];
        }
        _tokens.pop_back(); // get rid of last duplicate token.
        return true;
    }
    bool is_last() const { return size() == 0 || _index == static_cast<int>(size())-1; }
    void retokenize(const string& delimiters)
    {
        string str = join();
        _tokens.clear();
        tokenize(str, delimiters);
    }
    string join(string delimiter=" ", size_t start=0, size_t end=0) {
        return tokenizer::join(_tokens, delimiter, start, end);
    }
    static string join(vector<string>& tokens, const string& delimiters,
        size_t start=0, size_t end=0)
    {
        string str="";
        if ( tokens.size() == 0 ) return str;

        if ( end == 0 ) end = tokens.size() - 1;
        // Check to make sure bounds are legal.
        end = end > tokens.size() - 1 ? tokens.size() - 1 : end;
        start = start > tokens.size() - 1 ? tokens.size() - 1 : start;
        // swap, if start is greater than end.
        if ( start > end ) {
            size_t tmp = end;
            end = start;
            start = tmp;
        }
        for(size_t index=start; index<=end;  index++)
            str += tokens[index] + (index == end ? "" : delimiters) ;
        return str;
    }
    static string join(vector<float> tokens, const string& delimiters,
        size_t start=0, size_t end=0)
    {
        vector<string> numbers;
        for(size_t index=0; index<tokens.size(); index++)
            numbers.push_back(number(tokens[index]));
        return join(numbers, delimiters, start, end);
    }
    static void trim(string& str, const string& delimiters)
    {
        string::size_type pos     = str.find_first_not_of(delimiters);
        string::size_type lastPos = str.find_last_not_of(delimiters);

        if (string::npos != pos || string::npos != lastPos)
            str = str.substr(pos, lastPos - pos +1);
    }
    static string tolower(string& str) {
        string lower;
        for(size_t index=0; index<str.size(); index++)
            lower += isupper(str[index])?_tolower(str[index]):str[index];;
        return lower;
    }
    static bool is_integer(string& str) {
        for(size_t index=0; index<str.size(); index++)
            if ( !isdigit(str[index]) || (!index && str[index]=='-'))
                return false;
        return str.size() > 1 || (str.size()==1 && str[0]!='-');
    }
    static bool is_double(string& str) {
        // loose check. e.g. "e-" "-e" are not doubles.
        for(size_t index=0; index<str.size(); index++)
            if ( !isdigit(str[index]) && str[index] != '.' &&
                  str[index] != '+' && str[index] != '-' &&
                  str[index] != 'e')
                return false;
        return str.size();
    }
    // convert float into string with precision.
    static string number(const float num, short precision=5, const char* fmt=0x0) {
        static const short int FORMAT_SZ = 8 ;
        static const short int BUF_SZ = 64 ;
        static char cnum[BUF_SZ];
        static char format[FORMAT_SZ];

        if ( fmt ) {
            strncpy(format, fmt, FORMAT_SZ) ;
            format[FORMAT_SZ-1] = '\0' ;
        } else {
            float precision_val = 1.0;
            for(short i=0; i<precision; i++) precision_val /= 10;
            // change precision_val to 1.0 below to get rid of check_lib warning.
            if ( fabs(num) < precision_val )
                sprintf(format, "%%g");
            else
                sprintf(format, "%%.%df", precision);
        }
        sprintf (cnum, format, num);
        return cnum;
    }
    // convert int into string with base 2, 4, 8, 10 and 16.
    static string number(const int value, int base=10) {
        enum { kMaxDigits = 35 };
        string buf;
        buf.reserve( kMaxDigits ); // Pre-allocate enough space.

        // check that the base if valid
        if (base < 2 || base > 16) return buf;

        int quotient = value;

        // Translating number to string with base:
        do {
            buf += "0123456789abcdef"[ abs( quotient % base ) ];
            quotient /= base;
        } while ( quotient );

        // Append the negative sign for base 10
        if ( value < 0 && base == 10) buf += '-';

        reverse( buf.begin(), buf.end() );
        return buf;
    }
};

extern char* Tcl_STR(string);

// Following class manages pointer to T by keeping a
// reference count. It deletes the object, as soon as,
// reference count goes to zero.
// Example.
//      CDF* my_cdf = new CDF(...);
//      handle<CDF> hcdf(my_cdf);
//      // Now I can peacefully forget about managing memory of
//      // my_cdf object.
template <typename T>
struct handle {
public:
    T*    _ptr;
    short _ref;
public:
    handle(T* ptr) : _ptr(ptr), _ref(0) { }
    handle(const handle& other) {
        _ptr = other._ptr;
        _ref++;
    }
    inline handle& operator=(const handle& other) {
        if ( &other == this )
            return *this;
        _ptr = other._ptr;
        _ref++;
        return *this;
    }
    ~handle() {
        if ( --_ref == 0 ) delete _ptr;
    }
};

class flag {
protected:
    short _info; //can accomodate upto 15 (enum 0-15) flags.
public:
    flag() : _info(0) {};
    flag(short info) : _info(info) {}
    bool get(short index) const { return _info & (1 << index); }
    void set(short index) { _info |= (1 << index); }
    void reset(short index) { _info &= ~(1 << index); }
    flag operator | (const flag &rhs) const {
        return _info | rhs._info ;
    }
    bool operator < ( const flag &rhs ) const {
        return ( _info < rhs._info ) ;
    }
};

class banner {
public:
static void printBanner() ;
static string dateString() {
    time_t now = time(0x0);
    char* cnow = ctime(&now);
    size_t sz = strlen(cnow);
    cnow[sz-1] = '\0'; // weed out new line character.
    return cnow;
}
};

class pbs_istream {
    filebuf buf;
    istream* _in;
    STATUS _status;
public:
    pbs_istream(string& filename, ios_base::openmode mode=ios::in) {
        buf.open(filename.c_str(), mode);
        if ( !buf.is_open() ) {
            _status = FATAL;
            _in = 0x0;
        } else {
            _status = INFO;
            _in = new istream(&buf);
        }
    }
    ~pbs_istream() {
        if ( _in ) {
            buf.close();
            delete _in;
            _in = 0x0;
        }
    }
    bool next(string& sline) {
        static const unsigned int BUFFER_SIZE = 8096;
        static char line[BUFFER_SIZE];
        if ( !_in || _in->eof() )
            return false;
        _in->getline(line, BUFFER_SIZE);
        sline = line;
        return true;
    }
    STATUS status() { return _status; }
};

class pbs_ostream {
    filebuf buf;
    ostream* _out;
    STATUS _status;
public:
    pbs_ostream(const char* filename, ios_base::openmode mode=ios::out) {
        buf.open(filename, mode);
        if ( !buf.is_open() ) {
            _status = FATAL;
            _out = 0x0;
        } else {
            _status = INFO;
            _out = new ostream(&buf);
        }
    }
    ~pbs_ostream() {
        if ( _out ) {
            buf.close();
            delete _out;
            _out = 0x0;
        }
    }
    void write(const char* str) { if ( _out ) (*_out) << str; }
    void write(string str) { write(str.c_str()); }
    STATUS status() { return _status; }
};

class resource {
public:
    // RSS: resident set size, RAM size
    // Virtual: process size.
    //
    // Description:
    //   Returns the peak (maximum so far) resident set size (physical
    //   memory use) measured in bytes,
    size_t getPeakMem()
    {
        struct rusage rusage;
        getrusage( RUSAGE_SELF, &rusage );
        return (size_t)(rusage.ru_maxrss * 1024L);
    }

    static string getUsage()
    {
        struct rusage rusage;
        getrusage( RUSAGE_SELF, &rusage );

        double cpu_time = ((double)(clock() - resource::start_time)) / CLOCKS_PER_SEC;

        double peak_mem   = (rusage.ru_maxrss * 1024L) / 1048576 ; // in Mega bytes
        string mem_unit = "MB" ;
        if ( peak_mem > 1024 )
        {
            peak_mem = peak_mem/1024;
            mem_unit = "GB" ;
        }
        double utime    = rusage.ru_utime.tv_sec + 1e-6*rusage.ru_utime.tv_usec ;
        double stime    = rusage.ru_stime.tv_sec + 1e-6*rusage.ru_stime.tv_usec;

        char buf[2048] ;
        sprintf(buf, "Resurces used:\n");
        sprintf(buf+strlen(buf), "\tcpu time    : %0.2f sec.\n", cpu_time) ;
        sprintf(buf+strlen(buf), "\tuser time   : %0.2f sec.\n", utime) ;
        sprintf(buf+strlen(buf), "\tsystem time : %0.2f sec.\n", stime) ;
        sprintf(buf+strlen(buf), "\tpeak mem    : %0.2f %s.\n", peak_mem, mem_unit.c_str()) ;

        return buf ;
    }
public:
    static clock_t start_time ; // in clocks
};

//#ifdef __linux__
//        unsigned long starttime;
//        if ( fscanf(fp, "%d %*s %*c %*d %*d %*d %*d %*d %*u %*u %*u %*u %*u %lu %lu %*d %*d %*d %*d %*d %*d %lu %llu %llu %*u %*u %*u %*u %*u %*u %*u %*u %*u %*u %*u %*u %*u %*d %*d\n", &pid, &utime, &stime, &starttime, &swap, &rss) ) {
//
//            swap  = swap / 1024;
//            rss   = rss  / 1024;
//            utime = utime/100;
//            stime = stime/100;
//            result = true;
//        }
//#else
//        psinfo_t   info ;
//        if ( fread(&info, sizeof(psinfo_t), 1, fp) ) {
//            swap  = info.pr_size;
//            rss   = info.pr_size - info.pr_rssize;
//            utime = info.pr_time.tv_sec ;
//            stime = 0;
//            result = true;
//        }
//#endif

#endif
