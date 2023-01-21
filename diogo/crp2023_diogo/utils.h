/**
* função que transforma os valores de pulsos para um escalar
* cujo o limite inferior e superior é definido pelas
* variaveis "scaleLowVal" e "scaleHighVal" nos settings
*
* @param pulseVal valor da leitura do pulso.
* @return um INTEIRO compreendido entre o valor de scaleLowVal e scaleHighVal
*/
int convertPulseValue(int pulseVal, int minPulse, int maxPulse, bool calibrate=false){

  if (calibrate) return pulseVal;
  return map(pulseVal,minPulse,maxPulse,scaleLowVal,scaleHighVal);
 
}

/**
*  função que obtém os pulsos de cor aplicando
*  o respetivo filtro do fotodiodo pela ativação das
*  seguinte portas:
*
*      S2	  S3	    Photodiode type
*      LOW	  LOW	      Red
*      LOW	  HIGH	    Blue
*      HIGH	  LOW	      Clear (No filter)
*      HIGH	  HIGH	    Green
*  
*/
void updateColorValues(bool calibrate=false) {

    /*
      S2	  S3	    Photodiode type
      LOW	  LOW	      Red
      LOW	  HIGH	    Blue
      HIGH	LOW	      Clear (No filter)
      HIGH	HIGH	    Green
    */

    //Verifica e atualiza o valor Vermnelho
    digitalWrite(S2,LOW);
    digitalWrite(S3,LOW);
    redValue=convertPulseValue(pulseIn(SOut, LOW), redMin, redMax, calibrate);
    delay(COLOR_READ_DELAY);

    //Verifica e atualiza o valor Verde
    digitalWrite(S2,HIGH);
    digitalWrite(S3,HIGH);
    greenValue = convertPulseValue(pulseIn(SOut, LOW), greenMin, greenMax, calibrate);
    delay(COLOR_READ_DELAY);
    
    //Verifica e atualiza o valor Azul
    digitalWrite(S2,LOW);
    digitalWrite(S3,HIGH);
    blueValue = convertPulseValue(pulseIn(SOut, LOW), blueMin, blueMax, calibrate);
    delay(COLOR_READ_DELAY);

    //Verifica e atualiza o valor Branco
    digitalWrite(S2,HIGH);
    digitalWrite(S3,LOW);
    whiteValue = convertPulseValue(pulseIn(SOut, LOW), whiteMin, whiteMax, calibrate);
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
int wichColor(int r, int g, int b, int w){

  String Tmp = String(r) + "," + String(g) + "," + String(b) + "," + String(w);
  Serial.println(Tmp);

  int resultColor;

  if (w == 0 || w == 255){
      resultColor = 4;
  }
  else if ( r < g ) {
     resultColor   = 1;
    
  }
  return resultColor;
}


/**
* função que imprime as leituras dos vários pulsus.
*
* Esta função é importante fazer a leitura dos valores a inserir 
* nos parâmetros de calibração.
*
* @param r valor da leitura dos pulsos do RED 
* @param g valor da leitura dos pulsos do GREEN
* @param b valor da leitura dos pulsos do BLUE 
* @param w valor da leitura dos pulsos do WHITE 
* 
*/
void printCalibrationValues(){
     String str = "R:" + String(redValue)   + "," + "G:" + String(greenValue) + "," +
                  "B:" + String(blueValue)  + "," + "W:" + String(whiteValue);
     Serial.println(str);                 
}

int convertAngleToPulse(int angle){
  return map(angle, 0, 180, SERVOMIN, SERVOMAX);
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
        
}


	
