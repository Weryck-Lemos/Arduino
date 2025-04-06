int vet[] = {2,3,4,5,6,7,8}, n=7;
void setup() {
  for(int i=0; i<n; i++) pinMode(vet[i], OUTPUT);

}

void loop() {
  loading();
  

}

void desliga(){
  for(int i=0; i<n; i++)digitalWrite(vet[i], HIGH);
}

void zero(){
  desliga();
  for(int i=0; i<n-1; i++)
  {
    digitalWrite(vet[i], LOW);
  }
  digitalWrite(vet[6], HIGH);
}

void loading(){
  for(int i=0; i<n-1; i++){
    digitalWrite(vet[i], LOW);
    delay(100);
    digitalWrite(vet[i], HIGH);
  }
}

/*
a-1
b-2
c-3
d-4
e-5
f-6
g-7
h-8

*/
