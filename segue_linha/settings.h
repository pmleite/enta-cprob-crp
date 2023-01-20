#include <Wire.h>
#include <Adafruit_PWMServoDriver.h> 

/************************************************
     Esta secção rerefe-se apenas às
     configurações genéricas
 ************************************************/
#define BAUD_RATE      9600  //Velocidade de comunicação série
#define PULSE_FREQ       50  //Frequencia base de trabalho do MUX PWM 

/************************************************
     Esta seclção refere-se apenas às 
     configurações necessárias para os
     SENSORES Infra-Vermelhos
 ************************************************/
#define IR_LEFT_PIN    2
#define IR_CENTER_PIN  4
#define IR_RIGHT_PIN   7

#define SLOW_SPEED      20
#define MED_SPEED       15
#define FAST_SPEED      8

/************************************************
     Esta seclção refere-se apenas às 
     configurações necessárias para os MOTORES 
 ************************************************/

//Tensão de trabalho do motor e Vin. Necessário para calcular o PULSO Máximo
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

//Motor PWM - Index
#define MOTOR_1_A        8   //PWM MUX - Pino S1 do motor 1
#define MOTOR_1_B        9   //PWM MUX - Pino S2 do motor 1
#define MOTOR_2_A        10  //PWM MUX - Pino S1 do motor 2
#define MOTOR_2_B        11  //PWM MUX - Pino S2 do motor 2


/************************************************
     Esta seclção refere-se às instâncias
     do MUX PWM 
 ************************************************/
Adafruit_PWMServoDriver servoMUX = Adafruit_PWMServoDriver(0x40); //Atenção ao endereço da placa! pode ser outro.
uint8_t servonum = 0;

// Variaveis de estado dos sensores Ir
int irLeftStat, irCenterStat, irRightState;

//Variaveis de controlo da última posição dos servos
int servGarraLastPos =   0;
int servBaseLastPos  =   0;
int servVertLastPos  =   0;
int servHoriLastPos  =   0;

