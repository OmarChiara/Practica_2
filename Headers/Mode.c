/*
 * Mode.c
 *
 *  Created on: Feb 22, 2018
 *      Author: Misael
 */
/*
#include "fsl_gpio.h"
#include "BCD.h"
#include "Mode.h"
#include "GPIO.h"

void select_Mode(uint32_t Modo)

{
	           switch(Modo)
	        	{
	        	case 1 :
	        	{

	        		Init_Mode1();

	        	}
	        	break;

	        	case 2 :

	        	{
	        		Init_Mode2();
	        	}
	        	break;
	        	case 3 :
	        	{
	        		Init_Mode3();
	        	}
	        	break;
	        	}
}


void Init_Mode1(void)


{

Led_Mode1();
unsigned short dec, uni,cent;


    uni= numero % 10u;
    Digits(uni);
    select_Digit(1);
    select_Digit(4);




    dec=numero / 10u;
    Digits(dec);
    select_Digit(2);
    select_Digit(4);

    cent=numero / 100u;
    Digits(cent);
    select_Digit(3);
    select_Digit(4);


if  (x>=10000)
{
if (GPIO_ReadPinInput(GPIOB, INC_BUTTON)==0U)
{
if(numero>=MAX_VALUE)
{
numero=MIN_VALUE;
x=0;
}
else
{
++numero;
x=0;
}
}


if (GPIO_ReadPinInput(GPIOB, DEC_BUTTON)==0U)
    {
    if(numero<=MIN_VALUE)
    {
    numero=MAX_VALUE;
    x=0;
    }

    else {
    --numero;
    x=0;

    }
    }
    }

Cont_Reset();
     x++;
}



void Init_Mode2(void)

{

Led_Mode2();
unsigned short dec, uni,cent;



uni= numero % 10u;
Digits(uni);
select_Digit(1);
select_Digit(4);




dec=numero / 10u;
Digits(dec);
select_Digit(2);
select_Digit(4);

cent=numero / 100u;
    Digits(cent);
    select_Digit(3);
    select_Digit(4);

Cont_Reset();

if  (x>=100000)
{

numero++;
x=0;

if(numero>=101)
{
 numero=0;
}

}

x++;
}


void Init_Mode3(void)
{
while(1)
{

adc_val= ADC0 ->R[0];


//adc_val = ADC16_GetChannelConversionValue(ADC0, 0);

	PRINTF("\r\n\r\nADC Value: %d\r\n", adc_val);

//for(x=0; x<=1000;++x){
		 int dec, uni,cent;


	    uni= (adc_val % 100u) % 10;
	    Digits(uni);
	    select_Digit(1);
	    select_Digit(4);




	    dec=(adc_val % 100) / 10;
	    Digits(dec);
	    select_Digit(2);
	    select_Digit(4);

	    cent=adc_val / 100u;
	        Digits(cent);
	        select_Digit(3);
	        select_Digit(4);

	        adc_val=0;
}
}
*/
