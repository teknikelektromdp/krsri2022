/**
 * Fungsi memutar tubuh robot
 */
void Putar(String arah, int tinggiAngkat) {
  String pasanganServo11, pasanganServo12, 
         pasanganServo21, pasanganServo22,
         pasanganServo31, pasanganServo32,
         pasanganServo41, pasanganServo42;

  if (arah.equals("kiri")) {
    pasanganServo11="LFT"; pasanganServo12="LFM";
    pasanganServo21="LBT"; pasanganServo22="LBM";
    pasanganServo31="RBT"; pasanganServo32="RBM";
    pasanganServo41="RFT"; pasanganServo42="RFM";  
  } else if (arah.equals("kanan")) {
    pasanganServo11="RFT"; pasanganServo12="RFM";
    pasanganServo21="RBT"; pasanganServo22="RBM";
    pasanganServo31="LBT"; pasanganServo32="LBM";
    pasanganServo41="LFT"; pasanganServo42="LFM";    
  }

  //mundurkan kaki kiri depan bersamaan dengan menaikkannya
  ServoMovementDouble(pasanganServo11, -16, pasanganServo12, tinggiAngkat);
  //mundurkan kaki kiri depan bersamaan dengan menurunkannya
  ServoMovementDouble(pasanganServo11, -32, pasanganServo12, 0);
  delay(100);
  
  //mundurkan kaki kiri belakang bersamaan dengan menaikkannya
  ServoMovementDouble(pasanganServo21, -16, pasanganServo22, tinggiAngkat);
  //mundurkan kaki kiri belakang bersamaan dengan menurunkannya
  ServoMovementDouble(pasanganServo21, -32, pasanganServo22, 0);
  delay(100);

  //majukan kaki kanan belakang bersamaan dengan menaikkannya
  ServoMovementDouble(pasanganServo31, 16, pasanganServo32, tinggiAngkat);
  //majukan kaki kanan belakang bersamaan dengan menurunkannya
  ServoMovementDouble(pasanganServo31, 32, pasanganServo32, 0);
  delay(100);
  
  //majukan kaki kanan depan bersamaan dengan menaikkannya
  ServoMovementDouble(pasanganServo41, 16, pasanganServo42, tinggiAngkat);
  //majukan kaki kanan depan bersamaan dengan menurunkannya
  ServoMovementDouble(pasanganServo41, 32, pasanganServo42, 0);
  delay(100);

  //balik kedua kaki atas bersamaan tanpa menaikkannya
  ServoMovementDouble(pasanganServo11, 0, pasanganServo21, 0);
  delay(10);
  //balik kedua kaki atas bersamaan tanpa menaikkannya
  ServoMovementDouble(pasanganServo31, 0, pasanganServo41, 0);
  delay(10);
}

void Putar90(String arah, int tinggiAngkat){
  for(int i = 0; i<=5; i++){
    Putar(arah, tinggiAngkat);
  }
}
