#include "gengine.h"

void Graphics::begin() {
   lcd.begin(84, 48);
}

void Graphics::set_cell(int row, int col, int new_bit) {
  if(row >= 48 || col >= 84)
    return;
    
   int byte_index = col + 84*(row/8);
   int bit_index = row % 8;
   int bit_mask = 1 << bit_index;

   if(new_bit)
      data[byte_index] |= bit_mask; // on
   else
      data[byte_index] &= ~bit_mask; // off
}
 
int Graphics::get_cell(int row, int col) {
   int byte_index = col + 84*(row/8);
   int bit_index = row % 8;
   int bit_mask = 1 << bit_index;

   return (data[byte_index] & bit_mask)?1:0;
}

void Graphics::flush() {
   lcd.drawBitmap(data, 84, 48);
}

void Graphics::clear() {
  memset(data, 0, sizeof(data));
  lcd.clear();
}

void Graphics::text(const char *str, int row, int col) {
  lcd.setCursor(col, row);
  lcd.print(str);
}
