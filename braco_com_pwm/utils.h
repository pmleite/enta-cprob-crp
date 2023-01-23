/**
* função que converte um valor dado em angulo para
* para um intervalo proporcional dos pulso MIN, MAX
* admissovel para os servos.
*
* @param  angle valor do angulo desejado
* @return valor mapeado entre o angulo e os pulsos min,max admissiveis.
*/
int convertAngleToPulse(int angle){
  return map(angle, 0, 180, SERVOMIN, SERVOMAX);
}


/**
* função que executa um movimento de um servo
*
* @param  servo  o servo que se quer fazer mover
* @param  angulo a posisão (angulo) que se quer no servo.
* @param  speed  a velocidade do movimento (definido em constantes nos settings)
*/
void moveServo(int servo, int angulo, long speed){

        //Variavel para guardar a última posição
        int lastPos;

        //Guarda valor da ultima posição em função do servo indicado como argumento
        if (servo == 0) lastPos = servGarraLastPos;
        if (servo == 1) lastPos = servBaseLastPos;
        if (servo == 2) lastPos = servVertLastPos;
        if (servo == 3) lastPos = servHoriLastPos;
       
        //Verifica se a trajetória á crescente
        if (lastPos < angulo){
              for (int n = lastPos; n<= angulo; n++){
                servoMUX.setPWM(servo,0,convertAngleToPulse(n));
                delay(speed);
              }
        //Se a trajetória for decrescente
        }else{
          for (int n = lastPos; n>= angulo; n--){
                servoMUX.setPWM(servo,0,convertAngleToPulse(n));
                delay(speed);
              }
        }

        //Guarda a última posição do respetivo servo.
        if (servo == 0) servGarraLastPos = angulo;
        if (servo == 1) servBaseLastPos  = angulo;
        if (servo == 2) servVertLastPos  = angulo;
        if (servo == 3) servHoriLastPos  = angulo;
        
}