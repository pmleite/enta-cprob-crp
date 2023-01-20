<<<<<<< HEAD
void forward(){
  //Ambos os motores na mesma direção
  //Motor 1
  digitalWrite(MOTOR_1_PIN_A, HIGH);
  digitalWrite(MOTOR_1_PIN_B, LOW);
  //Motor 2
  digitalWrite(MOTOR_2_PIN_A, LOW);
  digitalWrite(MOTOR_2_PIN_B, HIGH); 
}

void backward(int speed=100){
  //Ambos os motores na mesma direção (oposta ao forward)
  //Motor 1
  digitalWrite(MOTOR_1_PIN_A, LOW);
  digitalWrite(MOTOR_1_PIN_B, HIGH);
  //Motor 2
  digitalWrite(MOTOR_2_PIN_A, HIGH);
  digitalWrite(MOTOR_2_PIN_B, LOW);  
}

void turnLeft(int speed=100){
  //Ambos os motores na mesma direção (oposta ao forward)
  //Motor 1
  digitalWrite(MOTOR_1_PIN_A, LOW);
  digitalWrite(MOTOR_1_PIN_B, HIGH);
  //Motor 2 (parado)
  digitalWrite(MOTOR_2_PIN_A, LOW);
  digitalWrite(MOTOR_2_PIN_B, LOW);  
}

void turnRigth(int speed=100){
  //Ambos os motores na mesma direção (oposta ao forward)
  //Motor 1 (parado)
  digitalWrite(MOTOR_1_PIN_A, LOW);
  digitalWrite(MOTOR_1_PIN_B, LOW);
  //Motor 2
  digitalWrite(MOTOR_2_PIN_A, LOW);
  digitalWrite(MOTOR_2_PIN_B, HIGH); 
}

void stop(){
  //Motor 1 (parado)
  digitalWrite(MOTOR_1_PIN_A, LOW);
  digitalWrite(MOTOR_1_PIN_B, LOW);
  //Motor 2 (parado)
  digitalWrite(MOTOR_2_PIN_A, LOW);
  digitalWrite(MOTOR_2_PIN_B, LOW);  
}

void setSpeedEqual(int speed, bool spdCTRL){
  if (spdCTRL){
    analogWrite(MOTOR_1_EN_PIN, speed);
    analogWrite(MOTOR_2_EN_PIN, speed);
  } 
=======
int trackSense(){
  if (digitalRead(IR_LEFT_PIN) && digitalRead(IR_CENTER_PIN)) return 1;
  if (digitalRead(IR_RIGHT_PIN) && digitalRead(IR_CENTER_PIN)) return 2;
  if (digitalRead(IR_LEFT_PIN))   return -1;
  if (digitalRead(IR_CENTER_PIN)) return 0;
  if (digitalRead(IR_RIGHT_PIN))  return -2;
  return 99;
}

int convertAngleToPulse(int angle){
  return map(angle, 0, 180, SERVOMIN, SERVOMAX);
}

int convertSpeedToPulse(int speed){
  return map(speed, 0, 100, MOTOR_MIN_PULSE, MOTOR_MAX_PULSE);
}

int moveServo(int servo, int angulo, long speed){

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
        
>>>>>>> 3572b4ccf0dc4682d982e2d0fb603fc229f2fa34
}


