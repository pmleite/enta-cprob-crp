#include "config.h"
#include "utils.h"

void setup() {

  Serial.begin(BAUT_RATE);
  delay(500);

  //Definição das GPIO do detetor de cor
  pinMode(S0, OUTPUT);
	pinMode(S1, OUTPUT);
	pinMode(S2, OUTPUT);
	pinMode(S3, OUTPUT);
  pinMode(SOut, INPUT);

  //Ajusta a amplitude do pulse para 20% (Varia se for arduino, raspbery, etc)
	digitalWrite(S0,HIGH);
	digitalWrite(S1,LOW);
}

void loop() {

  

  updateColorValues();
  printCalibrationValues();
  //wichColor(redValue, greenValue, blueValue, whiteValue);

}
