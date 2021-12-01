/************************************************
 * Author: AISK11                               *
 * Description: code to toggle (ON/OFF) BUTTON. *
 * Date Created: 2021-11-30                     *
 * Last Updated: 2021-11-30                     *
 ************************************************/
/* Arduino IDE Set up:
 ** Tools -> Port -> /dev/ttyACM0
 ** Tools -> Board -> Arduino Uno
 */

/* Schematic:
 ** Button:
 *** Arduino UNO GPIO D<2;13> <=> Button
 *** GROUND                   <=> Button
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


#define BUTTON_PIN 2 /* GPIO <2;13> pin connected to Button */


unsigned char btn_last_state = HIGH; /* the previous state from the input pin, initial HIGH -> from OFF to ON 1st time */
unsigned char btn_current_state;     /* the current reading from the input pin */
unsigned char btn_isOn = 0; 


void setup() {
  /* initialize serial communication at 9600 bits per second */
  Serial.begin(9600);

  /* initialize the Button pin as an pull-up input
   * the pull-up input pin will be HIGH when the switch 
   * is open and LOW when the switch is closed
   * (good for DIGITAL INPUT devices) */
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}


void checkButtonPress() {
  /* read the current state of the switch/button */
  btn_current_state = digitalRead(BUTTON_PIN);
  
  /* if previous state was LOW (pressed) and current is HIGH (free) */
  if(btn_last_state == LOW && btn_current_state == HIGH) {
    /* change BUTTON1 state */
    if (btn_isOn) {
      btn_isOn = 0;
      btnIsOff(); 
    }
    else {
      btn_isOn = 1;
      btnIsOn();
    }
    /* added delay, to prevent mutliple press detection in single press */
    delay(50);
  }

  /* update last state, so event is not executed multiple
   * times during single button press */
  btn_last_state = btn_current_state;
}


void btnIsOff() {
  Serial.println("OFF");
}


void btnIsOn() {
  Serial.println("ON");
}


void loop() {
  checkButtonPress();
}
