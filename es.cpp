void rotate(int angle);

void setup()
{
  pinMode(11, OUTPUT);
  pinMode(7, INPUT);
  pinMode(6, INPUT);
  pinMode(5, INPUT);
  pinMode(0, OUTPUT);
}

void loop()
{
  if (digitalRead(7) == HIGH){
    digitalWrite(11, HIGH);
    rotate(135);
  }
  else if (digitalRead(6) == HIGH){
    digitalWrite(11, HIGH);
    rotate(90);
  }
  else if (digitalRead(5) == HIGH){
    digitalWrite(11, HIGH);
    rotate(45);
  }
}

void rotate(int angle){
    int pulse = int(800 + angle * (70.0/9));
    int i;
    for (i < 50; i++){
        digitalWrite(0, HIGH);
        delay(pulse);
        digitalWrite(0, LOW);
        delay(2000 - pulse);
    }
}
