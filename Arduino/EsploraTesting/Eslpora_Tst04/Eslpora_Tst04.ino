///Peri: RGB Green
///Function: Fading in Repeat

#include <Esplora.h>

int brightness=0;
int fadeAmount=5;


void setup(){
  
}


void loop(){
  Esplora.writeBlue(brightness);
  brightness = brightness + fadeAmount;

  if(brightness==0||brightness==255){
    fadeAmount = -fadeAmount;
  }
}
