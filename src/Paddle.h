#pragma once

#include "ofMain.h"
#include "Ball.h"

class Paddle {
  
  public:
    Paddle();
    void loadFont();
    void playerPrintScore();
    void opponentPrintScore();
    void draw();
    void move();
    void playerUp();
    void opponentUp();
    void playerDown();
    void opponentDown();
    void boundry();
    void playerRelease();
    void opponentCenter();
    void opponentInPossession(Ball* ball);
    void opponentTrack(Ball* ball, int max);
    void collisionInitialize(Ball* ball);
    void collision(Ball* ball, float r, int n, float s);
    void point(Ball* ball);
    void setServe(Ball* ball);
    void gameEnd(Ball* ball);
    void gamePoint(Ball* ball);
    void gameOver(Ball* ball);

    int testOne();
    float testTwo();

  private:
    ofVec2f playerPosition;
    ofVec2f opponentPosition;
    int width;
    int height;
    float playerVelocity;
    float opponentVelocity;
    int acceleration;
    int speed;
    int opponentOffset;
    int playerScore;
    int opponentScore;
    ofColor color;
    ofTrueTypeFont notoSans;
};
