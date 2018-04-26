#include "ofApp.h"
#include "table.h"
#include "Player.h"

void ofApp::setup() {
  ofSetBackgroundColor(10, 34, 71);
  player = new Player();
}

void ofApp::update() {
  player->move();
  player->atBoundry();
}

void ofApp::draw() {
  player->draw();
  tableDraw(20);
}

void ofApp::keyPressed(int key) {
  if (key == 'a') {
    player->left();
  } else if (key == 'd') {
    player->right();
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
