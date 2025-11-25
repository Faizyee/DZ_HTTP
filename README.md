# DZ_HTTP Arduino Library

Library HTTP untuk Arduino/ESP32 dengan dukungan GET, POST, PUT, custom header, body, dan pengambilan response string.

## Fitur
- Base URL persisten
- GET/POST/PUT
- Header & body opsional
- Serial debug
- HTTPS (insecure)
- Mendapatkan response (return `String`)

## Contoh Penggunaan
```cpp
#include <DZ_HTTP.h>

DZ_HTTP http("https://example.com");

void setup() {
  Serial.begin(115200);
  WiFi.begin("SSID", "PASS");
  while(WiFi.status() != WL_CONNECTED);

  String r1 = http.send(DZ_HTTP::DZ_METHOD_GET, "/ping");
  Serial.println(r1);

  DZ_HTTP::DZ_HEADER headers = {
    {"Content-Type", "application/json"}
  };
  String r2 = http.send(DZ_HTTP::DZ_METHOD_POST, "/post", headers, "{\"hello\":\"world\"}");
  Serial.println(r2);
}

void loop() {}
