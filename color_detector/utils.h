//Função para ler o pulso de luz vermelha
int opbterPulsosDeCor(char color) {

    /*
      S2	  S3	    Photodiode type
      LOW	  LOW	      Red
      LOW	  HIGH	    Blue
      HIGH	LOW	      Clear (No filter)
      HIGH	HIGH	    Green
    */

    if (color == 'R'){
      digitalWrite(S2,LOW);
      digitalWrite(S3,LOW);
    }
    if (color == 'G'){
      digitalWrite(S2,HIGH);
      digitalWrite(S3,HIGH);
    }
    if (color == 'B'){
      digitalWrite(S2,LOW);
      digitalWrite(S3,HIGH);
    }
    if (color == 'W'){
      digitalWrite(S2,HIGH);
      digitalWrite(S3,LOW);
    }
	
  //Le o pulso de saida e retorna o valor (função do arduino)
	return pulseIn(SOut, LOW);
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
  //Variavel de controlo de avaliação da cor
  int resultColor;
  //Verifica se é branco, se sim devolve 3  
  resultColor = ( w == 0 ) ? 3 : false;
  //Verifica se é preto (todas as leituras negativas), se sim devolve 4
  resultColor = ( r<0 && g<0 && b<0 && w<0 ) ? 4 : false;
  //Verifica do r,g,b qual o maior e, dependendo do caso, devolve respetivamente 0,1,2
  resultColor = ( r > g ? 0 : 1) > b ? ( r > g ? 0 : 1 ) : 2 ;

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
void printCalibrationData(int r, int g, int b, int w){
    str = " RED -> " + String(r) + "  GREEN -> " + Stirng(g) + "  BLUE -> " + String(b) + "  WHITE -> " + String(w);
    Serial.println(str);
}

	