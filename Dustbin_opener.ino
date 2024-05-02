/* Dustbin Door opener project
  by L.Boaz
  nissiprojectzone@gmail.com
  https://github.com/NissiEmbeddedLab
*/
#include <Servo.h>
const int trig = 7;
const int echo = 6;
Servo myservo;
int pos = 0;
void setup() {
  myservo.attach(8);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  //Serial.begin(9600);
}
void loop() {
  myservo.attach(8);
  digitalWrite(trig, LOW);
  delay(2);
  digitalWrite(trig, HIGH);
  delay(10);
  digitalWrite(trig, LOW);
  long duration = pulseIn(echo, HIGH);
  long distance = duration * 0.034 / 2;
  // Serial.print("Distance : ");
  // Serial.println(distance);
  // Serial.print(" cm");
  delay(10);
  if (distance < 30)
  {
    for (pos = 5; pos <= 135; pos += 1) {
      myservo.write(pos);
      delay(25);
      delay(4000);
      for (pos = 135; pos >= 5; pos -= 1) {
        myservo.write(pos);
        delay(25);
      }
    }
  }
  else
  {
    myservo.write(0);
    delay(25);
  }
}
