/*

 motor functions here
 
 This funbciotn goes inside for loop
 
 blueWinning(){
 if (has IR been switched){
 motor position reverse
 }
 else {
 }
 }
 
 
 orangeWinning(){
 if (has IR been switched){
 motor position reverse
 }
 else {
 }
 }
 
 
 */

void MoveMotorDirBlue(){
  //move the arms in favour of blue
  analogWrite(enablePin, movePWM);
  digitalWrite(motor1pin, HIGH);
  digitalWrite(motor2pin, LOW);
}
void HoldMotorPosBlue(){
  ///hold the arms in place when on the blue side
  //i.e torwards orange
  analogWrite(enablePin, HoldingPWM);
  digitalWrite(motor1pin, LOW);
  digitalWrite(motor2pin,  HIGH);
}

void MoveMotorDirOrange(){
  analogWrite(enablePin, movePWM);
  digitalWrite(motor1pin, LOW);
  digitalWrite(motor2pin, HIGH);
}

void HoldMotorPosOrange(){
  ///hold the arms in place when on the orange side
  //i.e torwards blu
  analogWrite(enablePin, HoldingPWM);
  digitalWrite(motor1pin, HIGH);
  digitalWrite(motor2pin, LOW);
}

void IRBoolean(){
  // read raw valu from IR sensor
  qtra.read(sensorValues);

  if (sensorValues[0] > IRthreshold){
    black = true;
  } 
  else {
    black = false;
  }
}





