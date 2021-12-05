/************************************************
 * Author: AISK11                               *
 * Description: function to provide delay, but  *
 *              other code can still run.       *
 * Date Created: 2021-12-01                     *
 * Last Updated: 2021-12-05                     *
 ************************************************/
/* Arduino IDE Set up:
 ** Tools -> Port -> /dev/ttyACM0
 ** Tools -> Board -> Arduino Uno
 */


unsigned long _last_millis_count = 0;     /* when program starts, 0 milliseconds passed already (cause it starts now) */
unsigned long timer_without_delay = 1000; /* timer in milliseconds */


void setup() {
  /* initialize serial communication at 9600 bits per second */
  Serial.begin(9600);
}


/* smartDelayCheck()
 ** check if timer has passed + other code can still run unlike delay().
 * millis()
 ** returns the number of milliseconds passed since
 ** the Arduino board began running the current program.
 ** This number will overflow (go back to zero), after ~50 days. */
void smartDelayCheck(unsigned long delay_timer) {
  /* if millis() - _last_millis_count > delay_timer;
   * e.g. 74361 - 73360 > 1000 */
  if((millis() - _last_millis_count) > delay_timer) {
    /* execute function when timer has passed */
    smartDelayExecute();
    
    /* update _last_millis_count with current millis() */
    _last_millis_count = millis();
  }
}


/* execute code when timer has passed */
void smartDelayExecute() {
  Serial.print(timer_without_delay);
  Serial.print(" milliseconds passed.\n");
}


void loop() {
  /* check if specified amount of milliseconds has passed
   * and then it will call smartDelayExecute() */
  smartDelayCheck(timer_without_delay);
}