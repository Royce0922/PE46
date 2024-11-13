#include <Arduino.h>
#include "led.h"

myLED::myLED(uint8_t ledPin)
{
    this->ledPin = ledPin;
    pinMode(this->ledPin, OUTPUT);
}

myLED::~myLED()
{
}

void myLED::on(void)
{
    digitalWrite(this->ledPin, HIGH);
}

void myLED::off(void)
{
    digitalWrite(this->ledPin, LOW);
}

void myLED::setLedPin(uint8_t userLedPin)
{
    this->ledPin = userLedPin;
    pinMode(this->ledPin, OUTPUT);
}

uint8_t myLED::getLedPin()
{
    return this->ledPin;
}

void myLED::blink(void)
{
    this->on();
    delay(1000);
    this->off();
    delay(1000);
}

// interval/ms
void myLED::blink(uint8_t fois, uint16_t interval)
{
    for (int i = 0; i < fois; i++)
    {
        this->on();
        delay(interval);
        this->off();
        delay(interval);
    }
}
