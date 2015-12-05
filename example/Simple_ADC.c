#include "lpc11xx_adc.h"
#include "lcd.h"



void del()
{
	int i, j;
	/* Delay some time */
	for(i=0; i<50; i++) {
		for(j=0; j<10000; j++) {
		}
	}
}


void ADCExp()
{
	uint16_t adc_value,i;
	char buf[26];
	char temp;
	int temp_val;
	int buf_count=0;
	/* Configuration for ADC :
	 * 	Frequency at 1Mhz
	 *  ADC channel 2,
	 */
	ADC_Init(1000000);
	ADC_IntConfig(ADC_ADINTEN4,ENABLE);
    ADC_PinsInit(ADC_CHANNEL_4);
	ADC_ChannelCmd(ADC_CHANNEL_4,ENABLE);
    
	while(1)
	{
		/* Start conversion */
		ADC_StartCmd(ADC_START_NOW);
		/* Wait conversion complete */
		while (!(ADC_ChannelGetStatus(ADC_CHANNEL_4,ADC_DATA_DONE)));
		adc_value = ADC_ChannelGetData(ADC_CHANNEL_4);
		temp_val = (adc_value*3.3*100)/1023;

		lcd_gotoxy(0,5);
		lcd_putchar(' ');lcd_putchar(' ');lcd_putchar(' ');lcd_putchar(' ');
		lcd_gotoxy(0,5);
		buf_count=0;
		while(temp_val!=0)
		{
			temp = (temp_val%10)+48;
			temp_val = temp_val / 10;
			buf[buf_count]= temp;
			buf_count++;
		}
		for(i=buf_count;i>0;i--)
		{
			lcd_putchar(buf[i-1]);
		}

		lcd_gotoxy(1,5);
		lcd_putchar(' ');lcd_putchar(' ');lcd_putchar(' ');lcd_putchar(' ');
		lcd_gotoxy(1,5);
		buf_count=0;
		while(adc_value!=0)
		{
			temp = (adc_value%10)+48;
			adc_value = adc_value / 10;
			buf[buf_count]= temp;
			buf_count++;
		}
		for(i=buf_count;i>0;i--)
		{
			lcd_putchar(buf[i-1]);
		}
		del();


	}  
}
