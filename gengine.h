#ifndef H_GENGINE
#define H_GENGINE

#include <PCD8544.h>

// Controls macros
#define BOUNCE_DELAY 50
#define KEYS_COUNT 2
#define K_LEFT 0
#define K_RIGHT 1

class Graphics {

private:
   unsigned char data[504] = {0};
   PCD8544 lcd;

public:
   void begin();
   void set_cell(int row, int col, int new_bit);
   int get_cell(int row, int col);
   void flush();
   void clear();
   void text(const char *str, int row, int col);

   unsigned char* getData() { return data; }
};

class Controls {
private:
   // a key-to-pin mapping
   const short pins[KEYS_COUNT] = {11, 12};
   
   // last time a button was observed to be pressed
   unsigned long int down_times[KEYS_COUNT];

public:

   void begin();
   void on_tick();
   int is_key_down(short key);
};

#endif
