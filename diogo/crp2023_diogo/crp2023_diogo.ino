#include "config.h"
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

  //Definição das GPIO do detetor de cor
  pinMode(S0, OUTPUT);
	pinMode(S1, OUTPUT);
	pinMode(S2, OUTPUT);
	pinMode(S3, OUTPUT);
  pinMode(SOut, INPUT);

  //Ajusta a amplitude do pulse para 20% (Varia se for arduino, raspbery, etc)
	digitalWrite(S0,HIGH);
	digitalWrite(S1,LOW);

  armInitPosition();
}

void loop() {
  
  updateColorValues();
  printCalibrationValues();
  //wichColor(redValue, greenValue, blueValue, whiteValue);

}