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


#define PTB0 (8)
#define PTB1 (9)
#define PTB2 (12)
#define PTB3 (13)
#define PTC2 (11))
#define PTC1 (15)
//short adc_val;

void init_adc(void);


#endif /* ADC_H_ */
