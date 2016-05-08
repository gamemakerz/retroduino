#ifndef H_GENGINE
#define H_GENGINE

#include <PCD8544.h>

// Controls macros
#define BOUNCE_DELAY 50
#define KEYS_COUNT 2
#define K_LEFT 0
#define K_RIGHT 1
#define EVENT_PRESS 0
#define EVENT_RELEASE 1

class Graphics {

private:
   unsigned char data[504] = {0};
   PCD8544 lcd;

public:
   void begin();
   void set_cell(byte row, byte col, byte new_bit);
   int get_cell(byte row, byte col);
   void flush();
   void clear();
   void text(const char *str, byte row, byte col);

   unsigned char* getData() { return data; }
};

class Entity {

public:
   void on_init();
   void on_tick();
   void on_render(Graphics *p_g);
   void on_input(byte key, byte event);
};

class Controls {

   // will be notified of input events
   Entity *p_player;

   // a key-to-pin mapping
   const byte pins[KEYS_COUNT] = {11, 12};

   // last time a button was observed to be pressed
   unsigned long int down_times[KEYS_COUNT];

   // keeps track of keys that are (or were recently) pressed
   byte debounced_states[KEYS_COUNT];

public:

   Controls(Entity *p_player);

   void begin();
   void on_tick();
   int is_key_down(byte key);
};


#endif
