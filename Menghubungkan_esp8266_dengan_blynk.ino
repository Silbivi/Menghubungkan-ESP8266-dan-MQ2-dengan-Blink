#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#define BLYNK_PRINT Serial

char auth[] = "MsplCZe0U3ZbfqNf0nGCaOw5eA3YXw2i"; /*Auth Token*/
char ssid[] = "Silviaaaa";
char pass[] = "123456789";

BlynkTimer timer;

int mq2 = A0;
int data = 0;

void setup() {
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(1000L, getSendData);
}

void loop() {
  timer.run();
  Blynk.run();
}

void getSendData() {
  data = analogRead(mq2);
  Blynk.virtualWrite(V2, data);
  
  if (data > 700) {
    Blynk.notify("Smoke Detected!");
  }
}
