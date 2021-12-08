/************************************************
 * Author: AISK11                               *
 * Description: code to print text on LCD       *
 *              display.                        *
 * Date Created: 2021-11-30                     *
 * Last Updated: 2021-12-08                     *
 ************************************************/
/* Arduino IDE Set up:
 ** Tools -> Port -> /dev/ttyACM0
 ** Tools -> Board -> Arduino Uno
 */

/* Docs:
 ** Arduino Uno:
 *** https://store.arduino.cc/products/arduino-uno-rev3/
 ** LCD I2C:
 *** https://arduinogetstarted.com/tutorials/arduino-lcd-i2c
 *** https://arduinogetstarted.com/reference/library/arduino-lcd-library
 */

/* Schematic:
 ** LCD I2C:
 *** Arduino UNO GROUND <=> LCD I2C GND
 *** Arduino UNO 5V     <=> LCD I2C VCC
 *** Arduino UNO A4     <=> LCD I2C SDA
 *** Arduino UNO A5     <=> LCD I2C SCL
 */

/* Library:
 ** Download "LiquidCrystal I2C" lib:
 *** Sketch -> Include Library -> Manage Libraries -> "LiquidCrystal I2C"
 */


/************************
 **     Libraries      ** 
 ************************/
/* Import LCD I2C library. */
#include <LiquidCrystal_I2C.h> 


/************************
 ** Display Properties ** 
 ************************/
/* I2C address 0x27, 20 column and 4 rows. */
LiquidCrystal_I2C lcd(0x27, 20, 4); 


/************************
 ** Arduino Functions  ** 
 ************************/
void setup() {
  /* Initialize the lcd. */
  lcd.init();
  /* Open the backlight. */
  lcd.backlight();

  /* Hide LCD cursor. */
  lcd.noCursor();
}


void loop() {
  /* Print text to LCD Display */
  //lcdTestMessage();

  /* Print text at specific LCD Display location */
  //lcdMessage(0, 0, "Hi!");
}


/************************
 ** Program Functions  ** 
 ************************/
/* Function does the following:
 * 1. Prints "Hello World" followed with "-" for whole second line.
 * 2. After 1 second, clears the screen.
 * 3. After 1 second, prints "Bye World" followed with "-" for whole second line.
 * 4. After 1 second, clears the screen and repeats step 1.
 */
void lcdTestMessage() {
  lcd.setCursor(0, 0);                 /* Move cursor   to (0, 0) */
  lcd.print("Hello World!");           /* Print message at (0, 0) */
  lcd.setCursor(0, 1);                 /* Move cursor   to (0, 1) */
  lcd.print("--------------------");   /* Print message at (0, 0) */

  delay(1000);                         /* Wait 1000 milliseconds.   */
  lcd.clear();                         /* Clear the display screen. */
  delay(1000);                         /* Wait 1000 milliseconds.   */

  lcd.setCursor(0, 0);                 /* Move cursor   to (0, 0) */
  lcd.print("Bye World!");             /* Print message at (0, 0) */
  lcd.setCursor(0, 1);                 /* Move cursor   to (0, 1) */
  lcd.print("--------------------");   /* Print message at (0, 0) */

  delay(1000);                         /* Wait 1000 milliseconds.   */
  lcd.clear();                         /* Clear the display screen. */
  delay(1000);                         /* Wait 1000 milliseconds.   */
}


/* Function prints text on LCD Display on set row (x) and column (y). */
void lcdMessage(unsigned short int x, unsigned short int y, char message[]) {
  /* Move cursor to (x, y). */
  lcd.setCursor(x, y);

  /* Print message (string). */
  lcd.print(message);
}
