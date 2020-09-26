#include "PigListCol.h"

PigListCol::PigListCol(){

}

PigList PigListCol::getActivePigList(byte nr){
    return this->allPigLists[nr];
}

void PigListCol::createNewPigList(byte nr){
    this->allPigLists[nr].setSerieNumber(nr);
}
