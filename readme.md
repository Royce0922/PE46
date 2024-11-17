# $PE46$

## $Config$

> **Code** 
>
> const float DXL_PROTOCOL_VERSION = 1.0;(only)
>
> baudrate : 1000000

| Left_leg |  ID  | Right_leg |    ID    |  Corps   |
| :------: | :--: | :-------: | :------: | :------: |
| Servo_L1 |  1   | Servo_R1  |    5     |  fesse   |
| Servo_L2 |  2   | Servo_R2  |    6     |  cuisse  |
| Servo_L3 |  3   | Servo_R3  |    11    |  genou   |
| Servo_L4 |  4   | Servo_R4  | en panne | cheville |



## $Quickly\quad Start$

### $Basis$

**AX-12A is very simple servo and the same as its functions**

- $Led$

	every servo has one led which can be used to test and debug

- $Torque$

	you can enable and disable torque when there is a need

- $Position$
  **moving to the specific position**

  > use High Precision Encoder to detect the angle

  Set the DYNAMIXEL’s goal position through the Goal Position(30).
  The available position range is 0 to 1,023 (0x3FF) and the per unit value is 0.29 °
  If the Goal Position is set over the CW/CCW Angle Limit, the Status Packet transmits Angle Limit Error Bit (0x01) via its ERROR field. In the case, providing that Angle Limit Error Bit(0x01) in the Alarm LED(17)/Shutdown(18) is set, the Alarm LED will start blinking and the motor’s output will be 0 [%].

  ![angle](img\dx_series_goal_position.png)

- $Speed$
  **constantly moving in a specifi speed**

  It is the present moving speed. 0~2,047 (0x7FF) can be used. If a value is in the rage of 0~1,023, it means that the motor rotates to the CCW direction. If a value is in the rage of 1,024~2,047, it means that the motor rotates to the CW direction. That is, the 10th bit becomes the direction bit to control the direction, and 0 and 1,024 are equal. The unit of this value varies depending on operation mode.

  - Joint Mode

  	The unit is about 0.111rpm(revolutions per minute). For example, if it is set to 300, it means that the motor is moving to the CCW direction at a rate of about 33.3rpm.

  - Wheel Mode

  	The unit is about 0.1%. For example, if it is set to 512, it means that the torque is controlled by 50% of the maximum torque to the CCW direction.

- $API$
	
	> more detail? click the function and use the example with servo
	
	- [torqueOn()](https://emanual.robotis.com/docs/en/popup/arduino_api/torqueOn/)
	- [torqueOff()](https://emanual.robotis.com/docs/en/popup/arduino_api/torqueOff/)
	- [ledOn()](https://emanual.robotis.com/docs/en/popup/arduino_api/ledOn/)
	- [ledOff()](https://emanual.robotis.com/docs/en/popup/arduino_api/ledOff/)
	- [setOperatingMode()](https://emanual.robotis.com/docs/en/popup/arduino_api/setOperatingMode/)
	- [setGoalPosition()](https://emanual.robotis.com/docs/en/popup/arduino_api/setGoalPosition/)
	- [getPresentPosition()](https://emanual.robotis.com/docs/en/popup/arduino_api/getPresentPosition/)
	- [setGoalVelocity()](https://emanual.robotis.com/docs/en/popup/arduino_api/setGoalVelocity/)
	- [getPresentVelocity()](https://emanual.robotis.com/docs/en/popup/arduino_api/getPresentVelocity/)

**Attetion:** we aren't able to control its speed in position mode

### model of code

use the mode to start work by one servo

```C++
#include <Arduino.h>
#include <Dynamixel2Arduino.h>
#include "config.h"
#include "led.h"

/* configure for Arduino Board */
#include <SoftwareSerial.h>
SoftwareSerial soft_serial(7, 8); // DYNAMIXELShield UART RX/TX
#define DXL_SERIAL Serial
#define DEBUG_SERIAL soft_serial
const int DXL_DIR_PIN = 2; // DYNAMIXEL Shield DIR PIN

// Baudrate 1000000
const float DXL_PROTOCOL_VERSION = 1.0; // important

/* installize led */
myLED led(LED_BUILTIN);

Dynamixel2Arduino dxl(DXL_SERIAL, DXL_DIR_PIN);

// This namespace is required to use Control table item names
using namespace ControlTableItem;

void setup()
{
  DEBUG_SERIAL.begin(115200);
  while (!DEBUG_SERIAL)
    ;

  dxl.begin(Buadrate);
  dxl.setPortProtocolVersion(DXL_PROTOCOL_VERSION);
  /* add you codes here */
}

void loop()
{
  /* add your codes here */
}
```

















