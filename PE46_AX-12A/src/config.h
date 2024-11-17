#define Buadrate 1000000
#define DXL_PROTOCOL_VERSION 1.0 // important
/*  Robot name structure(temporary)!!!!
    Left_leg    Right_leg
    Servo_L1    Servo_R1    fesse
    Servo_L2    Servo_R2    cuisse
    Servo_L3    Servo_R3    genou
    Servo_L4    Servo_R4    cheville
 */
typedef enum
{
    Servo_L1 = 1,
    Servo_L2 = 2,
    Servo_L3 = 3,
    Servo_L4 = 4,
    Servo_R1 = 5,
    Servo_R2 = 6,
    Servo_R3 = 11,
    Servo_R4 = 0 // en panne
} AX_12A;