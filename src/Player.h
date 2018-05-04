#pragma once

#include "ofMain.h"
#include "Ball.h"

class Player {

  public:
    Player();
    void draw();
    void move();
    void up();
    void down();
    void release();
    void atBoundry();
    void rectInside(Ball* ball);

  private:
    ofVec2f position;
    int width;
    int height;
    float velocity;
    int acceleration;
    int speed;
    ofColor color;
};
