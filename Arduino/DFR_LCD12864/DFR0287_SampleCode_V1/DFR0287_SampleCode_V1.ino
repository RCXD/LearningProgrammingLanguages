/*
 # This sample codes is for testing the LCD12864 shield.
 # Editor : Mickey
 # Date   : 2013.11.27
 # Ver    : 0.1
 # Product: LCD12864 shield
 # SKU    : DFR0287
*/


#include "U8glib.h"

// setup u8g object, please remove comment from one of the following constructor calls
// IMPORTANT NOTE: The complete list of supported devices is here: http://code.google.com/p/u8glib/wiki/device

U8GLIB_NHD_C12864 u8g(13, 11, 10, 9, 8);	// SPI Com: SCK = 13, MOSI = 11, CS = 10, A0 = 9, RST = 8

#define KEY_NONE 0
#define KEY_PREV 1
#define KEY_NEXT 2
#define KEY_SELECT 3
#define KEY_BACK 4


uint8_t uiKeyCodeFirst = KEY_NONE;
uint8_t uiKeyCodeSecond = KEY_NONE;
uint8_t uiKeyCode = KEY_NONE;

int adc_key_in;
int key=-1;
int oldkey=-1;


// Convert ADC value to key number
//         4
//         |
//   0 --  1 -- 3
//         |
//         2
int get_key(unsigned int input)
{   
    if (input < 100) return 0;
    else  if (input < 300) return 1;
    else  if (input < 500) return 2;
    else  if (input < 700) return 3;
    else  if (input < 900) return 4;    
    else  return -1;
}

void uiStep(void) {
  
  adc_key_in = analogRead(0);    // read the value from the sensor  
  key = get_key(adc_key_in);	 // convert into key press	
  if (key != oldkey)	  // if keypress is detected
   {
    delay(50);		// wait for debounce time
    adc_key_in = analogRead(0);    // read the value from the sensor  
    key = get_key(adc_key_in);	   // convert into key press
    if (key != oldkey)				
    {			
      oldkey = key;
      if (key >=0){
             //Serial.println(key);
             if ( key == 0 )
               uiKeyCodeFirst = KEY_BACK;
             else if ( key == 1 )
               uiKeyCodeFirst = KEY_SELECT;
             else if ( key == 2 )
               uiKeyCodeFirst = KEY_NEXT;
             else if ( key == 4 )
               uiKeyCodeFirst = KEY_PREV;
             else 
               uiKeyCodeFirst = KEY_NONE;
  
             uiKeyCode = uiKeyCodeFirst;           
      }
    }
  }
 delay(100);
}


#define MENU_ITEMS 6
char *menu_strings[MENU_ITEMS] = { "LCD12864 Shield", "www.DFRobot.com", "Temperature", "Humidity" ,"About","OK"};

uint8_t menu_current = 0;
uint8_t menu_redraw_required = 0;
uint8_t last_key_code = KEY_NONE;


void drawMenu(void) {
  uint8_t i, h;
  u8g_uint_t w, d;

  u8g.setFont(u8g_font_6x12);//4x6 5x7 5x8 6x10 6x12 6x13
  u8g.setFontRefHeightText();
  u8g.setFontPosTop();
  
  h = u8g.getFontAscent()-u8g.getFontDescent();
  w = u8g.getWidth();
  for( i = 0; i < MENU_ITEMS; i++ ) {
    d = (w-u8g.getStrWidth(menu_strings[i]))/2;
    u8g.setDefaultForegroundColor();
    if ( i == menu_current ) {  
      u8g.drawBox(0, i*h+1, w, h);
      u8g.setDefaultBackgroundColor();
    }
    u8g.drawStr(d, i*h+1, menu_strings[i]);
  }
}

void updateMenu(void) 
{
  switch ( uiKeyCode ) {
    case KEY_NEXT:
      menu_current++;
      if ( menu_current >= MENU_ITEMS )menu_current = 0;
      menu_redraw_required = 1;
      break;
    case KEY_PREV:
      if ( menu_current == 0 )menu_current = MENU_ITEMS;
      menu_current--;
      menu_redraw_required = 1;
      break;
  }
  uiKeyCode = KEY_NONE;
}


void setup() {
  
  u8g.setRot180();// rotate screen, if required
  menu_redraw_required = 1;     // force initial redraw
  //Serial.begin(9600);
}

void loop() {  

  uiStep();                                // check for key press
  updateMenu();                            // update menu bar    
  
  if (  menu_redraw_required != 0 ) {
    u8g.firstPage();
    do  {
      drawMenu();
    } while( u8g.nextPage() );
    menu_redraw_required = 0;
  }
  
}
