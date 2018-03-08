/*
 * adc.c
 *
 *  Created on: Feb 22, 2018
 *      Author: Misael
 */


#include "adc.h"

void init_adc(void)



{
	adc16_config_t adc16ConfigStruct;

	 adc16ConfigStruct.referenceVoltageSource = kADC16_ReferenceVoltageSourceVref;
	 adc16ConfigStruct.clockSource = kADC16_ClockSourceAsynchronousClock;
	 adc16ConfigStruct.enableAsynchronousClock = 1;
	 adc16ConfigStruct.clockDivider = kADC16_ClockDivider8;
	 adc16ConfigStruct.resolution = kADC16_ResolutionSE12Bit;
	 adc16ConfigStruct.longSampleMode = kADC16_LongSampleCycle24;
	 adc16ConfigStruct.enableHighSpeed = 1;
	 adc16ConfigStruct.enableLowPower = 0;
	 adc16ConfigStruct.enableContinuousConversion = 1;

	ADC16_GetDefaultConfig(&adc16ConfigStruct);

	adc16_channel_config_t g_adc16ChannelConfigStruct;
	g_adc16ChannelConfigStruct.channelNumber = 0;
	g_adc16ChannelConfigStruct.enableInterruptOnConversionCompleted =0;

    ADC16_SetChannelConfig(ADC0, 0, &g_adc16ChannelConfigStruct);

	ADC16_Init(ADC0, &adc16ConfigStruct);



}



