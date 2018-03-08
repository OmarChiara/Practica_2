/*
 * GPIO.c
 *
 *  Created on: Feb 22, 2018
 *      Author: Misael
 */


#include "fsl_gpio.h"
#include "GPIO.h"
#include "fsl_port.h"
#include "BCD.h"

    	//PORTB and PORTC clock enable
void GPIO_Init(void)

{

    	CLOCK_EnableClock(kCLOCK_PortB);
    	CLOCK_EnableClock(kCLOCK_PortC);
    	CLOCK_EnableClock(kCLOCK_PortD);
    	CLOCK_EnableClock(kCLOCK_Adc0);
    	//PIN MUX B

    	port_pin_config_t ls_portb_mux;
    	ls_portb_mux.mux = kPORT_MuxAsGpio;
    	ls_portb_mux.pullSelect = kPORT_PullUp;

    		PORT_SetPinConfig(PORTB,RESET_BUTTON, &ls_portb_mux);
    		PORT_SetPinConfig(PORTB,INC_BUTTON, &ls_portb_mux);
    		PORT_SetPinConfig(PORTB,DEC_BUTTON, &ls_portb_mux);
    		PORT_SetPinConfig(PORTB,3, &ls_portb_mux);
    	//PIN MUX C

    	port_pin_config_t ls_portc_mux;
    	ls_portc_mux.mux = kPORT_MuxAsGpio;
    	ls_portc_mux.pullSelect = kPORT_PullUp;

    		PORT_SetPinConfig(PORTC,BCD_SEG_A, &ls_portc_mux);
    		PORT_SetPinConfig(PORTC,BCD_SEG_B, &ls_portc_mux);
    		PORT_SetPinConfig(PORTC,BCD_SEG_C, &ls_portc_mux);
    		PORT_SetPinConfig(PORTC,BCD_SEG_D, &ls_portc_mux);
    		PORT_SetPinConfig(PORTC,BCD_SEG_E, &ls_portc_mux);
    		PORT_SetPinConfig(PORTC,BCD_SEG_F, &ls_portc_mux);
    		PORT_SetPinConfig(PORTC,BCD_SEG_G, &ls_portc_mux);


    	//PIN MUX D

    		port_pin_config_t ls_portd_mux;
    		ls_portd_mux.mux = kPORT_MuxAsGpio;
    		ls_portd_mux.pullSelect = kPORT_PullUp;

       	   PORT_SetPinConfig(PORTD,CENTENAS, &ls_portd_mux);
        	PORT_SetPinConfig(PORTD,DECENAS, &ls_portd_mux);
        	PORT_SetPinConfig(PORTD,UNIDADES, &ls_portd_mux);




    	//PORT B AS INPUT
    		gpio_pin_config_t ls_portbcfg;

    		ls_portbcfg.pinDirection = kGPIO_DigitalInput;
    		ls_portbcfg.outputLogic= 0u;


    		GPIO_PinInit(GPIOB, RESET_BUTTON,&ls_portbcfg);
    		GPIO_PinInit(GPIOB, INC_BUTTON,&ls_portbcfg);
    		GPIO_PinInit(GPIOB, DEC_BUTTON,&ls_portbcfg);
    		GPIO_PinInit(GPIOB, 3,&ls_portbcfg);

    		//PORT C AS INPUT
    		gpio_pin_config_t ls_portccfg;

    		ls_portccfg.pinDirection = kGPIO_DigitalOutput;
    		ls_portccfg.outputLogic= 1u;

    		GPIO_PinInit(GPIOC,BCD_SEG_A, &ls_portccfg);
    		GPIO_PinInit(GPIOC,BCD_SEG_B, &ls_portccfg);
    		GPIO_PinInit(GPIOC,BCD_SEG_C, &ls_portccfg);
    		GPIO_PinInit(GPIOC,BCD_SEG_D, &ls_portccfg);
    		GPIO_PinInit(GPIOC,BCD_SEG_E, &ls_portccfg);
    		GPIO_PinInit(GPIOC,BCD_SEG_F, &ls_portccfg);
    		GPIO_PinInit(GPIOC,BCD_SEG_G, &ls_portccfg);

    		//PORT D AS INPUT
            	gpio_pin_config_t ls_portdcfg;

    		   ls_portdcfg.pinDirection = kGPIO_DigitalOutput;
    		   ls_portdcfg.outputLogic= 1u;


       		GPIO_PinInit(GPIOD,CENTENAS, &ls_portdcfg);
       		GPIO_PinInit(GPIOD,DECENAS, &ls_portdcfg);
       		GPIO_PinInit(GPIOD,UNIDADES, &ls_portdcfg);



}
