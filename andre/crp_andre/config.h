#include <Adafruit_PWMServoDriver.h>

#define BAUDRATE 9600
#define PULSE_FREQ 50

#define SERVO_GARRA 0
#define SERVO_BASE 1
#define SERVO_VERT 2
#define SERVO_HORI 3

#define INIT_GARRA_ANGLE 30
#define INIT_BASE_ANGLE 90
#define INIT_VERT_ANGLE 90
#define INIT_HORI_ANGLE 0

Adafruit_PWMServoDriver servoMUX = Adafruit_PWMServoDriver(0x40);
uint8_t servonum = 0;

int servGarraLastPos = 0;
int servBaseLastPos = 0;
int servVertLastPos = 0;
int servHoriLastPos = 0;
