#include <stdio.h>
#include <stdint.h>
#include "stm32f4xx.h"
#include "uart.h"
#include "adc.h"


uint32_t sensor_reading;
static void adc_callback(void);

int main(void){


	uart2_rxtx_init();
	pa1_adc_interrupt_init();
	start_conversion();

	while(1){


	}
}

static void adc_callback(void){
	sensor_reading = ADC1->DR;
}

void ADC_IRQHandler(void){
	/*Check for EOC in SR*/
	if((ADC1->SR & SR_EOC) != 0){
		/*Clear EOC*/
		ADC1->SR &= ~SR_EOC;

		adc_callback();
	}
}




