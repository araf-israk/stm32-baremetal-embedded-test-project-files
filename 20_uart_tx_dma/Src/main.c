#include <stdio.h>
#include <stdint.h>
#include "stm32f4xx.h"
#include "uart.h"
#include "adc.h"
#include "systick.h"
#include "tim.h"
#include "exti.h"

#define GPIOCEN (1U<<2)
#define PIN13 	(1U<<13)

#define LED_PIN PIN13

char key;

static void dma_callback(void);

int main(void){

	char message[31] = "Hello from Stm32 DMA transfer\n\r";

	/*Enable clock access to GPIOC*/
	RCC->AHB1ENR |= GPIOCEN;
	/*Set PC13 as Output pin*/
	GPIOC->MODER |= (1U<<26);
	GPIOC->MODER &= ~(1U<<27);

	uart2_tx_init();
	dma1_stream6_init((uint32_t) message, (uint32_t) &USART2->DR ,  31);

	while(1){

	}
}

static void dma_callback(void){
	GPIOA->ODR |= LED_PIN;
}

void DMA1_Stream6_IRQHandler(void){
	/*Check for transfer complete interrupt*/

	if(DMA1->HISR & HISR_TCIF6){
		/*Clear flag*/
		DMA1->HIFCR |= HIFCR_CTCIF6;

		dma_callback();
	}
}
