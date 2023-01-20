/*
 keyestudio 4DOF Mechanical Robot Arm Car
lesson 16.1
 PS2 control robotic arm
 http://www.keyestudio.com
*/
#include <PS2X_lib.h>  //add library of ps2 handle
#include <Servo.h>  //add the library of servo
PS2X ps2x;  // create PS2 Controller Class
#define PS2_DAT        12      //ps2 receiver
#define PS2_CMD        11  
#define PS2_SEL        10  
#define PS2_CLK        13  
Servo myservo1; //define the name of servo variable
Servo myservo2; //define the name of servo variable
Servo myservo3; //define the name of servo variable
Servo myservo4; //define the name of servo variable
int error=0;
byte vibrate=0;
int pos1=90,pos2=100,pos3=60,pos4=90; // define angle variable of four servos and set initial value(posture angle value when setting up)

void setup(){
  Serial.begin(9600);    //set to baud rate to 57600 when printing ps2, however, Bluetooth can't be used 
  myservo1.attach(A1);  //set control pin of servo 1 to A1
  myservo2.attach(A0);  //set control pin of servo 2 to A0
  myservo3.attach(8);   //set control pin of servo 3 to D8
  myservo4.attach(9);   //set control pin of servo 4 to D9
  myservo3.write(pos3);  //servo 3 rotates to 80° 
  delay(500);
  myservo2.write(pos2);  //servo 2 rotates to 100° 
  delay(500);
  myservo1.write(pos1);  //posture to start up, servo rotates to 90°
  delay(500);
  myservo4.write(pos4);  //servo 4 rotates to 90° 
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
  ps2x.read_gamepad(false, vibrate);
   down_ser();  //call function of servo of base
   left_ser();  //call left servo function
   right_ser(); //call right servo function
   zhuazi();  //call claw function
  
  delay(5);
}

void down_ser(){  //servo on base
  if(ps2x.Analog (PSS_LX) < 50)  //put left joystick leftward
  {
    pos1=pos1+1;
    myservo1.write(pos1);  //arm swings to left
    //delay(2);    //add delayed time to control rotation speed
    if(pos1>180)   //limit the angle of left swinging
    {
      pos1=180;
    }
  }
  if(ps2x.Analog (PSS_LX) > 200)  //put left joystick rightward
  {
    pos1=pos1-1;
    myservo1.write(pos1);  //arm swings to right
    //delay(2);
    if(pos1<1)  //limit the angle of right swinging
    {
      pos1=0;
    }
  }
}

void left_ser(){  //left servo
  if(ps2x.Analog(PSS_LY)<50)  //put left joystick forward
  {
    pos2=pos2+1;
    myservo2.write(pos2);  //arm swings forward
    //delay(2);
    if(pos2>100)   //limit the angle of forward swinging
    {
      pos2=100;
    }
  }
  if(ps2x.Analog(PSS_LY)>200)  //put left joystick backward
  {
    pos2=pos2-1;
    myservo2.write(pos2);  //arm swings back
    //delay(2);
    if(pos2<1)  //limit the angle of back swinging
    {
      pos2=0;
    }
  }
}

void right_ser(){ //right servo
  if(ps2x.Analog(PSS_RY)<50)  //put right joystick forward
  {
    pos3=pos3+1;
    myservo3.write(pos3);  //bigger arm swings forward
    //delay(2);
    if(pos3>180)   //limit the angle of forward swinging
    {
      pos3=180;
    }
  }
  if(ps2x.Analog(PSS_RY)>200)  //put right joystick backward
  {
    pos3=pos3-1;
    myservo3.write(pos3);  //bigger arm swings back
    //delay(2);
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
      delay(2);
      if(pos4>180)  //limit angle
      {
        pos4=180;
      }
   }
  if(ps2x.Analog(PSS_RX)<50) ////put right joystick leftward
  {
      myservo4.write(pos4); //servo 4 executes pose, claw gradually closes
      pos4-=3;
      delay(2);
      if(pos4<95)  //limit to open the maximum angle
      {
        pos4=95;
      }
  }
}
