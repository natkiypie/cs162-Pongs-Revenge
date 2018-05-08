#pragma once

#include "ofMain.h"

class Ball {

  public:
    Ball();
    void draw();
    void move();
    void bouncePlayer(float dir);
    void bounceOpponent(float dir);
    float getX();
    float getY();
    ofRectangle getBall();
    void soundLoad();
    void soundPlayer();
    void soundOpponent();
    void soundWall();
    void soundWin();
    void soundLose();

  private:
    ofVec2f position;
    float speed;
    float direction;
    ofVec2f velocity;
    int width;
    int height;
    ofColor color;
    ofSoundPlayer player, opponent, wall, win, lose;
};
