#include "stm32f30x_conf.h" // STM32 config
#include "30021_io.h" // Input/output library for this course
#include "stm32f30x_gpio.h"
#include "stm32f30x_i2c.h"
int main(void)
{
    init_usb_uart( 9600 ); // Initialize USB serial emulation at 9600 baud

    printf("Hello World!\n"); // Show the world you are alive!

    while(1)
    {

    }

    //Enable periphal clock
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C1, ENABLE);

    //Enable GPIO clock
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);

    //Enable alternate function
    GPIO_PinAFConfig(GPIOA, 14, GPIO_AF_4);

    //Enable alternate function
    GPIO_PinAFConfig(GPIOA, 15, GPIO_AF_4);

    //Pointer to struct
    GPIO_InitTypeDef * GPIO_InitStruct;

    //Config PA14
    GPIO_InitStruct->GPIO_Pin = GPIO_Pin_14;
    //Config alternate function
    GPIO_InitStruct->GPIO_Mode = GPIO_Mode_AF;
    //Config pull up
    GPIO_InitStruct->GPIO_PuPd = GPIO_PuPd_UP;
    //Config open drain
    GPIO_InitStruct->GPIO_Mode = GPIO_OType_OD;
    //Config speed
    GPIO_InitStruct->GPIO_Mode = GPIO_Speed_10MHz;

    GPIO_Init(GPIOA, GPIO_InitStruct);

}



