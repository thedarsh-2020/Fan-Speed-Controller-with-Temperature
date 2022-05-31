/**************************************************************************************************
 *
 * Author      : Mustafa Muhammad
 *
 * Description : Fan Speed Controller with Temperature
 *
 **************************************************************************************************/

#include "lcd.h"
#include "adc.h"
#include "dc-motor.h"
#include "lm35_sensor.h"
#include "pwm.h"
#include "std_types.h"

int main(void)
{
	/*
	 * Temperature Value
	 */
	uint8 temp;

	/*
	 * Initialize the LCD
	 */
	LCD_init();
	LCD_displayStringRowColumn(0, 4, "FAN is ");
	LCD_displayStringRowColumn(1, 4, "Temp =    C");

	/*
	 * Initialize ADC to work with Prescaler F_CPU/8 & Internal Ref. Voltage (2.56 Volt)
	 */
	ADC_ConfigType ADC_Config = {Internal_AREFF, Prescaler_8};
	ADC_init(&ADC_Config);

	/*
	 * Initialize Fan DC-Motor
	 */
	DcMotor_Init();

	for(;;)
	{
		/*
		 * Get Temperature value from Sensor and converting it by ADC
		 */
		temp = LM35_getTemperature();

		/*
		 * According to Temperature, controlling Fan speed and state
		 * Showing Fan state (ON/OFF) & Temperature value on LCD
		 */
		if ((temp >= 0) && (temp < 30))
		{
			LCD_displayStringRowColumn(0, 11, "OFF");
			LCD_moveCursor(1, 11);
			if(temp < 10)
			{
				LCD_intgerToString(temp);
				LCD_displayCharacter(' ');
				LCD_displayCharacter(' ');
			}
			else
			{
				LCD_intgerToString(temp);
				LCD_displayCharacter(' ');
			}
			DcMotor_Rotate(STOP, 0);
		}
		else if ((temp >= 30) && (temp < 60))
		{
			LCD_displayStringRowColumn(0, 11, "ON ");
			LCD_moveCursor(1, 11);
			LCD_intgerToString(temp);
			LCD_displayCharacter(' ');
			DcMotor_Rotate(CW, 25);
		}
		else if ((temp >= 60) && (temp < 90))
		{
			LCD_displayStringRowColumn(0, 11, "ON ");
			LCD_moveCursor(1, 11);
			LCD_intgerToString(temp);
			LCD_displayCharacter(' ');
			DcMotor_Rotate(CW, 50);
		}
		else if ((temp >= 90) && (temp < 120))
		{
			LCD_displayStringRowColumn(0, 11, "ON ");
			LCD_moveCursor(1, 11);
			if (temp < 100)
			{
				LCD_intgerToString(temp);
				LCD_displayCharacter(' ');
			}
			else
			{
				LCD_intgerToString(temp);
			}
			DcMotor_Rotate(CW, 75);
		}
		else if (temp >= 120)
		{
			LCD_displayStringRowColumn(0, 11, "ON ");
			LCD_moveCursor(1, 11);
			LCD_intgerToString(temp);
			DcMotor_Rotate(CW, 100);
		}
		else
		{
			LCD_displayStringRowColumn(0, 4, "OFF");
			LCD_moveCursor(1, 11);
			LCD_intgerToString(0);
			DcMotor_Rotate(STOP, 0);
		}
	}
}
