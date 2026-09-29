/*
  Project Name: Arduino Based LPG Gas Detector
  Author: Aman Shukla (Government Polytechnic Saharanpur)
  Description: Monitors LPG/combustible gas levels using an MQ-2/MQ-6 sensor.
               Triggers a buzzer and red LED when the concentration exceeds
               the predefined threshold; lights a green LED during safe levels.
*/

// Pin Configurations
const int gasSensorPin = A0;  // MQ sensor analog output connected to A0
const int buzzerPin    = 8;   // Piezo Buzzer connected to digital pin 8
const int greenLEDPin  = 9;   // Green LED (Safe Status) connected to digital pin 9
const int redLEDPin    = 10;  // Red LED (Alert Status) connected to digital pin 10

// Calibration Threshold
// Adjust this threshold value based on ambient sensor readings during testing
const int threshold = 300;

void setup() {
  // Configure digital output pins
  pinMode(buzzerPin, OUTPUT);
  pinMode(greenLEDPin, OUTPUT);
  pinMode(redLEDPin, OUTPUT);

  // Initialize serial communication for real-time monitoring and debugging
  Serial.begin(9600);
  Serial.println("System Initializing...");
  Serial.println("LPG Gas Detector System Started.");
}

void loop() {
  // Read analog voltage level from gas sensor
  int sensorValue = analogRead(gasSensorPin);

  // Output real-time value to Serial Monitor
  Serial.print("Current Gas Level: ");
  Serial.println(sensorValue);

  // Evaluate sensor reading against safety threshold
  if (sensorValue > threshold) {
    // Gas leak detected: Activate alert system
    digitalWrite(buzzerPin, HIGH);   // Sound alarm
    digitalWrite(redLEDPin, HIGH);   // Turn on Red alert LED
    digitalWrite(greenLEDPin, LOW);  // Turn off Green safe LED
  } else {
    // Normal level: Deactivate alert system
    digitalWrite(buzzerPin, LOW);    // Silence alarm
    digitalWrite(redLEDPin, LOW);    // Turn off Red alert LED
    digitalWrite(greenLEDPin, HIGH); // Turn on Green safe LED
  }

  // Delay before reading next value
  delay(1000);
}
