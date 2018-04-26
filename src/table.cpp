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
  tableLine((distance - (LINE_WIDTH / 2)), (distance + (LINE_WIDTH / 2)), (ofGetWidth() - (distance - (LINE_WIDTH / 2))), (distance + (LINE_WIDTH / 2)));
  tableLine((distance - (LINE_WIDTH / 2)), (ofGetHeight() - (distance + (LINE_WIDTH / 2))), (ofGetWidth() - distance + (LINE_WIDTH / 2)), (ofGetHeight() - (distance + (LINE_WIDTH / 2))));
  tableLine((ofGetWidth() / 2), (distance + LINE_WIDTH), (ofGetWidth() / 2), (ofGetHeight() - (distance + LINE_WIDTH)));
}
