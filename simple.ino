// PIR Motion Sensor Alarm Code
int pirSensorPin = 7;  // PIR sensor connected to digital pin 2
int buzzerPin = 4;
int sensorState = LOW; // Initial state of the PIR sensor

void setup() {
  pinMode(pirSensorPin, INPUT);  // Set PIR sensor pin as input
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);           // Start serial communication
}

void loop() {
  // Read the PIR sensor state
  sensorState = digitalRead(pirSensorPin);
  
  if (sensorState == HIGH) {    // Motion detected
    tone(buzzerPin, 5);
    Serial.println("Motion detected!");
  } else {                      // No motion
    Serial.println("No motion.");
    noTone(buzzerPin);
  }
  
  delay(100); // Small delay for sensor stability
}
