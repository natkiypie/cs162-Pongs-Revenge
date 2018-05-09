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
  paddle->inPossession(ball);
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
  paddle->printScorePlayer();
  paddle->printScoreOpponent();
  paddle->draw();
  ball->draw();

  ofSetColor(255, 255, 255);
  ofDrawBitmapString("Count: ", 40, (ofGetHeight() - 40));
  ofDrawBitmapString(ofToString(ball->getCount()), 40, (ofGetHeight() - 20));
}

void ofApp::keyPressed(int key) {
  if (key == OF_KEY_UP) {
    paddle->upPlayer();
  } else if (key == OF_KEY_DOWN) {
    paddle->downPlayer();
  }
}

void ofApp::keyReleased(int key) {
  if (key == OF_KEY_UP) {
    paddle->release();
  } else if (key == OF_KEY_DOWN) {
    paddle->release();
  }
}

void ofApp::halfCourt(int y) {
  ofSetLineWidth(4);
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
