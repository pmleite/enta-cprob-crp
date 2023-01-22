/* Variaveis de configuração base */
#define BAUD_RATE             115200
#define COLOR_READ_DELAY      50    //Não deve ser inferior a 50
#define COLOR_CALIBRATION     false
#define DEBUG                 false

/* Servos - PWM index (ports) */
#define BASE_SERVO_PWM   8
#define CLAW_SERVO_PWM   9
#define HORI_SERVO_PWM   10
#define VERT_SREVO_PWM   11

/* Motores - PWM index (porta) */
#define MOTOR1_A_PWM     0 
#define MOTOR1_B_PWM     1
#define MOTOR2_A_PWM     2
#define MOTOR2_B_PWM     3

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

// Variavel onde é guardada a cor detetada sem sempre que há 
// uma atualização das cores
int detectedColor;

// Variavel com a indicação do desvio do carro
int leftSensorReading, centerSensorReading, rightSensorReading;
int desvio;

//Variavel que armazena a distância detetada no ultrasom
long distancia;
















