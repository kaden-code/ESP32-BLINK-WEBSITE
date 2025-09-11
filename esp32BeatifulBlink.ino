#include <Arduino.h>
#include <ESPAsyncWebServer.h>
#include <WebSocketsServer.h>
#include "index.h"

String prevState;
const char* ssid     = "droneNigga";
// Wifi password
const char* password = "Kadenisagenius";

AsyncWebServer server(80); // starts server on port 80
WebSocketsServer webSocket = WebSocketsServer(81); // starts Webocket Server on port 81


void printGaps(){
  Serial.println();
  Serial.println();
}



void printConnectionAlert(){
  printGaps();
  Serial.print("Connect to ");
  Serial.println(ssid);
}


void WiFiConnect(){
  printConnectionAlert();
  // connects to wifi as station on given ssid and password
  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid,password);
}

void serveHTML(){
    // Serve a basic HTML page with JavaScript to create the WebSocket connection
  server.on("/", HTTP_GET, [](AsyncWebServerRequest* request) {
    Serial.println("Web Server: received a web page request");
    String html = HTML_CONTENT;  // Use the HTML content from the index.h file
    request->send(200, "text/html", html);
  });

  server.begin();
  Serial.print("ESP32 Web Server's IP address: ");
  Serial.println(WiFi.softAPIP());
}


void webSocketEvent(uint8_t clientID, WStype_t eventType, uint8_t* payload, size_t length) {
  switch (eventType) {
    case WStype_DISCONNECTED:
      Serial.printf("[%u] Disconnected!\n", clientID);
      break;
    case WStype_CONNECTED:
    // creates new scope for ip variable
      {
        // gets clients ip 
        IPAddress ip = webSocket.remoteIP(clientID);
        // prints format of client id and ip they connected from 
        Serial.printf("[%u] Connected from %d.%d.%d.%d\n", clientID, ip[0], ip[1], ip[2], ip[3]);
      }
      break;
    case WStype_TEXT:
      Serial.printf("[%u] Received text: %s\n", clientID, payload);
      // Send a response back to the client
       /* webSocket.sendTXT(clientID, "Received:  " + ); */ 
       String recievedText = String((char*)payload);
       Serial.println(recievedText);
       if(recievedText != prevState){
        prevState = recievedText;
       if(recievedText == "true"){
        digitalWrite(4,HIGH);
        Serial.println("led on");
       }
       else{
        digitalWrite(4,LOW);
        Serial.println("led off");
       }}
  
      break;
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(4,OUTPUT);
  digitalWrite(4,LOW);
  WiFiConnect();
  webSocket.begin();
  webSocket.onEvent(webSocketEvent);
  serveHTML();

}

void loop() {
  // put your main code here, to run repeatedly:
webSocket.loop();

}
