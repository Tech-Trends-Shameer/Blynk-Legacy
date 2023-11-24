//Tech Trends Shameer
//Temperature Alert in Email and Mobile

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>

// You should get Auth Token in the Blynk App.

char auth[] = "Auth Code";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Wifi Username";
char pass[] = "WifiPasswor";

#define DHTPIN 2          // Mention the digital pin where you connected

// Uncomment whatever type you're using!
#define DHTTYPE DHT11     // DHT 11
//#define DHTTYPE DHT22   // DHT 22, AM2302, AM2321
//#define DHTTYPE DHT21   // DHT 21, AM2301
int alarmPin = 4;
int led1 = 16;
int led2 = 14;
DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;

void sendSensor(){
  float h = dht.readHumidity();
  float t = dht.readTemperature(); // or dht.readTemperature(true) for Fahrenheit

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.println(t);
  Blynk.virtualWrite(V5, h);
  Blynk.virtualWrite(V6, t);

  // SETUP the ALARM Trigger and Send EMAIL 
  // and PUSH Notification

  if(t > 28){
    Blynk.email("techtrendsshameer@gmail.com", "Alert", "Temperature over 28C!");
    Blynk.notify("Alert - Temperature over 28C!");
  }
}

void setup(){
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  dht.begin();
  timer.setInterval(2500L, sendSensor);
}

void loop(){
  Blynk.run();
  timer.run();
}


/* Blynk EMAIL and NOTIFICATION
 * ESP8266 example
 * www.geekstips.com
*/
