/*
 * Quando se ajusta o valor da velocidade mínima deve-se ter em
 * consideração a tensão de alimentação do do circuito e a tensão
 * do motor, usando a seguinte fórmula:
 *
 *   4096 * Vm/Vin 
 *
 * Por exemplo, para uma alimentação de 6V, para um motor de 5V (normalmente é),
 * temos um pulso máximo de:
 *
 *   4096*5/6=3413. 
 *
 * Neste caso o valor não pode ultrapassar os 3413 pulsos para não danificar o(s) motor(es).
 */

//Pára ambos os motores
void stop(){
  //Pára Motor #1 e #2 (PWM 8,9 e 10,11 respetivamente)
  servoMUX.setPWM(8,0,0); servoMUX.setPWM(9,0,0);    // M1
  servoMUX.setPWM(10,0,0); servoMUX.setPWM(11,0,0);  // M2
}

//Anda para a frente
void forward(int speed){
  //Pára Motor #1 e #2 (PWM 8,9 e 10,11 respetivamente)
  servoMUX.setPWM(8,0,speed); servoMUX.setPWM(9,0,0);    //M1
  servoMUX.setPWM(10,0,speed); servoMUX.setPWM(11,0,0);  //M2
}

//Anda para trás
void backward(int speed){
  //Pára Motor #1 e #2 (PWM 8,9 e 10,11 respetivamente)
  servoMUX.setPWM(8,0,0); servoMUX.setPWM(9,0,speed);    //M1
  servoMUX.setPWM(10,0,0); servoMUX.setPWM(11,0,speed);  //M2
}

//Vira para a direita
void left(int speed, int diferential){
  //Pára Motor #1 e #2 (PWM 8,9 e 10,11 respetivamente)
  servoMUX.setPWM(8,0,(speed-diferential)); servoMUX.setPWM(9,0,speed);  //M1
  servoMUX.setPWM(10,0,0); servoMUX.setPWM(11,0,speed);                  //M2
}

//Vira para a direita
void right(int speed, int diferential){
  //Pára Motor #1 e #2 (PWM 8,9 e 10,11 respetivamente)
  servoMUX.setPWM(8,0,0); servoMUX.setPWM(9,0,speed);                     //M1
  servoMUX.setPWM(10,0,(speed-diferential)); servoMUX.setPWM(11,0,speed); //M2
}



