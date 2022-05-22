#define Kp 0.0038 //0.0075 0.0072
#define Ki 0
#define Kd 0.076 //0.047 0.057
#define MaxSpeed 200 // max speed of the robot
#define BaseSpeed1 130 //90 
#define BaseSpeed2 130 //90
#define TurnSpeed 200

#define NUM_SENSORS  8     // number of sensors used

// for qtr8rc
#define QTR_EMITTER_PIN A0
#define QTR_TIMEOUT 2500

#define BUZZER A1

//motor
#define DigitalSensorRight A2
#define DigitalSensorLeft A3
#define MotorMode A6
#define MotorInput1_A 9 //Right motor input 1
#define MotorInput2_A 10 //Right motor input 2
#define MotorInput1_B 5 //Left motor input 1
#define MotorInput2_B 6 //Left motor input 1
#define MOTOR_MODE_STATE LOW

#define closeObject 240

#define serialRate 9600

#ifndef DEFINES_H
#define DEFINES_H

enum Colors{RED,GREEN,BLUE,ERR};
enum SensorsDigitalState{LEFT,RIGHT,BOTH,NONE};

const uint8_t sensorPins[] = {2,3,4,7,8,11,12,13};

#endif
