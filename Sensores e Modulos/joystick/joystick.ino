int joyX = A4;
int joyY = A5;
int joyButton = 2;

void setup() {
   Serial.begin(9600);
   pinMode(joyX, INPUT);
   pinMode(joyY, INPUT);
   pinMode(joyButton, INPUT_PULLUP);
}

void loop() {
   int x = analogRead(joyX);
   int y = analogRead(joyY);
   int button = digitalRead(joyButton);

   if (x > 900 && y > 400 && y < 600) {
       Serial.println("d");
   } else if (x < 100 && y > 400 && y < 600) {
       Serial.println("a");
   } else if (y > 900 && x > 400 && x < 600) {
       Serial.println("w");
   } else if (y < 100 && x > 400 && x < 600) {
       Serial.println("s");
   }

   delay(100);
}


