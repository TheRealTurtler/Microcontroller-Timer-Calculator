#include "TimerCalculator.h"

void CalculateTimer(int f_cpu, int timerBits, int freq)
{
	char* prescaler;			// Timer prescaler
	float compareVal;			// OCRnA compare value
	float timerDivider;			// F_CPU / prescaler

	int OCRnA;
	float realFrequency;

	if (freq < MIN_FREQ)
	{
		printf("\nFrequenz zu klein, muss mindestens %f Hz sein\n", MIN_FREQ);
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

	printf("Prescaler-Bits (CSn0 CSn1 CSn2): %s\n", prescaler);
	printf("OCRnA Value: %d\n", OCRnA);
	printf("Real frequency: %f\n", realFrequency);
}