#include <Servo.h>



#define SERV_BASE_PIN         A1
#define SERV_HORIZONTAL_PIN   A0
#define SERV_VERTICAL_PIN     8
#define SERV_CLAMP_PIN        9


#define ULTRA_SLOW_SPEED 25
#define SLOW_SPEED 15  //Valores maiores é mais lento, max de 25
#define FAST_SPEED 0

//Definição de varíaveis com os calores máximos e mínimos para cada servo 
//Obtidos com a calibração individual

//Base rotativa
#define base_min_ang 0          //Angulo do braço virado para a direita
#define base_max_ang 180        //Angulo do braço virado para a esquerda

//Garra
#define clamp_min_ang 0         //Angulo para a garra fechada
#define clamp_max_ang 90        //Angulo para a garra aberta

//Movimento Vertical do braço
#define vertical_min_ang 0      //Angulo para a altura máxima do braço
#define vertical_max_ang 180    //Angulo para a altura mínima do braço

//Movimento Horizontal do braço
#define horizontal_min_ang 70   //Angulo para a retração minima do braço  (extensão máxima)
#define horizontal_max_ang 180  //Angulo para a retração máxima do braço  (extensão mínima)
