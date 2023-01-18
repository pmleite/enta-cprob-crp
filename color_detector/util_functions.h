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
	
  //Le o pulso de saida e retorna o valor
	return pulseIn(SOut, LOW);
}


int wichColor(int r, int g, int b, int w){
  
  int arr[] = {r,g,b};
  int resultColor;

  if (w == 0 || w == 255){
      resultColor = 3;
  }
  else if (r<0 && g<0 && b<0 && w<0 ) {
      resultColor = 4;
  }else{

      //Compara os valor do R e do G
      resultColor = (arr[0] > arr[1]) ? 0 : 1;

      //do maior valor obtido anteriormente compara com o B
      if (resultColor == 0){
        resultColor = (arr[0] > arr[2]) ? 0 : 2;
      }else{
        resultColor = (arr[1] > arr[2]) ? 1 : 2;    
      }
    
     /*
       Valor 0 == Vermelho
       Valor 1 == Verde
       Valor 2 == Azul
       Valor 3 == Branco
       Valor 4 == Preto
     */

  }
  return resultColor;
}



void printLogs(int r, int g, int b, int w){
    Serial.print("Red = ");
    Serial.print(r);
    Serial.print(" - Green = ");
    Serial.print(g);
    Serial.print(" - Blue = ");
    Serial.print(b);
    Serial.print(" - white = ");
    Serial.println(w);
}

	