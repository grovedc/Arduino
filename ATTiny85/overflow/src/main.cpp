// from:
//  https://www.gadgetronicx.com/attiny85-timer-tutorial-generating-time-delay-interrupts/

#include <avr/interrupt.h>

int intr_count=0;
int sec=0;

ISR(TIMER0_OVF_vect)       // Interrupt vector for Timer0 overflow
{
  if (intr_count==63)      // waiting for 63 to get 1 sec delay
  {
    PORTB^=(1<<PB1);       // toggling the LED
    intr_count=0;          // making intr_count=0 to repeat the count
  }
  else intr_count++;       // incrementing c upto 63
}

void timer_setup()
{
  DDRB |= (1<<PB1);        // set PB1 as output(LED)
  TCCR0A=0x00;             // Normal mode
  TCCR0B=0x00;
  TCCR0B|=(1<<CS00)|(1<<CS02);   // prescaling with 1024
  sei();                   // enabling global interrupt
  TCNT0=0;
  TIMSK|=(1<<TOIE0);       // enabling timer0 interrupt
  PORTB|=(1<<PB1);
}

int main () 
{
  timer_setup();
  while(1) { 
  }
}
