
#include <MK64F12.h>
//volatile int mySw=0;
void switchInit(){
	SIM_SCGC5 |= SIM_SCGC5_PORTB_MASK;
	SIM_SCGC5 |= SIM_SCGC5_PORTC_MASK;

	PORTC_PCR6 |= PORT_PCR_MUX(1);
	PORTB_PCR21 |= PORT_PCR_MUX(1);

	GPIOC_PDDR |= 0x00; // input enable pin 6
	GPIOB_PDDR |= 0x200000; // output enable pin 21
	return;
}

void switchInput(){
	int mySw=0;
	mySw = GPIOC_PDIR; // read the switch
	if(mySw){ // if port c is nonzero, the switch must be pressed
		GPIOB_PSOR = 0x200000; // sets the blue led to 1
	}else{ // otherwise, it isn't pressed
		GPIOB_PCOR = 0x200000; // sets the blue led to 0
	}
	return;
}

int main(){

	switchInit();

	while(1){
		switchInput();
	}
	return 0;
}