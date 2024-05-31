#include <ESP8266WiFi.h>

// WiFi credentials
const char* ssid = "EnterYourSSIDHere"; // Change SSID
const char* password = "EnterYourPasswordHere"; // Change Password

// Define LED pins
const int LED1 = D1; // Weak signal LED
const int LED2 = D2; // Moderate signal LED
const int LED3 = D3; // Strong signal LED

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);  // Set the LED pin as output
  Serial.begin(115200);
  while (!Serial); // Wait for the serial port to connect
  delay(1000); // Wait for the serial monitor to stabilize
  Serial.flush(); // Clear any garbage characters
  Serial.println("Starting up");  
  delay(10);
  Serial.println('\n');

  WiFi.begin(ssid, password);  // Connect to the network
  Serial.print("Connecting to ");
  Serial.print(ssid);
  Serial.println(" ...");

  int connectCount = 0;
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    connectCount++;
    if (connectCount > 20) {  // Timeout after 10 seconds
      Serial.println(" Failed to connect.");
      return; // Stop further execution if connection failed
    }
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\nConnection established!");
    Serial.print("IP address:\t");
    Serial.println(WiFi.localIP());
  }
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    int rssi = WiFi.RSSI();
    Serial.print("RSSI: ");
    Serial.print(rssi);
    Serial.println(" dBm");

    // Update LED states based on signal strength
    if (rssi > -50) {  // Strong signal
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, HIGH);
    } else if (rssi > -70) {  // Moderate signal
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, LOW);
    } else {  // Weak signal
      digitalWrite(LED1, HIGH);  // Only LED1 blinks
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      delay(500);
      digitalWrite(LED1, LOW);   // Turn off LED1
      delay(500);
    }

    delay(2000);  // Main loop delay
  } else {
    Serial.println("Trying to connect...");
    digitalWrite(LED_BUILTIN, HIGH);  // Turn the LED on
    delay(250);                       // Wait for 250 milliseconds
    digitalWrite(LED_BUILTIN, LOW);   // Turn the LED off
    delay(250);                       // Wait for 250 milliseconds
    WiFi.begin(ssid, password);       // Retry connection
  }
}
