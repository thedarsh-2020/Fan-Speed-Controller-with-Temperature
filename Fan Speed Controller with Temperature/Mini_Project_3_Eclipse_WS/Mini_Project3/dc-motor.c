/******************************************************************************
 *
 * Module: DC Motor
 *
 * Description: Source file for Fan DC-Motor
 *
 *******************************************************************************/

#include "dc-motor.h"
#include "gpio.h"
#include "common_macros.h"
#include <avr/io.h>
#include "pwm.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*
 * Description :
 * Function responsible Fan DC-Motor Initialization
 */
void DcMotor_Init(void)
{
	/*
	 * Set DC-Motor Pins as O/P
	 */
	GPIO_setupPinDirection(PORTB_ID, PIN0_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(PORTB_ID, PIN1_ID, PIN_OUTPUT);

	/*
	 * set PB3/OC0 as output pin --> pin where the PWM signal is generated from MC
	 */
	GPIO_setupPinDirection(PORTB_ID, PIN3_ID, PIN_OUTPUT);

	/*
	 * Set Initial state for the motor
	 */
	GPIO_writePin(PORTB_ID, PIN0_ID, LOGIC_LOW);
	GPIO_writePin(PORTB_ID, PIN1_ID, LOGIC_LOW);
}

/*
 * Description :
 * Function responsible Fan DC-Motor settings its state & speed
 */
void DcMotor_Rotate(uint8 state, uint8 speed)
{
	/*
	 * Set DC-Motor Pins according to state (CW, A-CW & STOP)
	 */
	PORTB = (PORTB & 0XFC) | (state & 0X03);

	/*
	 * Set DC-Motor speed using PWM
	 */
	PWM_Timer0_Start(speed);
}
