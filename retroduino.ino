#include <PCD8544.h>
#include "gengine.h"

static Graphics g;
static Controls c(NULL);

void setup() {
   Serial.begin(9600);
   g.begin();
   c.begin();
}

int pos = 0;

unsigned long int last_tick = 0;
unsigned long int last_repaint = 0;

void loop() {
   c.on_tick();
   g.set_cell(20, pos, 0);

   if(millis() - last_tick > 25) {
      if(c.is_key_down(K_RIGHT))
         pos++;

      last_tick = millis();
   }

   g.set_cell(20, pos, 1);

   if(millis() - last_repaint > 100) {
      g.flush();
      last_repaint = millis();
   }
}

