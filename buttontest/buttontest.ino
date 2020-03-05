/* State change for micro switches for Door Open/Close
 * Uses serial monitor, not an LED 
 *  
 */

const int butPin = 8;
int butState = 0;
int lastbutState = 0;


void setup() {
  
  pinMode(butPin, INPUT);
  Serial.begin(9600);

}

void loop() {

  butState = digitalRead(butPin);
  Serial.println(butState);
  // delay(50);  // avoid bouncing

}


 
