#include <Servo.h>

// Declare 6 servos
Servo base;        // 1Pin 3
Servo shoulder;    // 2Pin 5
Servo elbow;       // 3Pin 6
Servo wristPitch;  // 4Pin 9                                               
Servo wristRoll;   // 5Pin 10 
Servo gripper;     // 6Pin 11 

void setup() {
  Serial.begin(9600);
  Serial.println("6 Servo Test Starting...");

  base.attach(3);
  shoulder.attach(5);
  elbow.attach(6);
  wristPitch.attach(9);
  wristRoll.attach(10);
  gripper.attach(11);     // Use pin 11 for 6th servo

  // Center all
  base.write(90);
  shoulder.write(90);
  elbow.write(90);
  wristPitch.write(90);
  wristRoll.write(90);
  gripper.write(90);
  delay(1000);
}

void loop() {
  Serial.println("Sweeping all 6 servos...");

  for(int pos = 0; pos <= 180; pos += 3) {
    base.write(pos);
    shoulder.write(pos);
    elbow.write(pos);
    wristPitch.write(pos);
    wristRoll.write(pos);
    gripper.write(pos);
    delay(15);
  }

  for(int pos = 180; pos >= 0; pos -= 3) {
    base.write(pos);
    shoulder.write(pos);
    elbow.write(pos);
    wristPitch.write(pos);
    wristRoll.write(pos);
    gripper.write(pos);
    delay(15);
  }

  delay(1000);
}

  delay(1000); // Wait before next cycle
}
