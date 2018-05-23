#include "DerivedChar.h"

DerivedChar::DerivedChar() : c('.') { }

DerivedChar::DerivedChar(const char c) {
    this->operator =(c);
}

DerivedChar::DerivedChar(const DerivedChar& dc) {
    this->c = dc.c;
}

DerivedChar& DerivedChar::operator= (const char c){
    
    switch (c){
        case Symbol::X:
            this->c = c;
            break;
        case Symbol::O:
            this->c = c;
            break;
        case Symbol::P:
            this->c = c;
            break;
        default:
            throw IllegalCharException(c);
            break;
    }
    return *this;
}


DerivedChar& DerivedChar::operator= (const DerivedChar& dc){
    this->c = dc.c;
    return *this;
}

ostream& operator<< (ostream& os, const DerivedChar& dc){
    return os << dc.c;
}

DerivedChar::operator Symbol() const{
    switch (c){
        case Symbol::X:
            return Symbol::X;
            break;
        case Symbol::O:
            return Symbol::O;
            break;
        case Symbol::P:
            return Symbol::P;
            break;
        default:
            throw IllegalCharException(c);
            break;
    }
}

// bool DerivedChar::operator ==(const char c) const{
//     return this->c == c;
// }

// DerivedChar::operator char() const{
//     return c;
// }