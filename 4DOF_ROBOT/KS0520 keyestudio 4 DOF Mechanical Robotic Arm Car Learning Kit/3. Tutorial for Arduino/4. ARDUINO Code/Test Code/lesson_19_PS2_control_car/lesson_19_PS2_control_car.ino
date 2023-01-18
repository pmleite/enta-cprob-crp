/*
 keyestudio 4DOF Mechanical Robot Arm Car
 lesson 19
 PS2 control car
 http://www.keyestudio.com
*/
#include <PS2X_lib.h>  //add library of ps2 handle
#include <Servo.h>  //add the library of servo
PS2X ps2x;  // create PS2 Controller Class
#define PS2_DAT        12      //ps2receiver
#define PS2_CMD        11  
#define PS2_SEL        10  
#define PS2_CLK        13  
Servo myservo1; //define the name of servo variable
Servo myservo2; //define the name of servo variable
Servo myservo3; //define the name of servo variable
Servo myservo4; //define the name of servo variable
int error=0;
byte vibrate=0;
int pos1=90,pos2=100,pos3=80,pos4=90; // define angle variable of four servos and set initial value(posture angle value when setting up)

int M1[20];          //define four arrays
int M2[20];          //Respectively save the angle of four servos
int M3[20];          //array length is 20, can save 0~20 angle data
int M4[20]; 
int i=0,j=0,t=0;    //i is used to save array，j is used to save the maximum value of i,t is used to exit while loop
const int AIN2=2;  //define the driving pins of motor
const int PWMA=3; 
const int BIN2=4; //when AIN2 is low and AIN1 is high, BIN2 is high and BIN1 is low
const int PWMB=5;
void setup(){
  Serial.begin(9600);   
  myservo1.attach(A1);  //set control pin of servo 1 to A1
  myservo2.attach(A0);  //set control pin of servo 2 to A0
  myservo3.attach(8);   //set control pin of servo 3 to D8
  myservo4.attach(9);   //set control pin of servo 4 to D9
  myservo3.write(pos3);  //servo 3 rotates to 80° 
  delay(500);
  myservo2.write(pos2);  //servo 2 rotates 100° 
  delay(500);
  myservo1.write(pos1);  //posture to start up, servo rotates 90°
  delay(500);
  myservo4.write(pos4);  //servo 4 rotates 90° 
  pinMode(2,OUTPUT);  //set ports of motor to output
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  error=ps2x.config_gamepad(PS2_CLK,PS2_CMD,PS2_SEL,PS2_DAT); //setup pins check for error
  if(error==0){
    Serial.println("Found Controller, configured successful");
    Serial.println("Try out all the buttons, X will vibrate the controller, faster as you press harder;");
    Serial.println("holding L1 or R1 will print out the analog stick values.");
    Serial.println("Go to www.billporter.info for updates and to report bugs.");    
  }
  else if(error==1) Serial.println("No controller found, check wiring, see readme.txt to enable debug. visit www.billporter.info for troubleshooting tips");
  else if(error==2) Serial.println("Controller found but not accepting commands. see readme.txt to enable debug. Visit www.billporter.info for troubleshooting tips");

  ps2x.enableRumble();   //enable rumble vibration motors
  ps2x.enablePressures(); //enable reading the pressure values from the buttons.
}

void loop(){
  if(error!=0) return;  
   memory();  //call memory function
   if(ps2x.Button(PSB_PAD_UP)) {         //will be TRUE as long as button is pressed
       Serial.print("Up held this hard: ");
       advance();
      }
      if(ps2x.Button(PSB_PAD_RIGHT)){
        Serial.print("Right held this hard: ");
        turnR();
      }
      if(ps2x.Button(PSB_PAD_LEFT)){
       Serial.print("LEFT held this hard: ");
        turnL();
      }
      if(ps2x.Button(PSB_PAD_DOWN)){  
       Serial.print("DOWN held this hard: ");
       back();
      }
      if(ps2x.Button(PSB_L2))
        {
          Serial.println("L2 pressed");
          stopp();
        }
         
   down_ser();  //call function of servo on base 
   left_ser();  //call left servo function
   right_ser(); //call right servo function
   zhuazi();  //all claw function
   delay(10);
}

