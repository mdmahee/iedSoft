/* function to buzzer indication */

void beep()
{
   digitalWrite(buzzer,HIGH);
   digitalWrite(relay,LOW);
   delay(2000);
//   digitalWrite(buzzer,LOW);digitalWrite(relay,HIGH);
   delay(50);
}
