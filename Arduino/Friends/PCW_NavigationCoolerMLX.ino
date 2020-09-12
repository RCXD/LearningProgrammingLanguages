#include <Wire.h>
#include <Adafruit_MLX90614.h>
//MLX90614라이브러리
Adafruit_MLX90614 mlx = Adafruit_MLX90614();
#define fan 5

int minTEMP = 42.00;

void setup() {
//Serial.begin(9600);//시리얼 통신 시작.
//Serial.println("Project Cooling System");
mlx.begin();
pinMode(fan,OUTPUT);
}

void loop() {
//Serial.print("Ambient = ");
//Serial.print(mlx.readAmbientTempC());
//Serial.println("*C");
//Ambient:센서자체온도.
//Serial.print("*C\tObject = ");
//Serial.print(mlx.readObjectTempC());
//Serial.println("*C");
//Object:타겟의 온도
//Serial.println();
delay(60000); //필요한가유?(잘모름)

//if(Serial.available())
//{
    //int Ambient = Serial.parseInt();
    //int Object = Serial.parseInt();
    double Ambient = mlx.readAmbientTempC()
    double Object = mlx.readObjectTempC()
    if(Ambient>minTEMP && Object>minTEMP) {
      digitalWrite(fan,HIGH);     }
    else     {
      digitalWrite(fan,LOW);      }
  }
}

