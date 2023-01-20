/*
 keyestudio 4DOF Mechanical Robot Car
lesson 9.1
Ultrasonic Follow Robot 
http://www.keyestudio.com
*/ 
int AIN2=2;  //define driving pins of servo
int PWMA=3; 
int BIN2=4; //When AIN2 is high and AIN1 is low，
int PWMB=5;
int echoPin=A3;  // ultrasonic module   ECHO to A3
int trigPin=A4;  // ultrasonic module   TRIG to A4

int Ultrasonic_Ranging(){  //Ultrasonic_Ranging Function
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);  //send least 10us high level to trigger ultrasonic waves to trig pin
  digitalWrite(trigPin, LOW);    
  int distance = pulseIn(echoPin, HIGH);  // reading the duration of high level
  distance= distance/58;   // Transform pulse time to distance     
  delay(50); 
  return distance;    //return distance to this function
}

void advance(){    //car goes front
  digitalWrite(AIN2,LOW); //when AIN2 is low and AIN1 is high，motor MA turns clockwise
  analogWrite(PWMA,100); //rotation speed of motor MA is 100
  digitalWrite(BIN2,HIGH);  //when BIN2 is high and BIN1 is low，motor MB turns clockwise
  analogWrite(PWMB,100);//rotation speed of motor MB is 100
}
void turnL(){   //turn left
  digitalWrite(AIN2,HIGH);  //when AIN2 is high and AIN1 is low，motor MA turns anticlockwise
  analogWrite(PWMA,100); //rotation speed of motor MA is 100
  digitalWrite(BIN2,HIGH);  //When BIN2 is high and BIN1 is low，motor MB turns clockwise
  analogWrite(PWMB,100);//rotation speed of motor MB is 100
}
void turnR(){   //turn right
  digitalWrite(AIN2,LOW); //When AIN2 is low and AIN1 is high，motor MA turns clockwise
  analogWrite(PWMA,100); //rotation speed of motor MA is 100
  digitalWrite(BIN2,LOW); //When BIN2 is low and BIN1 is high，motor MB turns anticlockwise
  analogWrite(PWMB,100); //Rotation speed of motor MB is 100
}
void back(){    //go back
  digitalWrite(BIN2,LOW); //When BIN2 is low and BIN1 is high，motor MB turns anticlockwise
  analogWrite(PWMB,100); //rotation speed of motor MB is 100，
  digitalWrite(AIN2,HIGH);  //When AIN2 is high and AIN1 is low，motor MA turns anticlockwise
  analogWrite(PWMA,100); //rotation speed of motor MA is 100
}
void stopp(){   //stop
  analogWrite(PWMA,0);  //rotation speed of motor MA is 0
  analogWrite(PWMB,0);  //rotation speed of motor MB is 0
}

void setup(){
  Serial.begin(9600);
  pinMode(2,OUTPUT);  //set ports of motor to output
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(echoPin,INPUT);    //set echoPin to input
  pinMode(trigPin,OUTPUT);  //set trigPin to output
  stopp();  //stop car
}

void loop(){
  int distance=Ultrasonic_Ranging();  
  Serial.print("distance=");
  Serial.println(distance);
  if(distance<40&&distance>2){    //When distance<40 or distance>2
    if(distance<20){  //if distance<20, go back
      if(distance<15){
        back();
      }
      else{
        stopp();
      }
    }
    else{ //When 20< distance<35, go forward
      advance();
    }
  }  
  else{   //distance>35 or distance≤20，stop
    stopp();
  }
}
