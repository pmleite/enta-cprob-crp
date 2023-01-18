//Configurações gerais
#define COLOR_DET_CALIBRATION false  //FALSE Modo de leitura TRUE Modo de calibração
#define BAUT_RATE             115200
#define COLOR_READ_DELAY      100

//Pinos do detetor de COR
#define S0 3
#define S1 7
#define S2 5
#define S3 6
#define SOut 8

//Variaveis para medição dos pulsos de cor
int whitePW = 0;
int redPW = 0;
int greenPW = 0;
int bluePW = 0;

// Valores de calibração
// Obtidos com o programa em modo de calibração, COLOR_DET_CALIBRATION  TRUE
int redMin = 13; // Red minimum value
int redMax = 20; // Red maximum value

int greenMin = 69; // Green minimum value
int greenMax = 71; // Green maximum value

int blueMin = 36; // Blue minimum value
int blueMax = 37; // Blue maximum value

int whiteMin = 4; // Blue minimum value
int whiteMax = 5; // Blue maximum value

// Variaveis para guardar os valores finais das cores.
int redValue;
int greenValue;
int blueValue;
int whiteValue;