#include "settings.h"
#include "utils.h"
#include "motor_moves.h"

void setup() {
  Serial.begin(BAUD_RATE);

  //Pinos dos IR
  pinMode(IR_LEFT_PIN, INPUT);
  pinMode(IR_CENTER_PIN, INPUT);
  pinMode(IR_RIGHT_PIN, INPUT);
  
  servoMUX.begin();
  servoMUX.setPWMFreq(PULSE_FREQ);
  delay(500);

  stop();
  delay(200);
}


void loop() {


}


