#include <avr/io.h>
#include <avr/interrupt.h>

# define I 0x0384
# define L 0x0960
# define M 0x0BB8
# define R 0x0E10

int temp;

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
  
  
  while (true){
    if (PIND & (0b10000000)){
      OCR1B = R;
      PORTD |= 0x04;
	_delay_ms(150);
    }
    
    else if (PIND & (0b01000000)){
      OCR1B = M;
      PORTD |= 0x04;
	_delay_ms(150);
    }
    
    else if (PIND & (0b00100000)){
      OCR1B = L;
      PORTD |= 0x04;
	_delay_ms(150);
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
