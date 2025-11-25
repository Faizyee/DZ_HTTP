#include <DZ_HTTP.h>

const char* WIFI_SSID = "YOUR_SSID";
const char* WIFI_PASS = "YOUR_PASS";
DZ_HTTP http("https://example.com");

void setup() {
  Serial.begin(115200);
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  while(WiFi.status() != WL_CONNECTED);

  http.send(DZ_HTTP::DZ_METHOD_PUT, "/update", "{\"val\":123}");
}

void loop() {}
