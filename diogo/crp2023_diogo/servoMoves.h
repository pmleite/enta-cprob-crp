/**
* Move o braço para uma posição que se quer como incial
*/
void armInitPosition(long speed=SLOW_SPEED){
  moveServo(BASE_SERVO_PWM,  INIT_BASE_ANGLE,  speed);
  moveServo(VERT_SERVO_PWM,  INIT_VERT_ANGLE,  speed);
  moveServo(HORI_SERVO_PWM,  INIT_HORI_ANGLE,  speed);
  moveServo(CLAW_SERVO_PWM,  INIT_GARRA_ANGLE, speed);
}

/**
* função que abre a garra
* 
* @param INT  angulo - Angulo desejado, por defeito - OPENED_CLAW 
* @param LONG speed  - Velocidade de movimento, por defeito - SLOW_SPEED
*/
void abreGarra(int angulo=OPENED_CLAW, long speed=SLOW_SPEED){
angulo < CLOSED_CLAW || angulo > OPENED_CLAW ?
  Serial.println(String(angulo) + "º Excede o limite possivel"):
  moveServo(CLAW_SERVO_PWM, angulo, speed);
}

/**
* função que fecha a garra
* 
* @param INT  angulo - Angulo desejado, por defeito - CLOSED_CLAW 
* @param LONG speed  - Velocidade de movimento, por defeito - SLOW_SPEED
*/
void fechaGarra(int angulo=CLOSED_CLAW, long speed=SLOW_SPEED){
  angulo < CLOSED_CLAW || angulo > OPENED_CLAW ?
    Serial.println(String(angulo) + "º Excede o limite possivel"):
    moveServo(CLAW_SERVO_PWM, angulo, speed);
}

/**
* função que move verticalmente o braço
* 
* @param INT  angulo - Angulo desejado 
* @param LONG speed  - Velocidade de movimento, por defeito - SLOW_SPEED
*/
void moveVert(int angulo, long speed=SLOW_SPEED){
  angulo < VERT_MIN_ROT || angulo > VERT_MAX_ROT ?
    Serial.println(String(angulo) + "º Excede o limite possivel"):
    moveServo(VERT_SERVO_PWM, angulo, speed);    
}

/**
* função que move verticalmente o braço
* 
* @param INT  angulo - Angulo desejado 
* @param LONG speed  - Velocidade de movimento, por defeito - SLOW_SPEED
*/
void moveHori(int angulo, long speed=SLOW_SPEED){
  angulo < HORI_MIN_ROT || angulo > HORI_MAX_ROT ?
    Serial.println(String(angulo) + "º Excede o limite possivel"):
    moveServo(HORI_SERVO_PWM, angulo, speed);    
}

/**
* função que move a base o braço
* 
* @param INT  angulo - Angulo desejado 
* @param LONG speed  - Velocidade de movimento, por defeito - SLOW_SPEED
*/
void moveBase(int angulo, long speed=SLOW_SPEED){
  angulo < BASE_MIN_ROT || angulo > BASE_MAX_ROT ?
    Serial.println(String(angulo) + "º Excede o limite possivel"):
    moveServo(BASE_SERVO_PWM, angulo, speed);    
}



