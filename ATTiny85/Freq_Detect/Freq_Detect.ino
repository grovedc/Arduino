
// ATMEL ATTINY85
//
//                  +-\/-+
//      (D 5) PB5  1|    |8  Vcc
//      (D 3) PB3  2|    |7  PB2 (D 2)
//      (D 4) PB4  3|    |6  PB1 (D 1)
//            GND  4|    |5  PB0 (D 0) led
//                  +----+


//                            +-\/-+
//      RESET/ADC0 (D5) PB5  1|    |8  VCC
//       USB- ADC3 (D3) PB3  2|    |7  PB2 (D2) INT0/ADC1 - default TX Debug output for ATtinySerialOut
//       USB+ ADC2 (D4) PB4  3|    |6  PB1 (D1) MISO/DO/AIN1/OC0B/OC1A/PCINT1 - (Digispark) LED
//                      GND  4|    |5  PB0 (D0) OC0A/AIN0
//                            +----+

// power notes:
// draws about 2 milliamps when the clock is 1 mHz, and 6.25 milliamps at 8mHz.

unsigned long Start_Time = 0;
unsigned long End_Time = 0;

// normally 0, but 1 for digi attiny85 boards
#define LED 0

void setup()
{
  pinMode(LED, OUTPUT);
}

// The code asks for a 5 microsecond delay.  If the CPU
// is running at 1 mHz, then this is only 5 clock cycles.
// Just the function call/return overhead for the calls to 
// `delayMicroseconds` and `micros` will be more than 5
// clock cycles.  Evidently, when running at 8 mHz, the
// two function calls can execute in < 50 usec.

// In order to change the clock frequency, select the 
// desired internal frequency on the Tools menu, and burn
// the bootloader.  Curiously, no bootloader is actually 
// loaded - all 8k is available.  The clock frequency does
// not seem to be changed when uploading a program.

void loop()
{
  Start_Time = micros();
  delayMicroseconds(5);
  End_Time = micros();

  if ((End_Time - Start_Time) >= 50) 
  {
    // Slow blink for 1-MHz
    digitalWrite(LED, HIGH);
    delay(1000);
    digitalWrite(LED, LOW);
    delay(1000);
  }
  else 
  {
    // Fast blink for 8-MHz
    digitalWrite(LED, HIGH);
    delay(250);
    digitalWrite(LED, LOW);
    delay(250);
    digitalWrite(LED, HIGH);
    delay(250);
    digitalWrite(LED, LOW);
    delay(250);
  }
}
