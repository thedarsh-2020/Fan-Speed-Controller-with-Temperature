/******************************************************************************
 *
 * Module: PWM
 *
 * Description: Source file for PWM
 *
 *******************************************************************************/

#include "pwm.h"
#include "std_types.h"
#include <avr/io.h>

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

static uint8 required_duty_cycle;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */
void PWM_Timer0_Start(uint8 duty_cycle)
{
	TCNT0 = 0; //Set Timer Initial value

	if(duty_cycle == 100)
	{
		/*
		 * Set Compare Value according to Duty Cycle
		 */
		OCR0  = 255;
	}
	else
	{
		/*
		 * Compare Value calculation according to Duty Cycle
		 */
		required_duty_cycle = (uint8) ( (duty_cycle * 256) / 100 );

		/*
		 * Set Compare Value according to Duty Cycle
		 */
		OCR0  = required_duty_cycle;
	}

	/* Configure timer control register
	 * 1. Fast PWM mode FOC0=0
	 * 2. Fast PWM Mode WGM01=1 & WGM00=1
	 * 3. Clear OC0 when match occurs (non inverted mode) COM00=0 & COM01=1
	 * 4. clock = F_CPU/8 CS00=0 CS01=1 CS02=0
	 */
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);
}
