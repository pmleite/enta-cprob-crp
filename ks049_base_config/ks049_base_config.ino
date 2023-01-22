#include "config.h"
#include "utils.h"

void setup() {
  
  //Inicializa a porta série
  Serial.begin(BAUD_RATE);
  delay(100);

  //Define modo de operação dos pinos so sensor de cor.
  pinMode(COLOR_SENSOR_S0,   OUTPUT);
  pinMode(COLOR_SENSOR_S1,   OUTPUT); 
  pinMode(COLOR_SENSOR_S2,   OUTPUT);
  pinMode(COLOR_SENSOR_S3,   OUTPUT);
  pinMode(COLOR_SENSOR_READ, INPUT);
  //Define modo de operação dos pinos dos sensores Ir
  pinMode(LEFT_IR_SENSOR,    INPUT);
  pinMode(CENTER_IR_SENSOR,  INPUT);
  pinMode(RIGHT_IR_SENSOR,   INPUT);
  //Define o modo de operação do pino do LED
  pinMode(LED_PIN, OUTPUT);
  //Define o modo de operação dos pinos do sensor Ultrasonico
  pinMode(ULTRA_S_ECHO, INPUT);
  pinMode(ULTRA_S_PING, OUTPUT);

  //Ajusta a amplitude do pulse para 20% (Varia se for arduino, raspbery, etc)
	digitalWrite(COLOR_SENSOR_S0,HIGH);
	digitalWrite(COLOR_SENSOR_S1,LOW);

      //Em modo de calibração de cor executa sempre este loop
      while(COLOR_CALIBRATION){
        atualizaValoresDasCores(COLOR_CALIBRATION);
        Serial.print("R:");   Serial.print(redValue);
        Serial.print("\tG:"); Serial.print(greenValue);
        Serial.print("\tB:"); Serial.print(blueValue);
        Serial.print("\tW:"); Serial.println(whiteValue);
      }

  delay(1000);
}

void loop() {
  
   //Lê pulsos de cores e atualiza variaveis das cores
   atualizaValoresDasCores();
   //Deteta a cor e atualiza a variavel <detectedColor> com o valor detetado
   detetaCor();

   //Calcula a distancia medida pelo ultrasom e guarda na variaval <distancia>
   calculaDistancia();

   //deteta desvio do carro da linha preta e guarda na variavel <desvio>
   //Os valores são:  -2..-1...0...1...2, consoante o desvio
   detetaDesvio();

   Serial.println("Cor: " + String(detectedColor) + "\tDst: " + String(distancia) + "\t Desv:" + String(desvio));

   
}
