#include "Table.h"

void drawLine(int y) {
  ofSetLineWidth(4);
  ofDrawLine((ofGetWidth() / 2), y, (ofGetWidth() / 2), (y + 8));
}
