#pragma once

#include <stdio.h>
#include <math.h>

#define MIN_FREQ 0.2

#define PRESCALER_BITS_1	"001"
#define PRESCALER_BITS_8	"010"
#define PRESCALER_BITS_32	"011"
#define PRESCALER_BITS_64	"100"
#define PRESCALER_BITS_128	"101"
#define PRESCALER_BITS_256	"110"
#define PRESCALER_BITS_1024	"111"

#define DEFAULT_F_CPU 16000000
#define DEFAULT_TIMER_BITS 8

void CalculateTimerFrequency(int f_cpu, int timerBits, float freq);