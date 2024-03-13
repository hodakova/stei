void setup() {
  pinMode(17, OUTPUT);    // initiate the pin that red LED use
  pinMode(18, OUTPUT);    // initiate the pin that white LED use
}

void loop() {
  digitalWrite(17, HIGH); // turn the red LED on
  digitalWrite(18, LOW);  // turn the white LED off
  delay(5000);            // wait for 5000 ms (0.2 hz)
  digitalWrite(17, LOW);  // turn the red LED off
  digitalWrite(18, HIGH); // turn the white LED on
  delay(3333);            // wait for 3333 ms (0.3 hz)
}