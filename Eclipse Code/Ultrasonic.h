/******************************************************************************
*
* Module: Ultrasonic
*
* File Name: ultrasonic.h
*
* Description: Header file for the Ultrasonic driver
*
* Author: Amr Fahmy
*
*******************************************************************************/

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/* Define the ultrasonic sensor's trigger & Echo pins */
#define ULTRASONIC_TRIGGER_PORT_ID    PORTD_ID
#define ULTRASONIC_TRIGGER_PIN_ID     PIN7_ID

#define ULTRASONIC_ECHO_PORT_ID    PORTD_ID
#define ULTRASONIC_ECHO_PIN_ID     PIN6_ID

/*******************************************************************************
 *                      Functions Prototypes                                   *
*******************************************************************************/

/*
 * Initialize the ICU driver as required.
 * Set up the ICU callback function.
 * Set the direction for the trigger pin as output through
 * the GPIO driver
 */
void Ultrasonic_init(void);

/*
 * Send the trigger pulse to the ultrasonic sensor.
 */
void Ultrasonic_Trigger(void);

/*
 * Send the trigger pulse by using the Ultrasonic_Trigger
 * function.
 * Start the measurement process via the ICU driver.
 */
uint16 Ultrasonic_Read_Distance(void);

/*
 * This is the callback function called by the ICU driver.
 * It calculates the high time (pulse time) generated by
 * the ultrasonic sensor.
 */
void Ultrasonic_Edge_Processing(void);


#endif /* ULTRASONIC_H_ */
