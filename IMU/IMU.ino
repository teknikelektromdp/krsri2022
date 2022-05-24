#include "Wire.h"

#include "I2Cdev.h"
#include "ADXL345.h"
#include "ITG3200.h"

// class default I2C address is 0x53
// specific I2C addresses may be passed as a parameter here
// ALT low = 0x53 (default for SparkFun 6DOF board)
// ALT high = 0x1D
ADXL345 accel;
ITG3200 gyro;

int16_t gx, gy, gz;

int16_t ax, ay, az;

#define LED_PIN 13 // (Arduino is 13, Teensy is 6)
bool blinkState = false;

void setup() {
    // join I2C bus (I2Cdev library doesn't do this automatically)
    Wire.begin();

    // initialize serial communication
    // (38400 chosen because it works as well at 8MHz as it does at 16MHz, but
    // it's really up to you depending on your project)
    Serial.begin(38400);

    // initialize device
    Serial.println("Initializing I2C devices...");
    accel.initialize();
    gyro.initialize();
    
    // verify connection
    Serial.println("Testing device connections...");
    Serial.println(accel.testConnection() ? "ADXL345 connection successful" : "ADXL345 connection failed");
    Serial.println(gyro.testConnection() ? "ITG3200 connection successful" : "ITG3200 connection failed");

    // configure LED for output
    pinMode(LED_PIN, OUTPUT);
}

void loop() {
    // read raw accel measurements from device
    accel.getAcceleration(&ax, &ay, &az);
    gyro.getRotation(&gx, &gy, &gz);

    // display tab-separated accel x/y/z values
    Serial.print("accel:\t");
    Serial.print(ax); Serial.print("\t");
    Serial.print(ay); Serial.print("\t");
    Serial.print(az); Serial.print("\t");

    Serial.print("gyro:\t");
    Serial.print(gx); Serial.print("\t");
    Serial.print(gy); Serial.print("\t");
    Serial.println(gz);
    // blink LED to indicate activity
    blinkState = !blinkState;
    digitalWrite(LED_PIN, blinkState);
}
