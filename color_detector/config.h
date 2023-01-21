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
