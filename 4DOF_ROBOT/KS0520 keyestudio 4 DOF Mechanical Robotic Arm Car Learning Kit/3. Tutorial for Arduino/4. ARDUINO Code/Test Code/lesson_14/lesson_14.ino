/*
  keyestudio 4DOF Mechanical Robot Arm Car

  lesson 14
  http://www.keyestudio.com
*/
#include <Servo.h>
Servo myservo1,myservo2,myservo3,myservo4;
int pos1=90,pos2=100,pos3=80,pos4=90;//initialize angle values of four servos
void setup(){
  myservo1.attach(A1);  //0~180---90,servo 1, servo on base is connected to A1
  myservo2.attach(A0);  //0~100---100,servo 2, left servo is connected to A0
  myservo3.attach(8); //80~180---80,servo 3, right servo is connected to D8
  myservo4.attach(9); //90~180---90, servo 4, servo on claw is connected to D9
  delay(1000);
  myservo1.write(pos1); //servo 1 rotates to 90°
  myservo2.write(pos2); //servo 2 rotates to 100°
  myservo3.write(pos3); //servo 3rotates to 80°
  myservo4.write(pos4); //servo 4 rotates to 90° 
}
void loop(){
}
