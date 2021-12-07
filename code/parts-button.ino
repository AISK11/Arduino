/************************************************
 * Author: AISK11                               *
 * Description: code to toggle (ON/OFF) BUTTON. *
 * Date Created: 2021-11-30                     *
 * Last Updated: 2021-12-07                     *
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


/* When button is FREE, then INPUT PIN reads HIGH (1),
 * when button is PRESSED, then INPUT PIN reads LOW (0),
 * IF THIS IS REVERSED FOR YOUR SPECIFIC BUTTON, THEN SWAP THESE VALUES */
static unsigned char FREE = HIGH;
static unsigned char PRESSED = LOW;

/* Previous state from the INPUT PIN, 
 * initial HIGH -> button is Free (not pressed) on start. */
unsigned char _btn_press_last_state = FREE;
/* Current reading from the INPUT PIN, (not pressed) on start. */
unsigned char _btn_press_current_state = FREE;
/* Logical button states:
 ** 0 = OFF (default when initialized)
 ** 1 = ON */
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
  //checkButtonPressUp();
  //checkButtonPressDown();
  //checkButtonPress();
}


/* This function executes, when User presses
 * button (but code is executed on release of the button).
 * Something like Unity C# OnKeyUP(). */
void checkButtonPressUp() {
  /* Read the current state of the switch/button. */
  _btn_press_current_state = digitalRead(PIN_BUTTON);
  
  /* If previous state was PRESSED (LOW = 0), and current is FREE (HIGH = 1). */
  if(_btn_press_last_state == PRESSED && _btn_press_current_state == FREE) {
    /* Change Button state from 1 to 0 (ON -> OFF). */
    if (_btn_state) {
      /* If previously state was ON, now is OFF. */
      _btn_state = 0;
      
      /* Execute code for button OFF state. */
      btnIsOff(); 
    }
    /* Change Button state from 0 to 1 (OFF -> ON). */
    else {
      /* If previously state was OFF, now is ON. */
      _btn_state = 1;
      
      /* Execute code for button ON state. */
      btnIsOn();
    }
  }

  /* Update last state, so event is not executed
   * multiple times during single button press. */
  _btn_press_last_state = _btn_press_current_state;
}


/* This function executes, when User presses
 * button (but code is executed on exact moment of a button push).
 * Something like Unity C# OnKeyDown(). */
void checkButtonPressDown() {
  /* Read the current state of the switch/button. */
  _btn_press_current_state = digitalRead(PIN_BUTTON);
  
  /* If previous state was FREE (HIGH = 1), and current is PRESSED (LOW = 0). */
  if(_btn_press_last_state == FREE && _btn_press_current_state == PRESSED) {
    /* Change Button state from 1 to 0 (ON -> OFF). */
    if (_btn_state) {
      /* If previously state was ON, now is OFF. */
      _btn_state = 0;
      
      /* Execute code for button OFF state. */
      btnIsOff(); 
    }
    /* Change Button state from 0 to 1 (OFF -> ON). */
    else {
      /* If previously state was OFF, now is ON. */
      _btn_state = 1;
      
      /* Execute code for button ON state. */
      btnIsOn();
    }
  }

  /* Update last state, so event is not executed
   * multiple times during single button press. */
  _btn_press_last_state = _btn_press_current_state;
}


/* This function executes, when User presses and keeps executing 
 * while User holds button.
 * Something like Unity C# OnKey(). */
void checkButtonPress()
{
  /* Read the current state of the switch/button. */
  _btn_press_current_state = digitalRead(PIN_BUTTON);

  /* If current button state is PRESSED (LOW = 0). */
  if(_btn_press_current_state == PRESSED)
  {
    /* Execute code for button PRESSED state. */
    btnIsPressed();
  }
}


/* This function executes, when button state is 0 (OFF). */
void btnIsOff() {
  Serial.print("Button is in state: ");
  Serial.print(_btn_state);
  Serial.print(" (OFF)\n");
}


/* This function executes, when button state is 1 (ON). */
void btnIsOn() {
  Serial.print("Button is in state: ");
  Serial.print(_btn_state);
  Serial.print(" (ON)\n");
}


/* This function executes, when button is PRESSED (INPUT PIN reads LOW = 0). */
void btnIsPressed() {
  Serial.print("Button is currently pressed and is in logical state: ");
  Serial.print(PRESSED);
  Serial.print("!\n");
}
