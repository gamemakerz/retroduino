#include "gengine.h"

void Graphics::begin() {
   lcd.begin(84, 48);
}

void Graphics::set_cell(byte row, byte col, byte new_bit) {
   if(row >= 48 || col >= 84)
      return;

   int byte_index = col + 84*(row/8);
   int bit_index = row % 8;
   int bit_mask = 1 << bit_index;

   if(new_bit)
      data[byte_index] |= bit_mask; // on
   else
      data[byte_index] &= ~bit_mask; // off

   lcd.setCursor(col, row/8);
   unsigned char bitmap[] = {data[byte_index]};
   lcd.drawBitmap(bitmap, 1, 1);
}

int Graphics::get_cell(byte row, byte col) {
   int byte_index = col + 84*(row/8);
   int bit_index = row % 8;
   int bit_mask = 1 << bit_index;

   return (data[byte_index] & bit_mask)?1:0;
}

void Graphics::flush() {
  lcd.setCursor(0, 0);
  lcd.drawBitmap(data, 84, 48);
}

void Graphics::clear() {
   memset(data, 0, sizeof(data));
   lcd.clear();
}

void Graphics::text(const char *str, byte row, byte col) {
   lcd.setCursor(col, row);
   lcd.print(str);
}
