/*
 keyestudio 4DOF Mechanical Robot Arm Car
lesson 11.1
 Bluetooth Remote Control
 http://www.keyestudio.com
*/ 
int AIN2 = 2; //define the driving pins of motor
int PWMA = 3;
int BIN2 = 4; //when AIN2 is low and AIN1 is high，when BIN2 is high and BIN1 is low
int PWMB = 5;

void setup() {
  Serial.begin(9600);
  pinMode(AIN2, OUTPUT); //set ports of motor to output
  pinMode(PWMA, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(PWMB, OUTPUT);
  stopp();  //stop
}
void loop() {
  if (Serial.available() > 0) { //receive Bluetooth signals
    switch (Serial.read()) {
      case 'F': advance();  Serial.println("advance");  break;  //receive ‘F’，go forward

      case 'B': back(); Serial.println("back"); break;    //receive ‘B’，go back

      case 'L': turnL(); Serial.println("left"); break;  //receive ‘L’，turn left

      case 'R': turnR(); Serial.println("right"); break; //receive ‘R’，turn right

      case 'S': stopp();  Serial.println("stop");  break;   //receive ‘S’, stop
    }
  }
}

void advance() {   //go forward
  digitalWrite(AIN2, LOW); //when AIN2 is low and AIN1 is high，motor MA turns clockwise
  analogWrite(PWMA, 100); //rotation speed of motor MA is 100
  digitalWrite(BIN2, HIGH); //when BIN2 is high and BIN1 is low，motor MB turns clockwise
  analogWrite(PWMB, 100); //rotation speed of motor MB is 100
}
void turnL() {  //turn left
  digitalWrite(AIN2, HIGH); //when AIN2 is high and AIN1 is low，motor MA turns anticlockwise
  analogWrite(PWMA, 100); //rotation speed of motor MA is 100
  digitalWrite(BIN2, HIGH); //When BIN2 is high and BIN1 is low，motor MB turns clockwise
  analogWrite(PWMB, 100); //rotation speed of motor MB is 100
}
void turnR() {  //turn right
  digitalWrite(AIN2, LOW); //when AIN2 is low and AIN1 is high，motor MA turns clockwise
  analogWrite(PWMA, 100); //rotation speed of motor MA is 100
  digitalWrite(BIN2, LOW); //when BIN2 is low and BIN1 is high，motor MB turns anticlockwise
  analogWrite(PWMB, 100); //rotation speed of motor MB is 100
}
void back() {   //go back
  digitalWrite(BIN2, LOW); //when BIN2 is low and BIN1 is high，motor MB turns anticlockwise
  analogWrite(PWMB, 100); //rotation speed of motor MB is 100
  digitalWrite(AIN2, HIGH); //when AIN2 is high and AIN1 is low, motor MA turns anticlockwise
  analogWrite(PWMA, 100); //rotation speed of motor MA is 100
}
void stopp() {  //stop
  analogWrite(PWMA, 0); //rotation speed of motor MA is 0
  analogWrite(PWMB, 0); //rotation speed of motor MB is 0
}
