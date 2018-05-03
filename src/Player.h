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
    bool rectInside(ofVec2f ball);

  private:
    ofVec2f position;
    int width;
    int height;
    float velocity;
    float acceleration;
    int speed;
    ofColor color;
    ofRectangle rect;
};
