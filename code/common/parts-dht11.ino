/************************************************
 * Author: AISK11                               *
 * Description: code to get temperature value   *
 *              from DHT11 digital temp sensor. *
 * Date Created: 2021-12-14                     *
 * Last Updated: 2021-12-14                     *
 ************************************************/
/* Arduino IDE Set up:
 ** Tools -> Port -> /dev/ttyACM0
 ** Tools -> Board -> Arduino Uno
 */

/* Docs:
 ** Arduino Uno:
 *** https://store.arduino.cc/products/arduino-uno-rev3/
 ** DHT11:
 *** https://create.arduino.cc/projecthub/electronicsfan123/interfacing-dht22-dht11-with-arduino-uno-931539
 */

/* Schematic:
 ** DHT11:
 *** Arduino UNO 5V     <=> DHT11 (1st leg) <=> Resistor 10k Ohm <=+
 *** Arduino UNO <2;13> <=> DHT11 (2nd leg) <======================+
 *** <EMPTY>            <=> DHT11 (3rd leg)
 *** Arduino UNO GROUND <=> DHT11 (4th leg)
 */

/* Library:
 ** Download "DHT sensor library" lib:
 *** Sketch -> Include Library -> Manage Libraries -> "DHT sensor library"
 ** Download "Adafruit Unified Sensor" lib:
 *** Sketch -> Include Library -> Manage Libraries -> "Adafruit Unified Sensor"
 */


/************************
 **     Libraries      ** 
 ************************/
/* Import DHT sensors library. */
#include <DHT.h>


/************************
 **     GPIO Pins      ** 
 ************************/
/* GPIO <2;13> pin connected to DHT. */
static const unsigned char PIN_DHT = 9;


/************************
 ** Constant Variables ** 
 ************************/
/* Specify which type of DHT_TYPE is used. */
#define DHT_TYPE DHT11
//#define DHT_TYPE DHT21
//#define DHT_TYPE DHT22


/************************
 **   DHT Properties   ** 
 ************************/
/* Specify DHT Pin and DHT Type. */
DHT dht(PIN_DHT, DHT_TYPE);


/************************
 ** Arduino Functions  ** 
 ************************/
void setup() {
  /* Initialize serial communication at 9600 bits per second. */
  Serial.begin(9600);

  /* Initialize DHT sensor. */
  dht.begin();
}


void loop() {
  //Serial.println(dht11_temp_celsius(PIN_DHT));
  //Serial.println(dht11_temp_fahrenheit(PIN_DHT));
  //Serial.println(dht11_humidity(PIN_DHT));
}


/************************
 ** Program Functions  ** 
 ************************/
float dht11_temp_celsius(const unsigned char pin_dht) {
  /* Read temperature as Celsius (the default). */
  float temp_celsius = dht.readTemperature();
  
  return temp_celsius;
}


float dht11_temp_fahrenheit(const unsigned char pin_dht) {
  /* Read temperature as Fahrenheit (isFahrenheit = true). */
  float temp_fahrenheit = dht.readTemperature(true);
  
  return temp_fahrenheit;
}


float dht11_humidity(const unsigned char pin_dht) {
  /* Read humidity. */
  /* Reading temperature or humidity takes about 250 milliseconds!
   * Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor). */
  float humidity = dht.readHumidity();
  
  return humidity;
}
