int pot = A0, n=5;
int vet[]= {5,6,7,9,10};
void setup()
{
  for(int i=0; i<n; i++)
    pinMode(vet[i], OUTPUT);
}

void loop()
{
  int potValue = analogRead(pot);
  int ledsToLight = map(potValue, 0, 1023, 0,n);
  
  for(int i=0; i<n; i++)
  {
    if(i<ledsToLight) digitalWrite(vet[i], HIGH);
    
    else digitalWrite(vet[i], LOW);
  }
}