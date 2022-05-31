/******************************************************************************
 *
 * Module: DC Motor
 *
 * Description: header file for Fan DC-Motor
 *
 *******************************************************************************/

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_


#include "std_types.h"

/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/

/*
 * enum to define Fan state
 */
typedef enum
{
	STOP, CW, A_CW
}DcMotor_State;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible Fan DC-Motor Initialization
 */
void DcMotor_Init(void);

/*
 * Description :
 * Function responsible Fan DC-Motor settings its state & speed
 */
void DcMotor_Rotate(DcMotor_State state,uint8 speed);

#endif /* DC_MOTOR_H_ */
