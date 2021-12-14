/************************************************
 * Author: AISK11                               *
 * Description: code to get distance value      *
 *              from HCSR04 sensor.             *
 * Date Created: 2021-12-14                     *
 * Last Updated: 2021-12-14                     *
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
/* Sensor distance pointer. */ 
double* _hcsr_distances;


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
  //Serial.println(hcsr_distance_cm(_hcsr_distances));
  //Serial.println(hcsr_distance_mm(_hcsr_distances));
  //Serial.println(hcsr_distance_in(_hcsr_distances));
}


/************************
 ** Program Functions  ** 
 ************************/
/* Function returns distance in centimeters. */
double hcsr_distance_cm(double* distance) {
  /* Get distance from sensor in centimeters. */
  distance = HCSR04.measureDistanceCm();

  /* Return first (and only) value from pointer "_hcsr_distances". */
  return distance[0];
}


/* Function returns distance in milimeters. */
double hcsr_distance_mm(double* distance) {
  /* Get distance from sensor in centimeters * 1000 = milimeters. */
  double distance_mm = hcsr_distance_cm(distance) * 1000;
 
  /* Return distance in milimeters. */
  return distance_mm;
}


/* Function returns distance in inches. */
double hcsr_distance_in(double* distance) {
  /* Get distance from sensor in centimeters * 0.39370078740157 = inches. */
  double distance_in = hcsr_distance_cm(distance) * 0.39370078740157;
 
  /* Return distance in inches. */
  return distance_in;
}
