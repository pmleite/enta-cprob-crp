/*
keyestudio 4DOF Robot Arm Car
lesson 3.1
Servo
http://www.keyestudio.com
*/ 
#define servoPin 9  //servo Pin
int pos; //angle variable of servo
int pulsewidth; //pulsewidth varaible of servo
void setup() {
  pinMode(servoPin, OUTPUT);  //set pins of servo to output
  procedure(0); //set angle of servo to 0°
}
void loop() {
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    procedure(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                   //control the rotation speed of servo
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    procedure(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                    
  }}
//Function to control servo
void procedure(int myangle) {
  pulsewidth = myangle * 11 + 500;  //Calculate pulsewidth value
  digitalWrite(servoPin,HIGH);
  delayMicroseconds(pulsewidth);   //the duration of high levle is pulsewidth
  digitalWrite(servoPin,LOW);
  delay((20 - pulsewidth / 1000));  //the period is 20ms, low levle lasts the rest of time
}//**********************************************************************************
