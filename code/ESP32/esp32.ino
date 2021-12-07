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

/* Schematic:
 *          +-------------+
 *      3.3V|o           o|GND---+
 *        EN|o           o|IO23  |
 * SENSOR VP|o           o|IO22  |
 * SENSOR VN|o           o|TXD0  |
 *      IO34|o           o|RXD0  |
 *      IO35|o           o|IO21  |
 *      IO32|o           o|GND---+
 *      IO33|o           o|IO19
 *      IO25|o           o|IO18
 *      IO26|o           o|IO5
 *      IO27|o           o|IO17
 *      IO14|o           o|IO16
 *      IO12|o           o|IO4
 *       GND|o           o|IO0
 *      IO13|o           o|IO2
 *       SD2|o           o|IO15
 *       SD3|o           o|SD1
 *       CMD|o           o|SD0
 *        5V|o EN   Boot o|CLK
 *          +-----USB-----+
 */


void setup() {
  /* Initialize serial communication at 9600 bits per second. */
  Serial.begin(9600);
}


void loop() {
  Serial.println("TEST");
}
