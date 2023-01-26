#include <Servo.h>
#include <Adafruit_PWMServoDriver.h>
#include <Wire.h>

#define  LEFT_IR_SENS A0 //Acertar o pino consoante ligação 
#define  MIDD_IR_SENS A1 //Acertar o pino consoante ligação 
#define  RIGH_IR_SENS A2 //Acertar o pino consoante ligação 

#define BAUD_RATE        9600

#define BASE_SERVO_PIN   5
#define CLAW_SERVO_PIN   9
#define HORI_SERVO_PIN   10
#define VERT_SERVO_PIN   11

#define M1_PIN_1   0
#define M1_PIN_2   1
#define M2_PIN_1   2
#define M2_PIN_2   3

//Pinos do sensor ultrasonico
#define ULTRA_S_PING     2
#define ULTRA_S_ECHO     3

#define MAX_M_PULS       2600

#define PULSE_FREQ       50

Servo base;  //ligado ao pino 5
Servo claw;  //ligado ao pino 9 
Servo hori;  //ligado ao pino 10 
Servo vert;  //ligado ao pino 11

//Atenção ao endereço da placa! pode ser outro.
Adafruit_PWMServoDriver servoMUX = Adafruit_PWMServoDriver(0x47); 
