#pragma once

#include "ofMain.h"
#include "Player.h"
#include "Ball.h"

class Opponent {
  
  public:
    Opponent();
    void draw();
    void move();
    void up();
    void down();
    void center();
    void atBoundry();
    void inPossession(Ball* ball, Player* player);
    void track(Ball* ball, int max);
    void collision(Ball* ball);
    int getScore();
    void point(Ball* ball);
    
  private:
    ofVec2f position;
    int width;
    int height;
    float velocity;
    int acceleration;
    int speed;
    int offset;
    int score;
    ofColor color;
};
