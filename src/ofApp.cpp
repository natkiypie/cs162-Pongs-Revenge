#include "ofApp.h"
#include "Player.h"
#include "Ball.h"

void ofApp::setup() {
  ofSetBackgroundColor(0, 0, 0);
  player = new Player();
  ball = new Ball();
}

void ofApp::update() {
  player->move();
  player->atBoundry();
  
  ball->move();

  if (player->rectInside(ball->getBall()) == true) {
    ball->bounce();
  }

}

void ofApp::draw() {
  player->draw();
  ball->draw();

//  float dist = ofDist(player->getX(), player->getY(), ball->getX(), ball->getY());
//  ofSetColor(255, 255, 255);
//  ofDrawBitmapString("Distance: ", 40, (ofGetHeight() - 40));
//  ofDrawBitmapString(ofToString(), 40, (ofGetHeight() - 20));
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
