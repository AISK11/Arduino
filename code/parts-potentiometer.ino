/************************************************
 * Author: AISK11                               *
 * Description: code to control potentiometer.  *
 * Date Created: 2021-12-01                     *
 * Last Updated: 2021-12-01                     *
 ************************************************/
/* Arduino IDE Set up:
 ** Tools -> Port -> /dev/ttyACM0
 ** Tools -> Board -> Arduino Uno
 */

/* Docs:
 ** Arduino Uno:
 *** https://store.arduino.cc/products/arduino-uno-rev3/
 ** Potentiometer:
 *** https://arduinogetstarted.com/tutorials/arduino-potentiometer
 *** https://roboticsbackend.com/arduino-potentiometer-complete-tutorial/
 */ 

/* Schematic:
 ** Potentiometer:
 *** Arduino UNO 5V          <=> Potentiometer VCC    -+
 *** Arduino UNO GPIO A<0;5> <=> Potentiometer Output -+-------+
 *** Arduino UNO GROUND      <=> Potentiometer GND    -+
 */

/* Theory:
 ** Potentiometer:
 *** ADC value: <0;1023>
 */


#define PIN_POTENTIOMETER A1 /* GPIO <A0;A5> pin connected to LM35 OUTPUT */


void setup() {
  /* initialize serial communication at 9600 bits per second */
  Serial.begin(9600);
}


unsigned short int getPotentiometerOutput() {
  /* read value from potentiometer, range: 0-1023 */
  unsigned short int potentiometer_analog = analogRead(PIN_POTENTIOMETER);

  return potentiometer_analog;
}


unsigned short int getPotentiometerOutputRemapped(unsigned short int remap_min, unsigned short int remap_max) {
  /* read value from potentiometer, range: 0-1023 */
  unsigned short int potentiometer_analog = analogRead(PIN_POTENTIOMETER);

  /* mathematically remap potentiometer from range 0-1023 to 0,100 */
  unsigned short int potentiometer_remapped = map(potentiometer_analog, 0, 1023, remap_min, remap_max);

  return potentiometer_remapped;
}


void loop() {
  Serial.print("Potentiometer value: ");
  Serial.print(getPotentiometerOutput());
  Serial.print(";\n");
  Serial.print("Potentiometer percentage: ");
  Serial.print(getPotentiometerOutputRemapped(0, 100));
  Serial.print("%\n");
  delay(1000);
}
