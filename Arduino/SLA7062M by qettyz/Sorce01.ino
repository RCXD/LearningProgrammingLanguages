
// By Timo Heimonen
// Magenta Microstepping board SLA7062M & Arduino Mega & Stepper motor

#define MAXSPEED 500 // microseconds between steps = max speed control
#define ACCDEACC 1600 // accelration and deacceleration steps, also min speed

int DirPIN = 8;   // DIRECTION PIN
int StepPIN = 9;  // CLOCK PIN
int SyncPIN = 10; // SYNC PIN

long counter=0;


void setup()
{
 pinMode(DirPIN, OUTPUT);
 pinMode(StepPIN, OUTPUT);
 pinMode(SyncPIN, OUTPUT);
 digitalWrite(SyncPIN, HIGH);  
}

void motorstep(long howmany,int direc)
{
 if(direc==0)
 {
   digitalWrite(DirPIN, HIGH);
   delayMicroseconds(5);
 }
 if(direc==1)
 {
   digitalWrite(DirPIN, LOW);
   delayMicroseconds(5);
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
   digitalWrite(SyncPIN, LOW);
   digitalWrite(StepPIN, HIGH);
   delayMicroseconds(5);
   digitalWrite(StepPIN,LOW);
   digitalWrite(SyncPIN, HIGH);
   delayMicroseconds(i);
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

 motorstep(200,1);
 delay(100);

 motorstep(10000,1);
 delay(100);

 motorstep(400,0);
 delay(100);

}
