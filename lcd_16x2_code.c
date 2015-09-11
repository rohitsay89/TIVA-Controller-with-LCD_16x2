#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include "inc/tm4c1294ncpdt.h"
#include "driverlib/sysctl.h"

/*
  size is 1*16
  if do not need to read busy, then you can tie R/W=ground
  ground = pin 1    Vss
  power  = pin 2    Vdd   +3.3V or +5V depending on the device
  ground = pin 3    Vlc   grounded for highest contrast
  PE4    = pin 4    RS    (1 for data, 0 for control/status)
  ground = pin 5    R/W   (1 for read, 0 for write)
  PE5    = pin 6    E     (enable)
  PK0    = pin 7    DB0   (8-bit data)
  PK1    = pin 8    DB1
  PK2    = pin 9    DB2
  PK3    = pin 10   DB3
  PK4    = pin 11   DB4
  PK5    = pin 12   DB5
  PK6    = pin 13   DB6
  PK7    = pin 14   DB7
	anode	 = pin 15   +5v
	cathode= pin 16   GND
16 characters are configured as 1 row of 16
addr  00 01 02 03 04 05 ... 0F
*/

#define E  0x20 // on PE5
#define RS 0x10 // on PE4
#define LCDDATA (*((volatile uint32_t *)0x400613FC))   // PORTk
#define LCDCMD (*((volatile uint32_t *)0x4005C0C0))    // PE5,4

void OutCmd(unsigned char command){
  LCDDATA = command;
  LCDCMD = 0;           // E=0, R/W=0, RS=0
  SysCtlDelay(240);			//SysTick_Wait(T6us);   // wait 6us
  LCDCMD = E;           // E=1, R/W=0, RS=0
  SysCtlDelay(240);			//SysTick_Wait(T6us);   // wait 6us
  LCDCMD = 0;           // E=0, R/W=0, RS=0
  SysCtlDelay(1600);			//SysTick_Wait(T40us);  // wait 40us
}
// Output a character to the LCD
// Inputs: letter is ASCII character, 0 to 0x7F
// Outputs: none
void LCD_OutChar(unsigned char letter){
  LCDDATA = letter;
  LCDCMD = RS;          // E=0, R/W=0, RS=1
  SysCtlDelay(240);			//SysTick_Wait(T6us);   // wait 6us
  LCDCMD = E+RS;        // E=1, R/W=0, RS=1
  SysCtlDelay(240);			//SysTick_Wait(T6us);   // wait 6us
  LCDCMD = RS;          // E=0, R/W=0, RS=1
  SysCtlDelay(1600);			//SysTick_Wait(T40us);  // wait 40us
}

// Clear the LCD
// Inputs: none
// Outputs: none
void LCD_Clear(void){
  OutCmd(0x01);          // Clear Display
  SysCtlDelay(64000);			//SysTick_Wait(T1600us); // wait 1.6ms
  OutCmd(0x02);          // Cursor to home
  SysCtlDelay(64000);		 //SysTick_Wait(T1600us); // wait 1.6ms
}

//------------LCD_OutString------------
// Output String (NULL termination)
// Input: pointer to a NULL-terminated string to be transferred
// Output: none
void LCD_OutString(char *pt){
  while(*pt){
    LCD_OutChar(*pt);
    pt++;
  }
}

//-----------------------LCD_OutUDec-----------------------
// Output a 32-bit number in unsigned decimal format
// Input: 32-bit number to be transferred
// Output: none
// Variable format 1-10 digits with no space before or after
void LCD_OutUDec(uint32_t n){
// This function uses recursion to convert decimal number of unspecified length as an ASCII string
  if(n >= 10){
    LCD_OutUDec(n/10);
    n = n%10;
  }
  LCD_OutChar(n+'0'); // n is between 0 and 9 
}

volatile uint32_t ui32SysClkFreq;
void PortFunctionInit(void)
{
//
	volatile uint32_t ui32Loop;   // Enable the clock of the GPIO port N that is used for the on-board LED D1 
	ui32SysClkFreq = SysCtlClockFreqSet((SYSCTL_XTAL_25MHZ | SYSCTL_USE_PLL | SYSCTL_CFG_VCO_480), 120000000); // 120MHz
	
  SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R9|SYSCTL_RCGCGPIO_R4|SYSCTL_RCGCGPIO_R12;
  // Do a dummy read to insert a few cycles after enabling the peripheral
  ui32Loop = SYSCTL_RCGCGPIO_R;
	
	GPIO_PORTN_DIR_R |= 0x01;//PN0
	GPIO_PORTN_DEN_R |= 0x01;//PN0
	
	GPIO_PORTK_AMSEL_R &= ~0xFF;   // 3) disable analog function on PK7-0
	GPIO_PORTE_AHB_AMSEL_R &= ~0x30;   //    disable analog function on PE5-4  
	
	GPIO_PORTK_PCTL_R = 0x00000000;   // 4) configure PK7-0 as GPIO   
  GPIO_PORTE_AHB_PCTL_R &= ~0xFF000000; //    configure PA7-6 as GPIO
	
	GPIO_PORTK_DIR_R = 0xFF;       // 5) set direction register
  GPIO_PORTE_AHB_DIR_R |= 0x30;
	
	GPIO_PORTK_AFSEL_R = 0x00;     // 6) regular port function
  GPIO_PORTE_AHB_AFSEL_R &= ~0x30;
	
	GPIO_PORTK_DEN_R = 0xFF;       // 7) enable digital port
  GPIO_PORTE_AHB_DEN_R |= 0x30;
	
	GPIO_PORTK_DR8R_R = 0xFF;      // enable 8 mA drive
  GPIO_PORTE_AHB_DR8R_R |= 0x30;
	
  LCDCMD = 0;           // E=0, R/W=0, RS=0
  SysCtlDelay(600000);		//SysTick_Wait(T15ms);  // Wait >15 ms after power is applied
  OutCmd(0x30);         // command 0x30 = Wake up
  SysCtlDelay(200000);		//SysTick_Wait(T5ms);   // must wait 5ms, busy flag not available
  OutCmd(0x30);         // command 0x30 = Wake up #2
  SysCtlDelay(6400);		//SysTick_Wait(T160us); // must wait 160us, busy flag not available
  OutCmd(0x30);         // command 0x30 = Wake up #3
  SysCtlDelay(6400);		//SysTick_Wait(T160us); // must wait 160us, busy flag not available
  OutCmd(0x38);         // Function set: 8-bit/2-line
  OutCmd(0x10);         // Set cursor
  OutCmd(0x0C);         // Display ON; Cursor ON
  OutCmd(0x06);         // Entry mode set
}

int main(void)
{
	PortFunctionInit();
	GPIO_PORTN_DATA_R |= 0x01;
	SysCtlDelay(200000);
	LCD_Clear();
	LCD_OutString("sfsu.edu");
	SysCtlDelay(80000000);
	while(1)
	{
		GPIO_PORTN_DATA_R ^= 0x01;
		SysCtlDelay(40000000);
		LCD_Clear();
		LCD_OutString("SFSU.edu");
		SysCtlDelay(80000000);
	}
}
