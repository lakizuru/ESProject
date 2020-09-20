#include <Servo.h>

Servo motor;

void setup()
{
  pinMode(11, OUTPUT);
  pinMode(7, INPUT);
  pinMode(6, INPUT);
  pinMode(5, INPUT);
  //pinMode(0, OUTPUT);
  motor.attach(0);
}

void loop()
{
  if (digitalRead(7) == HIGH){
    digitalWrite(11, HIGH);
    motor.write(135);
  }
  else if (digitalRead(6) == HIGH){
    digitalWrite(11, HIGH);
    motor.write(90);
  }
  else if (digitalRead(5) == HIGH){
    digitalWrite(11, HIGH);
    motor.write(45);
  }
}
