void parar(){

  /*M1*/
  servoMUX.setPWM(M1_PIN_1,0,MAX_M_PULS); //pulso maximo possivel
  servoMUX.setPWM(M1_PIN_2,0,MAX_M_PULS); //pulso que controla a velicidade

  /*M2*/
  servoMUX.setPWM(M2_PIN_1,0,MAX_M_PULS); //pulso maximo possivel
  servoMUX.setPWM(M2_PIN_2,0,MAX_M_PULS); //pulso que controla a velicidade

}

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


void direita(int velocidade, int diff){

  /*M1*/
  servoMUX.setPWM(M1_PIN_1,0,MAX_M_PULS - velocidade); //pulso maximo possivel
  servoMUX.setPWM(M1_PIN_2,0,MAX_M_PULS - diff ); //pulso que controla a velicidade

  /*M2*/
  servoMUX.setPWM(M2_PIN_1,0,MAX_M_PULS - velocidade); //pulso maximo possivel
  servoMUX.setPWM(M2_PIN_2,0,MAX_M_PULS - diff); //pulso que controla a velicidade

}

void esquerda(int velocidade, int diff){

  /*M1*/
  servoMUX.setPWM(M1_PIN_1,0,MAX_M_PULS - diff); //pulso maximo possivel
  servoMUX.setPWM(M1_PIN_2,0,MAX_M_PULS - velocidade ); //pulso que controla a velicidade

  /*M2*/
  servoMUX.setPWM(M2_PIN_1,0,MAX_M_PULS - diff); //pulso maximo possivel
  servoMUX.setPWM(M2_PIN_2,0,MAX_M_PULS - velocidade); //pulso que controla a velicidade

}


void segueLinha() {

  //Verificar se a lógica dos sensores é esta ou iversa
  int leftValue   = analogRead(LEFT_IR_SENS);
  int middleValue = analogRead(MIDD_IR_SENS);
  int rightValue  = analogRead(RIGH_IR_SENS);

  int velocidade  = 1200; //Ajustar para o mínimo possivel
  int diff_H      = 500;  //Diferença de velocidade da roda para uma curva mais acentuada
  int diff_L      = 1000; //Diferença de velocidade da roda para uma curva mais save  

  if (leftValue == LOW && middleValue == LOW && rightValue == LOW) {
    // todos os sensores na linha
    avancar(velocidade);

  } else if (leftValue == LOW && middleValue == LOW) {
    // Sensor esquerdo e do centro na linha 
    direita(velocidade, diff_L);

  } else if (middleValue == LOW && rightValue == LOW) {
    // Sensor direito e do centro na linha  
    esquerda(velocidade, diff_L);

  } else if (leftValue == LOW) {
    // Sensor esquerdo na linha 
    direita(velocidade, diff_H);

  } else if (rightValue == LOW) {
    // Sensor direito na linha
    esquerda(velocidade, diff_H);

  } else {   
    // Todos os sensores fora da linha (para o carro)
    parar();
  }
}