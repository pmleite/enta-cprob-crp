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


//função que intrepreta os valores e devolve a cor
int wichColor(int r, int g, int b, int w){

  //Variavel de controlo de avaliação da cor
  int resultColor;
  /***********************************************************
    Esta avaliação vai decidir, a partir dos 4 valores 
    passados por parameteros r,g,b,w qual a cor que está
    a ser detetada cooresponde à cor detetada.
    @return: 0=Red, 1=Green, 2=Blue, 3=White, 4=Preto    
    **********************************************************/
  //Verifica se é branco, se sim devolve 3  
  resultColor = ( w == 0 ) ? 3 : false;
  //Verifica se é preto (todas as leituras negativas), se sim devolve 4
  resultColor = ( r<0 && g<0 && b<0 && w<0 ) ? 4 : false;
  //Verifica do r,g,b qual o maior e, dependendo do caso, devolve respetivamente 0,1,2
  resultColor = ( r > g ? 0 : 1) > b ? ( r > g ? 0 : 1 ) : 2 ;

  return resultColor;
}



void printCalibrationData(int r, int g, int b, int w){
    Serial.print("Red = ");
    Serial.print(r);
    Serial.print(" - Green = ");
    Serial.print(g);
    Serial.print(" - Blue = ");
    Serial.print(b);
    Serial.print(" - white = ");
    Serial.println(w);
}

	