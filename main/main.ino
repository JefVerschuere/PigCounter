#include <PinChangeInt.h>
#include "PigListCol.h"
//#include <SPI.h>
//#include <SD.h>
//#include <Wire.h>
#include <RTClib.h>

// RTC_DS1307 rtc;
//DateTime now = rtc.now();

//const int chipSelect = 10;
//const String nameFile = "AB_Sang.csv";
//File fichier;*/

const PigListCol* pigListCol = new PigListCol();

const byte NouvelleSerie = A0; 
const byte SerieValide = A4;
const byte SerieRefusee = A3;
const byte PorcIN = A1;
const byte PorcOUT = A2;
const byte Aquitement = A5;
const byte LedValide = 3;
const byte LedRefusee = 4;
const byte LedAquitement = 5;
const byte LedSerie = 6;
const byte LedFinSerie = 7;
 
byte comptageNouvelleSerie = 0;
byte comptagePorcIN = 0;
byte comptagePorcOUT = 0;

const unsigned long dureeAntiRebond = 50;
 
void interruptNouvelleSerie()
{
  Serial.println("interruptNouvelleSerie :");
  digitalWrite(LedSerie, HIGH);
  static unsigned long dateDernierChangement = 0;
 
  unsigned long date = millis();
  if ((date - dateDernierChangement) > dureeAntiRebond) {
    comptageNouvelleSerie++;
    pigListCol->createNewPigList(comptageNouvelleSerie);
    dateDernierChangement = date;
  }
}
 
void interruptPorcIN()
{
  Serial.println("interruptPorcIN :");
  static unsigned long dateDernierChangement = 0;
 
  unsigned long date = millis();
  if ((date - dateDernierChangement) > dureeAntiRebond) {
    comptagePorcIN++;
    pigListCol->getActivePigList(comptageNouvelleSerie).addPigIn();
    dateDernierChangement = date;
  }
}
 
void interruptPorcOUT()
{
  
  Serial.println("interruptPorcOUT :");
  static unsigned long dateDernierChangement = 0;
 
  unsigned long date = millis();
  if ((date - dateDernierChangement) > dureeAntiRebond) {
    comptagePorcOUT++;
    pigListCol->getActivePigList(comptageNouvelleSerie).addPigOut();
    dateDernierChangement = date;
  }
}
 
void interruptSerieValide()
{
  Serial.println("interruptSerieValide :");
  static unsigned long dateDernierChangement = 0;
 
  unsigned long date = millis();
  if ((date - dateDernierChangement) > dureeAntiRebond) {
    digitalWrite(LedValide, HIGH);
    digitalWrite(LedRefusee, LOW);
    dateDernierChangement = date;
  }
} 

void interruptSerieRefusee()
{
  Serial.println("interruptSerieRefusee :");
  static unsigned long dateDernierChangement = 0;
 
  unsigned long date = millis();
  if ((date - dateDernierChangement) > dureeAntiRebond) {
    digitalWrite(LedValide, LOW);
    digitalWrite(LedRefusee, HIGH);
    dateDernierChangement = date;
  }
} 
void interruptAquitement()
{
  Serial.println("Aquitement :");
  static unsigned long dateDernierChangement = 0;
 
  unsigned long date = millis();
  if ((date - dateDernierChangement) > dureeAntiRebond) {
    digitalWrite(LedValide, LOW);
    digitalWrite(LedRefusee, LOW);
    dateDernierChangement = date;
  }
} 

void setup()
{
  /*rtc.begin();
    if (! rtc.isrunning()) {
    rtc.adjust(DateTime(__DATE__, __TIME__));
  }
  DateTime now = rtc.now();*/
  
  Serial.begin(9600);

  pinMode(NouvelleSerie, INPUT_PULLUP);
  pinMode(PorcIN, INPUT_PULLUP);
  pinMode(PorcOUT, INPUT_PULLUP);
  pinMode(SerieValide, INPUT_PULLUP);
  pinMode(SerieRefusee, INPUT_PULLUP);
  pinMode(Aquitement, INPUT_PULLUP);
  pinMode(LedValide, OUTPUT);
  pinMode(LedRefusee, OUTPUT);
  pinMode(LedAquitement, OUTPUT);
  pinMode(LedSerie, OUTPUT);
  pinMode(LedFinSerie, OUTPUT);
 
  PCintPort::attachInterrupt(NouvelleSerie, interruptNouvelleSerie, FALLING);
  PCintPort::attachInterrupt(PorcIN, interruptPorcIN, FALLING);
  PCintPort::attachInterrupt(PorcOUT, interruptPorcOUT, FALLING);
  PCintPort::attachInterrupt(SerieValide, interruptSerieValide, FALLING);
  PCintPort::attachInterrupt(SerieRefusee, interruptSerieRefusee, FALLING);
  PCintPort::attachInterrupt(Aquitement, interruptAquitement, FALLING);  

  digitalWrite(LedValide, LOW);
  digitalWrite(LedRefusee, LOW);
  digitalWrite(LedAquitement, LOW);
  digitalWrite(LedSerie, LOW);
  
}
 
void loop()
{
  /*Serial.print(now.day(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.year(), DEC); 
  Serial.print(' ');
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.print(now.second(), DEC);
  Serial.println();*/
   
  Serial.print("Serie :");
  Serial.println(comptageNouvelleSerie);
 
  Serial.print("Porc In :");
  Serial.println(comptagePorcIN);
 
  Serial.print("Porc Out :");
  Serial.println(comptagePorcOUT);

  Serial.print("Serie en cours :");
  Serial.println(comptagePorcIN-comptagePorcOUT);
  
  delay(3000);
  
}
