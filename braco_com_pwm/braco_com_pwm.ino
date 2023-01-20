#include "settings.h"
#include "utils.h"
#include "servo_moves.h"


void setup() {

  //Init Serial
  Serial.begin(BAUD_RATE);
  delay(500);

  servoMUX.begin();
  servoMUX.setPWMFreq(PULSE_FREQ);
  delay(500);

  //Executa a funcao de teste do movimento do braço
  armInitPosition();

}

void loop() {


}


