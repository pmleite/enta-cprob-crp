#define IR_LEFT_PIN    2
#define IR_CENTER_PIN  4
#define IR_RIGHT_PIN   7

#define MOTOR_1_PIN_A  8   // S1
#define MOTOR_1_PIN_B  9   // S2 
#define MOTOR_2_PIN_A  12  // S3
#define MOTOR_2_PIN_B  13  // S4

#define MOTOR_1_EN_PIN 10  //Deve ser PWM
#define MOTOR_2_EN_PIN 11  //Deve ser PWM

#define BAUD_RATE      9600
#define HAS_ENA_PIN    true

int irLeftStat, irCenterStat, irRightState

/*
  S1	  S2	  S3	  S4	  ---> Result
  1	    0	    0	    1	    ---> Motor turn right
  0	    1	    1	    0   	---> Motor turn left

  0	    0	    0	    0     |
  1	    0	    0	    0     |
  0	    1	    0   	0     |--> Motor Coasts
  0	    0	    1	    0     |
  0	    0   	0   	1     |

  0	    1	    0	    1	    |--> Motor Brake
  1	    0	    1	    0     |--> Motor Brake

  X	    X	    1	    1	    |--> Short circuit
  1	    1   	X	    X     |--> Short circuit
*/
