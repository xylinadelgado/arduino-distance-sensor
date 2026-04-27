#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int trigPin = 9;;
const int echoPin = 10;
const int redPin = 6;
const int greenPin = 7;
const int bluePin = 8;
const int buzzerPin = 13;

void setColor(int red, int green , int blue){
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}

void beep (int duration){
  tone (buzzerPin, 1000);
  delay (duration);
  noTone(buzzerPin);
  delay (duration);
}

void setup() {
  lcd.begin(16, 2);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  lcd.print("Distance Meter");
  delay(2000);
  lcd.clear();

}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;

  lcd.setCursor(0, 0);
  if (distance > 2 && distance < 400) {
  lcd.print("Dist: ");
  lcd.print(distance);
  lcd.print(" CM  ");

  if (distance < 10){
    setColor(255, 0 , 0);
    beep(100);
  }
  else if(distance < 25){
    setColor(255, 165, 0);
    beep(300);
  }else {
    setColor(0, 255, 0);
    noTone(buzzerPin);
  }
  } else {
    lcd.print ("Out of range !   ");
    setColor (0, 0, 255);
    noTone(buzzerPin);
  }
  delay(500);
}