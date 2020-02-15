#include<Servo.h>
long duration;
int distance;
Servo servo;
void setup() {
  servo.attach(10);
  servo.write(0);
  pinMode(8, OUTPUT);
  pinMode(9, INPUT);
  Serial.begin(9600);
  delay(1000);
}
void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(8, LOW);
  delayMicroseconds(2);
  digitalWrite(8, HIGH);
  delayMicroseconds(10);
  digitalWrite(8, LOW);
  duration = pulseIn(9, HIGH);
  distance = duration * 0.03432 / 2;
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println("cm");
  if ((distance > 20) && (distance < 50))
  {
    servo.write(100);
  }
  else
  {
    servo.write(0);
  }
}
