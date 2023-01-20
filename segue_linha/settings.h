#include <Wire.h>
#include <Adafruit_PWMServoDriver.h> 

#define IR_LEFT_PIN    2
#define IR_CENTER_PIN  4
#define IR_RIGHT_PIN   7

#define BAUD_RATE      9600

#define SLOW_SPEED      20
#define MED_SPEED       15
#define FAST_SPEED      8

#define PULSE_FREQ      50

/* 
 * Estes dois valores são depois convertidos com a função convertAngleToPulse() 
 * numa escala de 0 a 180.
*/
#define SERVOMIN        100  //Pulso para 0 graus (depende da marca dos servos), o nome não pode ser alterado
#define SERVOMAX        450  //Pulso para 180 graus (depende da marca dos servos), o nome não 

#define MOTOR_VOLTAGE    5
#define POWER_VOLTAGE_IN 6

/* 
 * Estes dois valores são depois convertidos com a função convertSpeedToPulse() 
 * numa escala de 0 a 100, sendo que 0 é a velocidade minima possivel de andamento
 * obtida com uma calibração de velocidade minima.
 */
#define MOTOR_MIN_PULSE  1000 //Pulso para a velocidade mínima (Obter com calibração)
#define MOTOR_MAX_PULSE  4096 * MOTOR_VOLTAGE / POWER_VOLTAGE_IN  //VMAX -  Calculado com a fórmula (4096 * Vm/Vin)

/*
 * Constantes que irão definir a diferenca de velocidade entre
 * motores para fazer uma curva suave ou mais acentuada.
 * Na prática será o resultado de MOTOR_MAX_PULSE - (um valaor a definir)
 */
#define DIF_TURN_SPD_S   MOTOR_MAX_PULSE - 300
#define DIF_TURN_SPD_F   MOTOR_MAX_PULSE - 1000

#define INIT_GARRA_ANGLE 30
#define INIT_BASE_ANGLE  90
#define INIT_VERT_ANGLE  90
#define INIT_HORI_ANGLE  0

//Servo PWM - Index
#define SERVO_GARRA      0   //Min 30º  Max 100º
#define SERVO_BASE       1   //Min 0º   Max 180º
#define SERVO_VERT       2   //
#define SERVO_HORI       3   //Min 0º   Max 110º

//Motor PWM - Index
#define MOTOR_1_A        8
#define MOTOR_1_B        9
#define MOTOR_2_A        10
#define MOTOR_2_B        11

Adafruit_PWMServoDriver servoMUX = Adafruit_PWMServoDriver(0x40); //Atenção ao endereço da placa! pode ser outro.
uint8_t servonum = 0;

int irLeftStat, irCenterStat, irRightState;

int servGarraLastPos =   0;
int servBaseLastPos  =   0;
int servVertLastPos  =   0;
int servHoriLastPos  =   0;

