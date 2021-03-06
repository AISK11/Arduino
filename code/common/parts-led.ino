/************************************************
 * Author: AISK11                               *
 * Description: function to provide delay, but  *
 *              other code can still run.       *
 * Date Created: 2021-12-01                     *
 * Last Updated: 2021-12-13                     *
 ************************************************/
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
 *** Arduino UNO GROUND       <=> LED (-) AKA Shorter leg
 *** Arduino UNO GPIO D<2;13> <=> Resistor 220 Ohm <=> LED (+) AKA Longer leg
 */

/* Theory:
 ** LED:
 *** Longer leg:  Anode  (+)
 *** Shorter leg: Catode (-)
 *** LED is ON  = HIGH (1)
 *** LED IS OFF = LOW  (0)
 */


/************************
 **     GPIO Pins      ** 
 ************************/
/* GPIO <2;13> pin connected to LED (+) AKA Longer leg. */
static const unsigned char PIN_LED = 5;


/************************
 **  Public Variables  ** 
 ************************/
/* Start LED in turned OFF (LOW) state. */
unsigned char _led_state = LOW;


/************************
 ** Arduino Functions  ** 
 ************************/
void setup() {
  /* Initialize serial communication at 9600 bits per second. */
  Serial.begin(9600);

  /* Initialize the LED (+) pin as OUTPUT. */
  pinMode(PIN_LED, OUTPUT);

  /* Start LED in turned off STATE. */
  digitalWrite(PIN_LED, _led_state);
}


void loop() {
  //turnLedOn(PIN_LED);
  //turnLedOff(PIN_LED);
  //turnLedToggle(PIN_LED);
  //setLedBrightness(PIN_LED, 128);
}


/************************
 ** Program Functions  ** 
 ************************/
/* Turns the LED ON. */
void turnLedOn(const unsigned char pin_led) {
  /* Change LED status to ON (HIGH). */
  _led_state = HIGH;
  /* Turn ON LED. */
  digitalWrite(pin_led, _led_state);
}


/* Turns the LED OFF. */
void turnLedOff(const unsigned char pin_led) {
  /* Change LED status to OFF (HIGH). */
  _led_state = LOW;
  /* Turn OFF LED. */
  digitalWrite(pin_led, _led_state);
}


/* Toggle LED to opposite state. */
void turnLedToggle(const unsigned char pin_led) {
  if(_led_state) {
    _led_state = LOW;
  }
  else {
    _led_state = HIGH;
  }

  /* Put LED to opposite state. */
  digitalWrite(pin_led, _led_state);
}


/* setLedBrightness(),
 * REQUIRES PWM (Arduino PIN with '~'). */
void setLedBrightness(const unsigned char pin_led, unsigned char set_brightness) {
  /* Set LED brightness from interval <0;255>
   ** 0   = OFF
   ** 255 = MAX brightness AKA digitalWrite(PIN_LED, 1) */
  analogWrite(pin_led, set_brightness);
}
