/************************************************
 * Author: AISK11                               *
 * Description: code to get temperature value   *
 *              from LM35 temperature sensor.   *
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
 ** LM35:
 *** https://arduinogetstarted.com/tutorials/arduino-lm35-temperature-sensor
 */ 
 
/* Schematic:
 ** LM35:
 *** Arduino UNO 5V     <=> LM35 VCC
 *** Arduino UNO A<0;5> <=> LM35 OUT
 *** Arduino UNO GROUND <=> LM35 GND
 */

/* Theory:
 ** Temperature range:      0 - 500 °C
 ** Reading Resolution:     5000mv / 1024 = 4.88 mV
 ** Temperature Resolution: 0.488 °C
 */


#define PIN_LM35       A0     /* GPIO <A0;A5> pin connected to LM35 OUTPUT */
#define ADC_VREF_mV    5000.0 /* 5000 because 5V */
#define ADC_RESOLUTION 1024.0 /* 5000 / 1024 = 4.88 mV and Temperature Resolution is 0.488 °C */


void setup() {
  /* initialize serial communication at 9600 bits per second */
  Serial.begin(9600);
}


/* return Celsius degrees */
float lm35_celsius() {
  /* get the ADC value from the temperature sensor */
  int adc_value = analogRead(PIN_LM35);
  
  /* convert the ADC value to voltage in millivolt */
  float milli_volt = adc_value * (ADC_VREF_mV / ADC_RESOLUTION);
  
  /* convert the voltage to the temperature in Celsius */
  float temp_celsius = milli_volt / 10;

  return temp_celsius;
}


/* return Fahrenheit degrees */
float lm35_fahrenheit() {
  /* get the ADC value from the temperature sensor */
  int adc_value = analogRead(PIN_LM35);
  
  /* convert the ADC value to voltage in millivolt */
  float milli_volt = adc_value * (ADC_VREF_mV / ADC_RESOLUTION);
  
  /* convert the voltage to the temperature in Celsius */
  float temp_celsius = milli_volt / 10;
  
  /* convert the Celsius to Fahrenheit */
  float temp_fahrenheit = temp_celsius * 9 / 5 + 32;

  return temp_fahrenheit;
}


void loop() {
  Serial.print("Temperature: ");
  Serial.print(lm35_celsius());
  Serial.print("°C");
  Serial.print("  ~  "); // separator between Celsius and Fahrenheit
  Serial.print(lm35_fahrenheit());   // print the temperature in Fahrenheit
  Serial.println("°F");
  delay(1000);
}
