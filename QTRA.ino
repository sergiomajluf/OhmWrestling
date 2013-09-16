void initQTRASensor(){
  delay(500);
  pinMode(QTR_LED, OUTPUT);

  Serial.println("Calibration will start and take around 10 seconds");
  Serial.println("Expose sensor to both Black and White surfaces.");
  digitalWrite(QTR_LED, HIGH);    // turn on Arduino's LED to indicate we are in calibration mode

  // make the calibration take about 10 seconds
  // during this time, EXPOSE SENSOR TO BOTH WHITE AND BLACK
  for (int i = 0; i < 400; i++)  { 
    // reads all sensors 10 times at 2.5 ms per six sensors (i.e. ~25 ms per call)
    qtra.calibrate();       
  }
  digitalWrite(QTR_LED, LOW);     // turn off Arduino's LED to indicate we are through with calibration
  Serial.println("Calibration finished.");
  Serial.println("/////////////////////////////////////////");
  Serial.println("Minimum values.");
  // print the calibration minimum values measured when emitters were on
  for (int i = 0; i < NUM_SENSORS; i++)
  {

    Serial.print(qtra.calibratedMinimumOn[i]);
    Serial.print('\t');
  }
  Serial.println();
  delay(500);

  Serial.println("/////////////////////////////////////////");
  Serial.println("Maximum values.");
  // print the calibration maximum values measured when emitters were on
  for (int i = 0; i < NUM_SENSORS; i++)
  {

    Serial.print(qtra.calibratedMaximumOn[i]);
    Serial.print('\t');
  }
  Serial.println();
  Serial.println();
  delay(1500);

}


