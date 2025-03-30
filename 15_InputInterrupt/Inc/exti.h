/*
 * exti.h
 *
 *  Created on: Jan 21, 2025
 *      Author: arafi
 */

#ifndef EXTI_H_
#define EXTI_H_

#include "stm32f4xx.h"

#define LINE0  (1U<<0)

void pa0_exti_init(void);

#endif /* EXTI_H_ */
