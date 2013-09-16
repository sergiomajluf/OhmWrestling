//SET SERVO STUFF//
#include <Servo.h>
Servo MeterArm;

// QTR Sensors library
// Download from https://github.com/pololu/qtr-sensors-arduino
#include <QTRSensors.h>

//SET ANALOG PINS////

///ORANGE DEVICES
const float OrgBikePin = A0;
const float OrgCrankPin = A1;
const float OrgShakePin = A2;
const float OrgWheelPin = A5;
const float OrgPulleyPin = A6;
//orange device floats

///BLUE DEVICES////
const float BluBikePin = A9;
const float BluCrankPin = A10;
const float BluShakePin = A11;
const float BluWheelPin = A12;
const float BluPulleyPin = A13;

////Blue and Orange Device float to hold math function//
float GrandTotalDevices;
float BlueTotal;
float OrangeTotal;
float CheckDeviceTime = 2000;

////Timer for compiling math on devices
int DeviceMathTimer= 2000;

///ARMS MECH-MOTOR CONTROL PINS///
///HBRIDGE PINS
const int motor1pin = 5;  //HBridge leg 1 (pin 4, 1A);
const int motor2pin = 3;  // HBridge leg 2 (pin 3, 2A);
const int enablePin = 2;  // HBridge enable pin
int HoldingPWM = 160;  //the int which stores what PWM holds the motor arms still
int movePWM = 255; //the int which is the PWM for movement
///DELAY INT FOR TIME OF MOTOR MOVEMENT
///THIS IS THE INT THAT COMES FROM THE CALIBRATION SKETCH
int DegreeAngleTime;



//SET THE CALIBRATION BUTTONS///
const int BLUEbutton= 7;
const int ORGbutton= 13;

///set the IR ints here
#define NUM_SENSORS             1  // number of sensors used
#define NUM_SAMPLES_PER_SENSOR  4  // average 4 analog samples per sensor reading
#define EMITTER_PIN             QTR_NO_EMITTER_PIN  // emitter is controlled by digital pin 2

// Initizlize QTR Sensor
// and set the analog pin that the sensor will be connected to
QTRSensorsAnalog qtra((unsigned char[]) {15},NUM_SENSORS, NUM_SAMPLES_PER_SENSOR, EMITTER_PIN);

unsigned int sensorValues[NUM_SENSORS];
const int QTR_LED = 53;

unsigned int IR[NUM_SENSORS];
//threshold for IR 
int IRthreshold = 300;
///set the true function for the boolean IR
boolean black = false;
///holds the boolean int
int center= 0;



///BUTTON DEBOUNCING INTS
long time = 0;         // the last time the output pin was toggled
long debounce = 200;   // the debounce time, increase if the output flickers
int BLUEbuttonState =LOW;//the current state of button
int BLUEreading;
int BLUEprevious = HIGH; //the previous reading of button
int ORGbuttonState =LOW;//the current state of button
int ORGreading;
int ORGprevious = HIGH; //the previous reading of button

////SET THE TIMER FOR CALIBRATION MODE//
//int pressStart;
//int counter=0;
//unsigned long currentMillis;
//long waitTime = 1000;

void setup () {

  ///set the servo meter arm
  MeterArm.attach (9);
  ///Set the calibration button pins
  pinMode(BLUEbutton, INPUT);      // set the switch pin to be an input
  pinMode(ORGbutton, INPUT);      // set the switch pin to be an input

  ///SET THE MOTOR PINS///

  pinMode (motor1pin, OUTPUT);
  pinMode (motor2pin, OUTPUT);
  pinMode (enablePin, OUTPUT);
  ///sets the motor to begin at a holding position/stopped
  analogWrite(enablePin, HoldingPWM);

  ///SET THE CALIBRATION BUTTON PINS///
  pinMode (BLUEbutton, INPUT);
  //call the internal resistor from Ard.
  digitalWrite(BLUEbutton, HIGH);
  pinMode (ORGbutton, INPUT);
  //call the internal resistor from Ard.
  digitalWrite(ORGbutton, HIGH);

  Serial.begin(9600);
  
  initQTRASensor();
  
  // HW Interrupts on MEGA, are # over Pin, as follows
  // 0/2    1/3    2/21	3/20	4/19	5/18
  attachInterrupt(2, IRBoolean, CHANGE);
}

void loop(){
  //check that the movement of motor function has or has not passed center threshold
  //IRBoolean();
  //read the devices and do math 
  checkdevices();

  ///check the winning calibration buttons
  CalibrationBLUE();
  CalibrationORG();

  //get output from devices here
  GrandTotalDevices= BlueTotal - OrangeTotal;
  ///calculate the ratio of DegreeAngleTime to GrandTotalDevices Here.
  Serial.println(BLUEbuttonState);
  //Serial.println(GrandTotalDevices);

  //if the output of the devices is negative
  if (GrandTotalDevices  < 1 && GrandTotalDevices != 0){
    for ( int x = 0; x < DegreeAngleTime; x ++){
      //record the ir sensor for the amount of time the motor moves
      ///if there is is change black should have registered TRUE
      if (black == true){
        center=1;
      }

      MoveMotorDirOrange();
      ///meter arm angles
      ///this is commented out for testing later
      //this number will be bwtn 90 and 179
      // MeterArm.write (GrandTotalDevices);

      ///turn motor off
      //if no IR Change
      HoldMotorPosOrange();
      //if IR state change - i.e. Black == true
      if (center==1){ // 90center or center?
        HoldMotorPosBlue();
        center=0;
      }

    }
    if(GrandTotalDevices  > 1 && GrandTotalDevices != 0) {
      MoveMotorDirBlue();


      ///meter arm angles
      ///this is commented out for testing later
      ///this number will be between 0 and 90
      // MeterArm.write (GrandTotalDevices);
      delay (DegreeAngleTime);
      ///turn motor offf
      analogWrite(enablePin, HoldingPWM);

    }

  }
}























