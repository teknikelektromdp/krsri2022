

void PemadamanLama(){
  Berdiri();
  int apiAda=0, apiSuhu=45;
  double termalBaca=TermalMaxTemp();

  if (termalBaca>=apiSuhu){
    apiAda=1;
    lcd.setCursor(0,0);
    lcd.print(termalBaca); lcd.print(" api");
  }
  else {
    int cekKiri=0, cekKanan=0;
    
    
    //memeriksa dan memutar sebelah kiri
    while(apiAda==0 && cekKiri<=2){
      int i=0;
      cekKiri++;
      //memutar sebelah kiri
      while(apiAda==0 && i<=30) {
        i = i+2;
        ServoWrite("LFT", i);
        ServoWrite("RFT", -i);
        ServoWrite("LBT", i);
        ServoWrite("RBT", -i);
        termalBaca=TermalMaxTemp();
        BacaSensor();
        modeGerak="cari";
        LcdDisplay();
        delay(50);
        if (termalBaca>=apiSuhu){
          apiAda=1;
          BacaSensor();
          modeGerak="padam";
          LcdDisplay();
        }
      }

      //memutar badan robot jika api masih belum ketemu pada saat pencarian sebelumnya
      if (apiAda==0){
        //majukan kaki kiri belakang bersamaan dengan menaikkannya
        ServoMovementDouble("LFT", 15, "LFM", 40);
        //majukan kaki kiri belakang bersamaan dengan menurunkannya
        ServoMovementDouble("LFT", 0, "LFM", 0);
        delay(1);
        
        //majukan kaki kiri belakang bersamaan dengan menaikkannya
        ServoMovementDouble("LBT", 15, "LBM", 40);
        //majukan kaki kiri belakang bersamaan dengan menurunkannya
        ServoMovementDouble("LBT", 0, "LBM", 0);
        delay(1);

        //majukan kaki kiri belakang bersamaan dengan menaikkannya
        ServoMovementDouble("RBT", -15, "RBM", 40);
        //majukan kaki kiri belakang bersamaan dengan menurunkannya
        ServoMovementDouble("RBT", 0, "RBM", 0);
        delay(1);

        //majukan kaki kiri belakang bersamaan dengan menaikkannya
        ServoMovementDouble("RFT", -15, "RFM", 40);
        //majukan kaki kiri belakang bersamaan dengan menurunkannya
        ServoMovementDouble("RFT", 0, "RFM", 0);
        delay(1);
        BacaSensor();
        modeGerak="cari";
        LcdDisplay();
      }
    }
    
    //memeriksa dan memutar sebelah kanan
    while(apiAda==0 && cekKanan<=4){
      int i=0;
      cekKanan++;
      //memutar sebelah kanan
      while(apiAda==0 && i<=30) {
        i = i+2;
        ServoWrite("RFT", i);
        ServoWrite("LFT", -i);
        ServoWrite("RBT", i);
        ServoWrite("LBT", -i);
        termalBaca=TermalMaxTemp();
        BacaSensor();
        modeGerak="cari";
        LcdDisplay();
        delay(50);
        if (termalBaca>=apiSuhu){
          apiAda=1;
          Putar("kanan", 16, 50);
          BacaSensor();
          modeGerak="padam";
          LcdDisplay();
        }
      }

      //memutar badan robot jika api masih belum ketemu pada saat pencarian sebelumnya
      if (apiAda==0){
        //majukan kaki kanan belakang bersamaan dengan menaikkannya
        ServoMovementDouble("RFT", 15, "RFM", 40);
        //majukan kaki kanan belakang bersamaan dengan menurunkannya
        ServoMovementDouble("RFT", 0, "RFM", 0);
        delay(1);
        
        //majukan kaki kanan belakang bersamaan dengan menaikkannya
        ServoMovementDouble("RBT", 15, "RBM", 40);
        //majukan kaki kanan belakang bersamaan dengan menurunkannya
        ServoMovementDouble("RBT", 0, "RBM", 0);
        delay(1);

        //majukan kaki kiri belakang bersamaan dengan menaikkannya
        ServoMovementDouble("LBT", -15, "LBM", 40);
        //majukan kaki kiri belakang bersamaan dengan menurunkannya
        ServoMovementDouble("LBT", 0, "LBM", 0);
        delay(1);

        //majukan kaki kiri belakang bersamaan dengan menaikkannya
        ServoMovementDouble("LFT", -15, "LFM", 40);
        //majukan kaki kiri belakang bersamaan dengan menurunkannya
        ServoMovementDouble("LFT", 0, "LFM", 0);
        delay(1);
        BacaSensor();
        modeGerak="cari";
        LcdDisplay();
      }
    }
  }
}

