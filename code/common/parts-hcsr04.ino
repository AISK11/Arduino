/* Work In Progress... */

/************************************************
 * Author: AISK11                               *
 * Description: code to get distance value      *
 *              from HCSR04 sensor.             *
 * Date Created: YYYY-MM-dd                     *
 * Last Updated: YYYY-MM-dd                     *
 ************************************************/
/* Arduino IDE Set up:
 ** Tools -> Port -> /dev/ttyACM0
 ** Tools -> Board -> Arduino Uno
 */

/* Docs:
 ** Arduino Uno:
 *** https://store.arduino.cc/products/arduino-uno-rev3/
 ** HC-SR04:
 *** https://create.arduino.cc/projecthub/abdularbi17/ultrasonic-sensor-hc-sr04-with-arduino-tutorial-327ff6
 */

/* Schematic:
 ** HC-SR04:
 *** Arduino UNO 5V     <=> HCSR04 VCC
 *** Arduino UNO <2;13> <=> HCSR04 Trig
 *** Arduino UNO <2;13> <=> HCSR04 Echo
 *** Arduino UNO GROUND <=> HCSR04 GND
 */

/* Library:
 ** Download "HC-SR04" lib:
 *** Sketch -> Include Library -> Manage Libraries -> "HC-SR04"
 */


/************************
 **     Libraries      ** 
 ************************/
/* Import HC-SR04 library. */
#include <HCSR04.h>


/************************
 **     GPIO Pins      ** 
 ************************/
/* GPIO <2;13> pin connected to HCSR04 Trig. */
static const unsigned char PIN_HCSR04_TRIG = 10;
/* GPIO <2;13> pin connected to HCSR04 Echo. */
static const unsigned char PIN_HCSR04_ECHO = 11;


/************************
 **  Public Variables  ** 
 ************************/
double _hcsr_distance;


/************************
 ** Arduino Functions  ** 
 ************************/
void setup() {
  /* Initialize serial communication at 9600 bits per second. */
  Serial.begin(9600);

  /* Initialize HCSR04 sensor. */
  HCSR04.begin(PIN_HCSR04_TRIG, PIN_HCSR04_ECHO);
}


void loop() {
  //Serial.println(HCSR04.measureDistanceMm(_hcsr_distance));
  //HCSR04.measureDistanceCm(distances);
  //HCSR04.measureDistanceIn(distances);
}


/************************
 ** Program Functions  ** 
 ************************/
