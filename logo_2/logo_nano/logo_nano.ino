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
#define lett_0    2 // E
#define lett_1    7 // V
#define lett_2    5 // O
#define lett_3    9 // L
#define lett_4    10 // V
#define lett_5    6 // E

#define logo_0    8
#define backup_pin    12
#define fan_pin    11

// switches
#define sw_0    A0
#define sw_1    A1
#define sw_2    A2

#define rem_sw_0    A5
#define rem_sw_1    A6
#define rem_sw_2    A4
#define rem_sw_3    A3

// declaration global variables
int mode = 2;
int switch_state_0 = 0;
int switch_state_1 = 0;
int switch_state_2 = 0;


int brightness = 50;    // how bright the LED is
int fadeAmount = 20;    // how many points to fade the LED by

// the setup routine runs once when you press reset:


void rise() {
  turn_off();
  digitalWrite(lett_0, HIGH);
  delay(1000);
  digitalWrite(lett_0, LOW);
  digitalWrite(lett_1, HIGH);
  delay(1000);
  digitalWrite(lett_1, LOW);
  digitalWrite(lett_2, HIGH);
  delay(1000);
  digitalWrite(lett_2, LOW);
  digitalWrite(lett_3, HIGH);
  delay(1000);
  digitalWrite(lett_3, LOW);
  digitalWrite(lett_4, HIGH);
  delay(1000);
  digitalWrite(lett_4, LOW);
  digitalWrite(lett_5, HIGH);
  delay(1000);
  digitalWrite(lett_5, LOW);
  digitalWrite(logo_0, HIGH);
  delay(1000);
  digitalWrite(logo_0, LOW);
  delay(1000);
  digitalWrite(logo_0, HIGH);
  delay(1000);
  digitalWrite(logo_0, LOW);
  delay(1000);
}
void rise_2() {
  turn_off();
  digitalWrite(lett_0, HIGH);
  delay(1000);
  digitalWrite(lett_1, HIGH);
  delay(1000);
  digitalWrite(lett_2, HIGH);
  delay(1000);
  digitalWrite(lett_3, HIGH);
  delay(1000);
  digitalWrite(lett_4, HIGH);
  delay(1000);
  digitalWrite(lett_5, HIGH);
  delay(1000);
  digitalWrite(logo_0, HIGH);
  delay(1000);
  digitalWrite(lett_0, LOW);
  digitalWrite(lett_1, LOW);
  digitalWrite(lett_2, LOW);
  digitalWrite(lett_3, LOW);
  digitalWrite(lett_4, LOW);
  digitalWrite(lett_5, LOW);
  delay(2000);
  digitalWrite(logo_0, LOW);
}

void turn_off() {
  digitalWrite(lett_0, LOW);
  digitalWrite(lett_1, LOW);
  digitalWrite(lett_2, LOW);
  digitalWrite(lett_3, LOW);
  digitalWrite(lett_4, LOW);
  digitalWrite(lett_5, LOW);

  digitalWrite(logo_0, LOW);
}

void turn_on() {
  digitalWrite(lett_0, HIGH);
  digitalWrite(lett_1, HIGH);
  digitalWrite(lett_2, HIGH);
  digitalWrite(lett_3, HIGH);
  digitalWrite(lett_4, HIGH);
  digitalWrite(lett_5, HIGH);

  digitalWrite(logo_0, HIGH);
}

void setup() {
  Serial.begin(9600);      // open the serial port at 9600 bps:

  pinMode(lett_0, OUTPUT);
  pinMode(lett_1, OUTPUT);
  pinMode(lett_2, OUTPUT);
  pinMode(lett_3, OUTPUT);
  pinMode(lett_4, OUTPUT);
  pinMode(lett_5, OUTPUT);

  pinMode(logo_0, OUTPUT);
  pinMode(backup_pin, OUTPUT);
  pinMode(fan_pin, OUTPUT);

  pinMode(sw_0, INPUT);
  pinMode(sw_1, INPUT);
  pinMode(sw_2, INPUT);
  digitalWrite(sw_0, HIGH);
  digitalWrite(sw_1, HIGH);
  digitalWrite(sw_2, HIGH);
  pinMode(rem_sw_0, INPUT);
  pinMode(rem_sw_1, INPUT);
  pinMode(rem_sw_2, INPUT);
  pinMode(rem_sw_3, INPUT);
  mode = 3;
  turn_off();
}

void loop() {
  unsigned int wifi_mode = (
                             digitalRead(rem_sw_0)
                             | ((analogRead(rem_sw_1) > 150 ) << 1)
                             | (digitalRead(rem_sw_2) << 2)
                             | (digitalRead(rem_sw_3) << 3)
                           );
  if(wifi_mode != 3)
    mode = wifi_mode;
    
  switch (mode) {
    case 1:
      turn_off();
      analogWrite(fan_pin, 130);
      break;
    case 2:
      delayMicroseconds(400);
      turn_on();
      delayMicroseconds(3);
      turn_off();
      analogWrite(fan_pin, 130);
      break;
    case 3:
      delayMicroseconds(100);
      turn_on();
      delayMicroseconds(3);
      turn_off();
      analogWrite(fan_pin, 130);
      break;
    case 4:
      delayMicroseconds(10);
      turn_on();
      delayMicroseconds(3);
      turn_off();
      analogWrite(fan_pin, 180);
      break;
    case 5:
      delayMicroseconds(3);
      turn_on();
      delayMicroseconds(3);
      turn_off();
      analogWrite(fan_pin, 180);
      break;
    case 6:
      delayMicroseconds(3);
      turn_on();
      delayMicroseconds(8);
      analogWrite(fan_pin, 230);
      turn_off();
      break;
    case 7:
      delayMicroseconds(3);
      turn_on();
      delayMicroseconds(400);
      turn_off();
      analogWrite(fan_pin, 230);
      break;
    case 8:
      turn_on();
      analogWrite(fan_pin, 230);
      break;
    case 9:
      rise();
      analogWrite(fan_pin, 180);
      break;
    case 10:
      rise_2();
      analogWrite(fan_pin, 180);
      break;
    case 11:
      turn_on();
      delay(20);
      turn_off();
      delay(20);
      analogWrite(fan_pin, 180);
      break;
    case 12:
      turn_on();
      delay(50);
      turn_off();
      delay(50);
      analogWrite(fan_pin, 180);
      break;
    case 13:
      turn_on();
      delay(1000);
      turn_off();
      delay(1000);
      analogWrite(fan_pin, 180);
      break;

    default:
      delayMicroseconds(100);
      turn_on();
      delayMicroseconds(3);
      turn_off();
      analogWrite(fan_pin, 130);
      break;
  }
  if (digitalRead(sw_0) == LOW) {        // check if the input is HIGH (button released)
    delay(20);
    while (digitalRead(sw_0) == LOW) {
      delay(20);
    }
    delay(70);
    mode = mode + 1;
    if (mode >= 12)
      mode = 1;
  }
  if (digitalRead(sw_1) == LOW) {        // check if the input is HIGH (button released)
    delay(20);
    while (digitalRead(sw_1) == LOW) {
      delay(20);
    }
    delay(70);
    mode = 1;
  }
  if (digitalRead(sw_2) == LOW) {        // check if the input is HIGH (button released)
    delay(20);
    while (digitalRead(sw_2) == LOW) {
      delay(20);
    }
    delay(70);
    mode = 4;
  }

}
