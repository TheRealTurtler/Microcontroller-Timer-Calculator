#include "main.h"

int main()
{
	bool menu = true;
	int menuSelection;

	int f_cpu;
	int timerBits;
	float targetFreq;
	float targetCycleTime;

	printf("Select mode:\n");
	printf("\t1. Frequency\n");
	printf("\t2. Cycle time\n\n");

	while (menu)
	{
		printf("> ");
		scanf("%1d", &menuSelection);

		if (menuSelection < 3)
		{
			menu = false;
		}
		else
		{
			printf("Please enter a valid number.\n");
		}
	}

	printf("\nProcessor speed (F_CPU) [Hz]: ");
	scanf("%d", &f_cpu);

	if (f_cpu == 0)
	{
		printf("Setting processor speed to default (16 MHz)\n");
		f_cpu = DEFAULT_F_CPU;
	}

	printf("\nTimer bits (8 or 16 usually) [Bit]: ");
	scanf("%d", &timerBits);

	if (timerBits == 0)
	{
		printf("Setting timer bits to default (8 Bit)\n");
		timerBits = DEFAULT_TIMER_BITS;
	}

	if (menuSelection == 1)
	{
		printf("\nTarget frequency [Hz]: ");
		scanf("%f", &targetFreq);

		printf("\n");
		CalculateTimerFrequency(f_cpu, timerBits, targetFreq);
	}
	else if (menuSelection == 2)
	{
		printf("\nTarget cycle time [ms]: ");
		scanf("%f", &targetCycleTime);
		
		targetFreq = 1000 / targetCycleTime;

		printf("Target frequency: %f Hz\n", targetFreq);

		printf("\n");
		CalculateTimerFrequency(f_cpu, timerBits, targetFreq);
	}
}