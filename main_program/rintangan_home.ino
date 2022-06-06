void RintanganHome() {
  compass.init();
  CompassCalibration(); 
  compass.read();
  InitAzimuth();
  AdjustRobotPositionSelatan(); //fungsi yang memposisikan robot keluar home
}
