#include "blackLineSensor.h"

void setupBlackLineSensor(QTRSensors *qtr) {
  qtr->setTypeRC();
  qtr->setSensorPins(sensorPins, NUM_SENSORS);
  qtr->setTimeout(QTR_TIMEOUT);
  qtr->setEmitterPin(QTR_EMITTER_PIN);  
}

void calibrateBlackLineSensor(QTRSensors *qtr) {
  digitalWrite(LED_BUILTIN, HIGH); // turn on Arduino's LED to indicate we are in calibration mode
  Serial.println("Calibrating...");

  // 2.5 ms RC read timeout (default) * 10 reads per calibrate() call
  // = ~25 ms per calibrate() call.
  // Call calibrate() 400 times to make calibration take about 10 seconds.
  for (uint16_t i = 0; i < 250; i++) {
    if(i%25 == 0) {
      Serial.print((i/25)*10);
      Serial.println("% Calibrated");
      tone(BUZZER, 1000); // Send 1KHz sound signal...
    }
    qtr->calibrate();
    noTone(BUZZER);     // Stop sound...
  }
    
  digitalWrite(LED_BUILTIN, LOW); // turn off Arduino's LED to indicate we are through with calibration
  tone(BUZZER, 2500); // Send 1KHz sound signal...
  delay(1000);
  noTone(BUZZER);     // Stop sound...

  Serial.println("Done calibrating!");
  
  /*for (int i = 0; i < NUM_SENSORS; i++) {
    Serial.print(qtr->calibrationOn.minimum[i]);
    Serial.print(' ');
  }
  Serial.println();
  
  // print the calibration maximum values measured when emitters were on
  for (int i = 0; i < NUM_SENSORS; i++) {
    Serial.print(qtr->calibrationOn.maximum[i]);
    Serial.print(' ');
  }
  Serial.println();
  Serial.println();
  */
  delay(1000);
}

/*
void QTR8RCExmaple() {
  // read calibrated sensor values and obtain a measure of the line position
  // from 0 to 7500 (for a white line, use readLineWhite() instead)
  uint16_t position = qtr.readLineBlack(sensorValues);

  // print the sensor values as numbers from 0 to 1000, where 0 means maximum
  // reflectance and 1000 means minimum reflectance, followed by the line
  // position
  for (uint8_t i = 0; i < NUM_SENSORS; i++)
  {
    Serial.print("Sensor number ");
    Serial.print(i+1);
    Serial.print(": ");
    Serial.println(sensorValues[i]);
  }

  Serial.println();
  Serial.print("position: ");
  Serial.println(position);
  Serial.println();
  delay(50);    
}
*/
