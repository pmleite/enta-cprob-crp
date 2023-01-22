/**
* Função que mede a distância com recurso ao sensor de ultrasons
*
* Para gerar um ultrason, coloca-se o pino de PING (trigger) em HIGH por 10 segundos.
* Isto vai fazer com que o sensor envie 8 ciclos ultrsónicos que irá viajar à
* velocidade do som. Imediatamente a seguir coloca-se o pino do ECHO (escuta) em HIGH
* durante, por exemplo 2s (tempo que a função pulseIn tem) que ficará a aguardar o echo 
* do sinal enviado. 
* 
* Utilizando a fórmula da velocidade do som (distancia = velocidade x tempo) , sabendo o momento
* em que o som foi gerado e o tempo que demorou o seu eco, conseguimos calcular a distância.
*
* Guarda na variavel <distancia> o valor da distancia detetada
*/
void calculaDistancia(){

  //Envio de um sinal
  digitalWrite(ULTRA_S_PING, LOW);
  delayMicroseconds(2);
  digitalWrite(ULTRA_S_PING, HIGH);
  delayMicroseconds(10);
  digitalWrite(ULTRA_S_PING, LOW);

  //Detecao do echo do sinal e conversão para cm
  distancia = pulseIn(ULTRA_S_ECHO, HIGH) * 0.034 / 2;
}


/**
* função que transforma os valores de pulsos para um escalar
* cujo o limite inferior e superior é definido pelas
* variaveis "scaleLowVal" e "scaleHighVal" nos settings
*
* @param pulseVal valor da leitura do pulso.
* @return um INTEIRO compreendido entre o valor de scaleLowVal e scaleHighVal
*/
int convertPulseValue(int pulseVal, int minPulse, int maxPulse, bool calibrate=false){

  //Se está em modo de calibração só apresenta o valor de retorno sem map
  if (calibrate) return pulseVal;
  //Se não está em modo de calibração devolve o valor de retorno mapeado na
  //escala definida por scaleLowVal e scaleHighVal
  return map(pulseVal,minPulse,maxPulse,scaleLowVal,scaleHighVal);
 
}


/**
*  função que obtém os pulsos de cor aplicando
*  o respetivo filtro do fotodiodo pela ativação das
*  seguinte portas:
*
*      S2	     S3	      Photodiode type
*      LOW	  LOW	      Red
*      LOW	  HIGH	    Blue
*      HIGH	  LOW	      Clear (No filter)
*      HIGH	  HIGH	    Green
*  
*/
void atualizaValoresDasCores(bool calibrate = false) {

    /*
      S2	  S3	    Photodiode type
      LOW	  LOW	      Red
      LOW	  HIGH	    Blue
      HIGH	LOW	      Clear (No filter)
      HIGH	HIGH	    Green
    */

    //Muda a configuração do sensor para o filtro vermelho
    digitalWrite(COLOR_SENSOR_S2,LOW);
    digitalWrite(COLOR_SENSOR_S3,LOW);
    //Le o valor do sensor e atualiza a variavel redValue
    redValue = convertPulseValue(pulseIn(COLOR_SENSOR_READ, LOW), redMin, redMax, calibrate);
    delay(COLOR_READ_DELAY);

    //Muda a configuração do sensor para o filtro Verde
    digitalWrite(COLOR_SENSOR_S2,HIGH);
    digitalWrite(COLOR_SENSOR_S3,HIGH);
    //Le o valor do sensor e atualiza a variavel greenValue
    greenValue = convertPulseValue(pulseIn(COLOR_SENSOR_READ, LOW), greenMin, greenMax, calibrate);
    delay(COLOR_READ_DELAY);
    
    //Muda a configuração do sensor para o filtro Azul
    digitalWrite(COLOR_SENSOR_S2,LOW);
    digitalWrite(COLOR_SENSOR_S3,HIGH);
    //Le o valor do sensor e atualiza a variavel blueValue
    blueValue = convertPulseValue(pulseIn(COLOR_SENSOR_READ, LOW), blueMin, blueMax, calibrate);
    delay(COLOR_READ_DELAY);

    //Muda a configuração do sensor para o filtro Branco
    digitalWrite(COLOR_SENSOR_S2,HIGH);
    digitalWrite(COLOR_SENSOR_S3,LOW);
    //Le o valor do sensor e atualiza a variavel whiteValue
    whiteValue = convertPulseValue(pulseIn(COLOR_SENSOR_READ, LOW), whiteMin, whiteMax, calibrate);
    delay(COLOR_READ_DELAY);
}


