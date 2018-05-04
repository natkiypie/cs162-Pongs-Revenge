#pragma once

#include "ofMain.h"
#include "Ball.h"

class Opponent {
  
  public:
    Opponent();
    void draw();
    void move();
    void release();
    void atBoundry();
    bool rectInside(ofRectangle ball);
    void track(Ball* ball);
    
  private:
    ofVec2f position;
    int width;
    int height;
    float velocity;
    int acceleration;
    int speed;
    ofColor color;
};
