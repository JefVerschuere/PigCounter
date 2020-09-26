#include "PigListCol.h"

PigListCol::PigListCol(){

}

PigListCol::getActivePigList(byte nr){
    return this->pigLists[nr];
}

PigListCol::createNewPigList(byte nr){
    this->pigLists[nr] = new PigList(nr);
}