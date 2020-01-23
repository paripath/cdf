//#############################################################################
//#                           Copyright Paripath, Inc.
//#                            All Rights Reserved
//#############################################################################
//# Created by: Rohit Sharma
//#
//# Revision $Revision: 1.7 $, last checked in by $Author: srohit $ on $Date: 2016/08/21 23:58:37 $.
//#
//# CVS ID: $Id: equationParser.h,v 1.7 2016/08/21 23:58:37 srohit Exp $
//#############################################################################
//#
//# Description:
//
//
#ifndef _SHIFT_REDUCE_PARSER
#define _SHIFT_REDUCE_PARSER

// Liberty User Guide Volume-1, version 2003-12. Page 4-58
//
// Operator precedence
// -------------------
// The precedence of the operators is left to right, with inversion
// performed first, then XOR, then AND, then OR.
//
// Valid Boolean Operators
// -----------------------
// ` Invert previous expression
// ! Invert following expression
// ^ Logical XOR
// * Logical AND
// & Logical AND
// space Logical AND
// + Logical OR
// | Logical OR
//
// Examples
//---------
// The following function statements all describe 2-input
// multiplexers. The parentheses are optional. The operators and
// operands are separated by spaces.
// function : "A S + B S" ;
// function : "A & S | B & !S" ;
// function : "(A * S) + (B * S)" ;

#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

class boolToken {
public:
    boolToken() { }
    virtual ~boolToken() { }
    virtual bool isOp() = 0;
    virtual bool isVar() = 0;
    virtual string print() = 0;
};

class boolOp : public boolToken {
public:
    //           |     &    ^    !     `     (   )   $ 
    enum opType {OR=0, AND, XOR, INVF, INVP, LP, RP, OPEND} ;
    static string operators ;
private:
    opType _oper;
public:
    boolOp(opType oper) : _oper(oper) {}
    virtual ~boolOp() { }
    opType get() { return _oper; }
    static opType getOp(char opc) {
        opType op = OPEND;
        switch (opc) {
            case '+' :
            case '|' :
                op = OR; break;
            case '`' :
                op = INVP; break;
            case '!' :
                op = INVF; break;
            case '^' :
                op = XOR; break;
            case '&' :
            case '*' :
                op = AND; break;
            case '(' :
                op = LP; break;
            case ')' :
                op = RP; break;
            default :
                op = OPEND; break;
        }
        return op;
    }
    static string getOpChar(opType oper) {
        string ch = "\0";
        switch(oper) {
            case OR : ch="|"; break;
            case AND : ch="&"; break;
            case INVF : ch="!"; break;
            case INVP : ch="`"; break;
            case XOR : ch="^"; break;
            case LP : ch="("; break;
            case RP : ch=")"; break;
            case OPEND : break;
        }
        return ch;
    }
    string print() { return getOpChar(_oper); }
    bool isOp() { return true; }
    bool isVar() { return false; }
};

class boolVar : public boolToken {
    string _variable;
public:
    boolVar(string& var) : _variable(var) {}
    string get() { return _variable; }
    string print() { return get(); }
    bool isOp() { return false; }
    bool isVar() { return true; }
};

class boolTokens {
    size_t             _index;
    vector<boolToken*> _tokens;
    void parseTokens (string& expression) {
        string var = "";
        for(size_t index=0; index<expression.size(); index++) {
            boolOp::opType op = boolOp::getOp(expression[index]);
            if ( op != boolOp::OPEND ) {
                if (!var.empty()) _tokens.push_back(new boolVar(var));
                var = "";
                _tokens.push_back(new boolOp(op));
            } else {
                if (isspace(expression[index])) {
                    if (!var.empty()) _tokens.push_back(new boolVar(var));
                    var = "";
                } else {
                    var += expression[index];
                }
            }
        }
        if ( !var.empty() ) _tokens.push_back(new boolVar(var));
        _tokens.push_back(new boolOp(boolOp::OPEND)); //Very important line.
        _tokens.push_back(new boolOp(boolOp::OPEND)); //Very important line.
    }
public:
    boolTokens(string& expression) : _index(0) { parseTokens(expression); }
    boolToken* next() {    return (_index >= _tokens.size()) ? 0x0 : _tokens[_index++]; }
    ~boolTokens() {
        for (size_t index=0; index<_tokens.size(); index++)
            delete _tokens[index];
        _tokens.clear();
    }
    void DirtyHack() {
        // This grammer considers whitespace as an AND operator as well.
        // One token has 2 meanings (delimiter and AND operator) depending on context.
        // This is fixed here, by looking at 2 consecutive tokens. If there are 2
        // var tokens without an operator between them, then insert AND operator.
        vector<boolToken*> new_tokens = _tokens;
        _tokens.clear();
        vector<boolToken*>::iterator current = new_tokens.begin();
        vector<boolToken*>::iterator next    = ++new_tokens.begin();
        _tokens.push_back(*current);
//      VAR |   &   ^   !   `   (   )   $  <----next / current
//VAR    &              &       &       
//|                                     
//&                                     
//^                                     
//!                                     
//'                                     
//(                                     
//)      &              &       &       
        while(next != new_tokens.end()) {
            if ( ((*current)->isVar() && (*next)->isVar()) || // "A B"
                ((*current)->isVar() && ((*next)->isOp()) && ((boolOp*)(*next))->get() ==boolOp::LP) || // "A ("
                ((*current)->isVar() && ((*next)->isOp()) && ((boolOp*)(*next))->get() ==boolOp::INVF) || // "A !"
                (((*current)->isOp() && ((boolOp*)(*current))->get() == boolOp::RP) && ((*next)->isVar())) || // ") B"
                (((*current)->isOp() && ((boolOp*)(*current))->get() == boolOp::RP) && ((*next)->isOp() && ((boolOp*)(*next))->get() == boolOp::LP) )  || // ") ("
                (((*current)->isOp() && ((boolOp*)(*current))->get() == boolOp::RP) && ((*next)->isOp() && ((boolOp*)(*next))->get() == boolOp::INVF) )) { // ") !"
                _tokens.push_back(new boolOp(boolOp::AND));
            }
            _tokens.push_back(*next);
            ++current; ++next;
        }
    }
    string print() {
        string str ;
        while( boolToken* tok = next() ) {
            str += tok->print();
        }
        _index =0;
        return str;
    }
};

