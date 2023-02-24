#include <M5Core2.h>
#include <Adafruit_VCNL4040.h>
#include <Adafruit_SHT4x.h>

///////////////////////////////////////////////////////////////
// Variables
///////////////////////////////////////////////////////////////
Adafruit_SHT4x sht4 = Adafruit_SHT4x();
Adafruit_VCNL4040 vcnl4040 = Adafruit_VCNL4040();

///////////////////////////////////////////////////////////////
// Put your setup code here, to run once
///////////////////////////////////////////////////////////////
void setup() {

    // Init device
    M5.begin();

    // Use the Adafruit library to initialize the sensor over I2C
    Serial.println("Adafruit SHT40 Config demo");
    if (!sht4.begin())
    {
        Serial.println("Couldn't find SHT40 chip");
        while (1) ; // Program ends in infinite loop...
    }
    Serial.println("Found SHT40 chip\n");

    Serial.println("Adafruit VCNL4040 Config demo");
    if (!vcnl4040.begin())
    {
        Serial.println("Couldn't find VCNL4040 chip");
        while (1) ; // Program ends in infinite loop...
    }
    Serial.println("Found VCNL4040 chip\n");
}

///////////////////////////////////////////////////////////////
// Put your main code here, to run repeatedly
///////////////////////////////////////////////////////////////
void loop()
{
    // Library calls to get the sensor readings over I2C
    sensors_event_t humidity, temp;
  
  uint32_t timestamp = millis();
  sht4.getEvent(&humidity, &temp);// populate temp and humidity objects with fresh data
  timestamp = millis() - timestamp;

  Serial.print("Temperature: "); Serial.print(temp.temperature); Serial.println(" degrees C");
  Serial.print("Humidity: "); Serial.print(humidity.relative_humidity); Serial.println("% rH");

     Serial.printf("Proximity: %d\n", vcnl4040.getProximity());
    Serial.printf("Ambient light: %d\n", vcnl4040.getLux());
    Serial.printf("Raw white light: %d\n\n", vcnl4040.getWhiteLight());

  delay(1000);
}