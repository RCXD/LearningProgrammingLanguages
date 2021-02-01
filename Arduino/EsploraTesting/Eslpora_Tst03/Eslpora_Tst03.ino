///Peri: Light Sensor, UART

#include <Esplora.h>

void setup(){
  Serial.begin(9600);
}


void loop(){
  int sensorValue = Esplora.readLightSensor();
  float voltage = sensorValue * (5.0/1023.0);
  Serial.println(voltage);
}
