//
// taken from:
//  https://www.arduinoslovakia.eu/blog/2017/12/attiny85---blik?lang=en
// 


#include <avr/sleep.h>
#include <avr/power.h>

// Utility macro
#define adc_disable() (ADCSRA &= ~(1<<ADEN)) // disable ADC (before power-off)

const int led = 0;
const int sleep = 5000;

// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
//  bitSet(DDRB, led);

  adc_disable(); // ADC uses ~320uA

  pinMode(0, INPUT_PULLUP);
  pinMode(1, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);

  ADCSRA = 0;                           // disable ADC
  power_all_disable();                  // turn off all modules
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  sleep_enable();
  sleep_cpu();
}

// the loop routine runs over and over again forever
void loop() {
//  bitSet(PINB, led);
  delay(sleep);
}
