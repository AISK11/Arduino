/************************************************
 * Author: AISK11                               *
 * Description: code to toggle (ON/OFF) BUTTON. *
 * Date Created: 2021-11-30                     *
 * Last Updated: 2021-12-01                     *
 ************************************************/
/* Arduino IDE Set up:
 ** Tools -> Port -> /dev/ttyACM0
 ** Tools -> Board -> Arduino Uno
 */

/* Schematic:
 ** Button:
 *** Arduino UNO GPIO D<2;13> <=> Button
 *** Arduino UNO GROUND       <=> Button
 */

/* Docs:
 ** Arduino Uno:
 *** https://store.arduino.cc/products/arduino-uno-rev3/
 ** Button:
 *** https://arduinogetstarted.com/tutorials/arduino-button
 */ 

/* Theory:
 ** Button:
 *** Button is Free    = 1 (HIGH)
 *** Button is Pressed = 0 (LOW)
 */


#define PIN_BUTTON 2 /* GPIO <2;13> pin connected to Button */


unsigned char btn_last_state = HIGH; /* the previous state from the input pin, initial HIGH -> start in OFF */
unsigned char btn_current_state;     /* the current reading from the input pin */
unsigned char btn_state = 0;         /* button is Off on the start */


void setup() {
  /* initialize serial communication at 9600 bits per second */
  Serial.begin(9600);

  /* initialize the Button pin as an pull-up input
   * the pull-up input pin will be HIGH when the switch 
   * is open and LOW when the switch is closed
   * (good for DIGITAL INPUT devices) */
  pinMode(PIN_BUTTON, INPUT_PULLUP);
}


/* this function executes, when User presses
 * button (but code is executed on release of the button
 * something like Unity C# OnKeyUP() */
void checkButtonPress() {
  /* read the current state of the switch/button */
  btn_current_state = digitalRead(PIN_BUTTON);
  
  /* if previous state was LOW (pressed) and current is HIGH (free) */
  if(btn_last_state == LOW && btn_current_state == HIGH) {
    /* change BUTTON state */
    if (btn_state) {
      /* if was ON previously, now is OFF */
      btn_state = 0;
      /* execute code for button OFF state */
      btnIsOff(); 
    }
    else {
      /* if was OFF previously, now is ON */
      btn_state = 1;
      /* execute code for button OFF state */
      btnIsOn();
    }
    /* added delay, to prevent mutliple press detection in single press */
    delay(50);
  }

  /* update last state, so event is not executed
   * multiple times during single button press */
  btn_last_state = btn_current_state;
}


/* this function executes, when button state is 1 (ON) */
void btnIsOff() {
  Serial.print("Button is in state: ");
  Serial.print(btn_state);
  Serial.print(" (OFF)\n");
}


/* this function executes, when button state is 0 (OFF) */
void btnIsOn() {
  Serial.print("Button is in state: ");
  Serial.print(btn_state);
  Serial.print(" (ON)\n");
}


void loop() {
  checkButtonPress();
}
