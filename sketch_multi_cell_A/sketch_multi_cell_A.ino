#include <HX711.h>

int pinsDOUT[4] = {1,3,5,7}; 
//The pins hooked up to the respective cells' DOUT

int pinsSCK[4] = {2,4,6,8};
//The pins hooked up to the respective cells' SCK

float calibrations[4] = {-10000, -10000, -10000, -10000};
//The initial calibration factors for the cells
//HX711 fnord = scale(1,2);
//HX711 allCells[] = {scale1(1,2), scale2(3,4), scale3(5,6), scale4(7,8)};
HX711 allCells[4]; 

void setup() {
  for(int ii=0; ii<4; ii++){
    allCells[ii] = HX711(pinsDOUT[ii], pinsSCK[ii]);
    
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
