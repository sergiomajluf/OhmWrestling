void checkdevices(){
  //SET ANALOGE PIN READ - VALUES DEVICES///
  //READ DEVICE INPUTS///
  ///times the device inputs by the span of the voltage divider
  ///NOTE THE VALUE OF THE VOLTAGE DIVIDER RANGE


  ///DECLARE ALL ORGANGE DEVICES
  float OrgBike = analogRead (OrgBikePin) * 100;
  ///the voltage divider for org. bike is 470Ohm to 4.7Ohm 100
  float OrgCrank = analogRead (OrgCrankPin) * 1;
  ///undefined voltage divider value
  float OrgShake = analogRead (OrgShakePin) * 1;
  ///undefined voltage divider value
  float OrgWheel = analogRead (OrgWheelPin) * 1;
  ///undefined voltage divider value
  float OrgPulley = analogRead (OrgPulleyPin) * 1;
  ///undefined voltage divider value
  ///ADD ALL ANALOG READ FUNCTION
  float OrangeTotal = OrgBike+ OrgCrank + OrgShake + OrgWheel + OrgPulley;


  ////DECLARE ALL BLUE DEVICES////

  float BluBike = analogRead (BluBikePin) *1;
  ///undefined voltage divider value
  float BluCrank = analogRead (BluCrankPin) *1;
  ///undefined voltage divider value
  float BluShake = analogRead (BluShakePin) *1;
  ///undefined voltage divider value
  float BluWheel = analogRead (BluWheelPin) *1;
  ///undefined voltage divider value
  float BluPulley = analogRead (BluPulleyPin) *1;
  ///undefined voltage divider value
  float  BlueTotal = BluBike+ BluCrank + BluShake + BluWheel + BluPulley;
}

