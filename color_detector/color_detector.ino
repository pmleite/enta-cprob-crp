#include "config.h"
#include "util_functions.h"

void setup() {

  Serial.begin(BAUT_RATE);
  delay(500);

  //Definição das GPIO do detetor de cor
  pinMode(S0, OUTPUT);
	pinMode(S1, OUTPUT);
	pinMode(S2, OUTPUT);
	pinMode(S3, OUTPUT);
  pinMode(SOut, INPUT);

// Set Pulse Width scaling to 20%
	digitalWrite(S0,HIGH);
	digitalWrite(S1,LOW);
}

void loop() {

  /* 
  Este While só é executado se a constante de calibração, no config, for true.
  Esta rotina serve para calibrar o sensor. 
  Deve ser feita uma leitura de uma supreficie vermelha, verde e azul padrão
  e registar os pulsos max e min, que devem ser colocados nas respetivas variaveis
  de configuração no config.h
  */
  while (COLOR_DET_CALIBRATION){
    // Le o comprimento do pulso vermelho e aplica um delay para estabilizar a leitura
    redPW = opbterPulsosDeCor('R');
    delay(COLOR_READ_DELAY);
    // Le o comprimento do pulso verde e aplica um delay para estabilizar a leitura
    greenPW = opbterPulsosDeCor('G');
    delay(COLOR_READ_DELAY);
    // Le o comprimento do pulso azul e aplica um delay para estabilizar a leitura
    bluePW = opbterPulsosDeCor('B');
    delay(COLOR_READ_DELAY);
    // Le o comprimento do pulso branco e aplica um delay para estabilizar a leitura
    whitePW = opbterPulsosDeCor('W');
    delay(COLOR_READ_DELAY);

    //Imprime o resultado das Leituras
    printLogs(redPW, greenPW, bluePW, whitePW);
  }

  /*
  Esta porção de código é executada apenas se a constante 
  COLOR_DET_CALIBRATION tiver um valor FALSE
  */

    // Le o comprimento do pulso vermelho e aplica um delay para estabilizar a leitura
    redPW = opbterPulsosDeCor('R');
    delay(COLOR_READ_DELAY);
    redValue = map(redPW, redMin,redMax,255,0);
    // Le o comprimento do pulso verde e aplica um delay para estabilizar a leitura
    greenPW = opbterPulsosDeCor('G');
    delay(COLOR_READ_DELAY);
    greenValue = map(greenPW, greenMin,greenMax,255,0);
    // Le o comprimento do pulso azul e aplica um delay para estabilizar a leitura
    bluePW = opbterPulsosDeCor('B');
    delay(COLOR_READ_DELAY);
    blueValue = map(bluePW, blueMin,blueMax,255,0);
    // Le o comprimento do pulso branco e aplica um delay para estabilizar a leitura
    whitePW = opbterPulsosDeCor('W');
    delay(COLOR_READ_DELAY);
    whiteValue = map(whitePW, whiteMin,whiteMax,255,0);

    //printLogs(redValue, greenValue, blueValue, whiteValue);
    //Serial.println(wichColor(redValue, greenValue, blueValue, whiteValue));

    switch (wichColor(redValue, greenValue, blueValue, whiteValue)) {
      case 0:
        Serial.println("Vermelho... toca a parar");
      break;
      case 1:
        Serial.println("Verde... e um tal a acelerar");
      break;
      case 2:
        Serial.println("Azul... toca a dançar");
      break;
      case 3:
        Serial.println("E Branco... ");
      break;
      case 4:
        Serial.println("E preto...");
      break;
      default:
        Serial.println("Ops... não sei o que é");
      break;
    }
}
