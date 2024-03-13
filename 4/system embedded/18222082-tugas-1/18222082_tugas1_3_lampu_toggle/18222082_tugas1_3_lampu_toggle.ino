#define BUTTON_PIN 19 // define the pin that button use
#define LED_PIN 18    // define the pin that led use

// variables that will change
int led_state = LOW;  // initial state of led
int button_state;
int last_button_state;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);

  button_state = digitalRead(BUTTON_PIN); // read the initial state of button
}

void loop() {
  last_button_state = button_state;
  button_state = digitalRead(BUTTON_PIN);

  if(last_button_state == HIGH && button_state == LOW) {
    led_state = !led_state;               // toggle the state of led
    digitalWrite(LED_PIN, led_state);     // control led
  }
}