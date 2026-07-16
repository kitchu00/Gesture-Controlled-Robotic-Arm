#include <Servo.h>

// Declare servos
Servo base;
Servo shoulder;
Servo elbow;
Servo wrist;
Servo gripper;

void setup() {
  Serial.begin(9600);
  Serial.println("Servo Test Starting...");

  // Attach servos to pins
  base.attach(3);
  shoulder.attach(5);
  elbow.attach(6);
  wrist.attach(9);
  gripper.attach(10);

  // Move all to center position
  base.write(90);
  shoulder.write(90);
  elbow.write(90);
  wrist.write(90);
  gripper.write(90);
  delay(1000);
}

void loop() {
  Serial.println("Sweeping all servos...");

  // Sweep from 0 to 180
  for(int pos = 0; pos <= 180; pos += 3) {
    base.write(pos);
    shoulder.write(pos);
    elbow.write(pos);
    wrist.write(pos);
    gripper.write(pos);
    delay(15);
  }

  // Sweep back from 180 to 0
  for(int pos = 180; pos >= 0; pos -= 3) {
    base.write(pos);
    shoulder.write(pos);
    elbow.write(pos);
    wrist.write(pos);
    gripper.write(pos);
    delay(15);
  }

  delay(1000); // Wait before next cycle
}
