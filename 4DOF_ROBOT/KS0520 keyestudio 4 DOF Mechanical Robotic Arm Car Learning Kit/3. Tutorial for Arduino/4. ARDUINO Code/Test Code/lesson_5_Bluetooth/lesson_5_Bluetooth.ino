/*
 keyestudio 4DOF Mechanical Robot Arm Car
 lesson 5
 Bluetooth 
 http://www.keyestudio.com
*/ 
char blue_val;  //define a variable to receive Bluetooth signals
void setup() {
  Serial.begin(9600);  //set baud rate to 9600
}
void loop() {
  if(Serial.available() > 0)//receive Bluetooth Signals
  {
    blue_val = Serial.read();  //reception
    Serial.println(blue_val);  //Serial prints Bluetooth signals
  }
}
