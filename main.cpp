// Have 4 buttons wired to LEDs and one LED as the "success" light. Must press them in 1,2,3,4 order for it to light up
const int BUTTON1 = 12;
const int LED1 = 13;
int BUTTON1state = 0;
int lastBUTTON1state = 0;
const int BUTTON2 = 10;
const int LED2 = 11;
int BUTTON2state = 0;
int lastBUTTON2state = 0;
const int BUTTON3 = 8;
const int LED3 = 9;
int BUTTON3state = 0;
int lastBUTTON3state = 0;
const int BUTTON4 = 6;
const int LED4 = 7;
int BUTTON4state = 0;
int lastBUTTON4state = 0;
const int LED5 = 2;

int counter = 0;

void setup()
{
  pinMode(BUTTON1, INPUT);
  pinMode(LED1, OUTPUT);
  pinMode(BUTTON2, INPUT);
  pinMode(LED2, OUTPUT);
  pinMode(BUTTON3, INPUT);
  pinMode(LED3, OUTPUT);
  pinMode(BUTTON4, INPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  BUTTON1state = digitalRead(BUTTON1);
  BUTTON2state = digitalRead(BUTTON2);
  BUTTON3state = digitalRead(BUTTON3);
  BUTTON4state = digitalRead(BUTTON4);

  if (BUTTON1state == 1 && BUTTON2state == 0 && BUTTON3state == 0 && BUTTON4state == 0) {
    counter = counter = 1000;
    lastBUTTON1state = 1;
  }
  if (lastBUTTON1state == 1 && BUTTON1state == 0) {
    counter = 0;
    lastBUTTON1state = 0;
  }

  if (BUTTON1state == 1 && BUTTON2state == 1 && BUTTON3state == 0 && BUTTON4state == 0 && counter == 1000) {
    counter = counter + 100;
    lastBUTTON2state = 1;
  }
  if (lastBUTTON2state == 1 && BUTTON2state == 0) {
    counter = counter - 100;
    lastBUTTON2state = 0;
  }

  if (BUTTON1state == 1 && BUTTON2state == 1 && BUTTON3state == 1 && BUTTON4state == 0 && counter == 1100) {
    counter = counter + 10;
    lastBUTTON3state = 1;
  }
  if (lastBUTTON3state == 1 && BUTTON3state == 0) {
    counter = counter - 10;
    lastBUTTON3state = 0;
  }

  if (BUTTON1state == 1 && BUTTON2state == 1 && BUTTON3state == 1 && BUTTON4state == 1 && counter == 1110) {
    counter = counter + 1;
    lastBUTTON4state = 1;
  }
  if (lastBUTTON4state == 1 && BUTTON4state == 0) {
    counter = counter - 1;
    lastBUTTON4state = 0;
  }

  if (counter == 1111)
  {
    digitalWrite(LED5, HIGH);
  }
  else
  {
    digitalWrite(LED5, LOW);
  }

  digitalWrite(LED1, BUTTON1state);
  digitalWrite(LED2, BUTTON2state);
  digitalWrite(LED3, BUTTON3state);
  digitalWrite(LED4, BUTTON4state);
}