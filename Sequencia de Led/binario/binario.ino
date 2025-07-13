const int vet[]    = {2, 3, 4, 5, 6};
const int n        = sizeof(vet) / sizeof(vet[0]);
const int button1  = 7;
const int button2  = 8;
bool acender[n]    = { false, false, false, false, false };
int idx            = 0;
int valorAtual     = 0;
int aleatorio      = 0;

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(A0));
  for (int i = 0; i < n; i++) {
    pinMode(vet[i], OUTPUT);
    digitalWrite(vet[i], LOW);
  }
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  Serial.print("Número aleatório: ");
  aleatorio = gerarRandom();
  Serial.println(aleatorio);

}

void loop() {
  if (digitalRead(button1) == HIGH) press1();
  if (digitalRead(button2) == HIGH) press2();
  detectarBits();

  //acertou
  if(aleatorio == detectarBits()){
    resetar();
    aleatorio = gerarRandom();
    Serial.print("Número aleatório: ");
    Serial.println(aleatorio);
    idx = -1;
    

    
  }

 
}

void press1() {
  while (digitalRead(button1) == HIGH);
  delay(200);
  if (!acender[idx]) digitalWrite(vet[idx], LOW);
  idx = (idx + 1) % n;
  digitalWrite(vet[idx], HIGH);
}

void press2() {
  while (digitalRead(button2) == HIGH);
  delay(200);
  acender[idx] = !acender[idx];
}

int detectarBits() {
  int bits = 0;
  for (int i = 0; i < n; i++) {
    if (acender[i]) bits |= (1 << i);
  }
  return bits;
}

int gerarRandom() {
  int r = random(0, 32);
  return r;
}

void resetar(){
  for(int i=0; i<n; i++){
    acender[i]= false;

   for(int i=0; i<n; i++){
    digitalWrite(vet[i], LOW);
   }
   
   delay(50);
   
   for(int i=0; i<n; i++){
    digitalWrite(vet[i], HIGH);
   }

   delay(50);

   for(int i=0; i<n; i++){
    digitalWrite(vet[i], LOW);
   }
  
  }

}
