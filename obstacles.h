#include "gengine.h"

class Obstacles: public Entity { 
  int row, col;
  byte start;

public:
  void on_init();
  void on_tick();
  void on_render(Graphics *p_g, byte value);
  void on_input(byte key, byte event);
  void on_destroy();  
};
