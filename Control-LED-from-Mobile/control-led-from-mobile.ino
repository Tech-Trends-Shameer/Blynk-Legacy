#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "ymQpOdhmGpIamQ-mqiFlQrdfOo-2c6ipLhdfjgz";
char ssid[] = "WiFi Username";
char pass[] = "WiFi Password";
 
void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth,ssid,pass);
   
}

void loop()
{
  Blynk.run();
}
