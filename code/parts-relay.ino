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
 ** Relay:
 *** Arduino UNO GPIO D<2;13> <=> Relay
 *** GROUND                   <=> Relay
 */

/* Docs:
 ** Arduino Uno:
 *** https://store.arduino.cc/products/arduino-uno-rev3/
 ** Relay:
 *** https://arduinogetstarted.com/tutorials/arduino-relay
 */ 

/* Theory:
 ** Relay:
 *** Relay is OFF = 1 (HIGH)
 *** Relay is ON = 0 (LOW)
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


/* Turn the Relay OFF */
void relayTurnOff() {
  unsigned char relay_state = digitalRead(RELAY_PIN);
  digitalWrite(RELAY_PIN, HIGH);
  Serial.print("Relay is in state: ");
  Serial.print(relay_state);
  Serial.print(" (OFF)\n");
}


/* Turn the Relay ON */
void relayTurnOn() {
  unsigned char relay_state = digitalRead(RELAY_PIN);
  digitalWrite(RELAY_PIN, LOW);
  Serial.print("Relay is in state: ");
  Serial.print(relay_state);
  Serial.print(" (ON)\n");
}


void loop() {
  //Placeholder
}
