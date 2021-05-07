#include <SoftwareSerial.h>
#include <DHT.h>
SoftwareSerial Blue(3,4);
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN,DHTTYPE);
char val;
char red = 9;
char green = 10;
char blue = 11;
String h = String(dht.readHumidity());


char data ;
void setup() 
{
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(blue,OUTPUT);
  Serial.begin(9600);
  Blue.begin(9600);
  dht.begin();
}

void loop() 
{
  //*****transmitter*****
  if (Blue.available())
    {
      val = Blue.read();
      if (val=='r') 
        {
        digitalWrite(9,0);
        digitalWrite(10,255);
        digitalWrite(11,255);
        }
      else if (val=='g')
        {
        digitalWrite(9,255);
        digitalWrite(10,0);
        digitalWrite(11,255);
        }
      else if (val=='b')
        {
          digitalWrite(9,255);
          digitalWrite(10,255);
          digitalWrite(11,0);
        }
      else if (val=='o')
        {
          digitalWrite(9,0);
          digitalWrite(10,0);
          digitalWrite(11,0);
        }   
      else if (val=='y')
        {
          digitalWrite(9,0);
          digitalWrite(10,0);
          digitalWrite(11,255);
        }
      else if (val=='f')
        {
        digitalWrite(9,255);
        digitalWrite(10,255);
        digitalWrite(11,255);
        }
      else if (val=='e')
        {
        digitalWrite(9,0);
        digitalWrite(9,105);
        digitalWrite(9,255);
        }
      else if (val == 's')
        {
          //=========a==========
          analogWrite(blue,255);
          for (int i = 0;i<=255;i++)
          {
            analogWrite(red,i);
            analogWrite(green,255-i);
          }
          
          //=========b==========
          analogWrite(green , 0);
          analogWrite(red , 255);
          for (int i =255;i>=0;i--)
          {
            analogWrite(blue , i);
          }
                  
          //=========c==========
          analogWrite(blue , 0);
          analogWrite(red , 255);
          for (int i =0;i<=255;i++)
          {
            analogWrite(green , i);
          }
                  
          //=========d==========
          analogWrite(green , 255);
          analogWrite(blue , 0);
          for (int i =255;i>=0;i--)
          {
            analogWrite(red , i);
          }
                  
          //=========e==========
          analogWrite(green , 255);
          analogWrite(red , 0);
          for (int i =0;i<=255;i++)
          {
            analogWrite(blue , i);
          }
        }
    }

    
    //*****receiver*****
    if (Blue.available())
      {
        val = Blue.read();
        if (val == 't')
          {
            Blue.print('t');
            float h,t;
            t = dht.readTemperature();
            //h = dht.readHumidity();
            
            Blue.print(t);
            Serial.print(t);
          }
          if (val == 'h')
          {
            Blue.print(h);
            Serial.print(h); 
          }
                
      }
}
