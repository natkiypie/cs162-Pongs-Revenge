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
    float getD();
    void storeAngle();

  private:
    int x;
    int y;
    int xt;
    int yt;
    int w;
    int h;
    int ps;
    float d;
    float ball;
    ofColor color;
};

void print_values();
