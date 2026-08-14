#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <math.h>

Adafruit_MPU6050 mpu;

// =====================================================
// SETTINGS
// =====================================================

const float TILT_THRESHOLD = 15.0;

// Send command every 100 ms
const unsigned long SEND_INTERVAL = 100;

unsigned long lastSendTime = 0;

char currentCommand = 'S';


// =====================================================
// SETUP
// =====================================================

void setup() {

  // HC-05 connected to hardware Serial
  // D0 = RX
  // D1 = TX

  Serial.begin(9600);

  Wire.begin();

  // ---------------------------------------------------
  // MPU6050
  // ---------------------------------------------------

  if (!mpu.begin(0x68)) {

    // If sensor fails, transmit STOP continuously
    while (1) {
      Serial.write('S');
      delay(100);
    }
  }

  // Sensor configuration
  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);

  // Start safely
  Serial.write('S');

  lastSendTime = millis();
}


// =====================================================
// MAIN LOOP
// =====================================================

void loop() {

  sensors_event_t accel;
  sensors_event_t gyro;
  sensors_event_t temp;

  mpu.getEvent(&accel, &gyro, &temp);


  // ---------------------------------------------------
  // Convert acceleration to g
  // ---------------------------------------------------

  float ax = accel.acceleration.x / 9.80665;
  float ay = accel.acceleration.y / 9.80665;
  float az = accel.acceleration.z / 9.80665;


  // ---------------------------------------------------
  // Calculate roll and pitch
  // ---------------------------------------------------

  float roll =
    atan2(ay, az) * 180.0 / PI;

  float pitch =
    atan2(
      -ax,
      sqrt((ay * ay) + (az * az))
    ) * 180.0 / PI;


  // ---------------------------------------------------
  // Determine command
  // ---------------------------------------------------

  currentCommand = 'S';

  if (pitch > TILT_THRESHOLD) {

    currentCommand = 'F';

  }
  else if (pitch < -TILT_THRESHOLD) {

    currentCommand = 'B';

  }
  else if (roll > TILT_THRESHOLD) {

    currentCommand = 'R';

  }
  else if (roll < -TILT_THRESHOLD) {

    currentCommand = 'L';
  }


  // ---------------------------------------------------
  // CONTINUOUS TRANSMISSION
  // ---------------------------------------------------

  if (millis() - lastSendTime >= SEND_INTERVAL) {

    Serial.write(currentCommand);

    lastSendTime = millis();
  }

  delay(10);
}
