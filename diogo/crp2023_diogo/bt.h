  void BTmove() {
  
  if (Serial.available() > 0 ? bt_receive_val=Serial.read() : false) {
    char bt_receive_val = Serial.read();
    switch (bt_receive_val) {
      case 'F':
        moveCarForward(MED_SPEED);
      case 'B':
        moveCarBackward(MED_SPEED);
      case 'R':
        turnCarRight(MED_SPEED, DIF_M_SPEED);
      case 'L':
        turnCarLeft(MED_SPEED, DIF_M_SPEED);
      default:
        // handle unexpected input
        break;
    }
  }
}

