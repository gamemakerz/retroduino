#include "gengine.h"
#include "obstacles.h"

void Obstacles::on_init(){
  col = 20;
  row = 5;
  start = random(64);
  Serial.println(start);
}

void Obstacles::on_tick(){
  if(row >= 48){
    on_init(); 
  }
  else {
    row = row + 2;  
  }
}

void Obstacles::on_render(Graphics *p_g, byte value){ 
  for (int i = 0; i <= 20 ; i++){
      p_g->set_cell(row, start+i,value);
    }
}

void Obstacles::on_input(byte key, byte event){

}

void Obstacles::on_destroy() {
  
}
