#include "config.h"
#include "utils.h"
#include "motorMoves.h"
#include "servoMoves.h"

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

  //Inicializa o MUX PWM
  servoMUX.begin();
  servoMUX.setPWMFreq(PULSE_FREQ);
  delay(500);

  stopCar();
  armInitPosition();
  delay(1000);

}

void loop() {

  abreGarra();
  delay(1000);
  fechaGarra();
    delay(1000);
  // moveBase(BASE_MAX_ROT);
  // delay(5000);
  // moveBase(BASE_MIN_ROT);
  // delay(5000);

   
}
