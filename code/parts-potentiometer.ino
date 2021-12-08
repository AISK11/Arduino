/************************************************
 * Author: AISK11                               *
 * Description: code to control potentiometer.  *
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


/************************
 **     GPIO Pins      ** 
 ************************/
/* GPIO <A0;A5> pin connected to LM35 OUTPUT */
static const unsigned char PIN_POTENTIOMETER = A1;


/************************
 ** Arduino Functions  ** 
 ************************/
void setup() {
  /* Initialize serial communication at 9600 bits per second. */
  Serial.begin(9600);
}


void loop() {
  Serial.print("Potentiometer value: ");
  Serial.print(getPotentiometerOutput(PIN_POTENTIOMETER));
  Serial.print(";\n");
  Serial.print("Potentiometer percentage: ");
  Serial.print(getPotentiometerOutputRemapped(PIN_POTENTIOMETER, 0, 100));
  Serial.print("%\n");
  delay(1000);
}


/************************
 ** Program Functions  ** 
 ************************/
/* Returns value <0-1023> equal to potentiometer position. */
unsigned short int getPotentiometerOutput(const unsigned char pin_potentiometer) {
  /* Read value from potentiometer, range: 0-1023. */
  unsigned short int potentiometer_analog = analogRead(pin_potentiometer);

  /* Returns value <0-1023> equal to potentiometer position. */
  return potentiometer_analog;
}


/* Returns value <remap_min-remap_max> equal to potentiometer position. */
unsigned short int getPotentiometerOutputRemapped(const unsigned char pin_potentiometer, unsigned short int remap_min, unsigned short int remap_max) {
  /* Read value from potentiometer, range: 0-1023. */
  unsigned short int potentiometer_analog = analogRead(pin_potentiometer);

  /* Mathematically remap potentiometer from range 0-1023 to 0,100. */
  unsigned short int potentiometer_remapped = map(potentiometer_analog, 0, 1023, remap_min, remap_max);

  /* Returns value <remap_min-remap_max> equal to potentiometer position. */
  return potentiometer_remapped;
}
