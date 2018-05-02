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
    float getAngle();
    void setAngle();

  private:
    ofVec2f position;
    ofVec2f translation;
    int width;
    int height;
    int size;
    float degree;
    float ball;
    ofColor color;
};

void print_values();
