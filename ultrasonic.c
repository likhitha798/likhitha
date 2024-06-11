#include <Arduino.h>

// Define pins for the HC-SR04 sensor and LED
const int triggerPin = 23; // GPIO 23 for trigger
const int echoPin = 22;    // GPIO 22 for echo
const int ledPin = 2;      // GPIO 2 for LED

// Define the detection range in cm (e.g., detect objects closer than 10 cm)
const int detectionRange = 10;

// Function to measure distance in centimeters
long measureDistance() {
  // Send a 10 microsecond pulse to trigger the ultrasonic sensor
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  // Measure the echo pulse duration
  long duration = pulseIn(echoPin, HIGH);

  // Calculate the distance in centimeters
  long distance = duration * 0.034 / 2;

  return distance;
}

void setup() {
  // Initialize serial communication for printing the distance
  Serial.begin(115200);

  // Set the trigger pin as output and echo pin as input
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Set the LED pin as output
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Measure the distance
  long distance = measureDistance();

  // Print the distance for debugging
  Serial.print("Distance: ");
  Serial.println(distance);

  // Turn on the LED if an object is within the detection range
  if (distance < detectionRange) {
    digitalWrite(ledPin, HIGH); // Turn on the LED
  } else {
    digitalWrite(ledPin, LOW); // Turn off the LED
  }

  // Delay between measurements (optional, adjust as needed)
  delay(100);
}