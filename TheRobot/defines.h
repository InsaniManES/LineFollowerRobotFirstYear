#define Kp 0
#define Ki 0 // experiment to determine this, slowly increase the speeds and adjust this value.
#define Kd 0
#define MaxSpeed 255 // max speed of the robot
#define BaseSpeed1 150 
#define BaseSpeed2 150
#define TurnSpeed 200

#define NUM_SENSORS  8     // number of sensors used

// for qtr8rc
#define QTR_EMITTER_PIN 3
#define QTR_TIMEOUT 2500

#define BUZZER 14

//motor
#define DigitalSensorRight 5
#define DigitalSensorLeft 6
#define MotorMode 21
#define MotorInput1_A 5 //Right motor input 1
#define MotorInput2_A 6 //Right motor input 2
#define MotorInput1_B 9 //Left motor input 1
#define MotorInput2_B 10 //Left motor input 1
#define MOTOR_MODE_STATE LOW

#define closeObject 240

#define serialRate 9600

#ifndef DEFINES_H
#define DEFINES_H

enum Colors{RED,GREEN,BLUE,ERR};
enum SensorsDigitalState{LEFT,RIGHT,BOTH,NONE};

const uint8_t sensorPins[] = {2,3,4,7,8,11,12,13};

#endif
