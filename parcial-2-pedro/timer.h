#ifndef _TIMER_H_
#define _TIMER_H_

#include <stdint.h>

void timerInitialization(uint32_t period, uint32_t cycleTime);

void timerStart(void);

void timerStop(void);

#endif // _TIMER_H_