#pragma once
#include "ofMain.h"

class Instruct {

  public:
    Instruct();
    void loadFont();
    void printInstruct();

  private:
    int instructX;
    int instructY;
    ofColor color;
    ofTrueTypeFont instructFont;
};
