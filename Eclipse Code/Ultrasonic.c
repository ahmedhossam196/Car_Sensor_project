#include "Ultrasonic.h"
#include "ICU.h"
#include "GPIO.h"
#include <util/delay.h>


uint16 g_timePulse = 0;
uint8  g_edgeCount = 0;

ICU_ConfigType ICU_config = {
		F_CPU_8,
		RAISING
};


void Ultrasonic_init(void)
{
	ICU_init(&ICU_config);
	ICU_setCallBack(Ultrasonic_Edge_Processing);
	GPIO_setupPinDirection(ULTRASONIC_TRIGGER_PORT_ID, ULTRASONIC_TRIGGER_PIN_ID, PIN_OUTPUT);
}


void Ultrasonic_Trigger(void)
{
	GPIO_writePin(ULTRASONIC_TRIGGER_PORT_ID, ULTRASONIC_TRIGGER_PIN_ID, LOGIC_HIGH);
	_delay_us(20);
	GPIO_writePin(ULTRASONIC_TRIGGER_PORT_ID, ULTRASONIC_TRIGGER_PIN_ID, LOGIC_LOW);
}


uint16 Ultrasonic_Read_Distance(void)
{

	uint16 distance = 0;
	Ultrasonic_Trigger();
	 distance = (uint16)(g_timePulse / 117.6) + 1;

	return distance;
}


void Ultrasonic_Edge_Processing(void)
{
	g_edgeCount++;

	switch(g_edgeCount)
	{
	case 1:
		ICU_clearTimerValue();
		ICU_setEdgeDetectionType(FALLING);
		break;
	case 2:
		g_timePulse = ICU_getInputCaptureValue();
		ICU_clearTimerValue();
		ICU_setEdgeDetectionType(RAISING);
		g_edgeCount = 0;
		break;
	}
}
