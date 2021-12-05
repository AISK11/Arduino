/************************************************
 * Author: AISK11                               *
 * Description: code to toggle (ON/OFF) BUTTON. *
 * Date Created: 2021-11-30                     *
 * Last Updated: 2021-12-05                     *
 ************************************************/
/* Arduino IDE Set up:
 ** Tools -> Port -> /dev/ttyACM0
 ** Tools -> Board -> Arduino Uno
 */

/* Docs:
 ** Arduino Uno:
 *** https://store.arduino.cc/products/arduino-uno-rev3/
 ** Button:
 *** https://arduinogetstarted.com/tutorials/arduino-button
 */ 

/* Schematic:
 ** Button:
 *** Arduino UNO GPIO D<2;13> <=> Button
 *** Arduino UNO GROUND       <=> Button
 */

/* Theory:
 ** Button:
 *** Button is Free    = 1 (HIGH)
 *** Button is Pressed = 0 (LOW)
 */


#define PIN_BUTTON 2 /* GPIO <2;13> pin connected to Button */


/* Previous state from the input pin, initial HIGH -> start in OFF. */
unsigned char _btn_last_state = HIGH;
/* Current reading from the input pin. */
unsigned char _btn_current_state;
/* Button is OFF on the start. */
unsigned char _btn_state = 0;


void setup() {
  /* Initialize serial communication at 9600 bits per second. */
  Serial.begin(9600);

  /* Initialize the Button pin as an pull-up input
   * the pull-up input pin will be HIGH when the switch 
   * is open and LOW when the switch is closed
   * (good for DIGITAL INPUT devices). */
  pinMode(PIN_BUTTON, INPUT_PULLUP);
}


void loop() {
  checkButtonPress();
}


/* This function executes, when User presses
 * button (but code is executed on release of the button.
 * Something like Unity C# OnKeyUP(). */
void checkButtonPress() {
  /* Read the current state of the switch/button. */
  _btn_current_state = digitalRead(PIN_BUTTON);
  
  /* If previous state was LOW (pressed) and current is HIGH (free). */
  if(_btn_last_state == LOW && _btn_current_state == HIGH) {
    /* Change Button state. */
    if (_btn_state) {
      /* If previously state was ON, now is OFF. */
      _btn_state = 0;
      /* Execute code for button OFF state. */
      btnIsOff(); 
    }
    else {
      /* If previously state was OFF, now is ON. */
      _btn_state = 1;
      /* Execute code for button ON state. */
      btnIsOn();
    }
    /* Added delay, to prevent mutliple press detection in single press. */
    delay(50);
  }

  /* Update last state, so event is not executed
   * multiple times during single button press. */
  _btn_last_state = _btn_current_state;
}


/* This function executes, when button state is 1 (ON). */
void btnIsOff() {
  Serial.print("Button is in state: ");
  Serial.print(_btn_state);
  Serial.print(" (OFF)\n");
}


/* This function executes, when button state is 0 (OFF). */
void btnIsOn() {
  Serial.print("Button is in state: ");
  Serial.print(_btn_state);
  Serial.print(" (ON)\n");
}


/* Note: Working but fine, but will revise later */
