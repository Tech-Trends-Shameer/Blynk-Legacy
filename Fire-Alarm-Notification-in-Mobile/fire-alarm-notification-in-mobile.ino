#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
BlynkTimer timer;
char auth[] = "Q2jEWbbXh2vf7rfOafW3LoATOPAsNImQ"; //Enter the Auth Code sent to the registered email address from the Blynk App
 
char ssid[] = "wifi-username"; //Enter the Wifi Username
char pass[] = "password";	   //Enter the Wifi Password
int flag=0;
void notifyOnFire()
{
  int isButtonPressed = digitalRead(D1);
  if (isButtonPressed==0 && flag==0) {
    Serial.println("Fire in the House");
    Blynk.notify("Alert : Fire in the House");
    flag=1;
  }
  else if (isButtonPressed==1)
  {
    flag=0;
  }
}
void setup()
{
Serial.begin(9600);
Blynk.begin(auth, ssid, pass);
pinMode(D1,INPUT);
timer.setInterval(1000L,notifyOnFire); 
}
void loop()
{
  Blynk.run();
  timer.run();
}
