
void htlp()
{
lcd.clear();

  Serial.println("SubmitHttpRequest - started" );
  SubmitHttpRequest();

  
  delay(500);
  Serial.println("SubmitHttpRequest - finished" );
  //delay(1000);
  // concon();
}

void SubmitHttpRequest()
{

lcd.clear();
lcd.print("Web Connecting");
  Serial.println();content = "";

 
  SIM900.println("AT+CSQ"); // Signal quality check

  delay(100);
 
  ShowSerialData();// this code is to show the data from gprs shield, in order to easily see the process of how the gprs shield submit a http request, and the following is for this purpose too.
  
  SIM900.println("AT+CGATT?"); //Attach or Detach from GPRS Support
  delay(100);
 
  ShowSerialData();
  SIM900.println("AT+SAPBR=3,1,\"CONTYPE\",\"GPRS\"");//setting the SAPBR, the connection type is using gprs
  delay(1000);
 
  ShowSerialData();


  SIM900.println("AT+SAPBR=3,1,\"APN\",\"airtelgprs.com\"");//setting the APN, Access point name string
  delay(4000);
 
  ShowSerialData();
 
  SIM900.println("AT+SAPBR=1,1");//setting the SAPBR
  delay(2000);
 
  ShowSerialData();
 
  SIM900.println("AT+HTTPINIT"); //init the HTTP request
 
  delay(2000); 
  ShowSerialData();



DN=EEPROM.read(18); DN=DN;DN==DN;

// SIM900.println("AT+HTTPPARA=\"URL\",\"ems.mdmahee.com/api/event/11\"");
//String addr =  "AT+HTTPPARA=\"URL\",\"https://robi.eduine.com/api/bin/";

String addr =  "AT+HTTPPARA=\"URL\",\"ems.mdmahee.com/api/event/";
addr+=DN;
addr+= "\"";
delay(100);
SIM900.println(addr);
//Serial.println(addr);
 delay(1000);




// https://thectbl.com/gsm/getstate.php?color=All
 // SIM900.println("AT+HTTPPARA=\"URL\",\"sim900test.net46.net/getstate.php?color=All\"");// setting the httppara, the second parameter is the website you want to access
  //SIM900.println("AT+HTTPPARA=\"URL\",\"thectbl.com/gsm/getstate.php?color=All\"");// setting the httppara, the second parameter is the website you want to access

 //SIM900.println("AT+HTTPPARA=\"URL\",\"ems.mdmahee.com/api/event/11\"");// setting the httppara, the second parameter is the website you want to access
 
 // delay(1000);
 
  ShowSerialData();
 
  SIM900.println("AT+HTTPACTION=0");//submit the request 
  delay(15000);//the delay is very important, the delay time is base on the return from the website, if the return datas are very large, the time required longer.
  //while(!SIM900.available());
 
  ShowSerialData();
 
  SIM900.println("AT+HTTPREAD");// read the data from the website you access
  delay(300);
  contentt();
 // ShowSerialData();
   changeLed();


 // SIM900.println("");  Serial.println("");
  delay(1000);
 // SIM900.println("AT+HTTPTERM");  Serial.println("AT+HTTPTERM");

}


 
void contentt()
{
// String content = "";
// String RedState = content.substring();


 while(SIM900.available()!=0)
 {  
char inchar = (char)  SIM900.read();  if (inchar != '\n')      content += inchar; 
   
   // content = content + String(char (SIM900.read()));
  
  //  newcontent+=content;

   //Serial.print(" content="); Serial.print(char(SIM900.read()));
    //delay(100);
 }

/*    
 delay(5000);

newcontent=content.substring(39,58);
newcontent=newcontent;newcontent==newcontent;
      Serial.print("  newcontent= "); 
      Serial.print(newcontent); 
      Serial.print("  nCL="); 
      Serial.print(newcontent.length());
 */  
}


