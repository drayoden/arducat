/* State change for micro switches for Door Open/Close
 * Uses serial monitor, not an LED 
 *  
 */

const int dOpin = 8;
const int dCpin = 2;

int dOst = 0;
int dCst = 0;

void setup() {
  
  pinMode(dOpin, INPUT);
  pinMode(dCpin, INPUT);
  Serial.begin(9600);

}

void loop() {

  dOst = digitalRead(dOpin);
  dCst = digitalRead(dCpin);

  Serial.print("Door Open - ");
  Serial.println(dOst);
  Serial.print("Door Closed - ");
  Serial.println(dCst);
  
  // delay(50);  // avoid bouncing

}


 
