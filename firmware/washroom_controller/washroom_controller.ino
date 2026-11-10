#include <LiquidCrystal.h>

// Pin Definitions based on System Architecture
const int pirPin = 2;          // PIR Motion Sensor pin
const int gasPin = A0;         // MQ-135 Gas Sensor analog pin
const int relayPin = 7;        // Relay control for Water/Disinfectant Pump
const int buzzerPin = 8;       // Alert Buzzer pin
const int proxPin = 4;         // Proximity sensor for handwash

// LCD Initialization (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(12, 11, 5, 4, 3, 9);

void setup() {
  // Initialize Serial Communication at 9600 baud[cite: 48, 49]
  Serial.begin(9600);
  
  // Configure I/O pins
  pinMode(pirPin, INPUT);
  pinMode(gasPin, INPUT);
  pinMode(relayPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(proxPin, INPUT);
  
  // Set initial states
  digitalWrite(relayPin, LOW);
  digitalWrite(buzzerPin, LOW);
  
  // Initialize LCD
  lcd.begin(16, 2);
  lcd.print("Washroom System");
  delay(2000);
  lcd.clear();
}

void loop() {
  // 1. Read PIR Motion Sensor State
  int motionState = digitalRead(pirPin);
  if (motionState == HIGH) {
    Serial.println("Motion detected!");[cite: 48]
    lcd.setCursor(0, 0);
    lcd.print("Status: Occupied ");
  } else {
    Serial.println("Motion ended!");[cite: 48]
    lcd.setCursor(0, 0);
    lcd.print("Status: Vacant   ");
  }

  // 2. Read Gas/Air Quality Sensor (MQ-135)
  int gasValue = analogRead(gasPin);
  Serial.print("Smoke Level: ");[cite: 45]
  Serial.println(gasValue);
  
  lcd.setCursor(0, 1);
  lcd.print("Air PPM: ");
  lcd.print(gasValue);
  
  // Threshold check for air quality and sanitation triggering
  if (gasValue > 300) {[cite: 45]
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(relayPin, HIGH); // Trigger water/disinfectant pump spray
    Serial.println("Alert.... High Gas Level! Sanitizing...");[cite: 45]
  } else {
    digitalWrite(buzzerPin, LOW);
    digitalWrite(relayPin, LOW);
  }

  // 3. Proximity Handwash Automation Check
  int proxState = digitalRead(proxPin);
  if (proxState == HIGH) {
    // Handwash pump activation logic handled via transistor/relay
    delay(500);
  }

  delay(1000); // Sampling delay
}
