/*
 * Copyright (c) 2017, NXP Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of NXP Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
 
/**
 * @file    Practica_2.c
 * @brief   Application entry point.
 */
#include "fsl_debug_console.h"
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL25Z4.h"
#include "fsl_gpio.h"
#include "fsl_port.h"
#include "fsl_clock.h"
#include "fsl_adc16.h"
#include "fsl_dac.h"
#include "adc.h"
#include "GPIO.h"
#include "BCD.h"
#include "LED_INDICATOR.h"




/* TODO: insert other include files here. */


void select_Digit(uint32_t digit);
void Digits(uint32_t contador);
void Init_Mode1(void);
void Init_Mode2(void);
void Init_Mode3(void);
void select_Mode(uint32_t Modo);
void Cont_Reset(void);
void Det_Button(void);
void DAC_ADC_Init(void);
void Init_Mode4(void);
void delay(void);
void ToggleLed (void);




/* TODO: insert other definitions and declarations here. */

int adc_val;
int x=0;
int modo=1;
int numero=0;
int ModCont;




volatile bool g_Adc16ConversionDoneFlag = false;
volatile uint32_t g_Adc16ConversionValue = 0;
adc16_channel_config_t g_adc16ChannelConfigStruct;
int voltRead;

/*
 * @brief   Application entry point.
 */
