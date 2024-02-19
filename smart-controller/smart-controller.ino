#include <LiquidCrystal.h>

#define SWITCH_PIN        (A1)
#define LED_PIN           (13)
#define TEMP_SENSOR_PIN   (A0)

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

void toggleLed(void)
{
  int led_state = digitalRead(LED_PIN);
  digitalWrite(LED_PIN, led_state ^ (1 << 0));
}

void readSwitchState(void)
{
  int int_switch_state = analogRead(SWITCH_PIN);
  String string_switch_state = (int_switch_state > 1024 / 2) ? "ON" : "OFF";
  Serial.println(string_switch_state);
  lcd.setCursor(0, 1);
  lcd.print("Switch: " + string_switch_state + "     ");
}

void displayTemp(void)
{
  int adc_value = analogRead(TEMP_SENSOR_PIN);
  double voltage = ((double)adc_value / 1024.0) * 5000.0;
  double temperature = voltage / 10;
  lcd.setCursor(0, 0);
  lcd.print("Temp: " + String(temperature) + "^C     ");
}

void setup(void) 
{
  Serial.begin(9600);
  
  lcd.begin(16, 2);

  pinMode(LED_PIN, OUTPUT);
}

void loop(void) 
{
  toggleLed();
  displayTemp();
  readSwitchState();
  delay(3000);
}