void down_ser(){  //servo on base
  if(ps2x.Analog (PSS_LX) < 50)  //put left joystick rightward
  {
    pos1=pos1+2;
    myservo1.write(pos1);  //limit the angle of left swinging
    delay(2); //delay time to control rotation speed of servo
    if(pos1>179)   //limit the angle of left swinging
    {
      pos1=180;
    }
  }
  if(ps2x.Analog (PSS_LX) > 200)  //put left joystick rightward
  {
    pos1=pos1-2;
    myservo1.write(pos1);  //arm swings to right
    delay(2); //delay time to control rotation speed of servo
    if(pos1<1)  //limit the angle of right swinging
    {
      pos1=0;
    }
  }
}

void left_ser(){  //left servo
  if(ps2x.Analog(PSS_LY)<50)  //put left joystick forward
  {
    pos2=pos2+2;
    myservo2.write(pos2);  //swing forward
    delay(2);
    if(pos2>100)   //limit the angle of forward swinging
    {
      pos2=100;
    }
  }
  if(ps2x.Analog(PSS_LY)>200)  //put left joystick backward
  {
    pos2=pos2-2;
    myservo2.write(pos2);  //swing back
    delay(2);
    if(pos2<1)  //limit the angle of back swinging
    {
      pos2=0;
    }
  }
}

void right_ser(){ //right servo
  if(ps2x.Analog(PSS_RY)<50)  //put right joystick forward
  {
    pos3=pos3+2;
    myservo3.write(pos3);  //bigger arm swings forward
    delay(2);
    if(pos3>180)   //limit the angle of forward swinging
    {
      pos3=180;
    }
  }
  if(ps2x.Analog(PSS_RY)>200)  //put right joystick backward
  {
    pos3=pos3-2;
    myservo3.write(pos3);  //bigger arm swings back
    delay(2);
    if(pos3<80)  //limit the angle of back swinging
    {
      pos3=80;
    }
  }
}

void zhuazi(){  //servo of claw
  if(ps2x.Analog(PSS_RX)>200) //put right joystick rightward
  {
      myservo4.write(pos4);  //servo 4 moves，claw gradually opens
      pos4+=3;
      delay(1);
      if(pos4>180)  //limit angle
      {
        pos4=180;
      }
   }
  if(ps2x.Analog(PSS_RX)<50) ////put right joystick leftward
  {
      myservo4.write(pos4); //servo 4 executes pose, claw gradually closes
      pos4-=3;
      delay(1);
      if(pos4<95)  //limit the closed angle 
      {
        pos4=95;
      }
  }
}

