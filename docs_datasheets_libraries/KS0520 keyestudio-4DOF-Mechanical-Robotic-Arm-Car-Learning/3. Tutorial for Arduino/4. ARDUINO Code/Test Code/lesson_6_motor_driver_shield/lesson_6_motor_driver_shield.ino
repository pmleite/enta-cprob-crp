/*
 keyestudio 4DOF Mechanical Robot Arm Car
 lesson 6
 motor driver shield
 http://www.keyestudio.com
*/ 
int AIN2=2;  //define direction control pin of motor A as D2
int PWMA=3;  //define speed control pin of motor A as D3
int BIN2=4;   //define direction control pin of motor B as D4
int PWMB=5; //define speed control pin of motor B as D5

void setup(){
  pinMode(AIN2,OUTPUT);  //set ports of motor to output
  pinMode(PWMA,OUTPUT);
  pinMode(BIN2,OUTPUT);
  pinMode(PWMB,OUTPUT);
}
void loop(){  //go forward for 1s, back for 1s, turn left for 1s, right for 1s and stop for 1s
    //Go front
  digitalWrite(AIN2,LOW); //If AIN2 is low, AIN1 is high，motor MA turns clockwise
  analogWrite(PWMA,120); //rotation speed of motor MA is 120
  digitalWrite(BIN2,HIGH);  //If BIN2 is high, BIN1 is low，motor MB turns clockwise
  analogWrite(PWMB,120);//rotation speed of motor MB is 120
  delay(1000);
  
    //Go back
  digitalWrite(BIN2,LOW); //if BIN2 is low, BIN1 is high，motor MB turns anticlockwise
  analogWrite(PWMB,80); //rotation speed of motor MB is 80
  digitalWrite(AIN2,HIGH);  //AIN2 is high,AIN1 is low，motor MA turns anticlockwise
  analogWrite(PWMA,80); //rotation speed of motor MA is 80
  delay(1000);
  
    //Turn Left
  digitalWrite(AIN2,HIGH);  //If AIN2 is high, AIN1 is low，motor MA turns anticlockwise
  analogWrite(PWMA,120); //rotation speed of motor MA is 120
  digitalWrite(BIN2,HIGH);  //BIN2 is high,BIN1 is low，motor MB turns clockwise
  analogWrite(PWMB,120);//rotation speed of motor MB is 120
  delay(1000);
  
  //Turn right
  digitalWrite(AIN2,LOW); //If AIN2 is low, AIN1 is high，motor MA turns clockwise
  analogWrite(PWMA,80); //rotation speed of motor MA is 80
  digitalWrite(BIN2,LOW); //If BIN2 is low, and BIN1 is high，motor MB turns anticlockwise
  analogWrite(PWMB,80); //rotation speed of motor MB is 80
  delay(1000);

  //Stop
  analogWrite(PWMA,0);  //rotation speed of motor MA is 0
  analogWrite(PWMB,0);  //rotation speed of motor MB is 0
  delay(1000);
}
