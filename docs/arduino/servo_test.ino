#include <Servo.h>

Servo base, shoulder, elbow, wrist, gripper;

void setup() {
  Serial.begin(9600);
  Serial.println("Servo Test Starting...");

  base.attach(3);
  shoulder.attach(5);
  elbow.attach(6);
  wrist.attach(9);
  gripper.attach(10);

  // Center all
  base.write(90);
  shoulder.write(90);
  elbow.write(90);
  wrist.write(90);
  gripper.write(90);
  delay(1000);
}

void loop() {
  Serial.println("Sweeping all servos...");
  
  for(int pos = 0; pos <= 180; pos += 3) {
    base.write(pos);
    shoulder.write(pos);
    elbow.write(pos);
    wrist.write(pos);
    gripper.write(pos);
    delay(15);
  }
  
  for(int pos = 180; pos >= 0; pos -= 3) {
    base.write(pos);
    shoulder.write(pos);
    elbow.write(pos);
    wrist.write(pos);
    gripper.write(pos);
    delay(15);
  }
  
  delay(500);
}
