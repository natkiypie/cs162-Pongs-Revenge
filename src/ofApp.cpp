#include "ofApp.h"
#include "Menu.h"
#include "Paddle.h"
#include "Ball.h"

void ofApp::setup() {
  menu = new Menu();
  paddle = new Paddle();
  ball = new Ball();
  menu->loadFont();
  paddle->loadFont();
  ball->soundLoad();
  ofSetBackgroundColor(0, 0, 0);
}

void ofApp::update() {
  this->playUpdate();
}

void ofApp::draw() {
  if (this->state == play) {
    this->playDraw();
  } else if (this->state == title) {
    menu->printTitle();
    menu->barDraw();
    menu->printPlay();
    menu->printInstructions();
  }
}

void ofApp::keyPressed(int key) {

  if (menu->getSelection() == 0) {
    if (key == OF_KEY_RETURN) {
      this->state = play;
    } 
  } else if (menu->getSelection() == 1) {
    if (key == OF_KEY_RETURN) {
      this->state = instructions;
    }
  }

  if (this->state == title) {
    if (key == OF_KEY_DOWN) {
      menu->barDown();
    } else if (key == OF_KEY_UP) {
      menu->barUp();
    }
  } else if (this->state == play) {
    if (key == OF_KEY_UP) {
      paddle->playerUp();
    } else if (key == OF_KEY_DOWN) {
      paddle->playerDown();
    }
  }
}

void ofApp::keyReleased(int key) {
  if (key == OF_KEY_UP) {
    paddle->playerRelease();
  } else if (key == OF_KEY_DOWN) {
    paddle->playerRelease();
  }
}

void ofApp::playUpdate() {
  paddle->move();
  paddle->boundry();
  paddle->opponentInPossession(ball);
  paddle->collisionInitialize(ball);
  paddle->point(ball);
  ball->move();
  ball->bounceWall();
  ball->countDown();
}

void ofApp::playDraw() {
  for (int i = 36; i <= 732; i += 16) {
    halfCourt(i);
  }
  paddle->playerPrintScore();
  paddle->opponentPrintScore();
  paddle->draw();
  ball->draw();
}

void ofApp::halfCourt(int y) {
  ofSetLineWidth(4);
  ofSetColor(255, 255, 255);
  ofDrawLine((ofGetWidth() / 2), y, (ofGetWidth() / 2), (y + 8));
}
