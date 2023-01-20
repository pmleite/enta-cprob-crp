#include "settings.h"
#include "utils.h"
#include "servo_moves.h"
#include "motor_moves.h"

void setup() {

  Serial.begin(BAUD_RATE);

  //Pinos dos IR
  pinMode(IR_LEFT_PIN, INPUT);
  pinMode(IR_CENTER_PIN, INPUT);
  pinMode(IR_RIGHT_PIN, INPUT);

  //Pinos de controlo do motor
  // Não é utilizado porque os motores são controlados pelo PWM
  // pinMode(MOTOR_1_PIN_A, OUTPUT);
  // pinMode(MOTOR_1_PIN_B, OUTPUT);
  // pinMode(MOTOR_2_PIN_A, OUTPUT);
  // pinMode(MOTOR_2_PIN_B, OUTPUT);

  servoMUX.begin();
  servoMUX.setPWMFreq(PULSE_FREQ);
  delay(500);

  armInitPosition();
  delay(200);
  stop();
  delay(200);
}


void loop() {

  forward(convertSpeedToPulse(0));
  delay(500);
  stop();
  delay(500);
  backward(convertSpeedToPulse(0));
  delay(500);
  stop();
  delay(500);

}


