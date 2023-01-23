#include "config.h"
#include "utils.h"

void setup() {
  Serial.begin(BAUDRATE);
  delay(500);

  servoMUX.begin();
  servoMUX.setPWMFreq(PULSE_FREQ)
}

void loop() {
  // put your main code here, to run repeatedly:

}
