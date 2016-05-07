#include "gengine.h"

void Controls::begin() {
   for(int i = 0; i<KEYS_COUNT; i++) {
      pinMode(pins[i], INPUT);
      down_times[i] = 0;
   }
}

void Controls::on_tick() {
   for(int i=0; i<KEYS_COUNT; i++)
      if(digitalRead(pins[i]) == HIGH)
         down_times[i] = millis();
}

int Controls::is_key_down(short key) {
   if(key < 0 || key >= KEYS_COUNT)
      return 0;

  Serial.println(millis() - down_times[key]);
   return (millis() - down_times[key]) < BOUNCE_DELAY;
}
