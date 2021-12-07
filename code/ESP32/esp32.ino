/* Arduino IDE Set up:
 ** Tools -> Port -> /dev/ttyUSB0

 ** File -> Preferences -> Additional Boards Manager URLs:
 *** https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json -> OK
 ** Tools -> Board -> Boards Manager -> Arduino AVR Boards -> Install|Update
 ** Tools -> Board -> Boards Manager -> esp32 -> Install
 ** Tools -> Board -> ESP32 Arduino -> ESP32 Dev Module
 */

/* ERROR FIX:
 ** "python": executable file not found in $PATH
 *** > sudo ln -s /usr/bin/python3 /usr/bin/python
 ** ModuleNotFoundError: No module named ’serial’:
 *** > sudo python3 -m pip install pyserial
 ** Output is "GARBAGE":
 *** Baud: 9600
 *** Press "EN" button.
 */


void setup() {
  /* Initialize serial communication at 9600 bits per second. */
  Serial.begin(9600);
}


void loop() {
  Serial.println("TEST");
}
