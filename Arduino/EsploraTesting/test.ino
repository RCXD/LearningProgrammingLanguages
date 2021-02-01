///Arduino Esplora Library Testing w/ Embedded Peri.

#include <Esplora.h> 

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


///Configuration 1: Projects
///Choose only one project. Do not choose more than one
//#define JOYSTICK 1
//#define SWITCH 1
//#define MIC 1
//#define CDS 1
//#define TEMP 1
//#define ACC 1 
//#define RGB 1//option: RGB_TEST, RGB_SHOW, JOYSTICK_IN, SLIDER
#define PIEZO 1



///Configuration 2: Inputs & Readings
//#define JOYSTICK_IN
//#define SWITCH_IN
//#define MIC_IN
//#define CDS_IN
//#define TEMP_IN
//#define ACC_IN
//#define SLIDER_IN



///Configuration 2: Outputs
//#define MOUSE //demands JOYSTICK
//#define MONITOR //Choose either MONITOR or PLOTTER, not both
//#define PLOTTER
#define PIEZO_OUT
//#define RGB_OUT



///Configuration 3: Visual Shows
#define RGB_TEST
//#define RGB_SHOW //MONITOR or PLOTTER Available
#define RGB_SHOW2 //MONITOR or PLOTTER Available
//#define RAW_CDS //CDS Option for calibration


///Preprocessors, Error patterns
#if JOYSTICK + SWITCH + MIC + CDS + TEMP + ACC + RGB + PIEZO > 1
  #error "Duplicated Projects: Check Conf 1"
#endif
#if (defined JOYSTICK) && (defined JOYSTICK_IN)
  #error "JOYSTICK Duplication"
#endif
#if (!defined JOYSTICK) && (defined MOUSE)
  #error "MOUSE needs JOYSTICK to be defined"
#endif
#if (defined SWITCH) && (defined SWITCH_IN)
  #error "SWITCH Duplication"
#endif
#if (defined MIC) && (defined MIC_IN)
  #error "MIC Duplication"
#endif
#if (defined CDS) && (defined CDS_IN)
  #error "CDS Duplication"
#endif
#ifdef MOUSE
#include <Mouse.h>
#endif
#ifdef ACC || RGB
  #ifdef MONITOR || PLOTTER
    #define SERIAL
  #endif
#endif
#if (defined MONITOR) && (defined PLOTTER)
  #error "Choose either MONITOR or PLOTTER, not both"
#endif
#if (defined RGB_SHOW2) && (!defined SLIDER)
  #define SLIDER_IN
#endif
#ifdef PIEZO
  #define SLIDER_IN
#endif



///Global Variables
#if (defined JOYSTICK) || (defined JOYSTICK_IN)
boolean isJoystick = false;
int xValue = 0;
int yValue = 0;
#endif
#if (defined SWITCH) || (defined SWITCH_IN)
boolean isSW0 = false;
boolean isSW1 = false;
boolean isSW2 = false;
boolean isSW3 = false;
#endif
#if (defined MIC) || (defined MIC_IN)
static int mic = 0;
#endif
#if (defined CDS) || (defined CDS_IN)
int light = 0;
int lowLight = 247*4; //light sensor reading when it's covered
int highLight = 1023; //the maximum light sensor reading
int minGreen = 0; //minimum brightness of the green LED
int maxGreen = 255; //maximum brightness of the green LED
#endif
#ifdef TEMP
#endif
#if (defined ACC) || (defined ACC_IN)
int xAxis = 0;
int yAxis = 0;
int zAxis = 0;
#endif
#if (defined RGB) || (defined RGB_OUT)
byte red = 0;
byte green = 0;
byte blue = 0;
#endif
#ifdef PIEZO
const int note[] = { 262/*C*/, 277/*C#*/, 294/*D*/, 311/*D#*/, 330/*E*/, 349/*F*/, 370/*F#*/,
                     392/*G*/, 415/*G#*/, 440/*A*/, 466/*A#*/, 494/*B*/, 523/*octave C*/};
#endif
#ifdef SLIDER_IN
  int slider = Esplora.readSlider();
#endif



///setup Function
void setup(){
#ifdef JOYSTICK
  #ifdef MOUSE
  Mouse.begin();
  #endif
  #ifdef MONITOR
    #define SERIAL
  #endif
  #ifdef PLOTTER
    #define SERIAL
  #endif
#endif

#ifdef SWITCH
#endif

#ifdef MIC
#endif

#ifdef CDS
#endif

#ifdef TEMP
#endif

#ifdef ACC
#endif

#ifdef RGB_TEST
  testRGB();
#endif

#ifdef PIEZO
#endif

#ifdef SERIAL
  Serial.begin(9600);
#endif
}



