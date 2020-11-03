#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

# define I 0x0384
# define L 0x07D0
# define M 0x0BB8
# define R 0x0FA0

char l1;
char l2;

int main () {
	
	//Defining I/O ports
	//PortD 7,6,5 for PIR Sensors, 2 for LED and 0 for Servo Motor
	DDRD = 0x05; //00000101
	
	//control frequency of Servo Motors PWM signal(20ms period)
	OCR1A = 0x9C40;
	
	//CTC mode, internal clk, prescaler
	TCCR1A = 0x00;
	TCCR1B = 0x0A;
	
	TIMSK1 = 0x06;	//enable Timer1 compare match A int and compare match B.
	sei ();			//enable interrupts
	
	while (1){
		//all down
		if (PIND & (0b00000000)){
			l1 = '0';
			l2 = '0';
		}
		
		//R up
		else if (PIND & (0b00100000)){
			l1 = 'R';
			OCR1B = R;
			PORTD |= 0x04;
			_delay_ms(150);
		}
		
		//M up
		else if (PIND & (0b01000000)){
			l1 = 'M';
			OCR1B = M;
			PORTD |= 0x04;
			_delay_ms(150);
		}
		
		//M and R up
		else if (PIND & (0b01100000)){
			l2 = 'R';
			if (l1 == 'M')
			{
				OCR1B = R;
				PORTD |= 0x04;
				_delay_ms(150);
			}
			else if (l1 == 'R')
			{
				OCR1B = M;
				PORTD |= 0x04;
				_delay_ms(150);
			}
		}
		
		//L up
		else if (PIND & (0b10000000)){
			l1 = 'L';
			OCR1B = L;
			PORTD |= 0x04;
			_delay_ms(150);
		}
		
		//L and R up
		else if (PIND & (0b10100000)){
			l2 = 'M';
			if (l1 == 'L'){
				OCR1B = R;
				PORTD |= 0x04;
				_delay_ms(150);
			}
			else if (l1 == 'R'){
				OCR1B = L;
				PORTD |= 0x04;
				_delay_ms(150);
			}
		}
		
		//L and M up
		else if (PIND & (0b11000000)){
			l2 = 'L';
			if (l1 == 'L'){
				OCR1B = M;
				PORTD |= 0x04;
				_delay_ms(150);
			}
			else if (l1 == 'M'){
				OCR1B = L;
				PORTD |= 0x04;
				_delay_ms(150);
			}
		}
		
		//all up
		else if (PIND & (0b11100000)){
			if (l2 == 'L')
			{
				OCR1B = R;
				PORTD |= 0x04;
				_delay_ms(150);
			}
			else if (l2 == 'R')
			{
				OCR1B = L;
				PORTD |= 0x04;
				_delay_ms(150);
			}
			else if (l2 == 'M')
			{
				OCR1B = M;
				PORTD |= 0x04;
				_delay_ms(150);
			}
			
		}
	}
}

ISR (TIMER1_COMPA_vect) {	//ISR for Timer1 compare match A
	//set PORTD.0
	PORTD |= 0x01;
}

ISR (TIMER1_COMPB_vect) {	//ISR for Timer1 compare match B
	//clear PORTD.0
	PORTD &= ~ 0x01;
}
