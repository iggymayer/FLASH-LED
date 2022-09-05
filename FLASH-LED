/*raspberry pi pico rp2040*/

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
  delayMicroseconds(200000);
  digitalWrite(LED, LOW);
  delayMicroseconds(200000);

  digitalWrite(LED, HIGH);
  delayMicroseconds(200000);
  digitalWrite(LED, LOW);
  delayMicroseconds(200000);

  digitalWrite(LED, HIGH);
  delayMicroseconds(200000);
  digitalWrite(LED, LOW);
  delayMicroseconds(500000);

  // O
  digitalWrite(LED, HIGH);
  delayMicroseconds(400000);
  digitalWrite(LED, LOW);
  delayMicroseconds(200000);

  digitalWrite(LED, HIGH);
  delayMicroseconds(400000);
  digitalWrite(LED, LOW);
  delayMicroseconds(200000);

  digitalWrite(LED, HIGH);
  delayMicroseconds(400000);
  digitalWrite(LED, LOW);
  delayMicroseconds(500000);

  // S
  digitalWrite(LED, HIGH);
  delayMicroseconds(200000);
  digitalWrite(LED, LOW);
  delayMicroseconds(200000);

  digitalWrite(LED, HIGH);
  delayMicroseconds(200000);
  digitalWrite(LED, LOW);
  delayMicroseconds(200000);

  digitalWrite(LED, HIGH);
  delayMicroseconds(200000);
  digitalWrite(LED, LOW);
  delayMicroseconds(1300000);
}

void Strobe()
{
  digitalWrite(LED, HIGH);
  delayMicroseconds(20000);
  digitalWrite(LED, LOW);
  delayMicroseconds(5000000);
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
