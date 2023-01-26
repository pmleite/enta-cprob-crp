void avancar(int velocidade){

  /*M1*/
  servoMUX.setPWM(M1_PIN_1,0,MAX_M_PULS); //pulso maximo possivel
  servoMUX.setPWM(M1_PIN_2,0,MAX_M_PULS - velocidade); //pulso que controla a velicidade

  /*M2*/
  servoMUX.setPWM(M2_PIN_1,0,MAX_M_PULS); //pulso maximo possivel
  servoMUX.setPWM(M2_PIN_2,0,MAX_M_PULS - velocidade); //pulso que controla a velicidade

}

void recuar(int velocidade){

  /*M1*/
  servoMUX.setPWM(M1_PIN_1,0,MAX_M_PULS - velocidade); //pulso maximo possivel
  servoMUX.setPWM(M1_PIN_2,0,MAX_M_PULS); //pulso que controla a velicidade

  /*M2*/
  servoMUX.setPWM(M2_PIN_1,0,MAX_M_PULS - velocidade); //pulso maximo possivel
  servoMUX.setPWM(M2_PIN_2,0,MAX_M_PULS); //pulso que controla a velicidade

}


void segueLinha() {

  int leftValue   = analogRead(LEFT_IR_SENS);
  int middleValue = analogRead(MIDD_IR_SENS);
  int rightValue  = analogRead(RIGH_IR_SENS);

  if (leftValue > 500 && middleValue > 500 && rightValue > 500) {
    // all sensors are on the line
    digitalWrite(leftMotor, HIGH);
    digitalWrite(rightMotor, HIGH);
  } else if (leftValue > 500 && middleValue > 500) {
    // sensors are on the line
    digitalWrite(leftMotor, HIGH);
    digitalWrite(rightMotor, LOW);
  } else if (middleValue > 500 && rightValue > 500) {
    // sensors are on the line
    digitalWrite(leftMotor, LOW);
    digitalWrite(rightMotor, HIGH);
  } else if (leftValue > 500) {
    // left sensor is on the line
    digitalWrite(leftMotor, HIGH);
    digitalWrite(rightMotor, LOW);
  } else if (rightValue > 500) {
    // right sensor is on the line
    digitalWrite(leftMotor, LOW);
    digitalWrite(rightMotor, HIGH);
  } else {
    // all sensors are off the line
    digitalWrite(leftMotor, LOW);
    digitalWrite(rightMotor, LOW);
  }
}