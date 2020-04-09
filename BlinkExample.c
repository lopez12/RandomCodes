#include "derivative.h" /* include peripheral declarations */
#DEFINE TIMER_MULTIPLIER 10000
unsigned char BlinkLed(unsigned char timeLed);

/*Codigo para hacer un LED Blink sin delay para aplicaciones que corren en paralelo*/

int main(void)
{
	
	unsigned char LedTime = 0;
	config_gpio ();
	for(;;) 
	{
		
		LedTime = BlinkLed(LedTime,);
		LedTime++;
	}

	return 0;
}

void config_gpio (void)
{
	SIM_SCGC5 |= SIM_SCGC5_PORTB_MASK; 
	PORTB_PCR18 = PORT_PCR_MUX(1);  
	PORTB_PCR19 = PORT_PCR_MUX(1); 
	GPIOB_PDDR = 0xC0000;
}


unsigned char BlinkLed(unsigned char timeLed,unsigned char timeBlinking)
{
	timeBlinking = timeBlinking * TIMER_MULTIPLIER;
		if(timerLedcounter == timeBlinking)
		{
			GPIOB_PDOR ^= 0xC0000;
			timeLed = 0;
			return timeLed;
		}
		else
		{
			return timeLed;
		}
}			


	
