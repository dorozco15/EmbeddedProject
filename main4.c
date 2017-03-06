void UART0_interfaceInit(){
	SIM_SCGC5 |= SIM_SCGC5_PORTB_MASK; // enable clock to PORTB
	SIM_SCGC4 |= SIM_SCGC4_UART0_MASK; // enable clock to UART0

	PORTB_PCR16 |= PORT_PCR_MUX(3);
	PORTB_PCR17 |= PORT_PCR_MUX(3); // configure bits to be UART0

	UART0_C2 &= ~(UART_C2_TE_MASK | UART_C2_RE_MASK); // disable receive/transfer

	UART0_C1 = 0; // set 8 bits

	UART0_BDH = 0; // upper four bits set to zero
	UART0_BDL = 0b10001001; // lower four bits set to baud rate ~ 9600

	UART0_C2 |= (UART_C2_TE_MASK | UART_C2_RE_MASK); // enable receive/transfer
}

int UART0_putChar(char c){
	while(!(UART0_S1 & 0x80)); // check if the transmit buffer is full, do nothing if so
	UART0_D = c; // if not, write 8 bits to the UART0 data register
	return;
}

char UART0_getChar(void){
	while(!(UART0_S1 & 0x20)); // check if the receive buffer is empty, do nothing if so
	return UART0_D; // returns the gotten char
}

void UART0_putStr(char *str){
	int n = 0;
	while(str[n]){ // is the character a NULL?
		UART0_putChar(str[n]); // if not, use putChar to output it
		n++;
	}
	return; // quit when we hit a NULL
}


void ADC0_Init(void){
	 SIM_SCGC6 |= SIM_SCGC6_ADC0_MASK;
	 //default input for PTE25 / ADC0_SE18
	 ADC0_CFG1 |= 0x28; //sets input clock /2, shorts sample time, conversion mode (single-ended ten-bit), bus clock.
	 ADC0_CFG2 &= 0x1B; // sets it so that ADxxa channels selected, ADHSC normal conversion sequence
	 ADC0_SC2 = 0x0; // software trigger selected, compare function disabled, DMA function disabled, default voltage reference pin pair (VREFH and VREFL)
	 ADC0_SC3 &= 0x07; // do not start calibration, one conversion settings
	 ADC0_SC1A &= 0x12; // no interrupt, single-ended, ADC0_SE18.
 }

 int ADC0_Convert(void){
	 ADC0_SC1A &= 0x12; //abort any ongoing conversion
	 while(!(ADC0_SC1A & 0x80)); //do nothing

	 return ADC0_RA;
 }
 
 int main(void){
	UART0_interfaceInit();
	ADC0_Init();
	int ADC_val;
	while(1){
		ADC_val = ADC0_Convert();
		if(ADC_val){
			UART0_putChar('H');
		}
		else{
			UART0_putChar('L');
		}

	}
}