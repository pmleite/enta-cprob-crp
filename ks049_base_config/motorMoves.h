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
 *
 *     ___M1___    ____M2____
 *     S0	   S1	   S2	    S3	        
 *     1	   0	    1	     0	    ---> frente
 *     0	   1	    0	     1   	  ---> tras
 *     1	   0	    0	     1	    ---> direita
 *     0	   1	    1	     0   	  ---> esquerda
 *     0	   0	    0	     0	    ---> stop
 *
 */

/**
* Pára ambos os motores. Para tal coloca todos 
* os pulsos de S0,S1-M1 e S2,S3-M2 a 0
*/
void stopCar(){
  /* M1 */  
  servoMUX.setPWM(MOTOR_1_A_PWM,0,0); 
  servoMUX.setPWM(MOTOR_1_B_PWM,0,0); 
  /* M2 */
  servoMUX.setPWM(MOTOR_2_A_PWM,0,0); 
  servoMUX.setPWM(MOTOR_2_B_PWM,0,0);
}

/**
* Coloca em adamento os dois motores no mesmo sentido.
* devido à montagem dos motores, o que é para a frente num
* pode significar para trás no outro. (Tem de ser verificado caso a caso).
* Caso isto aconteça há duas soluções. Ou altera-se a polaridade dos cabos
* do motor (se o tipo de ligação permitir), ou troca-se o valor da variavel.
* por exemplo:
* S0 passa a ser S1 e S1 passa a ser S0
*/
void moveCarForward(int speed){

  /* M1 */
  servoMUX.setPWM(MOTOR_1_A_PWM,0,MOTOR_MAX_PULSE); 
  servoMUX.setPWM(MOTOR_1_B_PWM,0,MOTOR_MAX_PULSE - speed); 
  /**
  * M2 com fator de correção
  * (Ver comentários da variavel DIF_M_SPEED)
  */
  servoMUX.setPWM(MOTOR_2_A_PWM,0,MOTOR_MAX_PULSE); 
  servoMUX.setPWM(MOTOR_2_B_PWM,0,(MOTOR_MAX_PULSE - speed) + DIF_M_SPEED); 
}

/**
* Coloca em adamento os dois motores no mesmo sentido (Oposto de andar para a frente).
* (Ver comentários do andara para a frente)
*/
void moveCarBackward(int speed){
  /* M1 */
  servoMUX.setPWM(MOTOR_1_A_PWM,0,MOTOR_MAX_PULSE - speed); 
  servoMUX.setPWM(MOTOR_1_B_PWM,0,MOTOR_MAX_PULSE); 
  /**
  * M2 com fator de correção
  * (Ver comentários da variavel DIF_M_SPEED)
  */
  servoMUX.setPWM(MOTOR_2_A_PWM,0,(MOTOR_MAX_PULSE - speed) + DIF_M_SPEED); 
  servoMUX.setPWM(MOTOR_2_B_PWM,0,MOTOR_MAX_PULSE); 
}

//Vira para a direita
void turnCarRight(int speed, int difSpeed){
  /* M1 */
  servoMUX.setPWM(MOTOR_1_A_PWM,0, MOTOR_MAX_PULSE - difSpeed); 
  servoMUX.setPWM(MOTOR_1_B_PWM,0, MOTOR_MAX_PULSE - speed); 
  /**
  * M2 com fator de correção
  * (Ver comentários da variavel DIF_M_SPEED)
  */
  servoMUX.setPWM(MOTOR_2_A_PWM,0, MOTOR_MAX_PULSE);                  
  servoMUX.setPWM(MOTOR_2_B_PWM,0, (MOTOR_MAX_PULSE - speed) + DIF_M_SPEED); 
}

//Vira para a direita
void turnCarLeft(int speed, int difSpeed){
  /* M1 */
  servoMUX.setPWM(MOTOR_1_A_PWM,0, MOTOR_MAX_PULSE); 
  servoMUX.setPWM(MOTOR_1_B_PWM,0, MOTOR_MAX_PULSE - speed); 
  /**
  * M2 com fator de correção
  * (Ver comentários da variavel DIF_M_SPEED)
  */
  servoMUX.setPWM(MOTOR_2_A_PWM,0, (MOTOR_MAX_PULSE - difSpeed));                  
  servoMUX.setPWM(MOTOR_2_B_PWM,0, (MOTOR_MAX_PULSE - speed) + DIF_M_SPEED); 
}

//Spin car Right
void spinCarRight(int speed, long timmer=0){
 
  long initTime = millis();
  Serial.println(String(millis() - initTime) + " " + String(initTime) + " " + String(timmer));

  while (millis() - initTime  <= timmer){
      /* M1 */
      servoMUX.setPWM(MOTOR_1_A_PWM,0,0);
      servoMUX.setPWM(MOTOR_1_B_PWM,0,MOTOR_MAX_PULSE - speed ); 
      /* M2 */
      servoMUX.setPWM(MOTOR_2_A_PWM,0,(MOTOR_MAX_PULSE - speed) + DIF_M_SPEED); 
      servoMUX.setPWM(MOTOR_2_B_PWM,0,0);
  }
  stopCar();
}

//Spin car Left
void spinCarLeft(int speed, long timmer=0){
 
  long initTime = millis();
  Serial.println(String(millis() - initTime) + " " + String(initTime) + " " + String(timmer));

  while (millis() - initTime  <= timmer){
      /* M1 */
      servoMUX.setPWM(MOTOR_1_A_PWM,0,MOTOR_MAX_PULSE - speed );
      servoMUX.setPWM(MOTOR_1_B_PWM,0,0); 
      /* M2 */
      servoMUX.setPWM(MOTOR_2_A_PWM,0,0); 
      servoMUX.setPWM(MOTOR_2_B_PWM,0,(MOTOR_MAX_PULSE - speed) + DIF_M_SPEED);
  }
  stopCar();
}