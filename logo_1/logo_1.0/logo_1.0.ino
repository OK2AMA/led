/*
  Fade

  This example shows how to fade an LED on pin 9
  using the analogWrite() function.

  The analogWrite() function uses PWM, so if
  you want to change the pin you're using, be
  sure to use another PWM capable pin. On most
  Arduino, the PWM pins are identified with
  a "~" sign, like ~3, ~5, ~6, ~9, ~10 and ~11.

  This example code is in the public domain.
*/

// power supply 1 - main
#define ebec_0    A0
#define ebec_1    A1
#define ebec_2    A2

// power supply 2
#define ebec_3    A3
#define cogw_0    A4
#define cogw_1    A5

// power supply 3
#define cogw_2    9
#define cogw_3    10
#define cogw_4    11

// switches
#define sw_0    6
#define sw_1    7
#define sw_2    8

// declaration global variables
int mode = 0;
int switch_state_0 = 0;
int switch_state_1 = 0;
int switch_state_2 = 0;

int led = ebec_0;           // the PWM pin the LED is attached to
int brightness = 50;    // how bright the LED is
int fadeAmount = 20;    // how many points to fade the LED by

// the setup routine runs once when you press reset:
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);

  pinMode(ebec_0, OUTPUT);
  pinMode(ebec_1, OUTPUT);
  pinMode(ebec_2, OUTPUT);
  pinMode(ebec_3, OUTPUT);

  pinMode(cogw_0, OUTPUT);
  pinMode(cogw_1, OUTPUT);
  pinMode(cogw_2, OUTPUT);
  pinMode(cogw_3, OUTPUT);
  pinMode(cogw_4, OUTPUT);

  pinMode(sw_0, INPUT);
  pinMode(sw_1, INPUT);
  pinMode(sw_2, INPUT);
  digitalWrite(sw_0, HIGH);
  digitalWrite(sw_1, HIGH);
  digitalWrite(sw_2, HIGH);
  
  turn_off();
}

void turn_off() {
  digitalWrite(ebec_0, LOW);
  digitalWrite(ebec_1, LOW);
  digitalWrite(ebec_2, LOW);
  digitalWrite(ebec_3, LOW);

  digitalWrite(cogw_0, LOW);
  digitalWrite(cogw_1, LOW);
  digitalWrite(cogw_2, LOW);
  digitalWrite(cogw_3, LOW);
  digitalWrite(cogw_4, LOW);
}

void turn_on() {
  digitalWrite(ebec_0, HIGH);
  digitalWrite(ebec_1, HIGH);
  digitalWrite(ebec_2, HIGH);
  digitalWrite(ebec_3, HIGH);

  digitalWrite(cogw_0, HIGH);
  digitalWrite(cogw_1, HIGH);
  digitalWrite(cogw_2, HIGH);
  digitalWrite(cogw_3, HIGH);
  digitalWrite(cogw_4, HIGH);
}


void loop() {
  //  analogWrite(LED_BUILTIN, 0);

  switch (mode) {
    case 1:
      turn_on();
      break;
    case 2:
      turn_on();
      break;
    case 3:
      turn_on();
      delay(500);
      turn_off();
      delay(500);
      break;

    default:
    
     /* turn_on();
      delay(100);
      turn_off();
      delay(1000);
      */
      analogWrite(ebec_0, 0);
      analogWrite(ebec_1, 30);
      analogWrite(ebec_2, 70);
      analogWrite(ebec_3, 180);
      
      delay(30);
      break;
  }


  if (digitalRead(sw_0) == LOW){         // check if the input is HIGH (button released)
  delay(40);
    while (digitalRead(sw_0) == LOW) {
      delay(20);
    }
    delay(70);
    mode = mode + 1;
    if (mode >= 3)
      mode = 1;
  }
}
