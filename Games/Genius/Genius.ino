int button[]= {0,1,2,3}, vet[]={8,9,10,11};
int n=4;
int seq[100], level = 0;
int buzzer = A0;
int tones[] = {260, 330, 390, 520};
int pIndex;
void setup() {
  for(int i=0; i<n; i++){
    pinMode(vet[i], OUTPUT);
    pinMode(button[i], INPUT_PULLUP);
  }

  pinMode(buzzer, OUTPUT);
}

void loop() {
  seq[level] = random(0,n);
  tocar(level);

  pIndex = 0;
  while(pIndex <= level){
    bool pressed = false;

    while(!pressed){
      for(int i=0; i<n; i++){
        if(digitalRead(button[i])==LOW){
          pressed = true;

          if(i== seq[pIndex]){
            digitalWrite(vet[i], HIGH);
            tone(buzzer, tones[i], 200);
            delay(200);
            digitalWrite(vet[i], LOW);
            noTone(buzzer);
            pIndex++;

            if(pIndex>level){
              level++;
              delay(400);
              return; //proximo nivel
            }
          }

          else{
            reset();
            return; //errou;
          }
        }
      }
    }
  }
}

void tocar(int lv){
  for(int i=0; i<=lv; i++){
    int ledIndex = seq[i];
    digitalWrite(vet[ledIndex], HIGH);
    tone(buzzer, tones[ledIndex], 200);
    delay(200);
    digitalWrite(vet[ledIndex], LOW);
    noTone(buzzer);
    delay(200);
  }
}

void reset(){
  for(int i=0; i<3; i++){
    for(int j=0; j<n; j++){
      digitalWrite(vet[j], HIGH);
    }
    tone(buzzer, 200, 150);
    delay(250);
    for(int j=0; j<n; j++){
      digitalWrite(vet[j], LOW);
    }
    noTone(buzzer);
    delay(200);
  }
  delay(500);

  level = 0;
}
