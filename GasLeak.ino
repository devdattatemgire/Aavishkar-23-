#include <SoftwareSerial.h>

SoftwareSerial mySerial(9, 10);
#define sensorDigital A0
#define relay 12
#define buzzer 8
#define sensorAnalog A1
// int signal = 0;
void setup()
{
  pinMode(sensorDigital, INPUT);
  pinMode(relay, OUTPUT);
  pinMode(buzzer, OUTPUT);
  mySerial.begin(9600); 
  Serial.begin(9600);

}

void loop()
{ 
  bool digital = digitalRead(sensorDigital);
  int analog = analogRead(sensorAnalog);
  Serial.print("Analog value : ");
  Serial.print(analog);
  Serial.print("t");
  Serial.print("Digital value :");
  Serial.println(digital);
  if (digital == 0) {
  digitalWrite(relay, LOW);
  digitalWrite(buzzer, HIGH);
  
  // if (signal == 0)
  
mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
delay(1000);  // Delay of 1 second
 mySerial.println("AT+CMGS=\"+918169155357\"\r"); // Replace x with mobile number
delay(1000);
mySerial.println("Gas Leak Detected Run !!!!");// The SMS text you want to send
delay(100);
mySerial.println((char)26);// ASCII code of CTRL+Z for saying the end of sms to  the module 
delay(1000);
      // signal = signal + 1;
  delay(30000); 
 
}
else
{
 digitalWrite(relay, HIGH);
 digitalWrite(buzzer, LOW);
}
}
