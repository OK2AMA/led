
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
#define reserve_pin    12

// switches
#define sw_0    8
#define sw_1    7
#define sw_2    6

// declaration global variables
int mode = 0;
int mode_change_speed = 0;
int switch_state_0 = 0;
int switch_state_1 = 0;
int switch_state_2 = 0;

unsigned long currentMillis = millis();

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

  pinMode(reserve_pin, OUTPUT);

  pinMode(sw_0, INPUT);
  pinMode(sw_1, INPUT);
  pinMode(sw_2, INPUT);
  digitalWrite(sw_0, HIGH);
  digitalWrite(sw_1, HIGH);
  digitalWrite(sw_2, HIGH);

  OCR0A = 0xAF;
  TIMSK0 |= _BV(OCIE0A);

  turn_off();
  void startup();
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


void startup() {
  turn_off();
  delay(300);
  digitalWrite(cogw_0, HIGH);
  delay(300);
  digitalWrite(cogw_1, HIGH);
  delay(300);
  digitalWrite(cogw_2, HIGH);
  delay(300);
  digitalWrite(cogw_3, HIGH);
  delay(300);
  digitalWrite(cogw_4, HIGH);
  delay(1000);
  digitalWrite(ebec_0, HIGH);
  delay(600);
  digitalWrite(ebec_1, HIGH);
  delay(600);
  digitalWrite(ebec_2, HIGH);
  delay(600);
  digitalWrite(ebec_3, HIGH);
  delay(2500);
  turn_off();
  delay(500);
  turn_on();
  delay(1500);
  turn_off();
  delay(1500);
}

void startup_change_speed() {
  turn_off();
  delay(700);
  digitalWrite(cogw_0, HIGH);
  delay(700);
  digitalWrite(cogw_0, LOW);
  digitalWrite(cogw_1, HIGH);
  delay(700);
  digitalWrite(cogw_2, HIGH);
  delay(700);
  digitalWrite(cogw_3, HIGH);
  delay(300);
  digitalWrite(cogw_4, HIGH);
  delay(7000);
  digitalWrite(ebec_0, HIGH);
  delay(700);
  digitalWrite(ebec_1, HIGH);
  delay(700);
  digitalWrite(ebec_2, HIGH);
  delay(700);
  digitalWrite(ebec_3, HIGH);

}

void startup_change_speed_2() {
  turn_off();
  switch (mode_change_speed) {
    case 1:
      digitalWrite(ebec_3, LOW);
      digitalWrite(cogw_0, HIGH);
      break;
    case 2:
      digitalWrite(cogw_0, LOW);
      digitalWrite(cogw_1, HIGH);
      break;
    case 3:
      digitalWrite(cogw_1, LOW);
      digitalWrite(cogw_2, HIGH);
      break;
    case 4:
      digitalWrite(cogw_2, LOW);
      digitalWrite(cogw_3, HIGH);
      break;
    case 5:
      digitalWrite(cogw_3, LOW);
      digitalWrite(cogw_4, HIGH);
      break;
    case 6:
      digitalWrite(cogw_4, LOW);
      digitalWrite(ebec_0, HIGH);
      break;
    case 7:
      digitalWrite(ebec_0, LOW);
      digitalWrite(ebec_1, HIGH);
      break;
    case 8:
      digitalWrite(ebec_1, LOW);
      digitalWrite(ebec_2, HIGH);
      break;
    case 9:
      digitalWrite(ebec_2, LOW);
      digitalWrite(ebec_3, HIGH);
      break;
    default:
      turn_off();
      break;
  }

  mode_change_speed = mode_change_speed + 1;
  if (mode_change_speed >= 10)
    mode_change_speed = 1;
}

SIGNAL(TIMER0_COMPA_vect)
{
  if (currentMillis == HIGH)
  {
    //currentMillis
    //currentMillis
  }


}


void loop() {
  //  analogWrite(LED_BUILTIN, 0);

  switch (mode) {
    case 1:
      turn_on();
      break;
    case 2:
      turn_off();
      break;

    case 3:
      turn_on();
      delay(1000);
      turn_off();
      delay(1000);
      break;

    case 4:
      startup();
      break;
      
    case 5:
      startup_change_speed();
      break;   

    default:
      turn_off();
      break;
  }


  if (digitalRead(sw_0) == LOW) {        
    delay(40);
    while (digitalRead(sw_0) == LOW) {
      delay(20);
    }
    delay(70);
    mode = mode + 1;
    if (mode >= 7)
      mode = 1;
  }
  if (digitalRead(sw_1) == LOW) {        
    delay(40);
    while (digitalRead(sw_1) == LOW) {
      delay(20);
    }
    delay(70);
    mode = 4;
  
  if (digitalRead(sw_2) == LOW) {        
    delay(40);
    while (digitalRead(sw_2) == LOW) {
      delay(20);
    }
    delay(70);
    mode = 1;
  }  
  }

}