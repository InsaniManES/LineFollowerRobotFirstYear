#include "APDS9960_SparkFun.h"

// Global Variables
SparkFun_APDS9960 apds = SparkFun_APDS9960();
uint8_t proximity_data = 0;
uint16_t ambient_light = 0;
uint16_t red_light = 0;
uint16_t green_light = 0;
uint16_t blue_light = 0;

bool setup_apds9960_sparkfun() {
  // Initialize APDS-9960 (configure I2C and initial values)
  if ( apds.init() ) {
    Serial.println(F("APDS-9960 initialization complete"));
  } else {
    Serial.println(F("Something went wrong during APDS-9960 init!"));
    return false;
  }

  // Start running the APDS-9960 light sensor (no interrupts)
  if ( apds.enableLightSensor(false) ) {
    Serial.println(F("Light sensor is now running"));
  } else {
    Serial.println(F("Something went wrong during light sensor init!"));
    return false;
  }

  // Adjust the Proximity sensor gain
  if ( !apds.setProximityGain(PGAIN_2X) ) {
    Serial.println(F("Something went wrong trying to set PGAIN"));
    return false;
  }
  
  // Start running the APDS-9960 proximity sensor (no interrupts)
  if ( apds.enableProximitySensor(false) ) {
    Serial.println(F("Proximity sensor is now running"));
  } else {
    Serial.println(F("Something went wrong during sensor init!"));
    return false;
  }
  
  // Wait for initialization and calibration to finish
  delay(500);
  return true;  
}

int readColor_apds9960_sparkfun() {
    // Read the light levels (ambient, red, green, blue)
  if (  !apds.readAmbientLight(ambient_light) ||
        !apds.readRedLight(red_light) ||
        !apds.readGreenLight(green_light) ||
        !apds.readBlueLight(blue_light) ) {
    Serial.println("Error reading light values");
    return ERR;
  } else {
    Serial.print("Ambient: ");
    Serial.print(ambient_light);
    Serial.print(" Red: ");
    Serial.print(red_light);
    Serial.print(" Green: ");
    Serial.print(green_light);
    Serial.print(" Blue: ");
    Serial.println(blue_light);

    if(red_light > green_light && red_light > blue_light) return RED;
    if(green_light > red_light && green_light > blue_light) return GREEN;
    if(blue_light > red_light && blue_light > green_light) return BLUE;
  }
}

int readProximity_apds9960_sparkfun() {
  // Read the proximity value
  if ( !apds.readProximity(proximity_data) ) {
    Serial.println("Error reading proximity value");
    return -1;
  } else {
    Serial.print("Proximity: ");
    Serial.println(proximity_data);
    return proximity_data;
  }
}
