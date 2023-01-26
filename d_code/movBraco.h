
void apanhaObjeto(){
   //movimento para agarrar objeto
}


void largaObjeto(){
   //Movimento para largar objeto
}


void moveServo(Servo servo, int angulo, long speed){
        
        //identifica a posisão do servo
        int lastPos  = servo.read();

        //Verifica se a trajetória á crescente
        if (lastPos < angulo){
              for (int n = lastPos; n<= angulo; n++){
                servo.write(n);
                delay(speed);
              }
        //Se a trajetória for decrescente
        }else{
          for (int n = lastPos; n>= angulo; n--){
                servo.write(n);
                delay(speed);
              }
        }
}
