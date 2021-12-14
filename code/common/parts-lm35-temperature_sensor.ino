/************************************************
 * Author: AISK11                               *
 * Description: code to get temperature value   *
 *              from LM35 temperature sensor.   *
 * Date Created: 2021-12-01                     *
 * Last Updated: 2021-12-14                     *
 ************************************************/
/* Arduino IDE Set up:
 ** Tools -> Port -> /dev/ttyACM0
 ** Tools -> Board -> Arduino Uno
 */

/* Docs:
 ** Arduino Uno:
 *** https://store.arduino.cc/products/arduino-uno-rev3/
 ** LM35:
 *** https://arduinogetstarted.com/tutorials/arduino-lm35-temperature-sensor
 */ 
 
/* Schematic:
 ** LM35:
 *** Arduino UNO 5V     <=> LM35 VCC -+-,
 *** Arduino UNO A<0;5> <=> LM35 OUT -|  )
 *** Arduino UNO GROUND <=> LM35 GND -+-'
 */

/* Theory:
 ** Temperature range:      0 - 500 °C
 ** Reading Resolution:     5000mv / 1024 = 4.88 mV
 ** Temperature Resolution: 0.488 °C
 */

/* Note:
 ** If sensor is outputting too high values, connect to separate ground.
 */


/************************
 **     GPIO Pins      ** 
 ************************/
/* GPIO <A0;A5> pin connected to LM35 OUTPUT. */
static const unsigned char PIN_LM35 = A0;


/************************
 ** Constant Variables ** 
 ************************/
/* 5000 because 5V. */
#define ADC_VREF_mV    5000.0
/* 5000 / 1024 = 4.88 mV and Temperature Resolution is 0.488 °C. */
#define ADC_RESOLUTION 1024.0


/************************
 ** Arduino Functions  ** 
 ************************/
void setup() {
  /* Initialize serial communication at 9600 bits per second. */
  Serial.begin(9600);
}


void loop() {
  Serial.print("Temperature: ");
  Serial.print(lm35_celsius(PIN_LM35));
  Serial.print("°C");
  /* Separator between Celsius and Fahrenheit. */
  Serial.print("  ~  "); 
  Serial.print(lm35_fahrenheit(PIN_LM35));
  Serial.println("°F");
  delay(1000);
}


/************************
 ** Program Functions  ** 
 ************************/
/* Return Celsius degrees. */
float lm35_celsius(const unsigned char pin_lm35) {
  /* Get the ADC value from the temperature sensor. */
  int adc_value = analogRead(pin_lm35);
  
  /* Convert the ADC value to voltage in millivolt. */
  float milli_volt = adc_value * (ADC_VREF_mV / ADC_RESOLUTION);
  
  /* Convert the voltage to the temperature in Celsius. */
  float temp_celsius = milli_volt / 10;

  return temp_celsius;
}


/* Return Fahrenheit degrees. */
float lm35_fahrenheit(const unsigned char pin_lm35) {
  /* Convert the Celsius to Fahrenheit. */
  float temp_fahrenheit = lm35_celsius(pin_lm35) * 9 / 5 + 32;

  return temp_fahrenheit;
}
