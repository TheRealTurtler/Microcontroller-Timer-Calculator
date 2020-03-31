#include "TimerCalculator.h"

void CalculateTimerFrequency(int f_cpu, int timerBits, float freq)
{
	char* prescaler;			// Timer prescaler
	float compareVal;			// OCRnA compare value
	float timerDivider;			// F_CPU / prescaler

	int OCRnA;
	float realFrequency;
	float realCycleTime;

	float minFreq = f_cpu / 1024 / (pow(2, timerBits) - 1);

	if (freq < minFreq)
	{
		printf("Frequency too small, has to be at least %f Hz!\n", minFreq);
		return;
	}

	if (freq > f_cpu)
	{
		printf("Frequency too big, has to be at most %d Hz!\n", f_cpu);
		return;
	}

	prescaler = PRESCALER_BITS_1;
	timerDivider = f_cpu;
	compareVal = f_cpu / freq;

	if (compareVal > (pow(2,timerBits) - 1))
	{
		prescaler = PRESCALER_BITS_8;
		timerDivider = f_cpu / 8;
		compareVal = f_cpu / 8 / freq;

		if (compareVal > (pow(2, timerBits) - 1))
		{
			prescaler = PRESCALER_BITS_32;
			timerDivider = f_cpu / 32;
			compareVal = f_cpu / 32 / freq;

			if (compareVal > (pow(2, timerBits) - 1))
			{
				prescaler = PRESCALER_BITS_64;
				timerDivider = f_cpu / 64;
				compareVal = f_cpu / 64 / freq;

				if (compareVal > (pow(2, timerBits) - 1))
				{
					prescaler = PRESCALER_BITS_128;
					timerDivider = f_cpu / 128;
					compareVal = f_cpu / 128 / freq;

					if (compareVal > (pow(2, timerBits) - 1))
					{
						prescaler = PRESCALER_BITS_256;
						timerDivider = f_cpu / 256;
						compareVal = f_cpu / 256 / freq;

						if (compareVal > (pow(2, timerBits) - 1))
						{
							prescaler = PRESCALER_BITS_1024;
							timerDivider = f_cpu / 1024;
							compareVal = f_cpu / 1024 / freq;
						}
					}
				}
			}
		}
	}

	OCRnA = round(compareVal);
	realFrequency = timerDivider / OCRnA;
	realCycleTime = 1000 / realFrequency;

	printf("Prescaler-Bits (CSn0 CSn1 CSn2): %s\n", prescaler);
	printf("OCRnA Value: %d\n", OCRnA);
	printf("Real frequency: %f Hz\n", realFrequency);
	printf("Real cycle time: %f ms\n", realCycleTime);
}