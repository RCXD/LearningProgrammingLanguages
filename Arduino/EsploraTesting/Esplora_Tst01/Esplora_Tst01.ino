#include <Esplora.h>

///From example code https://www.arduino.cc/en/pmwiki.php?n=Guide/ArduinoEsploraExamples
///Modified example for use with Esplora
//int pushButton = 2; //Esplora는 2번핀이 없다

void setup() {
  Serial.begin(9600);
  //pinMode(pushButton, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int buttonState = Esplora.readButton(SWITCH_2);
  Serial.println(buttonState);
  delay(1);
}
