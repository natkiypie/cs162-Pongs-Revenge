#pragma once

#include "ofMain.h"
#include "Ball.h"

class Paddle {
  
  public:
    Paddle();
    void loadFont();
    void printScorePlayer();
    void printScoreOpponent();
    void draw();
    void move();
    void upPlayer();
    void upOpponent();
    void downPlayer();
    void downOpponent();
    void boundry();
    void release();
    void center();
    void inPossession(Ball* ball);
    void track(Ball* ball, int max);
    void collisionPlayer(Ball* ball);
    void collisionOpponent(Ball* ball);
    void point(Ball* ball);

  private:
    ofVec2f positionPlayer;
    ofVec2f positionOpponent;
    int width;
    int height;
    float velocityPlayer;
    float velocityOpponent;
    int acceleration;
    int speed;
    int offset;
    int scorePlayer;
    int scoreOpponent;
    ofColor color;
    ofTrueTypeFont notoSans;
};
