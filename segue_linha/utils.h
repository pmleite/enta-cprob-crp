int trackSense(){
  if (digitalRead(IR_LEFT_PIN) && digitalRead(IR_CENTER_PIN)) return 1;
  if (digitalRead(IR_RIGHT_PIN) && digitalRead(IR_CENTER_PIN)) return 2;
  if (digitalRead(IR_LEFT_PIN))   return -1;
  if (digitalRead(IR_CENTER_PIN)) return 0;
  if (digitalRead(IR_RIGHT_PIN))  return -2;
  return 99;
}

int convertAngleToPulse(int angle){
  return map(angle, 0, 180, SERVOMIN, SERVOMAX);
}

int convertSpeedToPulse(int speed){
  return map(speed, 0, 100, MOTOR_MIN_PULSE, MOTOR_MAX_PULSE);
}

int moveServo(int servo, int angulo, long speed){

        int lastPos;

        if (servo == 0) lastPos = servGarraLastPos;
        if (servo == 1) lastPos = servBaseLastPos;
        if (servo == 2) lastPos = servVertLastPos;
        if (servo == 3) lastPos = servHoriLastPos;
       
        if (lastPos < angulo){
              for (int n = lastPos; n<= angulo; n++){
                servoMUX.setPWM(servo,0,convertAngleToPulse(n));
                delay(speed);
              }
        }else{
          for (int n = lastPos; n>= angulo; n--){
                servoMUX.setPWM(servo,0,convertAngleToPulse(n));
                delay(speed);
              }
        }

        if (servo == 0) servGarraLastPos = angulo;
        if (servo == 1) servBaseLastPos  = angulo;
        if (servo == 2) servVertLastPos  = angulo;
        if (servo == 3) servHoriLastPos  = angulo;
        
}


