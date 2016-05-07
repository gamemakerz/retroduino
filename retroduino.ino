#include <PCD8544.h>
#include "gengine.h"

static Graphics g;

void setup() {
}

void loop() {
  
  g.text("Hello, world!", 0, 0);
  delay(3000);
  g.flush();
}
