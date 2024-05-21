#define pin1 13
#define pin2 12
#define pin3 14
#define pin4 27 
#define pin5 26

// resistor dan voltase total pada rangkaian
const float R_tot = 40000.0;
const float V_tot = 3.3;

void setup() {
 Serial.begin(9600);
 pinMode(pin1, INPUT);
 pinMode(pin2, INPUT);
 pinMode(pin3, INPUT);
 pinMode(pin4, INPUT);
 pinMode(pin5, INPUT);
}

void loop() {
 int ADC1 = analogRead(pin1);
 int ADC2 = analogRead(pin2);
 int ADC3 = analogRead(pin3);
 int ADC4 = analogRead(pin4);
 int ADC5 = analogRead(pin5);

 // ubah nilai ADC dari pin menjadi nilai voltase aktual
 float V1 = (ADC1 / 4095.0) * V_tot;
 float V2 = (ADC2 / 4095.0) * V_tot;
 float V3 = (ADC3 / 4095.0) * V_tot;
 float V4 = (ADC4 / 4095.0) * V_tot;
 float V5 = (ADC5 / 4095.0) * V_tot;

 // hasil pembacaan voltase dalam bentuk V
 Serial.print("V1 = ");
 Serial.print(V1);
 Serial.println(" V");
 Serial.print("V2 = ");
 Serial.print(V2);
 Serial.println(" V");
 Serial.print("V3 = ");
 Serial.print(V3);
 Serial.println(" V");
 Serial.print("V4 = ");
 Serial.print(V4);
 Serial.println(" V");
 Serial.print("V5 = ");
 Serial.print(V5);
 Serial.println(" V");

 // hitung nilai arus
 float I = V_tot / R_tot;

 // hasil penghitungan arus dalam bentuk µA
 Serial.print("I = ");
 Serial.print(I * 1000000);
 Serial.println(" µA");

 delay(5000);
}