void Pemadaman(){//tes
  Berdiri();
  int apiAda=0, apiSuhu=45;
  double termalBaca=TermalMaxTemp();

  if (termalBaca>=apiSuhu){
    apiAda=1;
    lcd.setCursor(0,0);
    Putar("kanan", 20, 50);
    BacaSensor();
    modeGerak="padam";
    LcdDisplay();
  }
  else {
    int cekKiri=0, cekKanan=0;
    
    //memeriksa dan memutar sebelah kanan
    while(apiAda==0 && cekKanan<=2){
      int i=0;
      cekKanan++;
      //memutar sebelah kanan
      while(apiAda==0 && i<=30) {
        i = i+2;
        ServoWrite("RFT", i);
        ServoWrite("LFT", -i);
        ServoWrite("RBT", i);
        ServoWrite("LBT", -i);
        termalBaca=TermalMaxTemp();
        BacaSensor();
        modeGerak="cari";
        LcdDisplay();
        delay(50);
        if (termalBaca>=apiSuhu){
          apiAda=1;
          Putar("kanan", 20, 50);
          BacaSensor();
          modeGerak="padam";
          LcdDisplay();
        }
      }

      //memutar badan robot jika api masih belum ketemu pada saat pencarian sebelumnya
      if (apiAda==0){
        //majukan kaki kanan belakang bersamaan dengan menaikkannya
        ServoMovementDouble("RFT", 15, "RFM", 40);
        //majukan kaki kanan belakang bersamaan dengan menurunkannya
        ServoMovementDouble("RFT", 0, "RFM", 0);
        delay(1);
        
        //majukan kaki kanan belakang bersamaan dengan menaikkannya
        ServoMovementDouble("RBT", 15, "RBM", 40);
        //majukan kaki kanan belakang bersamaan dengan menurunkannya
        ServoMovementDouble("RBT", 0, "RBM", 0);
        delay(1);

        //majukan kaki kiri belakang bersamaan dengan menaikkannya
        ServoMovementDouble("LBT", -15, "LBM", 40);
        //majukan kaki kiri belakang bersamaan dengan menurunkannya
        ServoMovementDouble("LBT", 0, "LBM", 0);
        delay(1);

        //majukan kaki kiri belakang bersamaan dengan menaikkannya
        ServoMovementDouble("LFT", -15, "LFM", 40);
        //majukan kaki kiri belakang bersamaan dengan menurunkannya
        ServoMovementDouble("LFT", 0, "LFM", 0);
        delay(1);
        BacaSensor();
        modeGerak="cari";
        LcdDisplay();
      }
    }
    
    //memeriksa dan memutar sebelah kiri
    while(apiAda==0 && cekKiri<=5){
      int i=0;
      cekKiri++;
      //memutar sebelah kiri
      while(apiAda==0 && i<=30) {
        i = i+2;
        ServoWrite("LFT", i);
        ServoWrite("RFT", -i);
        ServoWrite("LBT", i);
        ServoWrite("RBT", -i);
        termalBaca=TermalMaxTemp();
        BacaSensor();
        modeGerak="cari";
        LcdDisplay();
        delay(50);
        if (termalBaca>=apiSuhu){
          apiAda=1;
          BacaSensor();
          modeGerak="padam";
          LcdDisplay();
        }
      }

      //memutar badan robot jika api masih belum ketemu pada saat pencarian sebelumnya
      if (apiAda==0){
        //majukan kaki kiri belakang bersamaan dengan menaikkannya
        ServoMovementDouble("LFT", 15, "LFM", 40);
        //majukan kaki kiri belakang bersamaan dengan menurunkannya
        ServoMovementDouble("LFT", 0, "LFM", 0);
        delay(1);
        
        //majukan kaki kiri belakang bersamaan dengan menaikkannya
        ServoMovementDouble("LBT", 15, "LBM", 40);
        //majukan kaki kiri belakang bersamaan dengan menurunkannya
        ServoMovementDouble("LBT", 0, "LBM", 0);
        delay(1);

        //majukan kaki kiri belakang bersamaan dengan menaikkannya
        ServoMovementDouble("RBT", -15, "RBM", 40);
        //majukan kaki kiri belakang bersamaan dengan menurunkannya
        ServoMovementDouble("RBT", 0, "RBM", 0);
        delay(1);

        //majukan kaki kiri belakang bersamaan dengan menaikkannya
        ServoMovementDouble("RFT", -15, "RFM", 40);
        //majukan kaki kiri belakang bersamaan dengan menurunkannya
        ServoMovementDouble("RFT", 0, "RFM", 0);
        delay(1);
        BacaSensor();
        modeGerak="cari";
        LcdDisplay();
      }
    }
  }
}
