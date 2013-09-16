void CalibrationBLUE(){


  BLUEreading = digitalRead(BLUEbutton);

  if (BLUEreading == LOW && BLUEprevious == HIGH && millis() - time > debounce) {
    if (BLUEbuttonState == LOW)
      BLUEbuttonState = HIGH;
  }
  else{
    BLUEbuttonState = LOW;
    time = millis(); 
    Serial.println(BLUEreading);   

  }
  if (BLUEreading==0){
    //    delay (1000);
    Serial.println ("BLUE MOTORZ");
    ///initalizes the count from when the button was pressed
    analogWrite(enablePin, movePWM);

    digitalWrite(motor1pin, HIGH);
    digitalWrite(motor2pin, LOW);
    ///return meter to center
    ///****select pwm for this--i.e. the speed that the arm increases to center
    analogWrite(enablePin, HoldingPWM);

    //    if (IR == xxx){
    //      ///stop motor
    //   analogWrite(enablePin, 160);
    //    }

    ///set servo to center
    //center IS 98 if blue wins
    MeterArm.write (98); 
  }


}

void CalibrationORG(){
  ORGreading = digitalRead(ORGbutton);

  if (ORGreading == LOW && ORGprevious == HIGH && millis() - time > debounce) {
    if (ORGbuttonState == LOW)
      ORGbuttonState = HIGH;
  }
  else{
    ORGbuttonState = LOW;
    time = millis(); 
    Serial.println(ORGreading); 

  }
  if (ORGreading==0){
    //    delay (1000);
    Serial.println ("ORG MOTORZ");
    ///initalizes the count from when the button was pressed
    analogWrite(enablePin, HoldingPWM);
    digitalWrite(motor1pin, LOW);
    digitalWrite(motor2pin, HIGH);

    //    if (IR == xxx){
    //      ///stop motor
    analogWrite(enablePin, movePWM);
    //    }

    ///return meter to center degrees ///
    ///caveat- center IS 103 if the win is ORANGE
    MeterArm.write (103); 
  }
}



