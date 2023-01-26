int calculaDistancia(){

  //Envio de um sinal
  digitalWrite(ULTRA_S_PING, LOW);
  delayMicroseconds(2);
  digitalWrite(ULTRA_S_PING, HIGH);
  delayMicroseconds(10);
  digitalWrite(ULTRA_S_PING, LOW);

  //Detecao do echo do sinal e conversão para cm
  return pulseIn(ULTRA_S_ECHO, HIGH) * 0.034 / 2;
}


void demoMove(){

  //Carro
  avancar(1000);
  delay(2000);
  recuar(1000);
  delay(2000);
  
  //Base
  moveServo(base, 90, 10);
  delay(1000);
  moveServo(base, 0, 10);
  delay(1000);
  moveServo(base, 180, 10);
  delay(1000);

  //Garra
  moveServo(claw, 0, 10);
  delay(1000);
  moveServo(claw, 110, 10);
  delay(1000);

  //Horizontal
  moveServo(hori, 90, 10);
  delay(1000);
  moveServo(hori, 170, 10);
  delay(1000);

  //Vertical
  moveServo(vert, 0, 10);
  delay(1000);
  moveServo(vert, 100, 10);
  delay(1000);

}