/**
* função que intrepreta os valores e devolve a cor detetada
*
* @param r valor da leitura dos pulsos do RED, convertido em escala de 0 a 255
* @param g valor da leitura dos pulsos do GREEN, convertido em escala de 0 a 255
* @param b valor da leitura dos pulsos do BLUE, convertido em escala de 0 a 255
* @param w valor da leitura dos pulsos do WHITE, convertido em escala de 0 a 255
*
* @return 0=Red, 1=Green, 2=Blue, 3=White, 4=Preto   
*/
void detetaCor(){

  if (DEBUG){
      String str = String(redValue)   + "\t" + String(greenValue) + "\t" + 
                   String(blueValue)  + "\t" + String(whiteValue) + " \t\t C: " +
                   String(detectedColor);
      
      Serial.println(str);
  }

  //Condição para o branco
  if ((whiteValue == -255 ) || ( whiteValue >0 && redValue < 0 && redValue <0 && blueValue <0)) detectedColor = 4;
  //Condição para o vermelho
  else if ((redValue   == 255 || redValue   == 0 ) || (redValue   < greenValue && redValue   < blueValue))   detectedColor = 0;
  else if ((greenValue == 255 || greenValue == 0 ) || (greenValue < redValue   && greenValue < blueValue))   detectedColor = 1;
  else if ((blueValue  == 255 || blueValue  == 0 ) || (blueValue  < redValue   && blueValue  < greenValue))  detectedColor = 2;
  else  detectedColor = 99;
}


/**
* Função que deteta o desvio do carro em relação à linha preta, lendo
* os sensores de infravermelho e comparando
*
* Os valores que são atualizados na variavel são:
* -2 -1 0 1 2
* Valor negativo está desviado para a esquerda (quanto maior o número maior o desvio)
* Valor positivo está desviado para a direita (quanto maior o número maior o desvio)
* 
* A existência de 2 valores de desvios pode ser útil para saber qual a intensidade
* da correção da rota a fazer
*/
void detetaDesvio(){

  leftSensorReading   = !digitalRead(LEFT_IR_SENSOR);
  centerSensorReading = !digitalRead(CENTER_IR_SENSOR);
  rightSensorReading  = !digitalRead(RIGHT_IR_SENSOR);

  if(DEBUG){
    Serial.println(String(leftSensorReading) + "\t" + String(centerSensorReading) + "\t" + String(rightSensorReading) + "\t" + desvio);
  }

       if (!leftSensorReading  && centerSensorReading  && !rightSensorReading) desvio =  0;
  else if (leftSensorReading   && centerSensorReading  && !rightSensorReading) desvio = -1; 
  else if (leftSensorReading   && !centerSensorReading && !rightSensorReading) desvio = -2;
  else if (!leftSensorReading  && centerSensorReading  && rightSensorReading)  desvio =  1;
  else if (!leftSensorReading  && !centerSensorReading && rightSensorReading)  desvio =  2; 
     else desvio = 99;

}

/**
* função que converte angulos para pulsos
* que serão aplicados à porta PWM do MUX
* para movimentar o respetivo servo
* 
* @param INT valor do ângulo pretendido de 0 a 180
* @return um iteiro resultante da conversão angulo -> pulso
*/
int convertAngleToPulse(int angle){
  return map(angle, 0, 180, SERVOMIN, SERVOMAX);
}


/**
* função que faz movimentar o servo pretendido
* 
* @param servo  O servo que se quer movimentar
* @param angulo O angulo para onde se quer colocar o servo
* @param speed  A velocidade de deslocação do servo
*/
int moveServo(int servo, int angulo, long speed){

        //Variavel para guardar a última posição
        int lastPos;

        //Guarda valor da ultima posição em função do servo indicado como argumento
        if (servo == 9) lastPos = servGarraLastPos;
        if (servo == 8) lastPos = servBaseLastPos;
        if (servo == 11) lastPos = servVertLastPos;
        if (servo == 10) lastPos = servHoriLastPos;
       
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
        if (servo == 9) servGarraLastPos = angulo;
        if (servo == 8) servBaseLastPos  = angulo;
        if (servo == 11) servVertLastPos  = angulo;
        if (servo == 10) servHoriLastPos  = angulo;  
}