///Loop Function
void loop(){
#ifdef SERIAL
  while(!Serial);
#endif
#ifdef JOYSTICK
  readJoystick();
  printJoystick();
  #ifdef MOUSE
  moveMouse();  
  #endif
#endif

#ifdef SWITCH
#endif

#ifdef MIC
  mic = Esplora.readMicrophone();
  #ifdef RGB_OUT
  red = constrain(mic, 0, 255);
  #endif
#endif

#ifdef CDS
  light = Esplora.readLightSensor();
  #ifdef RGB_OUT
  #ifdef RAW_CDS
  green = light;
  #else
  green = constrain(map(light, lowLight, highLight, minGreen, maxGreen), 0, 255);
  #endif
  #endif
#endif

#ifdef TEMP
#endif

#ifdef ACC
  readAxes();
  printAxes();
#endif

#ifdef RGB
  readRGB();
#ifdef RGB_SHOW
  showRGB();
#endif
#ifdef RGB_SHOW2
  showRGB_2();
#endif
#endif

#if defined SLIDER_IN && !defined RGB
  slider = Esplora.readSlider();
  #ifdef RGB_OUT
  blue = slider/4;
  #endif
#endif

#ifdef RGB_OUT
  Esplora.writeRGB(red, green, blue);
#endif

#ifdef PIEZO
  writeSound();
#endif

  delay(10);
}



//Functions
#ifdef JOYSTICK
void readJoystick(){
  xValue = Esplora.readJoystickX();
  yValue = Esplora.readJoystickY();
  isJoystick = Esplora.readJoystickSwitch();
}
void printJoystick(){
  #ifdef MONITOR
  Serial.print("Joystick X: ");
  Serial.print(xValue);
  Serial.print("\tY: ");
  Serial.print(yValue);
  Serial.println(isJoystick); //Boolean인데 왜 100이나오는지?
  #endif

  Serial.print("\tButton: ");
  #ifdef PLOTTER
  Serial.print(xValue);
  Serial.print("\t");
  Serial.print(yValue);
  Serial.print("\t");
  Serial.println(isJoystick*100);
  #endif
}
#ifdef MOUSE
void moveMouse(){
  int mouseX = map(xValue, -512, 512, 10, -10);
  int mouseY = map(yValue, -512, 512, -10, 10);
  Mouse.move(mouseX, mouseY, 0);
  if(!isJoystick) Mouse.press();
  else Mouse.release();
  delay(10);
}
#endif
#endif


#ifdef RGB
#ifdef RGB_TEST
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
#endif
void readRGB(void){
  #if defined JOYSTICK_IN || defined JOYSTICK
  xAxis = Esplora.readJoystickX();
  yAxis = Esplora.readJoystickY();
  #endif
  #ifdef SLIDER_IN
  slider = Esplora.readSlider();
  #endif
  #ifdef MIC_IN
  mic = Esplora.readMicrophone();
  #endif
  #ifdef CDS_IN
  light = Esplora.readLightSensor();
  #endif
}
#ifdef RGB_SHOW
void showRGB(void){
  red = map(xAxis, -512, 512, 0, 255);
  green = map(yAxis, -512, 512, 0, 255);
  blue = slider / 4;
  Esplora.writeRGB(red, green, blue);
}
#endif
#ifdef RGB_SHOW2
void showRGB_2(void){
  red = constrain(mic, 0, 255);
  #ifdef RAW_CDS
  green = map(light,0,1023,0,255);
  #else
  green = constrain(map(light, lowLight, highLight, minGreen, maxGreen), 0, 255);
  #endif
  blue = slider/4;
  Esplora.writeRGB(red, green, blue);
  #ifdef MONITOR
  Serial.print("mic:\t");
  Serial.print(red);
  Serial.print("\tlight: ");
  Serial.print(green);
  Serial.print("\tslider: ");
  Serial.println(blue);
  #elif defined PLOTTER
  Serial.print(red);
  Serial.print("\t");
  Serial.print(green);
  Serial.print("\t");
  Serial.println(blue);
  #endif
}
#endif
#endif

#ifdef ACC
void readAxes(){
  xAxis = Esplora.readAccelerometer(X_AXIS);
  yAxis = Esplora.readAccelerometer(Y_AXIS);
  zAxis = Esplora.readAccelerometer(Z_AXIS);
}
void printAxes(){
#ifdef MONITOR
  Serial.print("x: ");
  Serial.print(xAxis);
  Serial.print("\ty:");
  Serial.print(yAxis);
  Serial.print("\tz:");
  Serial.println(zAxis);
#elif defined PLOTTER
  Serial.print(xAxis);
  Serial.print("\t");
  Serial.print(yAxis);
  Serial.print("\t");
  Serial.println(zAxis);
#endif
}
#endif

#ifdef PIEZO
void writeSound(){
  if(Esplora.readButton(SWITCH_DOWN)==LOW){
    int slider = Esplora.readSlider();
    byte thisNote = map(slider, 0, 1023, 0, 13);
    Esplora.tone(note[thisNote]);
  }
  else{
    Esplora.noTone();
  }
}
#endif