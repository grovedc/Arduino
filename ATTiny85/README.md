# ATTiny85

Pinouts:

                  +-\/-+
      (D 5) PB5  1|    |8  Vcc
      (D 3) PB3  2|    |7  PB2 (D 2)
      (D 4) PB4  3|    |6  PB1 (D 1)
            GND  4|    |5  PB0 (D 0) led
                  +----+


                            +-\/-+
      RESET/ADC0 (D5) PB5  1|    |8  VCC
       USB- ADC3 (D3) PB3  2|    |7  PB2 (D2) INT0/ADC1 - default TX Debug output for ATtinySerialOut
       USB+ ADC2 (D4) PB4  3|    |6  PB1 (D1) MISO/DO/AIN1/OC0B/OC1A/PCINT1 - (Digispark) LED
                      GND  4|    |5  PB0 (D0) OC0A/AIN0
                            +----+


## Freq_Detect

Suppose you want to know what frequency your ATTiny85 is running at.  Did you burn the fuses correctly?  Have a look at this project.