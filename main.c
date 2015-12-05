#include "lcd.h"

void ADCExp();



int main(void)
{

	init_lcd();						// Initialize LCD
	lcd_putstring(LINE1,"Temp:");
	lcd_putstring(LINE2,"ADC:");
    //automatically added by CoIDE
	ADCExp();
	while(1)
    {
    }
}

