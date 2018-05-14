#pragma once
#include "ofMain.h"
#include "Menu.h"
#include "Instruct.h"
#include "Paddle.h"
#include "Ball.h"

enum GameState {title, play, instructions};

class ofApp : public ofBaseApp {

	public:
    Menu* menu;
    Instruct* instruct;
    Paddle* paddle;
    Ball* ball;
		void setup();
		void update();
		void draw();
		void keyPressed(int key);
		void keyReleased(int key);
    void menuDraw();
    void instructDraw();
    void playUpdate();
    void playDraw();
    void halfCourt(int y);

  private:
    GameState state;
    ofSoundPlayer aka47;
};

