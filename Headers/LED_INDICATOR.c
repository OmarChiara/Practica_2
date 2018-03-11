/*
 * LED_INDICATOR.c
 *
 *  Created on: Feb 22, 2018
 *      Author: Misael
 */


#include "stdint.h"
#include "LED_INDICATOR.h"
#include "fsl_clock.h"
#include "mkl25z4.h"
#include "fsl_port.h"
#include "fsl_gpio.h"


void Led_Mode1(void)
{



	port_pin_config_t ls_LedMode1PinMux;
	ls_LedMode1PinMux.mux = kPORT_MuxAsGpio;

	PORT_SetPinConfig(PORTB,LED_MODE_1, &ls_LedMode1PinMux);
gpio_pin_config_t ls_LedMode1PinCfg;

ls_LedMode1PinCfg.pinDirection = kGPIO_DigitalOutput;
ls_LedMode1PinCfg.outputLogic= FALSE;

//PIN Initialization
GPIO_PinInit(GPIOB, LED_MODE_1,&ls_LedMode1PinCfg);
GPIO_WritePinOutput(GPIOB, LED_MODE_2,1);
GPIO_WritePinOutput(GPIOB, LED_MODE_1,0);

}
void Led_Mode2(void)
{
//PORTB clock enable
//	CLOCK_EnableClock(kCLOCK_PortB);
//PIN Mux
   port_pin_config_t ls_LedMode1PinMux;
	ls_LedMode1PinMux.mux = kPORT_MuxAsGpio;

	PORT_SetPinConfig(PORTB,LED_MODE_1, &ls_LedMode1PinMux);
gpio_pin_config_t ls_LedMode1PinCfg;

ls_LedMode1PinCfg.pinDirection = kGPIO_DigitalOutput;
ls_LedMode1PinCfg.outputLogic= 0;


/*	port_pin_config_t ls_LedMode2PinMux;
	ls_LedMode2PinMux.mux = kPORT_MuxAsGpio;

	PORT_SetPinConfig(PORTB,LED_MODE_2, &ls_LedMode2PinMux);
gpio_pin_config_t ls_LedMode2PinCfg;

ls_LedMode2PinCfg.pinDirection = kGPIO_DigitalOutput;
ls_LedMode2PinCfg.outputLogic= FALSE; */

//PIN Initialization


GPIO_PinInit(GPIOB, LED_MODE_1,&ls_LedMode1PinCfg);

GPIO_WritePinOutput(GPIOB, LED_MODE_2,1);
GPIO_WritePinOutput(GPIOB, LED_MODE_1,1);

}

void Led_Mode3(void)
{



	port_pin_config_t ls_LedMode1PinMux;
	ls_LedMode1PinMux.mux = kPORT_MuxAsGpio;

	PORT_SetPinConfig(PORTB,LED_MODE_2, &ls_LedMode1PinMux);
gpio_pin_config_t ls_LedMode1PinCfg;

ls_LedMode1PinCfg.pinDirection = kGPIO_DigitalOutput;
ls_LedMode1PinCfg.outputLogic= FALSE;

//PIN Initialization
GPIO_PinInit(GPIOB, LED_MODE_2,&ls_LedMode1PinCfg);
GPIO_WritePinOutput(GPIOB, LED_MODE_1,1);
GPIO_WritePinOutput(GPIOB, LED_MODE_2,0);

}

void Init_Led1(void)
{
	port_pin_config_t ls_LedMode1PinMux;
		ls_LedMode1PinMux.mux = kPORT_MuxAsGpio;

		PORT_SetPinConfig(PORTB,LED_MODE_1, &ls_LedMode1PinMux);
	gpio_pin_config_t ls_LedMode1PinCfg;

	ls_LedMode1PinCfg.pinDirection = kGPIO_DigitalOutput;
	ls_LedMode1PinCfg.outputLogic= 1;

	//PIN Initialization
	GPIO_PinInit(GPIOB, LED_MODE_1,&ls_LedMode1PinCfg);



}

void Init_Led2(void)
{

	port_pin_config_t ls_LedMode1PinMux;
			ls_LedMode1PinMux.mux = kPORT_MuxAsGpio;

			PORT_SetPinConfig(PORTB,LED_MODE_1, &ls_LedMode1PinMux);
			PORT_SetPinConfig(PORTB,LED_MODE_2, &ls_LedMode1PinMux);
			gpio_pin_config_t ls_LedMode1PinCfg;

			ls_LedMode1PinCfg.pinDirection = kGPIO_DigitalOutput;
			ls_LedMode1PinCfg.outputLogic= 1;

			//PIN Initialization
			GPIO_PinInit(GPIOB, LED_MODE_2,&ls_LedMode1PinCfg);
}

void Init_Led3(void)
{
	port_pin_config_t ls_LedMode1PinMux;
		ls_LedMode1PinMux.mux = kPORT_MuxAsGpio;

		PORT_SetPinConfig(PORTB,LED_MODE_2, &ls_LedMode1PinMux);
	gpio_pin_config_t ls_LedMode1PinCfg;

	ls_LedMode1PinCfg.pinDirection = kGPIO_DigitalOutput;
	ls_LedMode1PinCfg.outputLogic= 1;

	//PIN Initialization
	GPIO_PinInit(GPIOB, LED_MODE_2,&ls_LedMode1PinCfg);
	GPIO_WritePinOutput(GPIOB, LED_MODE_1,1);
}
