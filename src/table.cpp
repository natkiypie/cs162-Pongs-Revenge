#include "table.h"

static const int LINE_WIDTH = 4;

void tableLine(int x1, int y1, int x2, int y2) {
    ofSetColor(255, 255, 255);
    ofSetLineWidth(LINE_WIDTH);
    ofDrawLine(x1, y1, x2, y2);
}

void tableDraw(int distance) {
  tableLine(distance, distance, distance, (ofGetHeight() - distance));
  tableLine((ofGetWidth() - distance), (ofGetHeight() - distance), (ofGetWidth() - distance), distance);
  tableLine(distance, (distance + (LINE_WIDTH / 2)), (ofGetWidth() - distance), (distance + (LINE_WIDTH / 2)));
  tableLine(distance, (ofGetHeight() - (distance + (LINE_WIDTH / 2))), (ofGetWidth() - distance), (ofGetHeight() - (distance + (LINE_WIDTH / 2))));
  tableLine((ofGetWidth() / 2), distance, (ofGetWidth() / 2), (ofGetHeight() - distance));
}
