#include <SoftwareSerial.h>

SoftwareSerial SIM900(11, 10); // configure software serial port 11,10
 String content = "";
 String newcontent = "";

unsigned int lastStringLength = 63;     // api length

#include <Wire.h>
#include<EEPROM.h>
#include <RTClib.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(13, 12, 8, 7, 6, 5); 
RTC_DS1307 RTC;
int temp,inc,hours1,minut,day1,month1,yr1,add=11,ttime,htcall,dstatus,dn,iwminute,iwhour,iwday,iwmonth,iwyr,iwttime,iwdn,iwds;
String wminute,whour,wday,wmonth,wyr,wttime,wdn,wds ;

int next=2;    
int INC=3;
int set_mad=4;

#define buzzer A2
#define relay A3

int HOUR,MINUT,SECOND,DAY,MONTH,YR,TTIME,DSTATUS;

int DN=11;



  int tem[19];

float vOUT = 0.0;
float vIN = 0.0;
float R1 = 20000.0;       //Resistor 1 value in ohms (10000 ohms = 10Kohms) 
float R2 = 10000.0;        //Resistor 2 value in ohms (1000 ohms  =  1Kohms)
int value = 0;


 
void setup()
{
EEPROM.write(18, DN);

  
 Wire.begin();
 RTC.begin();
 lcd.begin(16,2);
 pinMode(INC, INPUT);
 pinMode(next, INPUT);
 pinMode(set_mad, INPUT);
 pinMode(buzzer, OUTPUT);
 pinMode(relay, OUTPUT);
  digitalWrite(relay, HIGH);
 digitalWrite(buzzer, LOW);

 digitalWrite(next, HIGH);
 digitalWrite(set_mad, HIGH);
 digitalWrite(INC, HIGH);

 Serial.begin(19200);
 SIM900.begin(19200);

   lcd.setCursor(0,0);
   lcd.print("Auto IED Mng:Sys");
   lcd.setCursor(0,1);
   lcd.print("   Sappers 43   ");
    delay(3000);

   digitalWrite(relay,HIGH);
   delay(500);
   
   digitalWrite(buzzer,HIGH);
   delay(100);
   digitalWrite(buzzer,LOW);
   delay(500);
   digitalWrite(buzzer,HIGH);
   delay(500); 
   digitalWrite(buzzer,LOW);

  SIM900.begin(19200);
  Serial.print("power up" );
  delay(2000); 
    
 if(!RTC.isrunning())
 {
 RTC.adjust(DateTime(__DATE__,__TIME__));
 }
}
 
void loop()
{

     digitalWrite(buzzer,LOW);digitalWrite(relay,HIGH);

   int temp=0,val=1,temp4;
   
   DateTime now = RTC.now();


   
   if(digitalRead(set_mad) == 0)      //set Alarm time  BT pressed
   { 
     lcd.setCursor(0,0);
     lcd.print("Set Event Time");   
     //Serial.print("  Set Event Time");
    delay(200);
    defualtt();
    time();
    delay(100);


    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("    Event"); 
    //Serial.print("  Event time ");
    lcd.setCursor(0,1);
    lcd.print(" has been set"); 
    //Serial.print(" has been set  ");
    delay(2000);
  }


  
 lcd.clear();
 lcd.setCursor(0,0);
lcd.print("T:"); 
Serial.print("   T:");
// lcd.setCursor(2,0);
 lcd.print(HOUR=now.hour(),DEC);  Serial.print(HOUR=now.hour(),DEC); 
 lcd.print(":"); Serial.print(":");
 lcd.print(MINUT=now.minute(),DEC); Serial.print(MINUT=now.minute(),DEC);
 lcd.print(":"); Serial.print(":");
 lcd.print(SECOND=now.second(),DEC); Serial.print(SECOND=now.second(),DEC);

 lcd.setCursor(0,1);
lcd.print("D:");
 Serial.print("  D ");
 lcd.print(DAY=now.day(),DEC);    Serial.print(now.day(),DEC);
 lcd.print(".");    Serial.print(".");
 lcd.print(MONTH=now.month(),DEC);    Serial.print(now.month(),DEC);
 lcd.print(".");   Serial.print(".");
 lcd.print(YR=(now.year()-2000),DEC); Serial.print((now.year()-2000),DEC); 
 Serial.print("      ");
/*

  value = analogRead(A1);
  vOUT = (value * 3.3) / 1024.0;
  vIN = vOUT / ( R2 / (R1 + R2) );
 lcd.setCursor(12,0);
  lcd.print(vIN); Serial.print(vIN);
 lcd.setCursor(15,0);
 lcd.print("V"); Serial.print("   V=");
*/
 lcd.setCursor(11,0);
 lcd.print("Dn"); Serial.print("   Dn=");
 lcd.print(DN); Serial.print(DN);
 
 lcd.setCursor(10,1);
 lcd.print("Ds"); Serial.print("   Ds=");
 lcd.print(DSTATUS); Serial.print(DSTATUS);

 lcd.setCursor(13,1);
 lcd.print("t"); Serial.print("   Tt=");
 lcd.print(TTIME); Serial.print(TTIME);
Serial.print("  htcall=");Serial.print(htcall);




TTIME=EEPROM.read(16);TTIME=TTIME;TTIME==TTIME;
DSTATUS=EEPROM.read(17);DSTATUS=DSTATUS;DSTATUS==DSTATUS;
DN=EEPROM.read(18);DN=DN;DN==DN;
htcall=EEPROM.read(12);htcall=htcall;htcall==htcall;

Serial.print("   ");
Serial.print("   whour=");Serial.print(iwhour);
Serial.print("   wminute=");Serial.print(iwminute);
Serial.print("   iwday=");Serial.print(iwday);
Serial.print("   wmonth=");Serial.print(iwmonth);
Serial.print("   wyr=");Serial.print(iwyr);
Serial.print("   wds=");Serial.print(iwds);
Serial.print("   wttime=");Serial.print(iwttime);

Serial.print("  ");



  Serial.println();
 
 match();

 
 delay(200);
}
