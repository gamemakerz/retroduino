#ifndef HEADER_BALL
#define HEADER_BALL

#include "gengine.h"

class Ball: public Entity {
  byte row, col;

  // -1 for left, 1 for right, 0 for Egypt
  int direction;
  
public:
  void on_init();
  void on_tick();
  void on_render(Graphics *p_g, byte value);
  void on_input(byte key, byte event);
  void on_destroy();
  byte get_col(); 
};

#endif
