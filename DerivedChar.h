#include <iostream>
#include "Symbol.h"
#include "IllegalCharException.h"

using namespace std;

class DerivedChar{
    private:
        char c;
        
    public:
        DerivedChar();
        DerivedChar(char c);
        DerivedChar(const DerivedChar& dc);
        DerivedChar& operator= (const char c);
        DerivedChar& operator= (const DerivedChar& dc);
        //bool operator ==(const char c) const;
        friend ostream& operator<< (ostream& os, const DerivedChar& dc);
        
        //operator char() const;
        operator Symbol() const;
};