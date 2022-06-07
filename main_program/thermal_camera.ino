void sendTemperatures(){
  for(int y=0;y<4;y++){ //go through all the rows
    Serial.print("[");
    
    for(int x=0;x<16;x++){ //go through all the columns
      double tempAtXY= termal.getTemperature(y+x*4); // extract the temperature at position x/y
      Serial.print(tempAtXY);
         
      if (x<15) Serial.print(",");
    }
    Serial.print("]");
    if (y<3)Serial.print("~"); 
  }
  Serial.print("\n");
}

void TermalInisialisasi() {
  termal.setRefreshRate(RATE_8HZ);
  termal.setResolution(RES_17bit);
  termal.setEmissivity(1.0);
  termal.initialize ();
}

double TermalMaxTemp() {
  termal.measure(true); //get new readings from the sensor
  sendTemperatures();
  return termal.getMaxTemp();  
}

void TermalSetup(){
  termal.setRefreshRate(RATE_8HZ);
  termal.setResolution(RES_17bit);
  termal.setEmissivity(1.0);
  termal.initialize ();
}

//void setup(){ 
//  Serial.begin(115200); //170ms a 19k2, 28ms a 115k2
//  //Serial.println(F("trying to initialize sensor..."));
//  sensor.setRefreshRate(RATE_8HZ);
//  sensor.setResolution(RES_17bit);
//  sensor.setEmissivity(1.0);
//  sensor.initialize (); // start the thermo cam
//  //Serial.println(F("sensor initialized!"));
//}
//void loop(){  
//  sensor.measure(true); //get new readings from the sensor
//  sendTemperatures();
//  Serial.println("Max :");
//  Serial.println(sensor.getMaxTemp());
//  delay(1000);
//};
