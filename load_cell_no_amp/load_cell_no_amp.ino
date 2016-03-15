float analogValueAverage = 0;
float sum = 0;
// How often do we do readings?
long timex = 0; //
const int timeBetweenPrintings = 5000; // We want a reading every 5000 ms;
const int readsPerPrint = 200;
float reads[readsPerPrint];
int readsSoFar = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("loaded");
}

void loop() {
  float analogValue = (analogRead(0)-analogRead(1));
  
  // running average - We smooth the readings a little bit
  if(millis() - timex > readsSoFar*timeBetweenPrintings/readsPerPrint && readsSoFar < readsPerPrint){
    reads[readsSoFar++] = analogValue;
  }
  
  // Is it time to print?
  //if(millis() - timex > timeBetweenPrintings){
  if(millis() > timex + timeBetweenPrintings){
    sum = 0;
    for(int ii=0; ii<readsPerPrint; ii++){
      sum += reads[ii];
    }
    analogValueAverage = sum/readsPerPrint;
    float offsetValue = analogValueAverage - 0.98;
    float correctedValue = offsetValue*20/2.87;
    Serial.println();
    Serial.println(correctedValue);
    //Serial.println(offsetValue);
    //Serial.println(analogValueAverage);
    timex = millis();
    readsSoFar = 0;
  }
}
