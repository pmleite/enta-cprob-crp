#include <Wire.h>
#include <Adafruit_PWMServoDriver.h> 

//Dfinições genéricas 
#define BAUD_RATE      9600  //Velocidade de comunicação série
#define PULSE_FREQ       50  //Frequencia base de trabalho do MUX PWM 



/************************************************
     Esta seclção refere-se apenas às 
     configurações necessárias para os SERVOS 
 ************************************************/
//Definições para os servo motores. O valor indica a posição onde liga no MUX PWM
#define SERVO_GARRA      0   //Min 30º  Max 100º
#define SERVO_BASE       1   //Min 0º   Max 180º
#define SERVO_VERT       2   //
#define SERVO_HORI       3   //Min 0º   Max 110º

//Definições das velocidades para o braço
#define SLOW_SPEED      20
#define MED_SPEED       15
#define FAST_SPEED      8

// Definição dos valores min e max de pulsos que atuam os servos
#define SERVOMIN        100  //Pulso para 0 graus (depende da marca dos servos), o nome não pode ser alterado
#define SERVOMAX        450  //Pulso para 180 graus (depende da marca dos servos), o nome não 

#define INIT_GARRA_ANGLE 30
#define INIT_BASE_ANGLE  90
#define INIT_VERT_ANGLE  90
#define INIT_HORI_ANGLE  0



/************************************************
     Esta seclção refere-se às instâncias
     do MUX PWM 
 ************************************************/
//Instancia do MUX PWM
Adafruit_PWMServoDriver servoMUX = Adafruit_PWMServoDriver(0x40); //Atenção ao endereço da placa! pode ser outro.
uint8_t servonum = 0;

//Variaveis de controlo
int servGarraLastPos =   0;
int servBaseLastPos  =   0;
int servVertLastPos  =   0;
int servHoriLastPos  =   0;


