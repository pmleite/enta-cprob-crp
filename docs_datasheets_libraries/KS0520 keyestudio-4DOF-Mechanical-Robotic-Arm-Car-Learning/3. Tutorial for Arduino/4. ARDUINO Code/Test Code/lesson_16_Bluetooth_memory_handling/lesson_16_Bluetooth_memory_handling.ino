/*
 keyestudio 4DOF Mechanical Robot Arm Car

lesson 16
 Bluetooth memory handling
 http://www.keyestudio.com
*/
#include <Servo.h>  //add the library of servo
Servo myservo1;   //define the name of servo variable
Servo myservo2;   //define the name of servo variable
Servo myservo3;   //define the name of servo variable
Servo myservo4;   //define the name of servo variable
int pos1=90,pos2=100,pos3=80,pos4=90; //define angle variable of four servos(angle value of posture when starting up)
int s1,s2,s3,s4;  //read angle value and save in the M[] array
int M1[20];          //define four arrays
int M2[20];          //save angle of four servos
int M3[20];          //the length of array is 20, save 0~20 angle data
int M4[20]; 
int i=0,j=0,t=0;    //i is used to save array，j is used to save the maximum value of i,t is used to exit while loop
void T_left(){  //turn left
  pos1+=1;
  myservo1.write(pos1);
  delay(5);
  if(pos1>=180){  //set the limited angle value of servo
    pos1=180;
  }
}

void T_right(){  //turn right
  pos1-=1;
  myservo1.write(pos1);
  delay(5);
  if(pos1<=0){
    pos1=0;
  }
}

void ZB(){  //claw closes
  pos4-=2;
  myservo4.write(pos4);
  delay(5);
  if(pos4<=95){
    pos4=95;
  }
}

void ZK(){  //claw opens
  pos4+=2;
  myservo4.write(pos4);
  delay(5);
  if(pos4>=180){
    pos4=180;
  }
}

void LF(){  //smaller arm lifts up
  pos2+=1;
  myservo2.write(pos2);
  delay(5);
  if(pos2>=100){
    pos2=100;
  }
}

void LB(){  //smaller arm lifts down
  pos2-=1;
  myservo2.write(pos2);
  delay(5);
  if(pos2<=1){
    pos2=0;
  }
}

void RF(){  // bigger arm swings forward
  pos3+=1;
  myservo3.write(pos3);
  delay(5);
  if(pos3>=180){
    pos3=180;
  }
}

void RB(){  // bigger arm swings back
  pos3-=1;
  myservo3.write(pos3);
  delay(5);
  if(pos3<=80){
    pos3=80;
  }
}

void setup(){
  Serial.begin(9600);
  myservo1.attach(A1);  //set control pin of servo 1 to A1
  myservo2.attach(A0);  //set control pin of servo 2 to A0
  myservo3.attach(8);   //set control pin of servo 3 to D8
  myservo4.attach(9);   //set control pin of servo 4 to D9
  myservo3.write(pos3);  //servo 3 rotates to 80° 
  delay(500);
  myservo2.write(pos2);  //servo 2 rotates to 100° 
  delay(500);
  myservo1.write(pos1);  //posture to start up, servo1 rotates to 90°
  delay(500);
  myservo4.write(pos4);  //servo 4 rotates to 90° 
  
}

void loop(){
  if(Serial.available()>0){  //determine if Bluetooth receives signals
    switch(Serial.read()){
      case 'Q':while('Q'){
        LF(); //smaller arm lifts up
        if(Serial.read()=='s')break;
      }break;
      case 'E':while('E'){
        LB(); //smaller arm lifts down
        if(Serial.read()=='s')break;
      }break;
      case 'l':while('l'){
        T_left(); //arm turns left
        if(Serial.read()=='s')break;
      }break;
      case 'r':while('r'){
        T_right();  //arm turns right
        if(Serial.read()=='s')break;
      }break;
      case 'f':while('f'){
        RF(); //bigger arm swings forward
        if(Serial.read()=='s')break;
      }break;
      case 'b':while('b'){
        RB(); //arm swings back
        if(Serial.read()=='s')break;
      }break;
      case 'V':while('V'){
        ZK(); //claw opens
        if(Serial.read()=='s')break;
      }break;
      case 'P':while('P'){
        ZB(); //claw closes
        if(Serial.read()=='s')break;
      }break; 
      case 't': {  //receive‘t’，remember
        M1[i]=myservo1.read();  //save the current angle of each servo to array
        delay(100); //delay time to save angle value
        M2[i]=myservo2.read();
        delay(100);
        M3[i]=myservo3.read();
        delay(100);
        M4[i]=myservo4.read();
        delay(100);
        i++;  //i increases 1 when save each time
        j=i;  //set the value of i to j
        Serial.print("j:");
        Serial.println(j);
        if(i>20)i=19;        //set the previous array to 20
        delay(200);
      }break;
      case 'i': { //receive‘i’，execute
        i=0;  //i clears
        t=1;  //used for while loop
        pos1=myservo1.read(); //set the current angle value to pos
        pos2=myservo2.read();
        pos3=myservo3.read();
        pos4=myservo4.read();
        while(t){
          for(int k=0;k<j;k++){   //repeat j times, execute all saved motions 
            if(pos1<M1[k]){ //when the angle value of servo 1 is less than the value saved in array 1 
              while(pos1<M1[k]){  //while loop, make servo rotate where value is saved in array
                myservo1.write(pos1); //servo 1 executes posture
                pos1++;   //pos1 increases 1
                delay(8); //delay in 8ms to control rotation speed of servo
              }
            }
            else{   //when the angle of servo 1 is more than the value saved in array 1 
              while(pos1>M1[k]){  //while loop, make servo rotate where value is saved in array
                myservo1.write(pos1); //servo 1 executes posture
                pos1--;   //pos1 reduces 1
                delay(8); //delay in 8ms to control rotation speed of servo
              }
            }
        //the same below
            if(pos2<M2[k]){
              while(pos2<M2[k]){
                myservo2.write(pos2);
                pos2++;
                delay(8);
              }
            }
            else{
              while(pos2>M2[k]){
                myservo2.write(pos2);
                pos2--;
                delay(8);
              }
            }
  
            if(pos3<M3[k]){
              while(pos3<M3[k]){
                myservo3.write(pos3);
                pos3++;
                delay(8);
              }
            }
            else{
              while(pos3>M3[k]){
                myservo3.write(pos3);
                pos3--;
                delay(8);
              }
            }
  
            if(pos4<M4[k]){
              while(pos4<M4[k]){
                myservo4.write(pos4);
                pos4++;
                delay(8);
              }
            }
            else{
              while(pos4>M4[k]){
                myservo4.write(pos4);
                pos4--;
                delay(8);
              }
            }
            
          }
          if(Serial.available()>0){ //in order to exit loop
            if(Serial.read()=='t'){ //receive‘i’and‘t’
              t=0;  //set t to 0，exit while loop
              break;  //exit
            }
          }
      }
        if(Serial.read()=='s')break;
      }break;
      
    } 
  }
  delay(5);
}
