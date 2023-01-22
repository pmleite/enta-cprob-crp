#include <Wire.h>
#include <Adafruit_PWMServoDriver.h> 

/* Variaveis de configuração base */
#define BAUD_RATE             115200
#define COLOR_READ_DELAY      50    //Não deve ser inferior a 50
#define COLOR_CALIBRATION     false
#define DEBUG                 false
#define PULSE_FREQ            50    //Frequencia base de trabalho do MUX PWM 

/* Servos - PWM index (ports) */
#define BASE_SERVO_PWM   8
#define CLAW_SERVO_PWM   9
#define HORI_SERVO_PWM   10
#define VERT_SERVO_PWM   11

/**
* Definição dos valores min e max de pulsos que atuam os servos
* Convertidos depois, pela função convertAngleToPulse() numa escala
* de 0 a 180
*/
#define SERVOMIN        100  //Pulso para 0 graus (depende da marca dos servos), o nome não pode ser alterado
#define SERVOMAX        450  //Pulso para 180 graus (depende da marca dos servos), o nome não 

/**
* Angulos inciais. Atenção aos limites mecânicos
*/
#define INIT_GARRA_ANGLE 30
#define INIT_BASE_ANGLE  90
#define INIT_VERT_ANGLE  90
#define INIT_HORI_ANGLE  0

/**
* Angulos maximos e minimos para cada servo.
* Por limitações mecânicas nem todos os servos, do robot, podem
* operar de 0 a 180 grau. Estes valores previnem exceder os
* limites possiveis para cada um (Ver funções de movimento dos seros)
*/
#define OPENED_CLAW       120
#define CLOSED_CLAW       30

#define BASE_MAX_ROT      170
#define BASE_MIN_ROT      30

#define VERT_MAX_ROT      110
#define VERT_MIN_ROT      0

#define HORI_MAX_ROT      0
#define HORI_MIN_ROT      180

/** 
* Variaveis com velocidades de movimento das garras, 
* na prática são valores de pausa para o delay().
* quandot maior a pausa mais lento é o movimento 
*/
#define SLOW_SPEED      20
#define MED_SPEED       15
#define FAST_SPEED      8

/* Motores - PWM index (porta) */
#define MOTOR_1_A_PWM     0 //Deve ser 0, no meu mux o 1 está avaraido
#define MOTOR_1_B_PWM     1 
#define MOTOR_2_A_PWM     2
#define MOTOR_2_B_PWM     3

/**
* Tensão de trabalho do motor e Vin. 
* Necessário para calcular o PULSO Máximo mediante a fórmula:
*
* 4096 * Vm/Vin
*/
#define MOTOR_VOLTAGE    5
#define POWER_VOLTAGE_IN 6

/**
* MOTOR_MIN_PULSE
* Pulso mínimo do motor (velocidade minima). Este valor deve ser consiguido
* testan qual o valor que faz com que o robot começe a andar, uma vez que 
* vai depender do seu peso, carga das beterrias e tipo de motor
* 
* MOTOR_MAX_PULSE
* Pulso máximo do motor (velocidade máxima). Este valor é calculado usando
* a fórmula:
* 
*  4096 * Vm/Vin
* 
*  Vm = MOTOR_VOLTAGE, Vin=POWER_VOLTAGE_IN
*/
#define MOTOR_MIN_PULSE  2200
#define MOTOR_MAX_PULSE  4096 * MOTOR_VOLTAGE / POWER_VOLTAGE_IN 

/**
* Calibração dos motores
* Esta variavel é usada apenas em um motor como fator de calibração
* se o carro, quando for dada instrução de seguir em frente, tiver um
* desvio, devemos alterar este valor para compensar e alinhar o carro
* pode ter valor positivo ou negativo, exp:  -100 ou + 100
*/
#define DIF_M_SPEED  0

/* Sensor de cor - Pinos */
#define COLOR_SENSOR_S0   5
#define COLOR_SENSOR_S1   9
#define COLOR_SENSOR_S2   10
#define COLOR_SENSOR_S3   11
#define COLOR_SENSOR_READ A3

/* Sensor Ultrasonico - Pinos */
#define ULTRA_S_PING     12
#define ULTRA_S_ECHO     13

/* Sensor de Infra Vermelhos - Pinos */
#define LEFT_IR_SENSOR   2
#define CENTER_IR_SENSOR 3
#define RIGHT_IR_SENSOR  4

/* LED - Pino */
#define LED_PIN          A2

//Variaveis de controlo do programa
int redMin    = 24;     // Pulso mínimo (vermelho)
int redMax    = 25;     // Pulso máximo (vermelho)

int greenMin  = 83;  // Pulso mínimo (Verde)
int greenMax  = 85;  // Pulso máximo (Verde)

int blueMin   = 53;    // Pulso mínimo (Azul)
int blueMax   = 54;    // Pulso máximo (Azul)

int whiteMin  = 6;    // Pulso mínimo (Branco)
int whiteMax  = 7;   // Pulso máximo (Branco)

// Variaveis para a escala da função map
int scaleLowVal  = 0;
int scaleHighVal = 255;

// Variaveis que estão constantemente a serem atualizadas com os
// Valores da leitura das cores
int redValue;
int greenValue;
int blueValue;
int whiteValue;

/**
* Variavel onde é guardada a cor detetada sem sempre que há 
* uma atualização das cores
*/
int detectedColor;

/**
* Variavel com a indicação do desvio do carro
*/
int leftSensorReading, centerSensorReading, rightSensorReading;
int desvio;

/**
* Variavel que armazena a distância detetada no ultrasom
*/
long distancia;

/**
* Variaveis de controlo onde é guardada a última 
* posição conhecida dos servos
*/
int servGarraLastPos =   0;
int servBaseLastPos  =   0;
int servVertLastPos  =   0;
int servHoriLastPos  =   0;

/**
* Instância do MUX PWM
*/
Adafruit_PWMServoDriver servoMUX = Adafruit_PWMServoDriver(0x40); //Atenção ao endereço da placa! pode ser outro.
//uint8_t servonum = 0;
















