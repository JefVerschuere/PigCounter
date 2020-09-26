#ifndef PIGLIST_H
#define PIGLIST_H

#include <Arduino.h>

class PigList {
    private: 
        byte serieNumber;
        byte pigCpOut;
        byte pigCpIn;
    public:
    PigList(byte serieNumber);

    void addPigIn();
    void addPigOut();

    bool isThisTheLastPig();
    
}