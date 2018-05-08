#include "ofApp.h"
#include "Player.h"
#include "Opponent.h"
#include "Ball.h"

void ofApp::setup() {
//  score.load("notosans.ttf", 40, true, true, true);
  ofSetBackgroundColor(0, 0, 0);
  player = new Player();
  opponent = new Opponent();
  ball = new Ball();

  player->loadFont();
  opponent->loadFont();
}

void ofApp::update() {
  player->move();
  player->atBoundry();
  player->collision(ball);
  player->point(ball);

  opponent->move();
  opponent->atBoundry();
  opponent->inPossession(ball, player);
  opponent->collision(ball);
  opponent->point(ball);

  ball->move();
}

void ofApp::draw() {
  for (int i = 36; i <= 732; i += 16) {
    halfCourt(i);
  }

  player->printScore();
  player->draw();

  opponent->printScore();
  opponent->draw();

  ball->draw();

//  ofSetColor(255, 255, 255);
//  ofDrawBitmapString("Player Y: ", 40, (ofGetHeight() - 40));
//  ofDrawBitmapString(ofToString(score.getGlyphBBox()), 40, (ofGetHeight() - 20));
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
