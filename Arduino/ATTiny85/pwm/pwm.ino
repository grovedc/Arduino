
int PWM_pin = 0; // LED pin for ATtiny85 (PB0-PIN5)

void setup() {
  pinMode(PWM_pin, OUTPUT);
}

void loop() {
  int i = 250;
  while (i>0) {
    analogWrite(PWM_pin, i);
    delay(10);
    i-=1;
  }

  while (i<250) {
    analogWrite(PWM_pin, i);
    delay(10);
    i+=1;
  }
}
