int LDR_Pin = A0;     // LDR connected to analog pin A0
int LED_Red = 9;      // Red LED connected to pin 9
int LED_Green = 8;    // Green LED connected to pin 8

void setup() {
  pinMode(LED_Red, OUTPUT);
  pinMode(LED_Green, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int ldrValue = analogRead(LDR_Pin);  // Read LDR value
  Serial.println(ldrValue);           // Print for calibration

  int threshold = 500;  // Adjust depending on light level

  if (ldrValue < threshold) {
    // Dark condition
    digitalWrite(LED_Red, LOW);  // Red OFF 
    digitalWrite(LED_Green, HIGH); // Green ON
  } else {
    // Bright condition
    digitalWrite(LED_Red, HIGH);  // Red ON
    digitalWrite(LED_Green, LOW); // Green OFF
  }
}