int main(void) {



	    BOARD_InitPins();
	    BOARD_BootClockRUN();

  	/* Init board hardware. */
BOARD_InitBootPins();
BOARD_InitBootClocks();
BOARD_InitBootPeripherals();
  	/* Init FSL debug console. */
    BOARD_InitDebugConsole();
    EnableIRQ(DEMO_ADC16_IRQn);
        PRINTF("\r\nDAC ADC Demo!\r\n");
        PRINTF("\r\nPlease refer to Kinetis SDK Demo Applications User's Guide document,\r\n");
        PRINTF("\r\nChapter DAC ADC demo, for pins configuration information.\r\n");

     //
        PRINTF("\r\nPress any key to start demo.\r\n");
     //   GETCHAR();
        PRINTF("\r\nDemo begin...\r\n");
        DAC_ADC_Init();


    //init_adc();
GPIO_Init();

    while (1)
    {




    select_Mode(modo);
if(GPIO_ReadPinInput(GPIOB, MASTER_RESET_BUTTON)==0U)
{
	modo=1;
	numero=0;
}




    }
    }


    void select_Digit(uint32_t digit)

    {
    	           switch(digit)
    	        	{
    	        	case 1 :GPIOD->PDOR= (0X4);break;
    	        	case 2 :GPIOD->PDOR= (0X2);break;
    	        	case 3 :GPIOD->PDOR= (0X1);break;
    	        	case 4 :GPIOD->PDOR= (0X0);break;

    	        	}
    }


    void Digits(uint32_t contador)
    {
    switch(contador)
        	{
        	case 0 :GPIOC->PDOR= (0X40);break;
        	case 1 :GPIOC->PDOR= (0X79);break;
        	case 2 :GPIOC->PDOR= (0X24);break;
        	case 3 :GPIOC->PDOR= (0X30);break;
        	case 4 :GPIOC->PDOR= (0X19);break;
        	case 5 :GPIOC->PDOR= (0X12);break;
        	case 6 :GPIOC->PDOR= (0X2);break;
        	case 7 :GPIOC->PDOR= (0X78);break;
        	case 8 :GPIOC->PDOR= (0X0);break;
        	case 9 :GPIOC->PDOR= (0X18);break;
        	}

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




  void Init_Mode3(void)
    {
	  Led_Mode3();


	  g_Adc16ConversionDoneFlag = false;
	      	        ADC16_SetChannelConfig(DEMO_ADC16_BASEADDR, DEMO_ADC16_CHANNEL_GROUP, &g_adc16ChannelConfigStruct);

	      	        while (!g_Adc16ConversionDoneFlag)
	      	        {
	      	        }
	      	        PRINTF("\r\n\r\nADC Value: %d\r\n", g_Adc16ConversionValue);

	      	        /* Convert ADC value to a voltage based on 3.3V VREFH on board */
	      	        voltRead = (float)(g_Adc16ConversionValue * (VREF_BRD / SE_12BIT));
	      	        PRINTF("\r\nADC Voltage: %f\r\n", voltRead);
	      	        for(x=0; x<=5000;++x){
	      	          Cont_Reset();
	      	        unsigned short dec, uni,cent;

	      	        uni= (voltRead % 100u) % 10;
	      	                Digits(uni);
	      	                select_Digit(1);
	      	                select_Digit(4);




	      	                dec=(voltRead % 100u) / 10u;
	      	                Digits(dec);
	      	                select_Digit(2);
	      	                select_Digit(4);

	      	                cent=voltRead / 100u;
	      	                Digits(cent);
	      	                select_Digit(3);
	      	                select_Digit(4);

	      	        }


    }





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
    		if(modo>=4)
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

    void DAC_ADC_Init(void)
    {
        adc16_config_t adc16ConfigStruct;
        dac_config_t dacConfigStruct;

        /* Configure the DAC. */
        /*
         * dacConfigStruct.referenceVoltageSource = kDAC_ReferenceVoltageSourceVref2;
         * dacConfigStruct.enableLowPowerMode = false;
         */
        DAC_GetDefaultConfig(&dacConfigStruct);
        DAC_Init(DEMO_DAC_BASEADDR, &dacConfigStruct);
        DAC_Enable(DEMO_DAC_BASEADDR, true); /* Enable output. */

        /* Configure the ADC16. */
        /*
         * adc16ConfigStruct.referenceVoltageSource = kADC16_ReferenceVoltageSourceVref;
         * adc16ConfigStruct.clockSource = kADC16_ClockSourceAsynchronousClock;
         * adc16ConfigStruct.enableAsynchronousClock = true;
         * adc16ConfigStruct.clockDivider = kADC16_ClockDivider8;
         * adc16ConfigStruct.resolution = kADC16_ResolutionSE12Bit;
         * adc16ConfigStruct.longSampleMode = kADC16_LongSampleDisabled;
         * adc16ConfigStruct.enableHighSpeed = false;
         * adc16ConfigStruct.enableLowPower = false;
         * adc16ConfigStruct.enableContinuousConversion = false;
         */
        ADC16_GetDefaultConfig(&adc16ConfigStruct);
    #if defined(BOARD_ADC_USE_ALT_VREF)
        adc16ConfigStruct.referenceVoltageSource = kADC16_ReferenceVoltageSourceValt;
    #endif
        ADC16_Init(DEMO_ADC16_BASEADDR, &adc16ConfigStruct);

        /* Make sure the software trigger is used. */
        ADC16_EnableHardwareTrigger(DEMO_ADC16_BASEADDR, false);
    #if defined(FSL_FEATURE_ADC16_HAS_CALIBRATION) && FSL_FEATURE_ADC16_HAS_CALIBRATION
        if (kStatus_Success == ADC16_DoAutoCalibration(DEMO_ADC16_BASEADDR))
        {
            PRINTF("\r\nADC16_DoAutoCalibration() Done.");
        }
        else
        {
            PRINTF("ADC16_DoAutoCalibration() Failed.\r\n");
        }
    #endif /* FSL_FEATURE_ADC16_HAS_CALIBRATION */

        /* Prepare ADC channel setting */
        g_adc16ChannelConfigStruct.channelNumber = DEMO_ADC16_USER_CHANNEL;
        g_adc16ChannelConfigStruct.enableInterruptOnConversionCompleted = true;

    #if defined(FSL_FEATURE_ADC16_HAS_DIFF_MODE) && FSL_FEATURE_ADC16_HAS_DIFF_MODE
        g_adc16ChannelConfigStruct.enableDifferentialConversion = false;
    #endif /* FSL_FEATURE_ADC16_HAS_DIFF_MODE */
    }

    void DEMO_ADC16_IRQ_HANDLER_FUNC(void)
    {
        g_Adc16ConversionDoneFlag = true;
        /* Read conversion result to clear the conversion completed flag. */
        g_Adc16ConversionValue = ADC16_GetChannelConversionValue(DEMO_ADC16_BASEADDR, DEMO_ADC16_CHANNEL_GROUP);
    }







