#define echo 4
#define trig 5
int vet[] = {8,9,10,11};
int n=4;
void setup() {
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  long duration = pulseIn(echo, HIGH);
  float distance = duration* 0.034/2.0;

  Serial.print(distance);
  Serial.print("\n");

  if(distance <5){
    ligarLeds(4);
  }

  else if(distance < 10){
    ligarLeds(3);
  }

  else if(distance < 15){
    ligarLeds(2);
  }

  else if(distance <20){
    ligarLeds(1);
  }

  else ligarLeds(0);

  delay(500);

}

void ligarLeds(int num){
  for(int i=0; i<n; i++){
    digitalWrite(vet[i], i<num ? HIGH : LOW);
  }
}
