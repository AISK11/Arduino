/************************************************
 * Author: AISK11                               *
 * Description: code to toggle (ON/OFF) RELAY.  *
 * Date Created: 2021-12-01                     *
 * Last Updated: 2021-12-01                     *
 ************************************************/
/* Arduino IDE Set up:
 ** Tools -> Port -> /dev/ttyACM0
 ** Tools -> Board -> Arduino Uno
 */

/* Schematic:
 ** Arduino UNO GPIO D<2;13> <=> Relay
 ** GROUND                   <=> Relay
 */

/* Docs:
 ** Arduino Uno:
 *** https://store.arduino.cc/products/arduino-uno-rev3/
 ** Relay:
 *** https://arduinogetstarted.com/tutorials/arduino-relay
 */ 

/* Theory:
 ** Relay is OFF = 1 (HIGH)
 ** Relay is ON = 0 (LOW)
 */


#define RELAY_PIN 3  /* GPIO <2;13> pin connected to Relay INPUT */


void setup() {
  /* initialize serial communication at 9600 bits per second */
  Serial.begin(9600);

  /* initialize the Relay input pin as OUTPUT */
  pinMode(RELAY_PIN, OUTPUT);
  
  /* Start relay in off state (OFF = HIGH) */
  relayTurnOff();
}


void relayTurnOff() {
  Serial.println("Relay is OFF.");
  digitalWrite(RELAY_PIN, HIGH);
}


void relayTurnOn() {
  Serial.println("Relay is ON.");
  digitalWrite(RELAY_PIN, LOW);
}


void loop() {
  //Placeholder
}
