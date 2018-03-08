/*
 * Debounce.c
 *
 *  Created on: Feb 22, 2018
 *      Author: Misael
 */
/*
#include "fsl_gpio.h"
#include "GPIO.h"
#include "Debounce.h"

void Cont_Reset(void)
{
	if(GPIO_ReadPinInput(GPIOB, RESET_BUTTON)==0U)
	{
		ModCont++;
	}
	else
	{
		Det_Button();
	}
}

void Det_Button(void)
{
	if(ModCont>=10000)
	{
		ModCont=0;
		numero=0;
		x=0;
		modo++;
		if(modo>=3)
			{
		modo=1;
			}

	}
	else if((ModCont>=100) && ( ModCont != 0))
	{
		ModCont=0;
		numero=0;
	}
	else
	{

	}

}

*/

