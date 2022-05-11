#define Kp 0.05 // used to be 0.1. experiment to determine this, start by something small that just makes your bot follow the line at a slow speed
#define Ki 0 // experiment to determine this, slowly increase the speeds and adjust this value.
#define Kd 1 // used to be 4. experiment to determine this, slowly increase the speeds and adjust this value. ( Note: Kp < Kd) 
#define MaxSpeed 255// max speed of the robot
#define BaseSpeed 255 // this is the speed at which the motors should spin when the robot is perfectly on the line
#define NUM_SENSORS  8     // number of sensors used

// for qtr8rc
#define QTR_EMITTER_PIN 3
#define QTR_TIMEOUT 2500

#define BUZZER 4

//motor
#define MotorMode 7
#define MotorInput1_A 9
#define MotorInput2_A 8
#define MotorInput1_B 10
#define MotorInput2_B 11
#define MOTOR_MODE_STATE LOW

#define speedturn 180
#define wayRight 6700
#define wayLeft 300 

#define closeObject 200

#define serialRate 9600
