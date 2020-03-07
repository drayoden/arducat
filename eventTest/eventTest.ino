#include <Eventually.h>

/*
 * TURN ON POWER SUPPLY!
 * Button (momentary) Toggles LED blinking -> HIGH/LOW
 * 
 */
 
#define LIGHT_PIN 7
#define BUTTON_PIN 2

bool speed = LOW;
EvtManager mgr;
bool pin_state = LOW;

bool blink() {
  pin_state = !pin_state;
  digitalWrite(LIGHT_PIN, pin_state);
  return false;
}

bool set_speed() {
  mgr.resetContext();
  // mgr.addListener(new EvtPinListener(BUTTON_PIN, 1000, (EvtAction)set_speed)); // second arg is dbounce - time to wait(ms) before the pin is read.
  mgr.addListener(new EvtPinListener(BUTTON_PIN, (EvtAction)set_speed));
  speed = !speed; // Change speeds
  Serial.println(speed);
  if(speed == HIGH) {
    mgr.addListener(new EvtTimeListener(100, true, (EvtAction)blink));
  } else {
    mgr.addListener(new EvtTimeListener(1000, true, (EvtAction)blink));
  }

  return true;
}

void setup() {
  pinMode(LIGHT_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
  set_speed();
  Serial.begin(9600);
}

USE_EVENTUALLY_LOOP(mgr);
