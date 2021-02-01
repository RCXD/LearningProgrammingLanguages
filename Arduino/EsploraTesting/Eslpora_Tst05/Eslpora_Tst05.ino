///Arduino Esplora Library Testing w/ Embedded Peri.

#include <Esplora.h>
#include <String

///https://www.arduino.cc/en/Reference/EsploraLibrary
///Documentation
///1. 2-Acis analog joystick
///2. center push-button of the joystick
///3. 4 push-buttons(SWITCH_0~3)
///4. microphone
///5. light sensor
///6. temperature sensor
///7. 3-axis accerlerometer
///8. 2 TinkerKit input connectors ...?
///9. RGB LED
///10. Piezo buzzer
///11. 2 TinkerKit output connectors ...?

//Select option for testing
#define JOYSTICK
#define SWITCH
#define MIC
#define CDS
#define TEMP
#define ACC
#define RGB
#define PIEZO


void setup(){
#ifdef JOYSTICK
  boolean isJoystick = false;
  int axisX = 0;
  int axisY = 0;
#endif

#ifdef SWITCH
  boolean isSW0 = false;
  boolean isSW1 = false;
  boolean isSW2 = false;
  boolean isSW3 = false;
#endif

#ifdef MIC
#endif

#ifdef CDS
#endif

#ifdef TEMP
#endif

#ifdef ACC
#ifndef SERIAL
#define SERIAL
  Serial.begin(9600);
#endif
  int accX = Esplora.readAccelerometer(X_AXIS);
  int accY = Esplora.readAccelerometer(Y_AXIS);
  int accZ = Esplora.readAccelerometer(Z_AXIS);
  Serial.print("x: ");
#endif

#ifdef RGB
  testRGB();
#endif

#ifdef PIEZO
#endif

}


void loop(){
#ifdef ACC
  
#endif
}

void testRGB(void){
  int i = 3;
  while(i-->0){
    Esplora.writeRed(255);
    delay(100);
    Esplora.writeRed(0);
    Esplora.writeGreen(255);
    delay(100);
    Esplora.writeGreen(0);
    Esplora.writeBlue(255);
    delay(100);
    Esplora.writeBlue(0);
  }
}
