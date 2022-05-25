#include <Wire.h>

#define MPU 0x68 //alamat register untuk MPU6050
#define GYRO_XOUT_H 0x43 //alamat register untuk GYRO_XOUT_H
#define ACCEL_XOUT_H 0x3B //alamat register untuk ACCEL_XOUT_H

long time_now, time_pass;
long timing = 200;

// prosedur untuk menginisialisasi MPU6050
void MPU_initialize (int MPU_ADDR){
  Wire.begin();                      // mulai komunikasi
  Wire.beginTransmission(MPU_ADDR);  // mulai komunikasi dengan MPU6050 // MPU=0x68
  Wire.write(0x6B);                  // Baca register 6B
  Wire.write(0x00);                  // reser ulang - tempatkan a 0 pada register 6B
  Wire.endTransmission(true);        //akhiri the transmisi
}

// === prosedur untuk membaca data giroskop === //
void MPU_read_Raw_gyro (float* x, float* y, float* z, int MPU_ADDRESS, int GYRO_X){
  Wire.beginTransmission(MPU_ADDRESS);
  Wire.write(GYRO_X); // Alamat data Gyro pertama pada alamat register pertama 0x43
  Wire.endTransmission(false);
  Wire.requestFrom(MPU, 6, true); // Baca total 6 register, setiap aksis disimpan pada 2 register
  // Untuk range 250deg/s  data menta harus dibagi nilai 131.0 sesuai dengan datasheet
  *x = (Wire.read()<<8 | Wire.read())/131.0; // baca register : 0x43 (GYRO_XOUT_H) dan 0x44 (GYRO_XOUT_L), nilai aksis x
  *y = (Wire.read()<<8 | Wire.read())/131.0; // baca register : 0x45 (GYRO_YOUT_H) dan 0x46 (GYRO_YOUT_L), nilai aksis y
  *z = (Wire.read()<<8 | Wire.read())/131.0; // baca register : 0x47 (GYRO_ZOUT_H) dan 0x48 (GYRO_ZOUT_L), nilai aksis z
}

// === Prosedur untuk membaca data akselerometer === //
void MPU_read_Raw_accel (float* x, float* y, float* z, int MPU_ADDRESS, int ACCEL_X){
  Wire.beginTransmission(MPU_ADDRESS);
  Wire.write(ACCEL_X); // Alamat data Accel pertama pada register address 0x3B
  Wire.endTransmission(false);
  Wire.requestFrom(MPU, 6, true); // Baca total 6 register, setiap aksis disimpan pada 2 register
  // Untuk range 2g  data mentah harus dibagi nilai 16384.0 sesuai dengan datasheet
  *x = (Wire.read()<<8 | Wire.read())/16384.0; // baca register: 0x3B (ACCEL_XOUT_H) and 0x3C (ACCEL_XOUT_L)
  *y = (Wire.read()<<8 | Wire.read())/16384.0; // baca register: 0x3D (ACCEL_YOUT_H) and 0x3E (ACCEL_YOUT_L)
  *z = (Wire.read()<<8 | Wire.read())/16384.0; // baca register: 0x3F (ACCEL_ZOUT_H) and 0x40 (ACCEL_ZOUT_L)
}

void setup() {
  Serial.begin(115200);
  MPU_initialize(MPU);
  delay(20);
}

void loop() {
  float gyro_x,gyro_y,gyro_z;
  float accel_x,accel_y,accel_z;
  time_pass = 0;
  time_now = millis();
  if(time_now > time_pass + timing){
    MPU_read_Raw_gyro(&gyro_x, &gyro_y, &gyro_z, MPU, GYRO_XOUT_H);
    MPU_read_Raw_accel(&accel_x, &accel_y, &accel_z, MPU, ACCEL_XOUT_H);
    time_pass = time_now;
  }
  
  //print variabel pada setiap aksis gyro dan accel
  Serial.print(accel_x);Serial.print("\t");
  Serial.print(accel_y);Serial.print("\t");
  Serial.print(accel_z);Serial.print("\t");
  Serial.print(gyro_x);Serial.print("\t");
  Serial.print(gyro_y);Serial.print("\t");
  Serial.print(gyro_z);Serial.print("\t");
  Serial.println("\n");
  
}
