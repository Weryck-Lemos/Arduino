int vet[] = {5,6,7,9,10,12,13}, n=7;
int button1 = 2, button2 = 3;
int phase1, phase2;
int preview1 = HIGH, preview2 = HIGH;
int idx = 0;
bool ledUP[7] = {false};

void setup()
{
  for(int i=0; i<n; i++)
  	pinMode(vet[i], OUTPUT);
  
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
}

void loop()
{
  phase1 = digitalRead(button1);
  phase2 = digitalRead(button2);
  
  digitalWrite(vet[idx], HIGH);
  if(phase1 == LOW && preview1 == HIGH)
  {
    if(!ledUP[idx])digitalWrite(vet[idx], LOW);
    idx ++;
    if(idx == n) idx=0;
  }
  preview1 = phase1;
  
  
  if(phase2 == LOW && preview2 == HIGH)
  {
    ledUP[idx] = !ledUP[idx];
    if(vet[idx] == HIGH) digitalWrite(vet[idx], LOW);
    
  }
  preview2 = phase2;
  
  if(ledUP[6])
  {
    reset();
  	digitalWrite(vet[6], LOW);
    for (int i = 0; i < 7; i++) ledUP[i] = false;
    delay(200);
    idx=0;
  }
}

void reset()
{
  for(int i=0; i<3; i++)
  {
    for(int i=0; i<n-1; i++)
      digitalWrite(vet[i],HIGH);
    delay(200);
    for(int i=0; i<n-1; i++)
      digitalWrite(vet[i],LOW);
    delay(200);
  }
}