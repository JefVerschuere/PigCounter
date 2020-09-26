#ifndef PIGLISTCOL_H
#define PIGLISTCOL_H

#include "pigList.h";

#include <Arduino.h>

class PigListCol {
    private: 
        PigList pigLists[11];
    public:
    PigListCol();

    PigList getActivePigList();

    void createNewPigList();
};

#endif