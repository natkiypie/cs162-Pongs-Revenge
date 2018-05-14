#include "ofApp.h"
#include "Menu.h"
#include "Instruct.h"
#include "Paddle.h"
#include "Ball.h"

void ofApp::setup() {
  aka47.load("aka47.mp3");
  aka47.play();
  menu = new Menu();
  instruct = new Instruct();
  paddle = new Paddle();
  ball = new Ball();
  menu->loadFont();
  instruct->loadFont();
  paddle->loadFont();
  ball->loadSound();
  ofSetBackgroundColor(0, 0, 0);
}

void ofApp::update() {
  if (this->state == play) {
    this->playUpdate();
  }
}

void ofApp::draw() {
  if (this->state == title) {
    this->menuDraw();
  } else if (this->state == instructions) {
    this->instructDraw();
  } else if (this->state == play) {
    this->playDraw();
  }
}

void ofApp::keyPressed(int key) {

  if (menu->getSelection() == 0) {
    if (key == OF_KEY_RETURN) {
      aka47.stop();
      this->state = play;
    } 
  } else if (menu->getSelection() == 1) {
    if (key == OF_KEY_RETURN) {
      aka47.stop();
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
    } else if (key == 'q') {
      aka47.play();
      this->state = title;
    }
  } else if (this->state == instructions) {
    if (key == 'r') {
      aka47.play();
      this->state = title;
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

void ofApp::menuDraw() {
  menu->printTitle();
  menu->barDraw();
  menu->printPlay();
  menu->printInstructions();
}

void ofApp::instructDraw() {
  instruct->printInstruct();
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
  if (paddle->getGameOver() == true) {
    aka47.play();
    this->state = title;
  }
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
