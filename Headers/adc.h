/*
 * adc.h
 *
 *  Created on: Feb 22, 2018
 *      Author: Misael
 */

#ifndef ADC_H_
#define ADC_H_

#include "MKL25Z4.h"
#include "fsl_adc16.h"
#include "fsl_dac.h"

#define DEMO_ADC16_BASEADDR ADC0
#define DEMO_ADC16_CHANNEL_GROUP 0U
#define DEMO_ADC16_USER_CHANNEL 0U /* PTE20, ADC0_SE0 */
#define DEMO_DAC_BASEADDR DAC0

#define DEMO_ADC16_IRQn ADC0_IRQn
#define DEMO_ADC16_IRQ_HANDLER_FUNC ADC0_IRQHandler
#define DAC_1_0_VOLTS 1241U
#define DAC_1_5_VOLTS 1862U
#define DAC_2_0_VOLTS 2482U
#define DAC_2_5_VOLTS 3103U
#define DAC_3_0_VOLTS 3724U

#define VREF_BRD 330
#define SE_12BIT 4096.0


#endif /* ADC_H_ */
