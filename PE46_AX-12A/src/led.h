#ifndef __LED_H
#define __LED_H

#include <Arduino.h>

class myLED
{
private:
    uint8_t ledPin;

public:
    myLED(uint8_t ledPin);
    ~myLED();
    void on();  // turn  on LED
    void off(); // turn off LED
    void setLedPin(uint8_t userLedPin);
    uint8_t getLedPin();
    void blink(void);
    void blink(uint8_t fois, uint16_t interval);
};

#endif