void changeLed()
{

//delay(500);

//content=content;
//content==content;
      Serial.print("  content="); 
      Serial.print(content); 
      Serial.print("  CL="); 
      Serial.print(content.length());

     //  Serial.print("  content2= ");       Serial.print(content.substring(39,63)); 


//String newc;
//newcontent+=content;

newcontent=content.substring(28,56); newcontent=newcontent;newcontent==newcontent;
      Serial.print("  content1="); 
      Serial.print(newcontent); 
      Serial.print("  CL="); 
      Serial.print(newcontent.length()); 

concon();

 
//ID8DN1DS1TT30T1556D20220415
  /*    
   if (content.length() != lastStringLength) 
   {
    Serial.print("content not complete");
    delay(100);
  TTIME=TTIME+2;TTIME=TTIME;TTIME==TTIME;EEPROM.write(16, TTIME);
   }
     
   else if (content.length() == lastStringLength) 
{
wds=content.substring(39,40); iwds=wds.toInt();iwds=iwds;iwds==iwds; EEPROM.write(17, iwds); 
 wttime=content.substring(42,44); iwttime=wttime.toInt();iwttime=iwttime;iwttime==iwttime; EEPROM.write(16, iwttime);
whour=content.substring(45,47); iwhour=whour.toInt();iwhour=iwhour;iwhour==iwhour; EEPROM.write(11, iwhour);
wminute=content.substring(47,49); iwminute=wminute.toInt();iwminute=iwminute;iwminute==iwminute; EEPROM.write(12, iwminute);
wyr=content.substring(50,54); iwyr=wyr.toInt();iwyr=iwyr-2000;iwyr=iwyr;iwyr==iwyr; EEPROM.write(15, iwyr);
wmonth=content.substring(54,56);iwmonth=wmonth.toInt(); iwmonth=iwmonth;iwmonth==iwmonth; EEPROM.write(14, iwmonth);
 wday=content.substring(56,58); iwday=wday.toInt();  iwday=iwday;iwday==iwday; EEPROM.write(13, iwday);
} 

Serial.println();
content = "";
*/
}
  /*   
     if (stringOne.toInt() == numberOne) {

     Serial.print(" 35, 36 DN=");  Serial.print(content.substring(35,36)); Serial.println();
     Serial.print(" 38, 39 Ds=");  Serial.print(content.substring(38,39)); Serial.println();
     Serial.print(" 41, 43 TT=");  Serial.print(content.substring(41,43)); Serial.println();
     Serial.print(" 44, 48 T=");  Serial.print(content.substring(44,48)); Serial.println();
     Serial.print(" 49, 57 D=");  Serial.print(content.substring(49,57)); Serial.println();
  
     Serial.println("  30 ");  Serial.print(content.substring(30));
    Serial.println("31 ");  Serial.print(content.substring(31));
    Serial.println("32 ");  Serial.print(content.substring(32));
    Serial.println("33 ");  Serial.print(content.substring(33)) ;
    Serial.println("34 ");  Serial.print(content.substring(34)) ;  
    Serial.println("35 ");  Serial.print(content.substring(35));
   */ 

 
 
/*  
  if(content.substring(38,39)== "1")    // device status
 {
       EEPROM.write(17, 1);
 }
 
else if (content.substring(38,39)== "0")
 {
       EEPROM.write(17, 0);
 }
 
 

 *   
 *   
 *   
 *   if(content.substring(31,32)== "1")
 {
   digitalWrite(GREENLed, HIGH);
 }
 else if (content.substring(31,32)== "0")
 {
   digitalWrite(GREENLed, LOW);
 }
 
 if(content.substring(32,33)== "1")
 {
   digitalWrite(BLUELed, HIGH);
 }
 else if (content.substring(32,33)== "0")
 {
   digitalWrite(BLUELed, LOW);
 }
 */

void ShowSerialData()
{
  while(SIM900.available()!=0)
    Serial.write(char (SIM900.read()));
}
 
