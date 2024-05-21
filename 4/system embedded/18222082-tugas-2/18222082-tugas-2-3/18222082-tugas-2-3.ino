#define PinButtonLeft 22
#define PinButtonRight 23

#define PinLed1 5
#define PinLed2 18
#define PinLed3 19
#define PinLed4 21

int StateButtonLeftPrev = HIGH;
int StateButtonRightPrev = HIGH;
int StateButtonLeft = HIGH;
int StateButtonRight = HIGH;

int PinLed[] = {PinLed1, PinLed2, PinLed3, PinLed4};
int IdxCurrLed = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(PinButtonLeft, INPUT_PULLUP);
  pinMode(PinButtonRight, INPUT_PULLUP);
  for(int i = 0; i < 4; i ++) {
    pinMode(PinLed[i], OUTPUT);
  }
  digitalWrite(PinLed[IdxCurrLed], HIGH);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  StateButtonLeftPrev = StateButtonLeft;
  StateButtonRightPrev = StateButtonRight;
  StateButtonLeft = digitalRead(PinButtonLeft);
  StateButtonRight = digitalRead(PinButtonRight);

  if(StateButtonLeft == LOW && StateButtonLeftPrev == HIGH) {
    digitalWrite(PinLed[IdxCurrLed], LOW);
    IdxCurrLed = (IdxCurrLed - 1 + 4) % 4;
    digitalWrite(PinLed[IdxCurrLed], HIGH);
  }

  if(StateButtonRight == LOW && StateButtonRightPrev == HIGH) {
    digitalWrite(PinLed[IdxCurrLed], LOW);
    IdxCurrLed = (IdxCurrLed + 1) % 4;
    digitalWrite(PinLed[IdxCurrLed], HIGH);
  }
}
