void setup() {
  pinMode(18, OUTPUT);    // initiate the pin that LED use
}

void loop() {
  digitalWrite(18, HIGH); // turn the LED on
  delay(500);             // wait for 500 ms (2hz)
  digitalWrite(18, LOW);  // turn the LED off
  delay(500);             // wait for 500 ms (2hz)
}