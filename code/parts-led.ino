/* Arduino IDE Set up:
 ** Tools -> Port -> /dev/ttyACM0
 ** Tools -> Board -> Arduino Uno
 */

/* Docs:
 ** Arduino Uno:
 *** https://store.arduino.cc/products/arduino-uno-rev3/
 ** LED:
 *** https://roboticsbackend.com/arduino-led-complete-tutorial/
 */

/* Schematic:
 ** LED:
 *** Arduino UNO GROUND       <=> LED (-) AKA Shoreter leg
 *** Arduino UNO GPIO D<2;13> <=> Resistor 220 Ohm <=> LED (+) AKA Longer leg 
 */

/* Theory:
 ** LED:
 *** Longer leg:  Anode  (+)
 *** Shorter leg: Catode (-)
 *** LED is ON  = HIGH (1)
 *** LED IS OFF = LOW  (0)
 */


#define PIN_LED 4 /* GPIO <2;13> pin connected to LED (+) AKA Longer leg */


unsigned char led_state = LOW; /* start LED in turned off STATE */


void setup() {
  /* initialize serial communication at 9600 bits per second */
  Serial.begin(9600);

  /* initialize the LED (+) pin as OUTPUT */
  pinMode(PIN_LED, OUTPUT);

  /* start LED in turned off STATE */
  digitalWrite(PIN_LED, led_state);
}


/* Turns the LED On */
void turnLedOn() {
  led_state = HIGH;
  digitalWrite(PIN_LED, led_state);
}


/* Turns the LED Off */
void turnLedOff() {
  led_state = LOW;
  digitalWrite(PIN_LED, led_state);
}


/* Toggle LED to opposite state */
void turnLedToggle() {
  if(led_state) {
    led_state = LOW;
  }
  else {
    led_state = HIGH;
  }
  digitalWrite(PIN_LED, led_state);
}


void loop() {
  //turnLedToggle();
  //delay(1500);
}
