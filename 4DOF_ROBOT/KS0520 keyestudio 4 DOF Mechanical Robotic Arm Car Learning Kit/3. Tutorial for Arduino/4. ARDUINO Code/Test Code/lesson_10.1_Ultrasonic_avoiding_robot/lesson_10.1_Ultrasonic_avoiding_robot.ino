/*
 keyestudio 4DOF Mechanical Robot Arm Car
 lesson 10.1
 Ultrasonic avoiding robot 
 http://www.keyestudio.com
*/ 
int AIN2=2;  //define driving pins of motor
int PWMA=3; 
int BIN2=4; //when AIN2 is low and AIN1 is high，when BIN2 is high and BIN1 is low
int PWMB=5;
int echoPin=A3;  // ultrasonic module   ECHO to A3
int trigPin=A4;  // ultrasonic module   TRIG to A4

int Ultrasonic_Ranging(){  //function of Ultrasonic Ranging
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);  //send least 10us high level to trigger ultrasonic waves to trig pin
  digitalWrite(trigPin, LOW);    
  int distance = pulseIn(echoPin, HIGH);  // reading the duration of high level
  distance= distance/58;   // Transform pulse time to distance     
  delay(50); 
  return distance;    //return distance to function
}

void advance(){    //go front
  digitalWrite(AIN2,LOW); //when AIN2 is low and AIN1 is high，motor MA turns clockwise
  analogWrite(PWMA,100); //rotation speed of motor MA is 100
  digitalWrite(BIN2,HIGH);  //when BIN2 is high and BIN1 is low，motor MB turns clockwise
  analogWrite(PWMB,100);//rotation speed of motor MB is 100
}
void turnL(){   //turn left
  digitalWrite(AIN2,HIGH);  //When AIN2 is high and AIN1 low，motor MA turns anticlockwise
  analogWrite(PWMA,100); //rotation speed of motor MB is 100
  digitalWrite(BIN2,HIGH);  //when BIN2 is high and BIN1 is low，motor MB turns clockwise
  analogWrite(PWMB,100);//rotation speed of motor MB is 100
}
void turnR(){   //turn right
  digitalWrite(AIN2,LOW); //When AIN2 is low and AIN1 is high，motor MA turns clockwise
  analogWrite(PWMA,100); //rotation speed of motor MA is 100
  digitalWrite(BIN2,LOW); //When BIN2 is low and BIN1 is high，motor MB turns anticlockwise
  analogWrite(PWMB,100); //rotation speed of motor MB is 100
}
void back(){    //go back
  digitalWrite(BIN2,LOW); //when BIN2 is low and BIN1 is high, motor MB rotates anticlockwise
  analogWrite(PWMB,100); //rotation speed of MB is 100
  digitalWrite(AIN2,HIGH);  //when AIN2 is high and AIN1 is low，motor MA rotates anticlockwise
  analogWrite(PWMA,100); //rotation speed of MA is 100
}
void stopp(){   //stop
  analogWrite(PWMA,0);  //rotation speed of MA is 0
  analogWrite(PWMB,0);  //rotation speed of MB is 0
}

void setup(){
  Serial.begin(9600);
  pinMode(2,OUTPUT);  //set ports of motor to output
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(echoPin,INPUT); //set echoPin to input
  pinMode(trigPin,OUTPUT);  //set trigPin to output
  stopp();  //stop car
}

void loop(){
  int distance=Ultrasonic_Ranging();
  Serial.print("distance=");
  Serial.println(distance);
  if(distance<30&&distance>2){  //distance<30cm
    if(distance<18){  //if distance<18, go back
      back();
      delay(300);
    }
    else{ //18<distance<30，turn right
      turnR();
      delay(300);
    }
  }
  else{   //distance>30, go forward
    advance();
  }
}
