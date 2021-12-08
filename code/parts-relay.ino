/************************************************
 * Author: AISK11                               *
 * Description: code to toggle (ON/OFF) RELAY.  *
 * Date Created: 2021-12-01                     *
 * Last Updated: 2021-12-08                     *
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


/************************
 **     GPIO Pins      ** 
 ************************/
/* GPIO <2;13> pin connected to Relay INPUT. */
static const unsigned char PIN_RELAY = 3;


/************************
 ** Arduino Functions  ** 
 ************************/
void setup() {
  /* Initialize serial communication at 9600 bits per second. */
  Serial.begin(9600);

  /* Initialize the Relay input pin as OUTPUT. */
  pinMode(PIN_RELAY, OUTPUT);
  
  /* Start relay in off state (OFF = HIGH). */
  relayTurnOff(PIN_RELAY);
}


void loop() {
  //relayTurnOff(PIN_RELAY);
  //relayTurnOn(PIN_RELAY);
}


/************************
 ** Program Functions  ** 
 ************************/
/* Turn the Relay OFF. */
void relayTurnOff(const unsigned char pin_relay) {
  /* Sets: OFF = 1 (HIGH). */
  digitalWrite(pin_relay, HIGH);
  /* Reads 1 (OFF). */
  unsigned char relay_state = digitalRead(pin_relay);
  
  Serial.print("Relay is in state: ");
  Serial.print(relay_state);
  Serial.print(" (OFF)\n");
}


/* Turn the Relay ON. */
void relayTurnOn(const unsigned char pin_relay) {
  /* Sets: ON = 0 (LOW). */
  digitalWrite(pin_relay, LOW);
  /* Reads 0 (ON). */
  unsigned char relay_state = digitalRead(pin_relay);
  
  Serial.print("Relay is in state: ");
  Serial.print(relay_state);
  Serial.print(" (ON)\n");
}
