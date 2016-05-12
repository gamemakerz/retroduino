#include <PCD8544.h>
#include "gengine.h"
#include "ball.h"
#include "obstacles.h"

#define MS_PER_FRAME (5)

static Ball ball;
static Obstacles obt1(0, &ball);
static Obstacles obt2(15, &ball);
static Obstacles obt3(30, &ball);
static Graphics g;
static Controls c(&ball);

void setup() {
   Serial.begin(9600);
   randomSeed(analogRead(0));
   g.begin();
   c.begin();
   g.text("RETRODUINO",1,10);
   while (true) {
    if (c.is_key_down(K_LEFT)||c.is_key_down(K_RIGHT) ) {
        break;
     }
   }
   
   g.clear();

   // init all entities
   ball.on_init();
}

void loop() {
  unsigned long int last_tick = 0;

  // GAME LOOP
  while(true) {
    c.on_cycle();

    // if the last tick is too old
    if(millis() - last_tick > MS_PER_FRAME) {

      // clear screen by unrendering all entities
      /*
      ball.on_render(&g, 0);
      obt1.on_render(&g, 0);
      obt2.on_render(&g, 0);
      obt3.on_render(&g, 0);
      */
      g.clear();
      
      // tick all entities
      ball.on_tick();
      obt1.on_tick();
      obt2.on_tick();
      obt3.on_tick();
      // render all entities
      ball.on_render(&g, 1);
      obt1.on_render(&g, 1);
      obt2.on_render(&g, 1);
      obt3.on_render(&g, 1);

      g.flush();
      // keep track when the last tick was executed
      last_tick = millis();
    }
  }
}

