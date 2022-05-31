/******************************************************************************
 *
 * Module: PWM
 *
 * Description: Header file for PWM
 *
 *******************************************************************************/

#ifndef PWM_H_
#define PWM_H_

#include "gpio.h"

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for PWM initialize.
 */
void PWM_Timer0_Start(uint8 duty_cycle);

#endif /* PWM_H_ */
