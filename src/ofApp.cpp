#include "ofApp.h"
#include "table.h"
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
}

void ofApp::draw() {
  player->draw();
  ball->draw();

  tableDraw(20);

  print_values(player);
}

void ofApp::keyPressed(int key) {
  if (key == 'a') {
    player->left();
  } else if (key == 'd') {
    player->right();
  }

  if (key == ' ') {
    player->storeAngle();
  }
}

void ofApp::keyReleased(int key) {
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
