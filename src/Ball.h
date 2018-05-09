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
    void soundPlayer();
    void soundOpponent();
    void soundWall();
    void soundWin();
    void soundLose();
    float getX();
    float getY();
    ofRectangle getBoundingBox();
    void setVelocity();
    void setCountStart();
    void countDown();
    int getCount();

  private:
    ofVec2f position;
    float speed;
    float direction;
    ofVec2f velocity;
    int width;
    int height;
    ofColor color;
    ofSoundPlayer player, opponent, wall, win, lose;

    int count;
    bool countStart;
};
