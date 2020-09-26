#ifndef PIGLISTCOL_H
#define PIGLISTCOL_H

#include "pigList.h";

#include <Arduino.h>

class PigListCol {
    private: 
        PigList allPigLists[11];
    public:
    PigListCol();

    PigList getActivePigList(byte nr);

    void createNewPigList(byte nr);
};

#endif
