
// By Timo Heimonen
// Magenta Microstepping board SLA7062M & Arduino Mega & Stepper motor

#define MAXSPEED 450 // microseconds between steps = max speed control
#define ACCDEACC 1600 // accelration and deacceleration steps, also min speed
#define DEBUG 0  // 1 = Serial debug ON, 0 = Serial debug OFF

int DirPIN = 8;   // DIRECTION PIN
int StepPIN = 9;  // CLOCK PIN
int HomePIN = 10; // HOME PIN
int SyncPIN = 11; // Sync PIN
int LedPIN = 13;  // Arduino Led
int stephome=0;
unsigned long counter=0;


void setup()
{
 if(DEBUG ==  1)
 {
   Serial.begin(115200);
 }
 pinMode(DirPIN, OUTPUT);
 pinMode(StepPIN, OUTPUT);
 pinMode(SyncPIN, OUTPUT);
 pinMode(HomePIN, INPUT);
 pinMode(LedPIN, OUTPUT);
}

void motorstep(unsigned long howmany,int direc)
{
 if(direc==0)
 {
   digitalWrite(DirPIN, HIGH);
 }
 if(direc==1)
 {
   digitalWrite(DirPIN, LOW);
 }
 int i=ACCDEACC;
 counter=0;
 while(counter<howmany)
 {
   if(counter<ACCDEACC)
   {
     if(i>MAXSPEED)
     {
       i=i-1;
     }
   }
   if(howmany-counter<ACCDEACC)
   {
     if(i<ACCDEACC);
     {
       i=i+1;
     }
   }
   digitalWrite(StepPIN, HIGH);      // GIVE HIGH EDGE (CLOCK) TO SLA7062M
   delayMicroseconds(5);             // WAIT LITTLE BIT BEFORE GET IT DOWN
   digitalWrite(StepPIN,LOW);
   delayMicroseconds(40);            // WE MUST WAIT THAT HOME SIGNAL HAS TIME GET UP
   stephome = digitalRead(HomePIN);  // ARE WE AT "HOME"
   if (stephome == HIGH)
   {    
     digitalWrite(SyncPIN, HIGH);    // IF SO, LETS SYNC
     digitalWrite(LedPIN, HIGH);
     if(DEBUG == 1)
     {
       Serial.write("HOME HIGH, SYNC HIGH");
       Serial.println();
     }
   }
   else
   {
     digitalWrite(SyncPIN, LOW);
     digitalWrite(LedPIN, LOW);
     if(DEBUG == 1)
     {
       Serial.write("HOME LOW, SYNC LOW");
       Serial.println();
     }
   }
   delayMicroseconds(i);             // DELAY BETWEEN STEPS, BETTER TO DO THIS WAIT HERE AND GIVE ANOTHER DELAY TO HOME READING, THIS WAY SYNC IS ALREADY WORKING
   counter=counter+1;
 }
}

void loop()  
{
 motorstep(3000,1);
 delay(100);
 motorstep(10000,0);
 delay(100);
 motorstep(400,1);
 delay(100);
 motorstep(200,0);
 delay(100);
 motorstep(200,0);
 delay(100);
 motorstep(10000,1);
 delay(100);
 motorstep(400,0);
 delay(100);
}