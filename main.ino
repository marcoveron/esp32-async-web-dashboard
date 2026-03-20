#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "";
const char* password = "";

int redPin = 15;
int greenPin = 16;
int bluePin = 17;

String red_state = "off";
String green_state = "off";
String blue_state = "off";

WebServer server(80);

void red_on() {
  red_state = "on";
  analogWrite(redPin, 255);
  handleRoot();
}

void red_off() {
  red_state = "off";
  analogWrite(redPin, 0);
  handleRoot();
}

void green_on() {
  green_state = "on";
  digitalWrite(greenPin, 255);
  handleRoot();
}

void green_off() {
  green_state = "off";
  digitalWrite(greenPin, 0);
  handleRoot();
}

void blue_on() {
  blue_state = "on";
  digitalWrite(bluePin, 255);
  handleRoot();
}

void blue_off() {
  blue_state = "off";
  digitalWrite(bluePin, 0);
  handleRoot();
}

void handleRoot() {
  String html = "<!DOCTYPE html><html><head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">";
  html += "<link rel=\"icon\" href=\"data:,\">";
  html += "<style>body { background-color: #121212; color: white; }"; 
  html += "html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}";
  html += ".button { background-color: #E53935; border: none; color: white; padding: 16px 40px; text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer; border-radius: 8px;}";
  html += ".button2 { background-color: #7F0000; }</style></head>";
  html += "<body><h1>ESP32 Web Server</h1>";

  html += "<p>Red - State " + red_state + "</p>";
  // to add the right button ON or OFF
  if (red_state == "off") {
    html += "<p><a href=\"/red/on\"><button class=\"button\">ON</button></a></p>";
  } else {
    html += "<p><a href=\"/red/off\"><button class=\"button button2\">OFF</button></a></p>";
  }

  html += "<p>Green - State " + green_state + "</p>";
  if (green_state == "off") {
    html += "<p><a href=\"/green/on\"><button class=\"button\">ON</button></a></p>";
  } else {
    html += "<p><a href=\"/green/off\"><button class=\"button button2\">OFF</button></a></p>";
  }

  html += "<p>Blue - State " + blue_state + "</p>";
  if (blue_state == "off") {
    html += "<p><a href=\"/blue/on\"><button class=\"button\">ON</button></a></p>";
  } else {
    html += "<p><a href=\"/blue/off\"><button class=\"button button2\">OFF</button></a></p>";
  }

  html += "</body></html>";
  server.send(200, "text/html", html);
}

void setup() {
  Serial.begin(9600);

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, LOW);
  digitalWrite(bluePin, LOW);

  WiFi.begin(ssid, password);

  server.begin();
  Serial.println("HTTP server started...");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("waiting...");
  }
  Serial.println("Your ESP32 local IP is:");
  Serial.println(WiFi.localIP());
  
  server.on("/", handleRoot);

  server.on("/red/on", red_on);
  server.on("/red/off", red_off);
  server.on("/green/on", green_on);
  server.on("/green/off", green_off);
  server.on("/blue/on", blue_on);
  server.on("/blue/off", blue_off);
}

void loop() {
  server.handleClient();
}
