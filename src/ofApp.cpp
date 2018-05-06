#include "ofApp.h"
#include "Player.h"
#include "Opponent.h"
#include "Ball.h"

void ofApp::setup() {
  ofSetBackgroundColor(0, 0, 0);
  player = new Player();
  opponent = new Opponent();
  ball = new Ball();
}

void ofApp::update() {
  player->move();
  player->atBoundry();
  player->rectInside(ball);

  opponent->move();
  opponent->atBoundry();
  opponent->rectInside(ball);
  opponent->inPossession(ball);

  ball->move();
}

void ofApp::draw() {
  player->draw();
  opponent->draw();
  ball->draw();

//  ofSetColor(255, 255, 255);
//  ofDrawBitmapString("Position: ", 40, (ofGetHeight() - 40));
//  ofDrawBitmapString(ofToString(opponent->thisPosition()), 40, (ofGetHeight() - 20));
}

void ofApp::keyPressed(int key) {
  if (key == OF_KEY_UP) {
    player->up();
  } else if (key == OF_KEY_DOWN) {
    player->down();
  }
}

void ofApp::keyReleased(int key) {
  if (key == OF_KEY_UP) {
    player->release();
  } else if (key == OF_KEY_DOWN) {
    player->release();
  }
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
