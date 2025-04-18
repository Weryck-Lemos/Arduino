int vet[]={1,3,5,7,8,10};
int n=6;
int dtime = 200;
void setup() {
  for(int i=0; i<n; i++)
    pinMode(vet[i], OUTPUT);

}

void loop() {
  ida();
  volta();
  duploCentro();
  duploPonta();
  AcenderTudo();
  delay(900);

}

void acender(int x){
  digitalWrite(vet[x], HIGH);
  delay(dtime);
  digitalWrite(vet[x], LOW);
}

void acenderDois(int x, int y){
  digitalWrite(vet[x], HIGH);
  digitalWrite(vet[y], HIGH);
  delay(dtime);
  digitalWrite(vet[x], LOW);
  digitalWrite(vet[y], LOW);
  delay(dtime);
}

void ida(){
  for(int i=0; i<n; i++)
    acender(i);
}

void volta(){
  for(int i=n-1; i>=0; i--)
    acender(i);
}

void duploCentro(){
for(int i=0, j=n-1; i<j; i++, j--)
  acenderDois(i,j);
}

void duploPonta(){
  for(int i=(n/2)-2, j=(n/2)+1; i>=0; i--, j++)
    acenderDois(i,j);
}

void AcenderTudo()
{
  for(int i=0;i<3;i++){
    digitalWrite(vet[0], HIGH);
    digitalWrite(vet[1], HIGH);
    digitalWrite(vet[2], HIGH);
    digitalWrite(vet[3], HIGH);
    digitalWrite(vet[4], HIGH);
    digitalWrite(vet[5], HIGH);
    delay(dtime);
    digitalWrite(vet[0], LOW);
    digitalWrite(vet[1], LOW);
    digitalWrite(vet[2], LOW);
    digitalWrite(vet[3], LOW);
    digitalWrite(vet[4], LOW);
    digitalWrite(vet[5], LOW);
    delay(dtime);
  }
}

