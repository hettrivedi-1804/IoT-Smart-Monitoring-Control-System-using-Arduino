#include <LiquidCrystal_I2C.h>
#include <Servo.h>

// Pins
const int trigPin = 2;
const int echoPin = 4;
const int moisturePin = A1;

Servo pumpServo;   // Servo for soil moisture
Servo sprinklerServo; // Servo for crop height (sprinkler)

LiquidCrystal_I2C lcd(0x20, 16, 2);

// Variables for ultrasonic
long duration;
int distance;
int lastDistance = 0;
int stableCounter = 0;
bool sprinklerActive = false;

// Tuning parameters
const int STABLE_TOLERANCE = 40;   // cm difference allowed to consider stable
const int STABLE_TIME = 30;       // 3 seconds (30 × 100ms loop delay)

void setup() {
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pumpServo.attach(12);
  sprinklerServo.attach(9);

  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Crop Monitor");
  delay(1500);
  lcd.clear();

  sprinklerServo.write(0); // Start position
}

void loop() {
  // ========== Soil Moisture ==========
  int moistureValue = analogRead(moisturePin);
  int moisturePercent = map(moistureValue, 800, 300, 100, 0);
  moisturePercent = constrain(moisturePercent, 0, 100);

  lcd.setCursor(0, 0);
  lcd.print("Moist: ");
  lcd.print(moisturePercent);
  lcd.print("%   ");

  if (moisturePercent < 30) {
    pumpServo.write(90);
  } else {
    pumpServo.write(0);
  }

  // ========== Ultrasonic Sensor ==========
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH, 20000);
  distance = duration * 0.034 / 2;

  lcd.setCursor(0, 1);
  lcd.print("Dist: ");
  lcd.print(distance);
  lcd.print("cm ");

  // ========== Crop Height Stability Logic ==========
  if (abs(distance - lastDistance) <= STABLE_TOLERANCE && distance > 0 && distance < 100) {
    stableCounter++;
    Serial.print("Stable for: ");
    Serial.println(stableCounter * 100);
    
    if (!sprinklerActive && stableCounter >= STABLE_TIME) {
      sprinklerServo.write(90);  // Activate sprinkler
      sprinklerActive = true;
      Serial.println("🌿 Crop stable → Sprinkler ON");
      lcd.setCursor(0, 1);
      lcd.print("Sprinkler: ON  ");
    }
  } else {
    stableCounter = 0;
    sprinklerActive = false;
    sprinklerServo.write(0);  // Reset sprinkler
    Serial.println("📉 Crop height changed → Sprinkler OFF");
    lcd.setCursor(0, 1);
    lcd.print("Sprinkler: OFF ");
  }

  lastDistance = distance;
  delay(100); // 100ms per loop
}
