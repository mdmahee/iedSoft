void defualtt()
{
  lcd.setCursor(0,1);
  lcd.print(HOUR);
  Serial.print(HOUR);
  lcd.print(":");
  Serial.print(":");
  lcd.print(MINUT);
  Serial.print(MINUT);
  lcd.print(":");
  Serial.print(":");
  lcd.print(SECOND);
  Serial.print(SECOND);
  Serial.println();
}
