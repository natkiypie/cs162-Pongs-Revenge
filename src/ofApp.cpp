#include "ofApp.h"
#include "Player.h"
#include "Opponent.h"
#include "Ball.h"
#include "Table.h"

void ofApp::setup() {
  score.load("notosans.ttf", 40, true, true, true);
  ofSetBackgroundColor(0, 0, 0);
  player = new Player();
  opponent = new Opponent();
  ball = new Ball();
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
  printScores();

  player->draw();
  opponent->draw();
  ball->draw();

  for (int i = 36; i <= 732; i += 16) {
    drawLine(i);
  }

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

void ofApp::printScores() {
  char scorePlayer[255];
  char scoreOpponent[255];

  ofSetColor(255, 255, 255);
  if (player->getScore() < 10) {
    sprintf(scorePlayer, "0%d", player->getScore());
    score.drawString(scorePlayer, (ofGetWidth() / 4), 100);
  } else {
    sprintf(scorePlayer, "%d", player->getScore());
    score.drawString(scorePlayer, (ofGetWidth() / 4), 100);
  }

  if (opponent->getScore() < 10) {
   sprintf(scoreOpponent, "0%d", opponent->getScore());
   score.drawString(scoreOpponent, (ofGetWidth() - ((ofGetWidth() / 4) + 60)), 100);
  } else {
   sprintf(scoreOpponent, "%d", opponent->getScore());
   score.drawString(scoreOpponent, (ofGetWidth() - ((ofGetWidth() / 4) + 60)), 100);
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
