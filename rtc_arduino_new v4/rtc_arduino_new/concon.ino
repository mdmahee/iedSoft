void concon() 
{

   if (newcontent.length() != 26) 
   {
    lcd.setCursor(3,1);
    lcd.print("failed");
    Serial.print("content not complete");
    delay(100);
  TTIME=TTIME+2;
  if(TTIME>=60)
      {TTIME=0;}
      TTIME=TTIME;TTIME==TTIME;EEPROM.write(16, TTIME);
   }
     
   else if (newcontent.length() == 26) 
{
  
   // ID011DS1TT55T1958D20220419
    
wds=newcontent.substring(7,8); iwds=wds.toInt();iwds=iwds;iwds==iwds; EEPROM.write(17, iwds); 
 wttime=newcontent.substring(10,12); iwttime=wttime.toInt();iwttime=iwttime;iwttime==iwttime; EEPROM.write(16, iwttime);
whour=newcontent.substring(13,15); iwhour=whour.toInt();iwhour=iwhour;iwhour==iwhour; EEPROM.write(11, iwhour);
wminute=newcontent.substring(15,17); iwminute=wminute.toInt();iwminute=iwminute;iwminute==iwminute; EEPROM.write(12, iwminute);
wday=newcontent.substring(24,26); iwday=wday.toInt();  iwday=iwday;iwday==iwday; EEPROM.write(13, iwday);
wmonth=newcontent.substring(22,24);iwmonth=wmonth.toInt(); iwmonth=iwmonth;iwmonth==iwmonth; EEPROM.write(14, iwmonth);
wyr=newcontent.substring(18,22); iwyr=wyr.toInt();iwyr=iwyr-2000;iwyr=iwyr;iwyr==iwyr; EEPROM.write(15, iwyr);
    lcd.setCursor(3,1);
    lcd.print("Success");
      delay(40000);

/* 
 Serial.print("   ");
 Serial.print("  9,10=");Serial.print(newcontent.substring(9,10));
 Serial.print("  12,14=");Serial.print(newcontent.substring(12,14));
 Serial.print("  15,17=");Serial.print(newcontent.substring(15,17));
 Serial.print("  17,19=");Serial.print(newcontent.substring(17,19));
 Serial.print("  20,24=");Serial.print(newcontent.substring(20,24));
 Serial.print("  24,26=");Serial.print(newcontent.substring(24,26));
 Serial.print("  26,28=");Serial.print(newcontent.substring(26,28));
*/
 
Serial.print("   whour=");Serial.print(iwhour);
Serial.print("   wminute=");Serial.print(iwminute);
Serial.print("   iwday=");Serial.print(iwday);
Serial.print("   wmonth=");Serial.print(iwmonth);
Serial.print("   wyr=");Serial.print(iwyr);
Serial.print("   wds=");Serial.print(iwds);
Serial.print("   wttime=");Serial.print(iwttime);


} 

//Serial.println();content = "";
}
