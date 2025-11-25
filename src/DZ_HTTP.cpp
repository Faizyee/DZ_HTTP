#include "DZ_HTTP.h"

DZ_HTTP::DZ_HTTP(String base_url) {
  this->base_url = base_url;
}

void DZ_HTTP::clearString(String &str) {
  str = "";
  str.remove(0);
  str.reserve(0);
}

String DZ_HTTP::methodToString(Method method) {
  switch (method) {
    case DZ_METHOD_GET: return "GET";
    case DZ_METHOD_POST: return "POST";
    case DZ_METHOD_PUT: return "PUT";
    default: return "UNKNOWN";
  }
}

void DZ_HTTP::send(Method http_method, String path_url) {
  send(http_method, path_url, std::vector<std::pair<String, String>>(), "");
}

void DZ_HTTP::send(Method http_method, String path_url, std::vector<std::pair<String, String>> http_headers) {
  send(http_method, path_url, http_headers, "");
}

void DZ_HTTP::send(Method http_method, String path_url, String http_body) {
  send(http_method, path_url, std::vector<std::pair<String, String>>(), http_body);
}

void DZ_HTTP::send(Method http_method, String path_url, std::vector<std::pair<String, String>> http_headers, String http_body) {
  HTTPClient http_req;
  WiFiClientSecure client;
  client.setInsecure();
  String full_url = base_url + path_url;

  if (full_url.startsWith("https://")) http_req.begin(client, full_url);
  else http_req.begin(full_url);

  for (auto& h : http_headers) http_req.addHeader(h.first, h.second);

  int code = 0;
  switch (http_method) {
    case DZ_METHOD_GET:   http_code = http_req.GET();             break;
    case DZ_METHOD_POST:  http_code = http_req.POST(http_body);   break;
    case DZ_METHOD_PUT:   http_code = http_req.PUT(http_body);    break;
  }
  if (http_code > 0) {
    Serial.printf("[%s] %s - code: %d\n", methodToString(http_method).c_str(), full_url.c_str(), http_code);
    Serial.println(http_req.getString());
  } else if (http_code == 0) {
    Serial.printf("Method not found! Code: %d\n", http_code);
  } else {
    Serial.printf("Request failed! Code: %d\n", http_code);
  }
  http_req.end();
  clearString(full_url);
}

String DZ_HTTP::send(Method http_method, String path_url) {
  return send(http_method, path_url, std::vector<std::pair<String, String>>(), "");
}

String DZ_HTTP::send(Method http_method, String path_url, std::vector<std::pair<String, String>> http_headers) {
  return send(http_method, path_url, http_headers, "");
}

String DZ_HTTP::send(Method http_method, String path_url, String http_body) {
  return send(http_method, path_url, std::vector<std::pair<String, String>>(), http_body);
}

String DZ_HTTP::send(Method http_method, String path_url, std::vector<std::pair<String, String>> http_headers, String http_body) {
  HTTPClient http_req;
  WiFiClientSecure client;
  client.setInsecure();
  String full_url = base_url + path_url;

  if (full_url.startsWith("https://")) http_req.begin(client, full_url);
  else http_req.begin(full_url);

  for (auto& h : http_headers) http_req.addHeader(h.first, h.second);

  int code = 0;
  switch (http_method) {
    case DZ_METHOD_GET:   code = http_req.GET();           break;
    case DZ_METHOD_POST:  code = http_req.POST(http_body); break;
    case DZ_METHOD_PUT:   code = http_req.PUT(http_body);  break;
  }

  String res = "";
  if (code > 0) res = http_req.getString();
  http_req.end();
  clearString(full_url);
  return res;
}
