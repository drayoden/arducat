#include <AccelStepper.h>
#define HALF4WIRE 8

// Motor pin definitions
#define motorPin1  3     // IN1 on the ULN2003 driver 1
#define motorPin2  4     // IN2 on the ULN2003 driver 1
#define motorPin3  5     // IN3 on the ULN2003 driver 1
#define motorPin4  6     // IN4 on the ULN2003 driver 1

AccelStepper stepper1(HALF4WIRE, motorPin1, motorPin3, motorPin2, motorPin4);

void setup() {
  stepper1.setMaxSpeed(2000.0);
  stepper1.setAcceleration(400.0);
  stepper1.setSpeed(500);
  stepper1.moveTo(4080); 
}//--(end setup )---



void loop() {

  //Change direction when the stepper reaches the target position
  
  if (stepper1.distanceToGo() == 0) {
    stepper1.moveTo(-stepper1.currentPosition());
  }
  
  stepper1.run();
  
}
