/************************************************
 * Author: AISK11                               *
 * Description: code to toggle (ON/OFF) RELAY.  *
 * Date Created: 2021-12-01                     *
 * Last Updated: 2021-12-05                     *
 ************************************************/
/* Arduino IDE Set up:
 ** Tools -> Port -> /dev/ttyACM0
 ** Tools -> Board -> Arduino Uno
 */

/* Docs:
 ** Arduino Uno:
 *** https://store.arduino.cc/products/arduino-uno-rev3/
 ** Relay:
 *** https://arduinogetstarted.com/tutorials/arduino-relay
 */ 

/* Schematic:
 ** Relay:
 *** Arduino UNO 5V           <=> Relay VCC
 *** Arduino UNO GPIO D<2;13> <=> Relay IN
 *** Arduino UNO GROUND       <=> Relay GND
 */

/* Theory:
 ** Relay:
 *** Relay is OFF = 1 (HIGH) AKA 5V ; green LED is OFF
 *** Relay is ON  = 0 (LOW)  AKA 0V ; green LED is ON
 */


/* GPIO <2;13> pin connected to Relay INPUT. */
#define PIN_RELAY 3


void setup() {
  /* Initialize serial communication at 9600 bits per second. */
  Serial.begin(9600);

  /* Initialize the Relay input pin as OUTPUT. */
  pinMode(PIN_RELAY, OUTPUT);
  
  /* Start relay in off state (OFF = HIGH). */
  relayTurnOff();
}


void loop() {
  //Placeholder
}


/* Turn the Relay OFF. */
void relayTurnOff() {
  /* Sets: OFF = 1 (HIGH). */
  digitalWrite(PIN_RELAY, HIGH);
  /* Reads 1 (OFF). */
  unsigned char relay_state = digitalRead(PIN_RELAY);
  
  Serial.print("Relay is in state: ");
  Serial.print(relay_state);
  Serial.print(" (OFF)\n");
}


/* Turn the Relay ON. */
void relayTurnOn() {
  /* Sets: ON = 0 (LOW). */
  digitalWrite(PIN_RELAY, LOW);
  /* Reads 0 (ON). */
  unsigned char relay_state = digitalRead(PIN_RELAY);
  
  Serial.print("Relay is in state: ");
  Serial.print(relay_state);
  Serial.print(" (ON)\n");
}
