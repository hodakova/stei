#define pin_ADC 4
#define pin_DAC 25

void setup() {
  Serial.begin(9600);
  dacWrite(pin_DAC, 0);
}

void loop() {
  for(int value_DAC = 0; value_DAC <= 255; value_DAC += 50) {
    dacWrite(pin_DAC, value_DAC);
    delay(10);

    int value_ADC = analogRead(pin_ADC);
    float voltage = (value_ADC / 4095.0) * 3.3;

    Serial.print("DAC value : ");
    Serial.println(value_DAC);
    Serial.print("ADC value : ");
    Serial.println(value_ADC);
    Serial.print("Voltage   : ");
    Serial.print(voltage);
    Serial.println(" V");

    delay(5000);
  }
}
