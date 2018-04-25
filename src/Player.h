#pragma once

#include "ofMain.h"

class Player {

  public:
    Player();
    void draw();
    void move();
    void left();
    void right();
    void atBoundry();

  private:
    int x;
    int y;
    int xt;
    int yt;
    int w;
    int h;
    int ps;
    float d;
    ofColor color;
};
