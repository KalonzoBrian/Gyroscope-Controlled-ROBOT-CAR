#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

Adafruit_MPU6050 mpu;

void setup(void) {
  Serial.begin(115200);

  // Initialize sensor
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) { delay(10); }
  }

  // Set ranges (Standard settings)
  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);

  Serial.println("MPU6050 Ready!");
  delay(100);
}

void loop() {
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  // --- ACCELEROMETER (m/s^2) ---
  // When sitting flat, Z should be ~9.8
  Serial.print("Accel X:"); Serial.print(a.acceleration.x);
  Serial.print(" Y:"); Serial.print(a.acceleration.y);
  Serial.print(" Z:"); Serial.print(a.acceleration.z);

  Serial.print("  |  ");

  // --- GYROSCOPE (rad/s) ---
  // When sitting still, these should be ~0.00
  Serial.print("Gyro X:"); Serial.print(g.gyro.x);
  Serial.print(" Y:"); Serial.print(g.gyro.y);
  Serial.print(" Z:"); Serial.println(g.gyro.z);

  delay(100); 
}
