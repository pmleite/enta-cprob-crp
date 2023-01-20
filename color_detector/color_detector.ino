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

  COLOR_DET_CALIBRATION ? redPW   = opbterPulsosDeCor('R') : redPW = map( opbterPulsosDeCor('R'), redMin,redMax,255,0);
  COLOR_DET_CALIBRATION ? greenPW = opbterPulsosDeCor('G') : redPW = map( opbterPulsosDeCor('G'), greenMin,greenMax,255,0);
  COLOR_DET_CALIBRATION ? bluePW  = opbterPulsosDeCor('B') : redPW = map( opbterPulsosDeCor('B'), blueMin,blueMax,255,0);
  COLOR_DET_CALIBRATION ? whitePW = opbterPulsosDeCor('W') : redPW = map( opbterPulsosDeCor('W'), whiteMin,whiteMax,255,0);

  if (COLOR_DET_CALIBRATION){
    printCalibrationData(redPW, greenPW, bluePW, whitePW);
  }else{
    Serial.println(String(wichColor(redPW, greenPW, bluePW, whitePW)));
  }

}
