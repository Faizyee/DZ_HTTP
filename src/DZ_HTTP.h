#ifndef DZ_HTTP_H
#define DZ_HTTP_H

#include <Arduino.h>

#if defined(ESP8266)
  #include <ESP8266WiFi.h>
  #include <ESP8266HTTPClient.h>
#elif defined(ESP32)
  #include <WiFi.h>
  #include <HTTPClient.h>
#endif

#include <WiFiClientSecure.h>
#include <WiFiClient.h>
#include <vector>
#include <utility>

class DZ_HTTP {
  public:
    DZ_HTTP(String base_url);
    enum Method {
      DZ_METHOD_GET,
      DZ_METHOD_POST,
      DZ_METHOD_PUT
    };
    using DZ_HEADER = std::vector<std::pair<String, String>>;
    void send(Method http_method, String path_url);
    void send(Method http_method, String path_url, std::vector<std::pair<String, String>> http_headers);
    void send(Method http_method, String path_url, String http_body);
    void send(Method http_method, String path_url, std::vector<std::pair<String, String>> http_headers, String http_body);
    String send_with_response(Method http_method, String path_url);
    String send_with_response(Method http_method, String path_url, std::vector<std::pair<String, String>> http_headers);
    String send_with_response(Method http_method, String path_url, String http_body);
    String send_with_response(Method http_method, String path_url, std::vector<std::pair<String, String>> http_headers, String http_body);

  private:
    String base_url;
    void clearString(String &str);
    String methodToString(Method method);
};

#endif
