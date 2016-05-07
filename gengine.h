#ifndef H_GENGINE
#define H_GENGINE

#include <PCD8544.h>

class Graphics {

private:
   unsigned char data[504] = {0};
   PCD8544 lcd;

public:
   Graphics();
   void set_cell(int row, int col, int new_bit);
   int get_cell(int row, int col);
   void flush();
   void clear();
   void text(const char *str, int row, int col);

   unsigned char* getData() { return data; }
};

#endif
