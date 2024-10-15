#include "LCD.h"
#include "Ultrasonic.h"
#include "Led.h"
#include "ICU.h"
#include "Buzzer.h"
#include <util/delay.h>
#include "avr/io.h"
#include <avr/interrupt.h>

int main(void)
{

	sei();
	uint16 Distance_Value = 0;
	Buzzer_init();
	LCD_init();
	LEDS_init();
	Ultrasonic_init();



	LCD_moveCursor(0, 0);
	LCD_displayString("Distance =  ");

do{

	Distance_Value = Ultrasonic_Read_Distance();


} while(Distance_Value == 1);



	while(1)
	{
		Distance_Value = Ultrasonic_Read_Distance();

		LCD_moveCursor(0, 11);
		LCD_intgerToString(Distance_Value);
		LCD_displayString(" CM  ");

		if (Distance_Value > 20)
		{
			Buzzer_off();
			LED_off(LED_RED);
			LED_off(LED_GREEN);
			LED_off(LED_BLUE);

			LCD_moveCursor(1, 5);
			LCD_displayString("     ");
		}
		else if (15 < Distance_Value && Distance_Value <= 20)
		{
			Buzzer_off();
			LED_on(LED_RED);
			LED_off(LED_GREEN);
			LED_off(LED_BLUE);

			LCD_moveCursor(1, 5);
			LCD_displayString("     ");
		}
		else if ( 10 < Distance_Value && Distance_Value <= 15)
		{
			Buzzer_off();
			LED_on(LED_RED);
			LED_on(LED_GREEN);
			LED_off(LED_BLUE);

			LCD_moveCursor(1, 5);
			LCD_displayString("     ");
		}
		else if (5 < Distance_Value && Distance_Value <= 10)
		{
			Buzzer_off();
			LED_on(LED_RED);
			LED_on(LED_GREEN);
			LED_on(LED_BLUE);

			LCD_moveCursor(1, 5);
			LCD_displayString("     ");
		}
		else if (Distance_Value <= 5)
		{
			Buzzer_on();

			LED_on(LED_RED);
			LED_on(LED_GREEN);
			LED_on(LED_BLUE);
			_delay_ms(400);
			LED_off(LED_RED);
			LED_off(LED_GREEN);
			LED_off(LED_BLUE);
			_delay_ms(400);

			LCD_moveCursor(1, 5);
			LCD_displayString("STOP!");
		}

	}

	return 0;
}
