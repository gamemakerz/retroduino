#include "gengine.h"
#include "ball.h"
class Obstacles: public Entity { 
  byte row;
  byte start;
  bool isGameOver=false;
  Ball* p_ball;
public:
  
  Obstacles(byte Row,Ball* p_ball);
  void on_init();
  void on_tick();
  void on_render(Graphics *p_g, byte value);
  void on_input(byte key, byte event);
  void on_destroy();  
};
