#include "Instruct.h"

Instruct::Instruct() {
  this->instructX = 220;
  this->instructY = (ofGetHeight() / 4);
  this->color = ofColor(255, 255, 255);
}

void Instruct::loadFont() {
  instructFont.load("vanadine.ttf", 30, true, true, true);
}

void Instruct::printInstruct() {
  char instruct[255];
  ofSetColor(this->color);
  sprintf(instruct,"Use the arrow keys to move up and down.\nThe first player to score 11 points wins.\nDuring gameplay, press 'Q' to to quit.\nPress 'R' to return to the menu screen.");
  instructFont.drawString(instruct, this->instructX, this->instructY);
}
