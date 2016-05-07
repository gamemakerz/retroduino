#include "gengine.h"

Controls::Controls(Entity *p_player) {
  this->p_player = p_player;
}

void Controls::begin() {
   for(byte i = 0; i<KEYS_COUNT; i++) {
      pinMode(pins[i], INPUT);
      down_times[i] = 0;
      debounced_states[i]=0;
   }
}

void Controls::on_tick() {
  
  for(int i=0; i<KEYS_COUNT; i++) {

    if(digitalRead(pins[i]) == HIGH)
      down_times[i] = millis();
      
    byte new_debounced_state = is_key_down(i);
    
    if(new_debounced_state > debounced_states[i])
      p_player->on_input(i, EVENT_PRESS);
    else if(new_debounced_state < debounced_states[i])
      p_player->on_input(i, EVENT_RELEASE);
    
    debounced_states[i] = new_debounced_state;
 }
}

int Controls::is_key_down(byte key) {
   if(key < 0 || key >= KEYS_COUNT)
      return 0;

   // if the button is currently pressed or was pressed a short while ago
   return digitalRead(pins[key]) || ((millis() - down_times[key]) < BOUNCE_DELAY);
}
