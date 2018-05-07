#pragma once

#include "ofMain.h"

class Ball {

  public:
    Ball();
    void draw();
    void move();
    void bounce(float dir, int vel);
    float getX();
    float getY();
    ofRectangle getBall();

  private:
    ofVec2f position;
    float speed;
    float direction;
    ofVec2f velocity;
    int width;
    int height;
    ofColor color;
};
