#include<SoftwareSerial.h>
// Configure software serial port
SoftwareSerial SIM900(10,8); 

//Variable to save incoming SMS characters
char incoming_char=0;

#include<LiquidCrystal.h>
LiquidCrystal lcd(14,15,16,17,18,19);
int led=13;
int flag=0;
String str="";
int lowerThreshold = 420;
int upperThreshold = 520;
// Water level Sensor pins
#define sensorPower 7
#define sensorPin A0
//Declare pins to which solenoid valve are connected
#define valve1 D1
#define valve2 D2
#define valve3 D3
// Value for storing water level
//int = 0;
const int CWL = 10; // analog
// Value for storing water flow
const int flow = 14;
//Allarm status
byte allarmSent = LOW;
// Declare pins to which LEDs are connected
int redLED = 2;
int yellowLED = 3;
int greenLED = 4;
int readSensor();
int pump = 2;
const int valve1 = 3; // digital
const int valve2 = 4; // digital
const int valve3 = 6; // digital
//Declare pins to which Moisture Sensor are connected
#define lamp1 11
#define moisturesensor1 A1
#define lamp2 12
#define moisturesensor2 A2
#define lamp3 13
#define moisturesensor3 A3

//Declare pins to which pump are connected
#define Pump  D4
void setup()
{
  lcd.begin(16,4);
  Serial.begin(9600);
  SIM900.begin(9600);
  pinMode(sensorPower, OUTPUT);
  digitalWrite(sensorPower, LOW);
   // Set LED pins as an OUTPUT
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  // Initially turn off all LEDs
  digitalWrite(redLED, LOW);
  digitalWrite(yellowLED, LOW);
  digitalWrite(greenLED, LOW);
   // Set Soil Moisture Sensor and Lamp pins as an OUTPUT
  pinMode(led, OUTPUT);
  pinMode(lamp1, OUTPUT); //sets the digital pin 11 as output
  pinMode(moisturesensor1, INPUT_PULLUP);
  pinMode(lamp2, OUTPUT);
  pinMode(moisturesensor2, INPUT_PULLUP);
  pinMode(lamp3, OUTPUT);
  pinMode(moisturesensor3, INPUT_PULLUP);
  pinMode(valve1, OUTPUT);
  pinMode(valve2, OUTPUT);
  pinMode(valve3, OUTPUT);
  pinMode(pump, OUTPUT);
  pinMode(flow, INPUT_PULLUP);
  pinMode(CWL, INPUT_PULLUP);
  lcd.print("Water Irrigaton");
  lcd.setCursor(4,1);
  delay(2000);
  lcd.clear();
  lcd.print("Circuit Digest");
  lcd.setCursor(0,1);
  lcd.print("Welcomes You");
  delay(2000);
  gsmInit();
  lcd.clear();
  lcd.print("System Ready");
}
void loop()
{
    lcd.setCursor(0,0);
    lcd.print("Automatic Mode    ");
    /* Change these values based on your calibration values */
     //int CWL = readSensor();
     // Water level Sensor 
  if (CWL == 0) 
      {
    Serial.println("Water Level: Empty");
    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(greenLED, LOW);
  }
  else if (CWL > 0 && CWL <= lowerThreshold) 
{
    Serial.println("Water Level: Low");
    digitalWrite(redLED, HIGH);
    digitalWrite(yellowLED, LOW);
    digitalWrite(greenLED, LOW);
  }
  else if (CWL > lowerThreshold && CWL <= upperThreshold)
 {
    Serial.println("Water Level: Medium");
    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, HIGH);
    digitalWrite(greenLED, LOW);
  }
  else if (CWL > upperThreshold) 
{
    Serial.println("Water Level: High");
    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(greenLED, HIGH);
  }
  delay(1000);
  //This is a function used to get the reading Water level

