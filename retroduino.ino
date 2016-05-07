#include <PCD8544.h>
#include "gengine.h"

static Graphics g;
static Controls c;

void setup() {
  Serial.begin(9600);
  g.begin();
  c.begin();
}

void loop() {

}

