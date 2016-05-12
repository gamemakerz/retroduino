#include "gengine.h"
#include "obstacles.h"
void(*resetFunc)(void)=0;
Obstacles::Obstacles(byte Row,Ball* p_ball)
{
  this->p_ball =p_ball;
 row = Row;
 //on_init(); 
 start = random(64);
   time_before = millis();
}
void Obstacles::on_init(){
  //col = 20;
  row = 5;
  start = random(64);

}

void Obstacles::on_tick(){
  if(row >= 48){
    on_init(); 
  }
  else {
    row = row + 2;  
  }
  byte ballcol = p_ball->get_col();
  if(row == 47||row == 46||row==45||row ==44||row == 43)
  {
    if((start <= ballcol-2 && start+20 >= ballcol-2) || (start <= ballcol+2 && start+20 >= ballcol+2))
    {
      isGameOver = true;
      
      
    }
  }

}

void Obstacles::on_render(Graphics *p_g, byte value){ 
  for (int i = 0; i <= 20 ; i++){
    if(isGameOver == true)
    {
      //p_g->clear();
      time_after= millis();
      int score = (time_after - time_before)/1000;
      p_g->text("GAME OVER!",1,10);
      char buffer[25];
      sprintf(buffer, "Score: %d", score);
      
      p_g->text(buffer,3,10);
     
      delay(4000);
      resetFunc();
    }
      /*if(value==1)
      {
        if(p_g->get_cell(row,start+i)==1)
        {
          p_g->clear();
          p_g->text("GAME OVER!",1,10);
          delay(4000);
          resetFunc();     
        }
      }*/
      p_g->set_cell(row, start+i,value);
      p_g->set_cell(row - 1, start+i,value);
    
      
    }
}

void Obstacles::on_input(byte key, byte event){

}

void Obstacles::on_destroy() {
  
}
