#include "APDS9960_Arduino.h"

int boost_mode = 3; //300% BOOST!!

bool setup_apds9960_arduino() {
  if (!APDS.begin()) {
    Serial.println("Error initializing APDS-9960 sensor.");
    return false;
  }
  APDS.setLEDBoost(boost_mode);
  return true;
}

int readColor_apds9960_arduino() {
  int r, g, b;
  // Check if a color reading is available.
  while (!APDS.colorAvailable()) delay(5);
 
  // Read the color.
  APDS.readColor(r, g, b);

  // Print the values:
  Serial.print("r = ");
  Serial.println(r);
  Serial.print("g = ");
  Serial.println(g);
  Serial.print("b = ");
  Serial.println(b);
  Serial.println();

  if(r > g && r > b) return RED;
  if(g > r && g > b) return GREEN;
  if(b > r && b > g) return BLUE;
}

int readProximity_apds9960_arduino() {
  int proximity;

  // Check if a proximity reading is available.
  while(!APDS.proximityAvailable()) delay(5);
    
    // Read the proximity where:
    // - 0   => close
    // - 255 => far
    // - -1  => error
    proximity = APDS.readProximity();

    // Print value to the Serial Monitor.
    Serial.print("proximity = ");
    Serial.println(proximity);
    return proximity;

}
