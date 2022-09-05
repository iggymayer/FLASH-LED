/*raspberry pi pico rp2040*/
/*VSCode platfrom io*/

#include "Arduino.h"
#define LED 0
#define BUTTON 1

int state = 0;

boolean buttonLastState = HIGH;
void checkState()
{
  boolean buttonCurrentState = digitalRead(BUTTON);
  if (buttonLastState == LOW && buttonCurrentState == HIGH)
  {
    state++;
    if (state > 1)
    {
      state = 0;
    }
  }
  buttonLastState = buttonCurrentState;
}

void SOS()
{
  // S
  digitalWrite(LED, HIGH);
  delay(200);
  digitalWrite(LED, LOW);
  delay(200);

  digitalWrite(LED, HIGH);
  delay(200);
  digitalWrite(LED, LOW);
  delay(200);

  digitalWrite(LED, HIGH);
  delay(200);
  digitalWrite(LED, LOW);
  delay(500);

  // O
  digitalWrite(LED, HIGH);
  delay(400);
  digitalWrite(LED, LOW);
  delay(200);

  digitalWrite(LED, HIGH);
  delay(400);
  digitalWrite(LED, LOW);
  delay(200);

  digitalWrite(LED, HIGH);
  delay(400);
  digitalWrite(LED, LOW);
  delay(500);

  // S
  digitalWrite(LED, HIGH);
  delay(200);
  digitalWrite(LED, LOW);
  delay(200);

  digitalWrite(LED, HIGH);
  delay(200);
  digitalWrite(LED, LOW);
  delay(200);

  digitalWrite(LED, HIGH);
  delay(200);
  digitalWrite(LED, LOW);
  delay(1300);
}

void Strobe()
{
  digitalWrite(LED, HIGH);
  delay(20);
  digitalWrite(LED, LOW);
  delay(5000);
}

void setup()
{
  pinMode(BUTTON, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(BUTTON), checkState, CHANGE);
}

void loop()
{
  checkState();
  switch (state)
  {
  case 0:
    Strobe();
    break;

  case 1:
    SOS();
    break;

  default:
    break;
  }
}