{
  digitalWrite(sensorPower, HIGH);
  delay(10);
 // CWL = analogRead(sensorPin);
  digitalWrite(sensorPower, LOW);
  return CWL;
}
    // Soil Moisture Sensor1
    if(digitalRead(moisturesensor1)==1 && flag==0)
    {
      delay(1000);
      if(digitalRead(moisturesensor1)==1)
      {
        digitalWrite(led, HIGH);
        sendSMS("Low Soil Moisture1 detected. Valve1 turned ON");
        lcd.begin(16,2);
        lcd.setCursor(0,1);
        lcd.print("Valve1 ON    ");
        digitalWrite(valve1, HIGH);
        delay(2000);
        flag=1;
      }
       }

    else if(digitalRead(moisturesensor1)==0 && flag==1)
    {
      delay(1000);
      if(digitalRead(moisturesensor1)==0)
      {
        digitalWrite(led, LOW);
        sendSMS("Soil Moisture1 is Normal. Valve1 turned OFF");
        digitalWrite(valve1, LOW);
        lcd.begin(16,2);
        lcd.print("Valve1 OFF");
        lcd.setCursor(0,1);
        lcd.print("Valve1 OFF");
        delay(2000);
        flag=0;
      }
    }
    //Soil Moisture Sensor2

     if(digitalRead(moisturesensor2)==1 && flag==0)
    {
      delay(1000);
      if(digitalRead(moisturesensor2)==1)
      {
        digitalWrite(led, HIGH);
        sendSMS("Low Soil Moisture2 detected. Vavle2 turned ON");
        lcd.begin(16,2);
        lcd.setCursor(0,1);
        lcd.print("Valve2 ON    ");
        digitalWrite(valve2, HIGH);
        delay(2000);
        flag=1;
      }
       }

    else if(digitalRead(moisturesensor2)==0 && flag==1)
    {
      delay(1000);
      if(digitalRead(moisturesensor2)==0)
      {
        digitalWrite(led, LOW);
        sendSMS("Soil Moisture2 is Normal. Valve2 turned OFF");        
        digitalWrite(valve2, LOW);

        lcd.begin(16,2);
        lcd.print("Valve2 OFF");
        lcd.setCursor(0,1);
        lcd.print("Valve2 OFF");
        delay(2000); 
        flag=0;
      }
    }
    
    //Soil Moisture Sensor3

     if(digitalRead(moisturesensor3)==1 && flag==0)
    {
      delay(1000);
      if(digitalRead(moisturesensor3)==1)
      {
        digitalWrite(led, HIGH);
        sendSMS("Low Soil Moisture3 detected. Valve3 turned ON");
        lcd.begin(16,2);
        lcd.setCursor(0,1);
        digitalWrite(valve3, HIGH);
        lcd.print("Valve3 ON    ");
        delay(2000);
        flag=1;
      }
       }

    else if(digitalRead(moisturesensor3)==0 && flag==1)
    {
      delay(1000);
      if(digitalRead(moisturesensor3)==0)
      {
        digitalWrite(led, LOW);
        sendSMS("Soil Moisture3 is Normal . Valve3 turned OFF");
        digitalWrite(valve3, LOW);
        lcd.begin(16,2);
        lcd.print("Valve3 OFF");
        lcd.setCursor(0,1);
        lcd.print("Valve3 OFF");
        delay(2000); 
        flag=0;
      }
    }
  if(digitalRead(moisturesensor1)==0 && flag==1 && (moisturesensor2)==0 && flag==1 && (moisturesensor3)==0 && flag==1)
     {
      delay(1000);
      if(digitalRead(moisturesensor1)==0 && (moisturesensor2)==0 && (moisturesensor3)==0)
      {
        digitalWrite(led, LOW);
        sendSMS("Water pump stop and Flow meter OFF");
        digitalWrite(flow, LOW);
        lcd.begin(16,2);
        lcd.print("Water pump OFF");
        lcd.setCursor(0,1);
        lcd.print("Water Flow OFF");
        delay(2000); 
        flag=0;
      }
    }
     else if(digitalRead(moisturesensor1)==0 && flag==0 && (moisturesensor2)==0 && flag==0 && (moisturesensor3)==0 && flag==0)
    {
      delay(1000);
      if(digitalRead(moisturesensor3)==1 && (moisturesensor2)==1 && (moisturesensor3)==1)
      {
       digitalWrite(led, HIGH);
        sendSMS("Water pump stop and Flow meter OFF");
        digitalWrite(flow, HIGH);
        lcd.begin(16,2);
        lcd.print("Water pump ON");
        lcd.setCursor(0,1);
        lcd.print("Water Flow ON");
        delay(2000); 
        flag=1;
      }
    }
    
     }

void sendSMS(String msg)
{
  lcd.clear();
  lcd.print("Sending SMS");
  SIM900.println("AT+CMGF=1");
  delay(500);
  SIM900.print("AT+CMGS=");
  SIM900.print("");
  // Set SMS message
  SIM900.println("***Something problem ***");
  SIM900.print("+251911644873");    // counter code with moible number
  SIM900.print("");
  SIM900.println();
  delay(500);
  SIM900.println(msg);
  delay(500);
   SIM900.write(26);
  delay(1000);
  lcd.clear();
  lcd.print("SMS Sent");
  delay(1000);
  lcd.begin(16,2);
}

void gsmInit()
{
  lcd.clear();
  lcd.print("Finding Module..");
  boolean at_flag=1;
  while(at_flag)
  {
    SIM900.println("AT");
    while(SIM900.available()>0)
    {
      if(SIM900.find("OK"))
      at_flag=0;
       }
    delay(1000);
  }
  SIM900.println("AT");
  lcd.clear();
  lcd.print("Finding Network..");
  boolean net_flag=1;
  while(net_flag)
  {
    SIM900.println("AT+CPIN?");
    while(SIM900.available()>0)
    {
      if(SIM900.find("READY"))
      net_flag=0;
      break;
    }
    delay(1000);
  }
  SIM900.println("AT+CNMI=2,2,0,0,0");
   delay(1000);
   SIM900.println("AT+CMGF=1");
   delay(1000);
   SIM900.println("AT+CSMP=17,167,0,0");
   lcd.clear();
   SIM900.flush();
}

