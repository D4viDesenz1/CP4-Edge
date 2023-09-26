#include "DHT.h"
#include <HTTPClient.h>
#include "WiFi.h"

 

char serverAddress[] = "https://api.tago.io/data";  // TagoIO address
char contentHeader[] = "application/json";
char tokenHeader[] = "718a479e-cd15-4223-be59-1502b641faa0"; // TagoIO Token
const char wifiSsid[] = "nobody 3.0";
const char wifiPass[] = "milokzin";

WiFiClient wifia;
HTTPClient client;
int status = WL_IDLE_STATUS;
int dhtHumidity;
int dhtTemperature;
int sensor = 36;

 

int sensorValue = 0;

 

// DHT configuration
#define DHTPIN 13    // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11   
DHT dht(DHTPIN, DHTTYPE);

void init_wifi(void) {
  Serial.println("Conectando Wifi...");
  Serial.print("SSID: ");
  Serial.println(wifiSsid);
  Serial.print("PASS: ");
  Serial.println(wifiPass);
  WiFi.begin(wifiSsid, wifiPass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi Conectado!");
  Serial.print("IP is ");
  Serial.println(WiFi.localIP());
}

void setup() {
  Serial.begin(9600);
  pinMode(sensor, INPUT);

  dht.begin();
  init_wifi();
}

void loop() {
    char anyData[30];
    char postData[300];
    char anyData1[30];
    char bAny[30];
    int statusCode=0;

  //float h = dhtHumidity++;
  dhtHumidity = dht.readHumidity();

  //float t = dhtTemperature++;
  dhtTemperature = dht.readTemperature();

  sensorValue = analogRead(sensor);
  //float l = sensorValue++;

  send_temperature();
  send_humidity();
  send_light();
  delay(5000);
}

void send_temperature(void){
  char anyData[30];
  char postData[300];
  char anyData1[30];
  char bAny[30];
  int statusCode = 0;

  strcpy(postData, "{\n\t\"variable\": \"Temperature\",\n\t\"value\": ");
  dtostrf(dhtTemperature, 6, 2, anyData);
  strncat(postData, anyData, 100);
  strcpy(anyData1, ",\n\t\"unit\": \"C\"\n\t}\n");
  strncat (postData, anyData1, 100);
  Serial.println(postData);
  client.begin(serverAddress);
  client.addHeader("Content-Type", contentHeader);
  client.addHeader("Device-Token", tokenHeader);
  statusCode = client.POST(postData);
  delay(5000);
  // read the status code and body of the response
  Serial.print("Status code: ");
  Serial.println(statusCode);
  Serial.println("End of POST to TagoIO");
  Serial.println();
}

void send_humidity(void) {
  char anyData[30];
  char postData[300];
  char anyData1[30];
  char bAny[30];
  int statusCode = 0;
  strcpy(postData, "{\n\t\"variable\": \"Humidity\",\n\t\"value\": ");
  dtostrf(dhtHumidity, 6, 2, anyData);
  strncat(postData, anyData, 100);
  strcpy(anyData1, ",\n\t\"unit\": \"%\"\n\t}\n");
  strncat (postData, anyData1, 100);
  Serial.println(postData);
  client.begin(serverAddress);
  client.addHeader("Content-Type", contentHeader);
  client.addHeader("Device-Token", tokenHeader);
  statusCode = client.POST(postData);
  delay(5000);
  // read the status code and body of the response
  Serial.print("Status code: ");
  Serial.println(statusCode);
  Serial.println("End of POST to TagoIO");
  Serial.println();
}

void send_light(void){
  char anyData[30];
  char postData[300];
  char anyData1[30];
  char bAny[30];
  int statusCode = 0;
  strcpy(postData, "{\n\t\"variable\": \"Luminosidade\",\n\t\"value\": ");
  dtostrf(sensorValue, 6, 2, anyData);
  strncat(postData, anyData, 100);
  strcpy(anyData1, ",\n\t\"unit\": \"%\"\n\t}\n");
  strncat (postData, anyData1, 100);
  Serial.println(postData);
  client.begin(serverAddress);
  client.addHeader("Content-Type", contentHeader);
  client.addHeader("Device-Token", tokenHeader);
  statusCode = client.POST(postData);
  delay(5000);
  // read the status code and body of the response
  Serial.print("Status code: ");
  Serial.println(statusCode);
  Serial.println("End of POST to TagoIO");
  Serial.println();
}
