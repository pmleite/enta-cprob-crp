#include "config.h"
#include "movMotor.h"
#include "movBraco.h"

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


  base.attach(5);   
  claw.attach(9);   
  hori.attach(10);    
  vert.attach(11);   

  servoMUX.begin();
  servoMUX.setPWMFreq(PULSE_FREQ); 
}

void loop() {



  //Carro
  avancar(1000);
  delay(2000);
  recuar(1000);
  delay(2000);
  
  //Base
  moveServo(base, 90, 10);
  delay(1000);
  moveServo(base, 0, 10);
  delay(1000);
  moveServo(base, 180, 10);
  delay(1000);

  //Garra
  moveServo(claw, 0, 10);
  delay(1000);
  moveServo(claw, 110, 10);
  delay(1000);

  //Horizontal
  moveServo(hori, 90, 10);
  delay(1000);
  moveServo(hori, 170, 10);
  delay(1000);

  //Vertical
  moveServo(vert, 0, 10);
  delay(1000);
  moveServo(vert, 100, 10);
  delay(1000);


}
