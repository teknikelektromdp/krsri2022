void RintanganNaikTurun(){
//  int dinding3;

//  dinding3=0;//flag yang menyimpan keadaan robot menemukan dinding di depan, nilai ini nantinya digunakan untuk keluar dari while
//  while(dinding3==0){
  BacaSensor();
  LcdDisplay();

  int keluarNaikTurun = 0;

  BerdiriNaik();
  NaikMajuAwal();
  
  BacaSensor();
  LcdDisplay();

  while(keluarNaikTurun==0){
    NaikMaju();
    
    BacaSensor();
    modeGerak="naik";
    LcdDisplay();
    
    if ((par_f<45 && par_f>0) && (par_r>40 || par_r==0)) {
      keluarNaikTurun=1;
    } else if((par_f<50 && par_f>0) && (par_l >=40 || par_l == 0)){
      keluarNaikTurun=1;
    } else if((par_r>40 || par_r==0) && (par_l >=40 || par_l == 0)){
      keluarNaikTurun=1;
    } else {
      keluarNaikTurun=0;
    }
  }
  Berdiri();
  modeGerak="R1";
  LcdDisplay();
}
