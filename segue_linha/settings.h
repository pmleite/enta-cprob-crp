#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

#define IR_LEFT_PIN    3
#define IR_CENTER_PIN  4
#define IR_RIGHT_PIN   5

#define MOTOR_1_PIN_A  8
#define MOTOR_1_PIN_B  9
#define MOTOR_2_PIN_A  10
#define MOTOR_2_PIN_B  11

#define MOTOR_1_EN_PIN 12  //Deve ser PWM
#define MOTOR_2_EN_PIN 13  //Deve ser PWM

#define BAUD_RATE      9600

#define SLOW_SPEED     20
#define MED_SPEED      15
#define FAST_SPEED     8

#define PULSE_FREQ     60
#define SERVOMIN       120  //Pulso para 0 graus (depende da marca dos servos), o nome não pode ser alterado
#define SERVOMAX       575  //Pulso para 180 graus (depende da marca dos servos), o nome não 

#define INIT_GARRA_ANGLE 0
#define INIT_BASE_ANGLE  90
#define INIT_VERT_ANGLE  90
#define INIT_HORI_ANGLE  0

#define SERVO_GARRA    0
#define SERVO_BASE     1
#define SERVO_VERT     2
#define SERVO_HORI     3

Adafruit_PWMServoDriver servoMUX = Adafruit_PWMServoDriver(0x40); //Atenção ao endereço da placa do concurso
uint8_t servonum = 0;

int servGarraLastPos = 0;
int servBaseLastPos  = 0;
int servVertLastPos  = 0;
int servHoriLastPos  = 0;

/*
  S1	  S2	  S3	  S4	  ---> Result
  1	    0	    0	    1	    ---> Motor turn right
  0	    1	    1	    0   	---> Motor turn left

  0	    0	    0	    0     |
  1	    0	    0	    0     |
  0	    1	    0   	0     |--> Motor Coasts
  0	    0	    1	    0     |
  0	    0   	0   	1     |

  0	    1	    0	    1	    |--> Motor Brake
  1	    0	    1	    0     |--> Motor Brake

  X	    X	    1	    1	    |--> Short circuit
  1	    1   	X	    X     |--> Short circuit
*/
