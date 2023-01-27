#include <LiquidCrystal.h>
const int rs = 13 , en = 12 , d4 = 11 , d5 = 10 , d6 = 9 , d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int tempPin = 0;
int val;

short celcius;
char temp[16];


void setup() {
  pinMode (7, OUTPUT);
  pinMode (6, OUTPUT);
  pinMode (5, OUTPUT);
  pinMode (4, OUTPUT);
  pinMode (3, OUTPUT);
  pinMode (2, OUTPUT);
  pinMode (1, OUTPUT);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Temp.Monitoring"); 
  lcd.setCursor(1, 1);
  lcd.print("Temp.Read:");
}

void loop() {
  Readtemp();
  //NORMAL TEMP
  if (celcius <= 35 && celcius >= 20) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(1, LOW);
    digitalWrite(7, LOW);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);    
  }
  //HIGH TEMP
  else if (celcius > 35) {
    FanON();
    digitalWrite(1, HIGH);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
    delay(800);
    lcd.setCursor(0, 1);
    lcd.print("                 ");
    lcd.setCursor(1, 1);
    lcd.print("The Fan is ON");
    
  }
  //LOW TEMP
  else if (celcius < 20) {
    HeaterON();
    digitalWrite(3, HIGH);
    digitalWrite(2, LOW);
    digitalWrite(1, LOW);
    digitalWrite(7, LOW);
    digitalWrite(6, LOW); 
    delay(800); 
    lcd.setCursor(0, 1);
    lcd.print("                 ");
    lcd.setCursor(0, 1);
    lcd.print("The Heater is ON");
     
  }

}

void Readtemp() {
  delay(500);
  lcd.setCursor(0, 1);
  lcd.print("                 ");
  val = analogRead(tempPin);
  celcius = val*4.88/10;
  sprintf(temp, "%0.2d", celcius);
    lcd.setCursor(1, 1);
    lcd.print("Temp.Read:");
    lcd.print(temp);
    lcd.write(B11011111);
    lcd.print("C");    
}

void FanON() {
  digitalWrite(7, HIGH);
  digitalWrite(6, LOW);  
  delay(100);
}

void HeaterON() {
  digitalWrite(5, HIGH);
  digitalWrite(4, LOW);
  delay(100);  
}
