// Pin definitions
#define SW_1 2
#define D1 5
#define D2 4
#define D3 3

#define DELAY 75 //ms

void setup() {
  pinMode(SW_1, INPUT);
  pinMode(D3, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D1, OUTPUT);
}

void loop() {
  if(digitalRead(SW_1) == LOW){
    digitalWrite(D3, HIGH);
    digitalWrite(D2, LOW);
    digitalWrite(D1, LOW);
  } else {
    digitalWrite(D3, LOW);
    digitalWrite(D2, HIGH);
    digitalWrite(D1, LOW);

    delay(DELAY);
    digitalWrite(D2, LOW);
    digitalWrite(D1, HIGH);
    delay(DELAY);
  }
}
