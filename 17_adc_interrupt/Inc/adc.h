/*
 * adc.h
 *
 *  Created on: Jan 20, 2025
 *      Author: arafi
 */

#ifndef ADC_H_
#define ADC_H_

#include <stdint.h>

#define SR_EOC 		(1U<<1)


void pa1_adc_init(void);
void start_conversion(void);
uint32_t adc_read(void);
void pa1_adc_interrupt_init(void);

#endif /* ADC_H_ */
