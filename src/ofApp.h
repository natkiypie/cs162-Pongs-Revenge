#pragma once
#include "ofMain.h"
#include "Menu.h"
#include "Paddle.h"
#include "Ball.h"

enum GameState {title, play, instructions};

class ofApp : public ofBaseApp {

	public:
    Menu* menu;
    Paddle* paddle;
    Ball* ball;
		void setup();
		void update();
		void draw();
		void keyPressed(int key);
		void keyReleased(int key);
    void halfCourt(int y);

    void menuDraw();

    void playUpdate();
    void playDraw();

  private:
    GameState state;
};