void memory(){  //ps2 memory function
  ps2x.read_gamepad(false, vibrate);  //read controller
    if (ps2x.NewButtonState()){
//     delay(20);
     ps2x.read_gamepad(false, vibrate);
     if(ps2x.Button(PSB_L3)){ //press L3, true
      Serial.println("L3 pressed");
      M1[i]=myservo1.read();  //read the angle values of each servo
      delay(100);
      Serial.println(M1[i]);   //print the current angle value of servo 1 in serial monitor
      M2[i]=myservo2.read();
      delay(100);
      Serial.println(M2[i]);
      M3[i]=myservo3.read();
      delay(100);
      Serial.println(M3[i]);
      M4[i]=myservo4.read();
      delay(100);     
      Serial.println(M4[i]); 
      i++;  //i increases when save each time
      if(i>20)i=19;
      j=i;   //set the last value of i to j 
      delay(200);
      Serial.print("j=");
      Serial.println(j);   //print j value in serial monitor
    }
    
    if(ps2x.Button(PSB_R3)){  //If R3 is pressed, if it is, it’s true
      Serial.println("R3 pressed");
      i=0;  //i clears
      t=1;  //used for while loop
      pos1 = myservo1.read(); //read the current angle value of servo
      pos2 = myservo2.read();
      pos3 = myservo3.read();
      pos4 = myservo4.read();
      while(t){
     for(int k=0;k<j;k++){      //loop j times, execute all saved motions
     if(pos1<M1[k]){        //when the angle value of servo 1 is more than the value saved in array 1  
     while(pos1<M1[k]){        //while loop，make servo rotate to value where array is saved
              myservo1.write(pos1);        //servo 1 executes posture
              pos1++;                        //pose increases 1
              delay(10);                    //delay 10ms to control rotation speed of servo
            }
          }
          else{    //when the angle of servo 1 is more than the value saved in array 1
          while(pos1>M1[k]){   //while loop，make servo rotate to value where the array is saved
              myservo1.write(pos1);      //servo 1 executes posture
              pos1--;                  //pose reduces 1
              delay(10);                  //delay 10ms to control rotation speed of servo
            }
          }
          
          if(pos2<M2[k]){
            while(pos2<M2[k]){
              myservo2.write(pos2);
              pos2++;
              delay(10);
            }
          } 
          else{
           while(pos2>M2[k]){
             myservo2.write(pos2);
             pos2--;
             delay(10);
           }
          }
          
          if(pos3<M3[k]){
            while(pos3<M3[k]){
              myservo3.write(pos3);
              pos3++;
              delay(10);
            }
          }
         else{
            while(pos3>M3[k]){
              myservo3.write(pos3);
              pos3--;
              delay(10);
            }
          }
          
         if(pos4<M4[k]){
            while(pos4<M4[k]){
              myservo4.write(pos4);
              pos4++;
              delay(10);
            }
          }
         else{
           while(pos4>M4[k]){
             myservo4.write(pos4);
             pos4--;
             delay(10);
           }
         }
       }
       //exit loop
       ps2x.enableRumble();              //enable rumble vibration motors
       ps2x.enablePressures();
       ps2x.read_gamepad(false, vibrate); 
       vibrate = ps2x.Analog(PSAB_BLUE);
       if(ps2x.Button(PSB_START)){  //press R3 and hold down START to exit mode of motion memory
           Serial.println("break");
           t=0;
           break;        
       }
       delay(50);
     }   
    }
  }
}
void advance() {   //go forward
  digitalWrite(AIN2, LOW); //when AIN2 is low and AIN1 is high，motor MA turns clockwise
  analogWrite(PWMA, 100); //rotation speed of motor MA is 100
  digitalWrite(BIN2, HIGH); //When BIN2 is high and BIN1 is low, motor MB turns clockwise
  analogWrite(PWMB, 100); //rotation speed of motor MB is 100
}
void turnL() {  //turn left
  digitalWrite(AIN2, HIGH); //when AIN2 is high and AIN1 is low，motor MA turns anticlockwise
  analogWrite(PWMA, 100); //rotation speed of motor MA is 100
  digitalWrite(BIN2, HIGH); //When BIN2 is high and BIN1 is low, motor MB turns clockwise
  analogWrite(PWMB, 100); //rotation speed of motor MB is 100
}
void turnR() {  //turn right
  digitalWrite(AIN2, LOW); //when AIN2 is low and AIN1 is high，motor MA turns clockwise
  analogWrite(PWMA, 100); //rotation speed of motor MA is 100
  digitalWrite(BIN2, LOW); //When BIN2 is low and BIN1 is high, motor MB turns clockwise
  analogWrite(PWMB, 100); //rotation speed of motor MB is 100
}
void back() {   //go back
  digitalWrite(BIN2, LOW); //When BIN2 is low and BIN1 is high motor MB turns anticlockwise
  analogWrite(PWMB, 100); //rotation speed of motor MB is 100
  digitalWrite(AIN2, HIGH); //when AIN2 is high and AIN1 is low，motor MA turns anticlockwise
  analogWrite(PWMA, 100); //rotation speed of motor MA is 100
}
void stopp() {  //stop
  analogWrite(PWMA, 0); //rotation speed of motor MA is 0
  analogWrite(PWMB, 0); //rotation speed of motor MB is 0
}
