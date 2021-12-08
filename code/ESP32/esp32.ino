/* WORK IN PROGRESS */

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

/* Docs:
 ** Arduino ESP32:
 *** https://www.mischianti.org/2020/05/30/esp32-pinout-specs-and-arduino-ide-configuration-part-1/
 ** Button:
 *** https://arduinogetstarted.com/tutorials/arduino-button
 */ 

/* Schematic (ESP32 DevKitC V4):
 *          +---------------+
 *      3.3V|o            ~o|GND-----+
 *        EN|o            ~o|GPIO23  |
 *    GPIO36|o            ~o|GPIO22  |
 *    GPIO39|o            ~o|GPIO1   |
 *    GPIO34|o            ~o|GPIO3   |
 *    GPIO35|o            ~o|GPIO21  |
 *    GPIO32|o~           ~o|GND-----+
 *    GPIO33|o~           ~o|GPIO19
 *    GPIO25|o~           ~o|GPIO18
 *    GPIO26|o~           ~o|GPIO5
 *    GPIO27|o~           ~o|GPIO17
 *    GPIO14|o~           ~o|GPIO16
 *    GPIO12|o~           ~o|GPIO4
 *       GND|o            ~o|GPIO0
 *    GPIO13|o~           ~o|GPIO2
 *    GPIO09|o~           ~o|GPIO15
 *    GPIO10|o~           ~o|GPIO7
 *    GPIO11|o~           ~o|GPIO8
 *        5V|o  EN   Boot ~o|GPIO6
 *          +------USB------+
 */


void setup() {
  /* Initialize serial communication at 9600 bits per second. */
  Serial.begin(9600);
}


void loop() {
  Serial.println("TEST");
}
