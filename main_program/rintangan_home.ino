void RintanganHome() {
  compass.init();
  compassCalibration(); 
  compass.read();
  initAzimuth();
  adjustRobotPosition(); //fungsi yang memposisikan robot keluar home
}
