/**
 * Fungsi memutar tubuh robot
 */
void Putar(String arah, int jauhGerakan, int tinggiAngkat) {//jauh gerakan maksimal 32
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
  ServoMovementDouble(pasanganServo11, -(jauhGerakan/2), pasanganServo12, tinggiAngkat);
  //mundurkan kaki kiri depan bersamaan dengan menurunkannya
  ServoMovementDouble(pasanganServo11, -(jauhGerakan), pasanganServo12, 0);
  delay(100);
  
  //mundurkan kaki kiri belakang bersamaan dengan menaikkannya
  ServoMovementDouble(pasanganServo21, -(jauhGerakan/2), pasanganServo22, tinggiAngkat);
  //mundurkan kaki kiri belakang bersamaan dengan menurunkannya
  ServoMovementDouble(pasanganServo21, -(jauhGerakan), pasanganServo22, 0);
  delay(100);

  //majukan kaki kanan belakang bersamaan dengan menaikkannya
  ServoMovementDouble(pasanganServo31, (jauhGerakan/2), pasanganServo32, tinggiAngkat);
  //majukan kaki kanan belakang bersamaan dengan menurunkannya
  ServoMovementDouble(pasanganServo31, jauhGerakan, pasanganServo32, 0);
  delay(100);
  
  //majukan kaki kanan depan bersamaan dengan menaikkannya
  ServoMovementDouble(pasanganServo41, (jauhGerakan/2), pasanganServo42, tinggiAngkat);
  //majukan kaki kanan depan bersamaan dengan menurunkannya
  ServoMovementDouble(pasanganServo41, jauhGerakan, pasanganServo42, 0);
  delay(100);

  //balik kedua kaki atas bersamaan tanpa menaikkannya
  ServoMovementDouble(pasanganServo11, 0, pasanganServo21, 0);
  delay(10);
  //balik kedua kaki atas bersamaan tanpa menaikkannya
  ServoMovementDouble(pasanganServo31, 0, pasanganServo41, 0);
  delay(10);
}
