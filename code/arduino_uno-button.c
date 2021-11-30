/* Arduino IDE Set up:
 ** Tools -> Port -> /dev/ttyACM0
 ** Tools -> Board -> Arduino Uno
 */

/* Schematic:
 ** Arduino UNO GPIO D8 <=> Button
 ** GROUND              <=> Button
 */

/* Docs:
 ** Arduino Uno:
 *** https://store.arduino.cc/products/arduino-uno-rev3/
 ** Button:
 *** https://arduinogetstarted.com/tutorials/arduino-button
 */ 
#define BUTTON1_PIN 8 /* GPIO8 pin connected to button */

unsigned char btn1_last_state = HIGH; /* the previous state from the input pin */
unsigned char btn1_current_state;     /* the current reading from the input pin */
unsigned char btn1_isOn = 0; 

void setup() {
  /* initialize serial communication at 9600 bits per second */
  Serial.begin(9600);

  /* initialize the pushbutton pin as an pull-up input
   * the pull-up input pin will be HIGH when the switch 
   * is open and LOW when the switch is closed */
  pinMode(BUTTON1_PIN, INPUT_PULLUP);
}


void checkButtonPress() {
  /* read the current state of the switch/button */
  btn1_current_state = digitalRead(BUTTON1_PIN);
  
  /* if current state is LOW (pressed) and previous was HIGH (free) */
  if(btn1_last_state == LOW && btn1_current_state == HIGH) {
  /* change BUTTON1 state */
  if (btn1_isOn) {
    btn1_isOn = 0;
    Serial.println("OFF");
  }
  else {
    btn1_isOn = 1;
    Serial.println("ON");
  }
  /* added delay, to prevent mutliple press detection in single press */
  delay(50);
}

  /* update last state, so event is not executed multiple
   * times during single button press */
  btn1_last_state = btn1_current_state;
}


void loop() {
  checkButtonPress();
}
