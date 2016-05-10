#include <PCD8544.h>
#include "gengine.h"
#include "ball.h"

#define MS_PER_FRAME (100)

static Ball ball;
static Graphics g;
static Controls c(&ball);

void setup() {
   Serial.begin(9600);
   g.begin();
   c.begin();
   g.text("RETRODUINO",1,10);
   while (true){
    if (c.is_key_down(K_LEFT)||c.is_key_down(K_RIGHT) ){
      
      break;
      
      }
    
    }
   g.clear();

   // init all entities
   ball.on_init();
}

unsigned long int last_tick = 0;
unsigned long int last_repaint = 0;

void loop() {

  unsigned long int last_tick = 0;

  // GAME LOOP
  while(true) {
    c.on_cycle();

    // if the last tick it too old
    if(millis() - last_tick > MS_PER_FRAME) {

      // clear screen by unrendering all entities
      ball.on_render(&g, 0);
      
      // tick all entities
      ball.on_tick();

      // render all entities
      ball.on_render(&g, 1);

      // keep track when the last tick was executed
      last_tick = millis();
    }
  }
}

