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
    bool rectInside(ofVec2f ball);

  private:
    ofVec2f position;
    int width;
    int height;
    int speed;
    float degree;
    float ballAngle;
    ofColor color;
    ofRectangle rect;
};
