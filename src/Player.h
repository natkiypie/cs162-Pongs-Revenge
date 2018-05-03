#pragma once

#include "ofMain.h"

class Player {

  public:
    Player();
    void draw();
    void move();
    void up();
    void down();
    void release();
    void atBoundry();
    bool rectInside(ofRectangle ball);

  private:
    ofVec2f position;
    int width;
    int height;
    float velocity;
    int acceleration;
    int speed;
    ofColor color;
};
