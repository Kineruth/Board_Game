#pragma once

class IllegalCharException {
    private:
        const char c;
        
    public:
        IllegalCharException(const char c) : c(c){ }
        
        const char theChar() const{
            return this->c;
        }
};