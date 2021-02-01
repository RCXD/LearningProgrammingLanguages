///Peri.: SWITCH_0, RGB LED

int buttonState = 0;

#include <Esplora.h>
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = Esplora.readButton(SWITCH_1);
  if (buttonState == LOW){
    Esplora.writeRed(255); //writeRed replaces digitalWrite()
  }
  else{
    Esplora.writeRed(0);
  }
}
