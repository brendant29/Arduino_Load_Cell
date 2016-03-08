#include <HX711.h>

#define scaleCount 4
//how many load cells are hooked up

int pinsDOUT[scaleCount] = {1,3,5,7}; 
//The pins hooked up to the respective cells' DOUT

int pinsSCK[scaleCount] = {2,4,6,8};
//The pins hooked up to the respective cells' SCK

float calibrations[scaleCount] = {-10000, -10000, -10000, -10000};
//The initial calibration factors for the cells

// How often do we do readings?
 long time = 0; //
 int timeBetweenReadings = 2000; // How often we want a reading (ms)

HX711 *allCells[scaleCount] = {NULL, NULL, NULL, NULL}; 

void setup() {
  for(int ii=0; ii<scaleCount; ii++){
    allCells[ii] = new HX711(pinsDOUT[ii], pinsSCK[ii]);
    allCells[ii]->set_scale(calibrations[ii]);
    allCells[ii]->tare();
  }
  Serial.begin(9600);
}

void loop() {
  // Is it time to print?
   if(millis() > time + timeBetweenReadings){

    //read each scale
    for(int ii=0; ii<scaleCount; ii++){
      Serial.print("Cell ");
      Serial.print(ii);
      Serial.println(": ");
      Serial.print(allCells[ii]->get_units()); //the actual reading
      Serial.println(" units");
    }
    time = millis();
   }

}
