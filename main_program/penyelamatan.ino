

//scanning area

//      int apiAda=0, apiSuhu=40;
//      double termalBaca=TermalMaxTemp();
//      
//      if (termalBaca>=apiSuhu) apiAda=1;
//      else {
//      while(apiAda==0){
//      
//        int i=0;
//        while(apiAda==0 && i<=30) {
//          i++;
//          ServoWrite("LFT", i);
//          ServoWrite("RFT", -i);
//          ServoWrite("LBT", i);
//          ServoWrite("RBT", -i);
//          termalBaca=TermalMaxTemp();
//          delay(1000);
//          if (termalBaca>=apiSuhu) apiAda=1;
//          lcd.clear();
//          lcd.setCursor(0,0); lcd.print(termalBaca);
//          lcd.setCursor(0,1); lcd.print(i);
//        }
//        
//        //memutar badan robot jika api masih belum ketemu pada saat pencarian sebelumnya
//        if (apiAda==0){
//          //majukan kaki kiri belakang bersamaan dengan menaikkannya
//          ServoMovementDouble("LFT", 15, "LFM", 30);
//          //majukan kaki kiri belakang bersamaan dengan menurunkannya
//          ServoMovementDouble("LFT", 0, "LFM", 0);
//          delay(100);
//          
//          //majukan kaki kiri belakang bersamaan dengan menaikkannya
//          ServoMovementDouble("LBT", 15, "LBM", 30);
//          //majukan kaki kiri belakang bersamaan dengan menurunkannya
//          ServoMovementDouble("LBT", 0, "LBM", 0);
//          delay(100);
//          
//          //majukan kaki kiri belakang bersamaan dengan menaikkannya
//          ServoMovementDouble("RBT", -15, "RBM", 30);
//          //majukan kaki kiri belakang bersamaan dengan menurunkannya
//          ServoMovementDouble("RBT", 0, "RBM", 0);
//          delay(100);
//          
//          //majukan kaki kiri belakang bersamaan dengan menaikkannya
//          ServoMovementDouble("RFT", -15, "RFM", 30);
//          //majukan kaki kiri belakang bersamaan dengan menurunkannya
//          ServoMovementDouble("RFT", 0, "RFM", 0);
//          delay(100);
//          lcd.clear();
//          lcd.setCursor(0,0); lcd.print(termalBaca);   
//          }
//        }
//      }
