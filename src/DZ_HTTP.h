#ifndef DZ_HTTP_H
#define DZ_HTTP_H

#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <HTTPClient.h>
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
    String send(Method http_method, String path_url);
    String send(Method http_method, String path_url, std::vector<std::pair<String, String>> http_headers);
    String send(Method http_method, String path_url, String http_body);
    String send(Method http_method, String path_url, std::vector<std::pair<String, String>> http_headers, String http_body);

  private:
    String base_url;
    void clearString(String &str);
    String methodToString(Method method);
};

#endif
