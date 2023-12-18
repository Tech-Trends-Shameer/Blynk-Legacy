#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
BlynkTimer timer;
char auth[] = "1DMx_CxxGV0Wnjsh-Xs8MtKggidfAU7ozgBSwX"; 
 
char ssid[] = "WIFI Username";
char pass[] = "WIFI Password";
int flag=0;
void notifyOnFire()
{
  int isButtonPressed = digitalRead(D1);
  // int r = analogRead(A0);
 //  r = map(r, 0, 1023, 100, 0);
  if (isButtonPressed==0 && flag==0) {
    Serial.println("Its Raining");
     Blynk.email("shameer50@gmail.com", "Alert", "It's Raining");
    Blynk.notify("Alert : Its Raining");
   // Blynk.virtualWrite(V2, r);  //V2 is for Rainfall
 
   //Serial.println(r);
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
