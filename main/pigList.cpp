#include "pigList.h";

PigList::PigList() {}

PigList::PigList(byte nr) {
    this->serieNumber = nr;
}

PigList::addPigIn(){
    this->pigCpIn = this->pigCpIn +1;
}

PigList::addPigOut(){
    this->pigCpOut = this->pigCpOut +1;
}
