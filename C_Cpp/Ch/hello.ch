/* File: hello.ch
   Print 'Hello, world' on the screen. */

#define STP_RST 1   //PORTA0 
#define STP_CW  2   //PORTA1 
#define STP_CLK 4   //PORTA2 
#define STP_M2  8   //PORTA3 
#define STP_M1  16   //PORTA4 
#define STP_MOUT 32  //PORTA5 
#define STP_SYNC 64  //PORTA6 
//#define PORTA7 
#define HALF 1
#define QUARTER 2
#define EIGHTH 3
#define SIXTEENTH 4

int DDRA = 0;
int PORTA = 0;

void step_init(int mode){
    DDRA |= STP_RST|STP_CW|STP_CLK|STP_M2|STP_M1|STP_SYNC;
    printf("1, 0x%x \n", DDRA);
    DDRA &= ~STP_MOUT;
    printf("2, 0x%x \n", DDRA);
	//PORTA |= 
	PORTA &= ~( STP_RST|STP_CW|STP_CLK|STP_SYNC );
    printf("3, 0x%x \n", ~PORTA);
	
    switch(mode)
    {
        case HALF:
            //Set M1-M2 to 1-1
            PORTA |= STP_M1|STP_M2;
            printf("4/2, 0x%x \n", ~PORTA);
			break;
        case QUARTER:
            //Set M1-M2 to 1-0
            PORTA |= STP_M1;
            PORTA &= ~STP_M2;
            printf("4/4, 0x%x \n", ~PORTA);
			break;
        case EIGHTH:
            //Set M1-M2 to 0-1
            PORTA &= ~STP_M1;
            PORTA |= STP_M2;
            printf("4/8, 0x%x \n", ~PORTA);
			break;
        case SIXTEENTH:
            //Set M1-M2 to 0-0
            PORTA &= ~(STP_M1|STP_M2);
            printf("4/16, 0x%x \n", ~PORTA);
			break;
    }
}

step_init(HALF);
step_init(QUARTER);
step_init(EIGHTH);
step_init(SIXTEENTH);

//printf("Hello, world\n");

//int x = 0x44;
//int y = 0xff;
//int z = 0x00;
//printf("x | y = 0x%x \n", x|y);
//printf("x & z = 0x%x \n", x&z);

//printf("0x%x \n", ~0x45); //0xba = 0b1011 1010 -(inv)-> 0b0100 0101
//printf("0x%x \n", 0xff&0xba);
