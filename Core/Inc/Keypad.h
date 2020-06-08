#include "stm32f3xx_hal.h"

 //R - ROWS OUTPUT
 //C - COLUMNS INPUT

#define R1_PORT GPIOE
#define R1_PIN GPIO_PIN_7
#define R2_PORT GPIOB
#define R2_PIN GPIO_PIN_1
#define R3_PORT GPIOC
#define R3_PIN GPIO_PIN_5
#define R4_PORT GPIOA
#define R4_PIN GPIO_PIN_7
#define C1_PORT GPIOA
#define C1_PIN GPIO_PIN_5
#define C2_PORT GPIOF
#define C2_PIN GPIO_PIN_4
#define C3_PORT GPIOA
#define C3_PIN GPIO_PIN_3
#define C4_PORT GPIOA
#define C4_PIN GPIO_PIN_1

char read_pad(void);
