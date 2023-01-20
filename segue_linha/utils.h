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
}