class shiftReduceParser {
protected:
    static char parseTable[8][8];
    string _expression;
    boolToken* _currentToken; //running token.
    bool _done; //are we there yet?
    vector<boolOp> _opStack;
    
    boolOp::opType opStackTop() {
        size_t sz = _opStack.size();
        return !sz ? boolOp::OPEND : _opStack[sz-1].get(); 
    }
public:
    typedef enum { S, /* shift */ R, /* reduce */ A, /* accept */ 
        E1, /* error: missing right parenthesis */
        E2,  /* error: missing operator */
        E3,  /* error: unbalanced right parenthesis */
        E4,  /* error: missing operand for right inversion ' */
    } actions;
    shiftReduceParser(string expression) 
        : _expression(expression), _currentToken(0x0), _done(false) {}
    void parse() {
        boolTokens tokens(_expression);
        // HACK for dirty grammer. Blame big 'S'
        tokens.DirtyHack();
#ifdef _DEBUG
cout << tokens.print() << "\n";
#endif
        _currentToken=tokens.next();
#ifdef _DEBUG
cout << "shift to " << (_currentToken ? _currentToken->print() : "") << "\n";
#endif
        while(!_done) {
            if ( _currentToken->isVar() ) {
                shift(tokens);
                continue;
            }
            // Now token must be operator.
            _currentToken = ((boolOp*)_currentToken);
            boolOp::opType prevOp = opStackTop();
            switch (parseTable[prevOp][((boolOp*)_currentToken)->get()]) {
                case R :
                    reduce();
                    break;
                case S :
                    shift(tokens);
                    break;
                case A :
#ifdef _STAND_ALONE
cout << "expression " << this->varStackTop() << "\n";
#endif
                    _done = true;
                    break;
                case E1 :
                     cout << "error: E1";
                    _done = true;
                    break;
                case E2 :
                     cout << "error: E2";
                    _done = true;
                    break;
                case E3 :
                     cout << "error: E3";
                    _done = true;
                    break;
                case E4 :
                     cout << "error: E4";
                    _done = true;
                    break;
                default :
                    break;
            }
        }
    }
    virtual ~shiftReduceParser() { }
    void shift(boolTokens& tokens) {
        if ( _currentToken->isOp() )
        {
            _opStack.push_back(((boolOp*)_currentToken)->get()) ;
        }
        else
        {
            string var = ((boolVar*)_currentToken)->get();
            this->pushVarStack(var) ; // overloaded for every class
        }
        _currentToken = tokens.next();
#ifdef _DEBUG
cout << "shift to " << (_currentToken ? _currentToken->print() : "") << "\n";
#endif
    }
    virtual void reduce() = 0;
    virtual void pushVarStack(string var) = 0;
    virtual string varStackTop() = 0;
};

class mapEquation : public shiftReduceParser {
    map<string, string> _varMap; // key:old name -> value: new name
    vector<string>      _varStack;

    string mappedName(string oldName)
    {
        string name = oldName;

        map<string, string>::iterator iter = _varMap.find(name) ;
        if ( iter != _varMap.end() )
            name = iter->second ;

        return name;
    }

public:
    mapEquation(map<string, string>& nmap, const char* expr) :
      shiftReduceParser(expr), _varMap(nmap)
      {
          parse();
      }
    virtual ~mapEquation() {}
    virtual string varStackTop() {
        return _varStack.back() ;
    }
    string stackTop() {
        return _varStack.size() ? _varStack.back() : "";
    }
    virtual void pushVarStack(string var) {
        _varStack.push_back(mappedName(var));
    }
    virtual void reduce() {
        boolOp::opType op = opStackTop();
        string a, b;
        switch(op) {
            case boolOp::OR :
                a = stackTop(); _varStack.pop_back();
                b = stackTop(); _varStack.pop_back();
                _varStack.push_back(a + " | " + b);
                break;
            case boolOp::AND :
                a = stackTop(); _varStack.pop_back();
                b = stackTop(); _varStack.pop_back();
                _varStack.push_back(a + " & " + b);
                break;
            case boolOp::XOR:
                a = stackTop(); _varStack.pop_back();
                b = stackTop(); _varStack.pop_back();
                _varStack.push_back(a + " ^ " + b);
                break;
            case boolOp::INVF:
            case boolOp::INVP:
                a = stackTop(); _varStack.pop_back();
                _varStack.push_back("!" + a);
                break;
            case boolOp::LP:
                ; //No action
                break;
            case boolOp::RP:
                _opStack.pop_back(); //pop off LP as well.
                a = stackTop(); _varStack.pop_back();
                _varStack.push_back( "(" + a + ")" ) ;
                break;
            default:
                break;
        }
#ifdef _DEBUG
cout << "reduce " << varStackTop() << "\n";
#endif
        _opStack.pop_back();
    }
};
#endif
