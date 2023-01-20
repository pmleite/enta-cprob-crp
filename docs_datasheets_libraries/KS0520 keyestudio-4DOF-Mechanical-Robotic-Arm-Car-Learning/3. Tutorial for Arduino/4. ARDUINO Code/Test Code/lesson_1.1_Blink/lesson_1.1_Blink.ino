/*
 keyestudio 4DOF Robot Arm Car
 lesson 1.1  
 Blink
 http://www.keyestudio.com
*/
int ledPin=6;// Define the LED pin at D6
void setup()
{
  pinMode(ledPin, OUTPUT);// initialize ledpin as an output.
}
void loop() // the loop function runs over and over again forever
{
  digitalWrite(ledPin, HIGH); // turn the LED on (HIGH is the voltage level)
  delay(1000); // wait for a second
  digitalWrite(ledPin, LOW); // turn the LED off by making the voltage LOW
  delay(1000); // wait for a second
}
