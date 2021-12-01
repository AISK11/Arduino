/* Arduino IDE Set up:
 ** Tools -> Port -> /dev/ttyACM0
 ** Tools -> Board -> Arduino Uno
 */

/* Docs:
 ** Arduino Uno:
 *** https://store.arduino.cc/products/arduino-uno-rev3/
 ** LCD I2C:
 *** https://arduinogetstarted.com/tutorials/arduino-lcd-i2c
 */

/* Schematic:
 ** LCD I2C:
 *** Arduino UNO GROUND <=> LCD I2C GND
 *** Arduino UNO 5V     <=> LCD I2C VCC
 *** Arduino UNO A4     <=> LCD I2C SDA 
 *** Arduino UNO A5     <=> LCD I2C SCL
 */

/* Download "LiquidCrystal I2C" library
 ** Sketch -> Include Library -> Manage Libraries -> LiquidCrystal I2C 
 */


#include <LiquidCrystal_I2C.h> /* Import LCD I2C library */
