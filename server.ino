#include <ESP8266WebServer.h>
//Change the items in <>.
ESP8266WebServer server(<PORT>);

const char* ssid = "<MY_SSID>";
const char* password = "<MY_PASSWORD>";
const char* host = "";
String intent = "";

void handleText() {
  String message = "";
  for (uint8_t i=0; i<server.args(); i++){
    message += server.argName(i) + ": " + server.arg(i) + "\n";
    
  }
  server.send(200, "text/plain", message);
  intent = server.arg(0);

  if( intent == "on" ){
    digitalWrite(D2, HIGH);
  }else{
    digitalWrite(D2, LOW);
  }
  
  Serial.print(intent);
  Serial.print("\n");
 }

void setup() {
  pinMode(D2, OUTPUT);
  Serial.begin(9600);
  delay(10);
  Serial.print(WiFi.localIP());
 
  // Connect to WiFi network
  Serial.print("");
  Serial.print("");
  Serial.print("Connecting to ");
  Serial.print(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.print("");
  Serial.print("WiFi connected");
  // Start the server
  server.on("/text", handleText);
  server.begin();
  Serial.print("HTTP server started");
  // Print the IP address
  Serial.print(WiFi.localIP());
}

void loop() {
  // Check if a client has connected
   server.handleClient();
  }

