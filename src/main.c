#include "stm32f30x_conf.h" // STM32 config
#include "30021_io.h" // Input/output library for this course
#include "stm32f30x_gpio.h"
#include "stm32f30x_i2c.h"



int main(void)
{
    init_usb_uart( 9600 ); // Initialize USB serial emulation at 9600 baud

    printf("Hello World!\n"); // Show the world you are alive!

    RCC->AHBENR |= RCC_AHBENR_GPIOBEN;
    //////////////////////////////////////////////////////
    //MODE, TYPE, SPEED, AND ALTERNATE FUNCTION:
    //Mode register set for alternate function - pin 8 and 9
    GPIOB->MODER &= ~GPIO_MODER_MODER8_0;
    GPIOB->MODER |= GPIO_MODER_MODER8_1;
    GPIOB->MODER &= ~GPIO_MODER_MODER9_0;
    GPIOB->MODER |= GPIO_MODER_MODER9_1;

    //Type register open drain
    GPIOB->OTYPER |= GPIO_OTYPER_OT_8;
    GPIOB->OTYPER |= GPIO_OTYPER_OT_9;

    //Set speed, lowest speed
    GPIOB->OSPEEDR &= ~GPIO_OSPEEDER_OSPEEDR8_0;
    GPIOB->OSPEEDR &= ~GPIO_OSPEEDER_OSPEEDR9_0;

    //Set pull up
    GPIOB->PUPDR = (1<<18) | (1<<16);

    //Set alternate functions for pin 8 and 9
    GPIOB->AFR[1] = (1<<6) | (1<<2);

    //////////////////////////////////////////////////////
    //Enable I2C #1
    RCC->APB1ENR |= RCC_APB1ENR_I2C1EN;
    //Timing using the excel sheet
    I2C1->TIMINGR = (uint32_t)0x0010020A;
    //Enable peripheral
    I2C1->CR1 |= I2C_CR1_PE;

    //////////////////////////////////////////////////////
    //Shift SADD (Slave address) 1 bit left
    I2C1->CR2 |= (0x90 << 1);
    //Set read/write
    I2C1->CR2 &= ~I2C_CR2_RD_WRN;
    //Number of bytes
    I2C1->CR2 |= (1 << 16);
    //Establish start condition
    I2C1->CR2 |= I2C_CR2_START;
//    //Confirm start condition
//    while(I2C1->CR2 & I2C_CR2_START);
//    //Write a byte to the transmit data register
//        I2C1->TXDR = 0x2C;
//    //Confirm transmit by making sure the TXDR is empty
//    while(!(I2C1->ISR & I2C_ISR_TXE));
//    //Establish a stop condition
//        I2C1->CR2 |= I2C_CR2_STOP;
//    //Confirm a stop condition
//    while(I2C1->CR2 & I2C_CR2_STOP);


    while(1)
    {

    }



}



