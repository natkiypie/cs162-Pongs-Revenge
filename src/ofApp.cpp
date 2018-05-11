#include "ofApp.h"
#include "Paddle.h"
#include "Ball.h"

void ofApp::setup() {
  paddle = new Paddle();
  ball = new Ball();
  paddle->loadFont();
  ball->soundLoad();
  ofSetBackgroundColor(0, 0, 0);
}

void ofApp::update() {
  paddle->move();
  paddle->boundry();
  paddle->opponentInPossession(ball);
  paddle->collisionInitialize(ball);
  paddle->point(ball);

  ball->move();
  ball->bounceWall();
  ball->countDown();
}

void ofApp::draw() {
  for (int i = 36; i <= 732; i += 16) {
    halfCourt(i);
  }
  paddle->playerPrintScore();
  paddle->opponentPrintScore();
  paddle->draw();
  ball->draw();

//  //testOne
//  ofSetColor(255, 255, 255);
//  ofDrawBitmapString("Serve: ", 20, (ofGetHeight() - 20));
//  ofDrawBitmapString(ofToString(ball->testOne()), 80, (ofGetHeight() - 20));
//
//  //testTwo
//  ofSetColor(255, 255, 255);
//  ofDrawBitmapString("Modulus: ", 100, (ofGetHeight() - 20));
//  ofDrawBitmapString(ofToString(paddle->testTwo()), 180, (ofGetHeight() - 20));
}

void ofApp::keyPressed(int key) {
  if (key == OF_KEY_UP) {
    paddle->playerUp();
  } else if (key == OF_KEY_DOWN) {
    paddle->playerDown();
  }
}

void ofApp::keyReleased(int key) {
  if (key == OF_KEY_UP) {
    paddle->playerRelease();
  } else if (key == OF_KEY_DOWN) {
    paddle->playerRelease();
  }
}

void ofApp::halfCourt(int y) {
  ofSetLineWidth(4);
  ofSetColor(255, 255, 255);
  ofDrawLine((ofGetWidth() / 2), y, (ofGetWidth() / 2), (y + 8));
}

void ofApp::mouseMoved(int x, int y ) {
}

void ofApp::mouseDragged(int x, int y, int button) {
}

void ofApp::mousePressed(int x, int y, int button) {
}

void ofApp::mouseReleased(int x, int y, int button) {
}

void ofApp::mouseEntered(int x, int y) {
}

void ofApp::mouseExited(int x, int y) {
}

void ofApp::windowResized(int w, int h) {
}

void ofApp::gotMessage(ofMessage msg) {
}

void ofApp::dragEvent(ofDragInfo dragInfo) { 
}
