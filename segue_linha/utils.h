int trackSense(){
  if (digitalRead(IR_LEFT_PIN) && digitalRead(IR_CENTER_PIN)) return -1;
  if (digitalRead(IR_RIGHT_PIN) && digitalRead(IR_CENTER_PIN)) return -2;
  if (digitalRead(IR_LEFT_PIN))   return 1;
  if (digitalRead(IR_CENTER_PIN)) return 0;
  if (digitalRead(IR_RIGHT_PIN))  return 2;
  return 99;
}

