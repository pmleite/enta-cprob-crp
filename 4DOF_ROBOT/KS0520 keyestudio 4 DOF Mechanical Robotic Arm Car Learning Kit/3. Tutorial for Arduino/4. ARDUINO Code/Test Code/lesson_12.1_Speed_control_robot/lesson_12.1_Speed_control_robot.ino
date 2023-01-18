/*
 keyestudio 4DOF Mechanical Robot Arm Car
lesson 12.1
 Speed control robot
 http://www.keyestudio.com
*/
int AIN2 = 2; //define driving pins of motor
int PWMA = 3;
int BIN2 = 4; ///when AIN2 is low and AIN1 is high，when BIN2 is high and BIN1 is low
int PWMB = 5;
int speeds=100;
void setup() {
  Serial.begin(9600);
  pinMode(AIN2, OUTPUT); //set ports of motor to output
  pinMode(PWMA, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(PWMB, OUTPUT);
  stopp();  //stop
void loop() {
  if (Serial.available() > 0) { //receive Bluetooth signals
    switch (Serial.read()) {
      case 'F': advance();  Serial.println("advance");  break;  //receive ‘F’，go forward

      case 'B': back(); Serial.println("back"); break;    //receive ‘B’，go back

      case 'L': turnL(); Serial.println("turn left"); break;  //receive ‘L’，turn left

      case 'R': turnR(); Serial.println("turn right"); break; //receive ‘R’，turn right

      case 'S': stopp();  Serial.println("stop");  break;   //receive ‘S’, stop

      case 'a': speeds_a();   break;   //receive ‘a’

      case 'd': speeds_d();   break;   //receive ‘d’
    }
  }
}

void advance() {   //go back
  digitalWrite(AIN2, LOW); //When AIN2 is low and AIN1 is high，motor MA turns clockwise
  analogWrite(PWMA, speeds); //rotation speed of motor MA is speeds
  digitalWrite(BIN2, HIGH); //When BIN2 is high and BIN1 is low，motor MB turns clockwise
  analogWrite(PWMB, speeds); //rotation speed of motor MB is speeds
}
void turnL() {  //turn left
  digitalWrite(AIN2, HIGH); //When AIN2 is high and AIN1 is low，motor MA turns anticlockwise
  analogWrite(PWMA, speeds); //rotation speed of motor MA is speeds
  digitalWrite(BIN2, HIGH); //When BIN2 is high and BIN1 is low，motor MB turns clockwise
  analogWrite(PWMB, speeds); //rotation speed of motor MB is speeds
}
void turnR() {  //turn right
  digitalWrite(AIN2, LOW); //When AIN2 is low and AIN1 is high，motor MA turns clockwise
  analogWrite(PWMA, speeds); //rotation speed of motor MA is speeds
  digitalWrite(BIN2, LOW); //When BIN2 is low and BIN1 is high，motor MB turns anticlokwise
  analogWrite(PWMB, speeds); //rotation speed of motor MB is speeds
}
void back() {   //go back
  digitalWrite(BIN2, LOW); ///When BIN2 is low and BIN1 is high，motor MB turns anticlockwise
  analogWrite(PWMB, speeds); //rotation speed of motor MB is speeds
  digitalWrite(AIN2, HIGH); //When AIN2 is high and AIN1 is low, motor MA turns anticlockwise
  analogWrite(PWMA, speeds); //rotation speed of motor MA is speeds
}
void stopp() {  //stop
  analogWrite(PWMA, 0); //rotation speed of MA is 0
  analogWrite(PWMB, 0); //rotation speed of MB is 0
}

void speeds_a(){
  int a_flag=1;
  while(a_flag){
    Serial.println(speeds);
    if(speeds<=254){  //add speed up to 255
      speeds++;
      delay(10);  //change the delayed time to alter the acceleration
    }
    char blue_val=Serial.read();
    if(blue_val=='S') a_flag=0;   //receive ‘S’ to stop acceleration
  }
}

void speeds_d(){
  int d_flag=1;
  while(d_flag){
    Serial.println(speeds);
    if(speeds>=1){  //reduce speed to 0 at least
      speeds--;
      delay(10);  //change the delayed time to speed down
    }
    char blue_val=Serial.read();
    if(blue_val=='S') d_flag=0;  //receive ‘S’, stop to reduce speed
  }
}
