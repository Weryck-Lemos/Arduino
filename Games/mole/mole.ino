int led[] = {8, 9, 10, 11};
int button[] = {1, 2, 3, 4};
int buzzer = 13;
int n = 4;

void setup() {
  for (int i = 0; i < n; i++) {
    pinMode(led[i], OUTPUT);
  }

  for (int i = 0; i < n; i++) {
    pinMode(button[i], INPUT_PULLUP);
  }

  pinMode(buzzer, OUTPUT);
}

void loop() {
  int randIndex = random(0, n);
  digitalWrite(led[randIndex], HIGH);

  bool pressed = false;
  while(!pressed)
  {
    if(digitalRead(button[randIndex]) == LOW)
    {
      pressed = true;
      digitalWrite(led[randIndex], LOW);
      tone (buzzer, 1000, 100);
      delay(300);
    }

    else if(miss(randIndex))
    {
      reset();
      return;
    }
  }

  delay(200);
}

bool miss(int randIndex) {
  for(int i=0; i<n; i++)
  {
    if(i != randIndex && digitalRead(button[i])==LOW) return true;
  }
  return false;
}

void reset() {
  tone(buzzer, 500, 200);
  for(int i=0; i<n; i++) digitalWrite(led[i], HIGH);
  delay(200);
  tone(buzzer, 250, 200);
  for(int i=0; i<n; i++) digitalWrite(led[i], LOW);
  delay(200);
  tone(buzzer, 600, 160);
  delay(200);
}
