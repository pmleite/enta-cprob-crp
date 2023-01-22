#include <Wire.h>
#include <Adafruit_PWMServoDriver.h> 

/************************************************
     Esta secção rerefe-se apenas às
     configurações genéricas
 ************************************************/
#define COLOR_DET_CALIBRATION true  //FALSE Modo de leitura TRUE Modo de calibração
#define BAUT_RATE             9600
#define COLOR_READ_DELAY      100

/************************************************
     Esta seclção refere-se apenas às 
     configurações necessárias para o
     SENSOR de Cor
 ************************************************/
#define S0 3
#define S1 7
#define S2 5
#define S3 6
#define SOut 8

//Variaveis de controlo para medição dos pulsos de cor
int whitePW   = 0;
int redPW     = 0;
int greenPW   = 0;
int bluePW    = 0;

// Valores de calibração
// Obtidos com o programa em modo de calibração, COLOR_DET_CALIBRATION  TRUE
int redMin = 32;   // Red minimum value
int redMax = 33;   // Red maximum value

int greenMin = 114; // Green minimum value
int greenMax = 120; // Green maximum value

int blueMin = 73;  // Blue minimum value
int blueMax = 74;  // Blue maximum value

int whiteMin = 2;  // Blue minimum value
int whiteMax = 10;  // Blue maximum value

// Variaveis para a escala da função map
int scaleLowVal  = 0;
int scaleHighVal = 255;

// Variaveis para guardar os valores finais das cores.
int redValue;
int greenValue;
int blueValue;
int whiteValue;

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
// Convertidos depois, pela função convertAngleToPulse() numa escala de 0 a 180
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

//Variaveis de controlo da última posição dos servos
int servGarraLastPos =   0;
int servBaseLastPos  =   0;
int servVertLastPos  =   0;
int servHoriLastPos  =   0;