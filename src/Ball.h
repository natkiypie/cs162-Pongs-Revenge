#pragma once

#include "ofMain.h"

class Ball {

  public:
    Ball();
    void draw();
    void move();
    ofVec2f getPosition();
    void bounce();

  private:
    ofVec2f position;
    ofVec2f velocity;
    int width;
    int height;
    float degree;
    ofColor color;
};
