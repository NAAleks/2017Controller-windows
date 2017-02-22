#include <UnoJoy.h>

int trapDoor = 5;
int roofDoor = 12;
int flyWheel = 11;
int ag_forward = 10;
int ag_backwards = 9;
int climb = 8;
int extra1 = 7;
int extra2 = 6;
void setup() {
//  Serial.begin(9600);
  setupUnoJoy();
  for(int i=12; i>=5;i--){ //An example of laziness 
  pinMode(i,INPUT_PULLUP);  
  } 
}

void loop() {
  dataForController_t controllerData = getControllerData();
  setControllerData(controllerData);
//  Serial.println(!digitalRead(trapDoor));
}
dataForController_t getControllerData(void){
  
  dataForController_t controllerData = getBlankDataForController();

  /*
  MAP 
  TrapDoor -> triangle 
  RoofDoor -> Circle
  FlyWheel -> Square
  ag_forward -> l10n
  ag_backward -> l20n
  climb -> cross (x) 
  extra1 -> r10n 
  extra2 -> r20n
  */

  controllerData.triangleOn = !digitalRead(trapDoor);
  controllerData.circleOn = !digitalRead(roofDoor);
  controllerData.squareOn = !digitalRead(flyWheel);
  controllerData.crossOn = !digitalRead(climb);
  controllerData.l1On = !digitalRead(ag_forward);
  controllerData.l2On = !digitalRead(ag_backwards);
  controllerData.r1On = !digitalRead(extra1);
  controllerData.r2On = !digitalRead(extra2);
  
  return controllerData;
}

