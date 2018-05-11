#pragma once

#include "ofMain.h"

class Ball {

  public:
    Ball();
    void soundLoad();
    void draw();
    void move();
    void bounceWall();
    void bouncePlayer(float dir);
    void bounceOpponent(float dir);
    void soundPlayerScore();
    void soundOpponentScore();
    float getX();
    float getY();
    ofRectangle getBoundingBox();
    void countDown();
    void center();
    void serve();
    void serveChange();

    bool test();

  private:
    ofVec2f position;
    float speed;
    float direction;
    ofVec2f velocity;
    int width;
    int height;
    ofColor color;
    ofSoundPlayer player, opponent, wall, playerScore, opponentScore, gameLose, gameWin;
    bool playerServe;
    int count;
    bool countStart;
};
