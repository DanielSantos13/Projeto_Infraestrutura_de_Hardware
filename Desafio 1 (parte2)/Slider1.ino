#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <jled.h>

auto led =JLed(D4);

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "ffbf8cdeefcb40d6811357dc7d1c6909";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "jualabs-ap";
char pass[] = "jualabs-ap";



BLYNK_WRITE(V3)
{
  int pinValue = param.asInt();

  int brilho = (pinValue - 1023) * -1;
  analogWrite(D4, brilho);

  // process received value
}
void setup() {
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);

}

void loop() {
  Blynk.run();
  led.Update();

}
