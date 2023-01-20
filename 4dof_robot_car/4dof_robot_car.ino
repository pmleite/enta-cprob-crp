#include "config.h"
#include "PS2X_lib.h"

Servo servo_clamp;
Servo servo_base;
Servo servo_vertical;
Servo servo_horizontal;

void setup() {

//Init Serial
Serial.begin(115200);

//Associar cada servo ao respetivo pino
servo_clamp.attach(SERV_CLAMP_PIN);
servo_base.attach(SERV_BASE_PIN);
servo_vertical.attach(SERV_VERTICAL_PIN);
servo_horizontal.attach(SERV_HORIZONTAL_PIN);

//Executa a funcao de teste do movimento do braço
delay(1000);
initArmPosition(servo_base, servo_clamp, servo_vertical, servo_horizontal, SLOW_SPEED);
}

void loop() {

//  rodarBraco(150, SLOW_SPEED);
//  baixaBraco(SLOW_SPEED);
//  agararObjeto(SLOW_SPEED);
//  levantarBraco(SLOW_SPEED);
//  delay(1000);
//  rodarBraco(20, SLOW_SPEED);
//  baixaBraco(SLOW_SPEED);
//  largarObjeto(SLOW_SPEED);
//  levantarBraco(SLOW_SPEED);
//  baixaBraco(SLOW_SPEED);
//  delay(1000);
//  agararObjeto(SLOW_SPEED);
//  levantarBraco(SLOW_SPEED);
//  delay(1000);
//  rodarBraco(150, SLOW_SPEED);
//  baixaBraco(SLOW_SPEED);
//  largarObjeto(SLOW_SPEED);
//  levantarBraco(SLOW_SPEED);
//  delay(1000);

}


void largarObjeto(float speed){
  moveServo(servo_horizontal, 120, speed);
  abrirGarra(speed);
}

void agararObjeto(float speed){
  abrirGarra(speed);
  moveServo(servo_horizontal, 120, speed);
  fecharGarra(speed);
}

void abrirGarra(float speed){
  moveServo(servo_clamp, clamp_max_ang, speed);
}

void fecharGarra(float speed){
  moveServo(servo_clamp, clamp_min_ang, speed);
}

void baixaBraco(float speed){
    moveServo(servo_horizontal, 120, speed);
    moveServo(servo_vertical, 20, speed);
    moveServo(servo_horizontal, 90, speed);
    moveServo(servo_vertical, 90, speed);
}

void levantarBraco(float speed){
    moveServo(servo_vertical, 0, speed);
    moveServo(servo_horizontal, 180, speed);
}

void rodarBraco(int angle, float speed){
    moveServo(servo_base, angle, speed);
}

void initArmPosition(Servo base, Servo clamp, Servo vertical, Servo horizontal, float spd){
  moveServo(base, ((base_min_ang + base_max_ang)/2), spd);
  moveServo(vertical, 0, spd);
  moveServo(horizontal, 180, spd);
  moveServo(clamp, 0, spd);
}

void moveServo(Servo serv, int ang, float speed){
  //Avalia se o angulo desejado é maior ou menos que a posição atual.
  int curr_pos = serv.read();

  //Se o angulo desejado for maior que a posição atual então o movimento é feito com INCREMENTOS
  if (ang >= curr_pos){
    for (int n=curr_pos; n<= ang; n++){
      serv.write(n);
      printServoPosition(serv);
      delay(speed);
    }
  }

  //Se o angulo desejado for maior que a posição atual então o movimento é feito com DECREMENTOS
  else if(ang <= curr_pos){
     for (int n=curr_pos; n>= ang; n--){
      serv.write(n);
      printServoPosition(serv);
      delay(speed);
    }
  } 
}


void printServoPosition(Servo srv){
  Serial.println("POS:" + String(srv.read()));
}
