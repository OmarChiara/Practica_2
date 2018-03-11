/*
 * GPIO.h
 *
 *  Created on: Feb 22, 2018
 *      Author: Misael
 */

#ifndef GPIO_H_
#define GPIO_H_

#define RESET_BUTTON ((uint32_t) 0u)
#define INC_BUTTON   ((uint32_t) 1u)
#define DEC_BUTTON   ((uint32_t) 2u)
#define MASTER_RESET_BUTTON   ((uint32_t) 3u)


#define BCD_SEG_A  ((uint32_t) 0u)
#define BCD_SEG_B  ((uint32_t) 1u)
#define BCD_SEG_C  ((uint32_t) 2u)
#define BCD_SEG_D  ((uint32_t) 3u)
#define BCD_SEG_E  ((uint32_t) 4u)
#define BCD_SEG_F  ((uint32_t) 5u)
#define BCD_SEG_G  ((uint32_t) 6u)
#define MAX_VALUE ((uint32_t) 100u)
#define MIN_VALUE ((uint32_t) 0u)

#endif /* GPIO_H_ */


void GPIO_Init(void);
