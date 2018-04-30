#pragma once

class Ball {

  public:
    Ball();
    void draw();
    void move();

  private:
    int x;
    int y;
    int w;
    int h;
    ofColor color;
};
