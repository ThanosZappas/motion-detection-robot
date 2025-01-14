
#define BUZZER_PIN 4
// Frequencies for the notes
#define zw 121
#define NH 131
#define PA 147
#define BOU 162
#define GA 175
#define DI 196
#define KE 220
#define ZW 242
#define NH_UP 262
#define PA_UP 294

// Durations
#define FULL_NOTE 400   // 1 second for a full note
#define DOUBLE_NOTE 800 // 2 seconds for a double note
#define SHORT_PAUSE 25   // Very short pause (50ms)
#define LONG_PAUSE 50   // Longer pause (250ms) for commas

void playTone(int frequency, int duration, bool longPause = false) {
    tone(BUZZER_PIN, frequency, duration);
    delay(duration);            // Wait for the note to finish
    delay(longPause ? LONG_PAUSE : SHORT_PAUSE); // Add appropriate pause
}

void playSong() {
    // First part: 2*GA GA GA GA GA 2*GA
    playTone(GA, DOUBLE_NOTE); // 2*GA
    playTone(GA, FULL_NOTE);
    playTone(GA, FULL_NOTE);
    playTone(GA, FULL_NOTE);
    playTone(GA, FULL_NOTE);
    playTone(GA, DOUBLE_NOTE,true); // 2*GA

    // Second part: 2*DI GA BOU PA BOU 2*GA
    playTone(DI, DOUBLE_NOTE); // 2*DI
    playTone(GA, FULL_NOTE);
    playTone(BOU, FULL_NOTE);
    playTone(PA, FULL_NOTE);
    playTone(BOU, FULL_NOTE);
    playTone(GA, DOUBLE_NOTE, true); // 2*GA, with comma pause

    // Third part: DI DI DI GA DI GA BOU PA
    playTone(DI, FULL_NOTE);
    playTone(DI, FULL_NOTE);
    playTone(DI, FULL_NOTE);
    playTone(GA, FULL_NOTE);
    playTone(DI, FULL_NOTE);
    playTone(GA, FULL_NOTE);
    playTone(BOU, FULL_NOTE);
    playTone(PA, FULL_NOTE);

    // Fourth part: DI GA BOU PA 2*NH
    playTone(DI, FULL_NOTE);
    playTone(GA, FULL_NOTE);
    playTone(BOU, FULL_NOTE);
    playTone(PA, FULL_NOTE);
    playTone(NH, DOUBLE_NOTE); // 2*NH
}


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
    playSong();
    Serial.println("Motion detected!");
  } else {                      // No motion
    Serial.println("No motion.");
    noTone(buzzerPin);
  }
  
  delay(100); // Small delay for sensor stability
}
