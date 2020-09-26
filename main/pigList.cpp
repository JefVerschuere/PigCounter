#include "pigList.h";

PigList::PigList() {}

PigList::PigList(byte nr) {
    this->serieNumber = nr;
}

void PigList::addPigIn(){
    this->pigCpIn = this->pigCpIn +1;
}

void PigList::addPigOut(){
    this->pigCpOut = this->pigCpOut +1;
}

void PigList::setSerieNumber(byte nr){
  this->serieNumber = nr;
}
