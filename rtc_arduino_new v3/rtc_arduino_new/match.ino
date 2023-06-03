/* Function to chack medication time */

void match()
{
  int tem[19];
  for(int i=11;i<19;i++)
  {
    tem[i]=EEPROM.read(i);
  //  Serial.print("  ");
  //  Serial.print(tem[i]);
  }


 
 if(DSTATUS==1)
 {  
  if(HOUR == tem[11] && MINUT == tem[12] && DAY == tem[13] && MONTH == tem[14] && YR == tem[15]&& TTIME == tem[16] && DSTATUS == tem[17]  ) 
  {
   beep();beep();beep();beep();
   lcd.clear();
   lcd.print("Event Happening");   Serial.print("Event Happening");
   lcd.setCursor(0,1);
   lcd.print("Event Happening");
   beep();beep();beep();beep();
  }
 }

else
 {  
  if(HOUR == tem[11] && MINUT == tem[12] && DAY == tem[13] && MONTH == tem[14] && YR == tem[15]&& TTIME == tem[16] && DSTATUS == tem[17]  ) 
  {
   
   lcd.clear();
   lcd.print("Event Happening"); Serial.print("Event Happening");
   lcd.setCursor(0,1);
   lcd.print("Device Nt Active");   Serial.print("Device Nt Active");
   digitalWrite(buzzer,LOW);digitalWrite(relay,HIGH);

  
  }
 }



  if(TTIME==htcall)
    {
lcd.clear();
Serial.print("event minute & Tt can't be same");
lcd.print("event minute &");
lcd.setCursor(0,1);
lcd.print("Tt can't be same");
    }



      
if(TTIME== MINUT)
{

  htlp();

  
        //content=content.substring(39,58);Serial.print("  newcontent= ");Serial.print(content);
}

}
