#include "settings.h"
#include "utils.h"

void setup() {

  Serial.begin(BAUD_RATE);

  //Pinos dos IR
  pinMode(IR_LEFT_PIN, INPUT);
  pinMode(IR_CENTER_PIN, INPUT);
  pinMode(IR_RIGHT_PIN, INPUT);

  //Pinos de controlo do motor
  pinMode(MOTOR_1_PIN_A, OUTPUT);
  pinMode(MOTOR_1_PIN_B, OUTPUT);
  pinMode(MOTOR_2_PIN_A, OUTPUT);
  pinMode(MOTOR_2_PIN_B, OUTPUT);

 
  servoMUX.begin();
  servoMUX.setPWMFreq(60);

}

void loop() {
  // servoMUX.setPWM(0,0,125);
  // delay(500);
  // servoMUX.setPWM(0,0,575);
  // delay(500);
  // servoMUX.setPWM(1,0,125);
  // delay(500);

}


