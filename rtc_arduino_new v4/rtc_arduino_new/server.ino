
void htlp()
{
lcd.clear();

  Serial.println("SubmitHttpRequest - started" );
  SubmitHttpRequest();

  
  delay(500);
  Serial.println("SubmitHttpRequest - finished" );
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
  //SIM900.println("AT+SAPBR=3,1,\"APN\",\"gpinternet\"");//setting the APN, Access point name string
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

String addr =  "AT+HTTPPARA=\"URL\",\"ems.mdmahee.com/api/event/";
addr+=DN;
addr+= "\"";
delay(100);
SIM900.println(addr);
 delay(1000);


  ShowSerialData();
 
  SIM900.println("AT+HTTPACTION=0");//submit the request 
  delay(15000);//the delay is very important, the delay time is base on the return from the website, if the return datas are very large, the time required longer.
 
  ShowSerialData();
 
  SIM900.println("AT+HTTPREAD");// read the data from the website you access
  delay(300);
  contentt();
  changeLed();
  delay(1000);
}


 
void contentt()
{
 while(SIM900.available()!=0)
 {  
char inchar = (char)  SIM900.read();  
if (inchar != '\n')    
{
  content += inchar; 
}
      Serial.print(content); 
 }
}


void changeLed()
{
      Serial.print("  content="); 
      Serial.print(content); 
      Serial.print("  CL="); 
      Serial.print(content.length());

//ID011DS1TT55T195800D20220419

newcontent=content.substring(28,54); newcontent=newcontent;newcontent==newcontent;
      Serial.print("  content1="); 
      Serial.print(newcontent); 
      Serial.print("  CL="); 
      Serial.print(newcontent.length()); 

concon();
}

void ShowSerialData()
{
  while(SIM900.available()!=0)
    Serial.write(char (SIM900.read()));
}
