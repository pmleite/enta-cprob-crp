#include "config.h"
#include "movMotor.h"
#include "movBraco.h"
#include "utils.h"

void setup() {
  
  //Inicializa a porta série
  Serial.begin(BAUD_RATE);
  delay(100);

  pinMode(BASE_SERVO_PIN,   OUTPUT);
  pinMode(CLAW_SERVO_PIN,   OUTPUT); 
  pinMode(HORI_SERVO_PIN,   OUTPUT);
  pinMode(VERT_SERVO_PIN,   OUTPUT);

  pinMode(LEFT_IR_SENS, INPUT);
  pinMode(MIDD_IR_SENS, INPUT);
  pinMode(RIGH_IR_SENS, INPUT);

  pinMode(ULTRA_S_ECHO, INPUT);
  pinMode(ULTRA_S_PING, OUTPUT);

  base.attach(BASE_SERVO_PIN);   
  claw.attach(CLAW_SERVO_PIN);   
  hori.attach(HORI_SERVO_PIN);    
  vert.attach(VERT_SERVO_PIN);   

  servoMUX.begin();
  servoMUX.setPWMFreq(PULSE_FREQ);
  delay(50); 

  demoMove();  //Comentar depois de mostrar aos jurados
  delay(3000);

}

void loop() {

  long tempoAteLargarObjeto =  10000;

  if (calculaDistancia() >=30){
    segueLinha();
  }
  else if (calculaDistancia >=18) {
    apanhaObjeto();
    long iniTime = millis();
    while(millis() - iniTime <= tempoAteLargarObjeto){
      segueLinha();
    }
    largaObjeto();
  }

}
