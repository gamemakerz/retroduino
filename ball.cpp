#include "gengine.h"
#include "ball.h"

void Ball::on_init() {
  row = 44;
  col = 10;
  direction = 0;
}

void Ball::on_tick() {
  col += 6*direction;
  if(col >= 80)
  {
    col = 80;
  }
  else if (col <=8)
  {
    col = 8;
  }
}

void Ball::on_render(Graphics *p_g, byte value) {
  for(int r = -2; r <=2; r++) {
    for(int c = -2; c<=2; c++) {
      p_g->set_cell(row+r, col+c, value);
      
    }
  }
}

void Ball::on_input(byte key, byte event) {
  if(key == K_LEFT && event == EVENT_PRESS)
    direction = -1;
  else if(key == K_RIGHT && event == EVENT_PRESS)
    direction = 1;
}

void Ball::on_destroy () {
  
}
byte Ball::get_col()
{
  return col;
}

