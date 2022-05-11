#include <QTRSensors.h>

#include "defines.h"
#include "helpers.h"
#include "songs.h"
#include "motor.h"
#include "blackLineSensor.h"
#include "steering.h"
#include "APDS9960_Arduino.h"
#include "APDS9960_SparkFun.h"

const bool debugMode = true;
const bool testMode = true;

MotorDriver driver(MotorInput1_A,MotorInput2_A,MotorInput1_B,MotorInput2_B,MotorMode);
QTRSensors qtr;
uint16_t sensorValues[NUM_SENSORS];

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  
  if(debugMode) {
    Serial.begin(serialRate);
    while (!Serial); // Wait for Serial Monitor to open   
  }

  setup_apds9960_arduino();
  //setup_apds9960_sparkfun();
  
  setupBlackLineSensor(&qtr);
  calibrateBlackLineSensor(&qtr);
    
  Serial.println("All good... Program started!");
}

void loop() {
  if(testMode){
    tests();
    return;
  }

  if(isCloseObject()) {
    //handle close object
    driver.stopAll();
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
  } else {
    //not close object
    handleSteering(&qtr,sensorValues,&driver);
  }
}

bool isCloseObject() {
  return readProximity_apds9960_arduino() < closeObject;
}

void tests() {
  
}

/*
void motorExmaple() {
  driver.motor1->backward(127);
  driver.stopAll();
}
*/
