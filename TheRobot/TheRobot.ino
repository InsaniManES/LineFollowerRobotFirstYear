#include <QTRSensors.h>

#include "defines.h"
#include "helpers.h"
#include "songs.h"
#include "motor.h"
#include "blackLineSensor.h"
#include "steering.h"
#include "APDS9960_Arduino.h"

//configuration
const bool debugMode = true;
const bool testMode = true;
const bool calibrateMode = true;

Motor motorRight(MotorInput1_A,MotorInput2_A);
Motor motorLeft(MotorInput1_B,MotorInput2_B);
QTRSensors qtr;

uint16_t sensorValues[NUM_SENSORS];

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);  

  if(debugMode) {
    Serial.begin(serialRate);
    while (!Serial); // Wait for Serial Monitor to open   
  }

  setupDigitalSensors();

  setup_apds9960_arduino(); //distance and color sensor

  motorRight.setup();
  motorLeft.setup();  
  
  setupBlackLineSensor(&qtr);
  delay(500);
  if(calibrateMode) calibrateBlackLineSensor(&qtr);
    
  Serial.println("All good... Program started!");
}

void loop() {
  if(testMode){
    tests();
    return;
  }

  if(isCloseObject()) {
    //handle close object
    stopAll();
    handleColor();
  } else {
    //not close object
    handleSteering(&qtr,sensorValues,&motorRight,&motorLeft);
  }
}

void stopAll() {
  motorRight.stop();
  motorLeft.stop();
}

bool isCloseObject() {
  return readProximity_apds9960_arduino() < closeObject;
}

void handleColor() {
  switch(readColor_apds9960_arduino()) {
    case RED:
      handleRed(isCloseObject);
      break;
    case GREEN:
      handleGreen(isCloseObject);
      break;
    case BLUE:
      handleBlue(isCloseObject); 
      break;
    default:
      Serial.println("Got an error with reading color");
      break;
  }
}

void goStraight() {
  motorRight.forward(BaseSpeed1);
  motorLeft.forward(BaseSpeed2);
}

void tests() {
//  goStraight();
  handleSteering(&qtr,sensorValues,&motorRight,&motorLeft);
  //handleSharpLeft(&qtr,sensorValues,&motorLeft,&motorLeft);    
}
