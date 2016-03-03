#include <HX711.h>

int pinsDOUT[4] = [1,3,5,7]; 
//The pins hooked up to the respective cells' DOUT

int pinsSCK[4] = [2,4,6,8];
//The pins hooked up to the respective cells' SCK

HX711 allCells[4];

void setup() {
  for(ii=0, ii<4, ii++){
    allCells[ii] = scale(pinsDOUT[ii], pinsSCK[ii]);
    
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
