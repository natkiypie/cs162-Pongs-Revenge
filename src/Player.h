#pragma once

#include "ofMain.h"

class Player {

  public:
    Player();
    void draw();
    void move();

  private:
    int x;
    int y;
    int w;
    int h;
    ofColor color;
};
