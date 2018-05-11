#include "Ball.h"

static const int COUNT_VALUE = 50;

Ball::Ball() {
  this->position = ofVec2f((ofGetWidth()/2), (ofGetHeight()/2));
  this->speed = 16;
  this->direction = 0;
  this->velocity = ofVec2f(this->speed, this->direction);
  this->width = 10;
  this->height = 10;
  this->color = ofColor(255, 255, 255);
  this->playerServe = true;
  this->count = COUNT_VALUE;
  this->countStart = false;
}

void Ball::soundLoad() {
  player.load("ping.wav");
  opponent.load("pong.wav");
  wall.load("blip.wav");
  playerScore.load("playerScore.wav");
  opponentScore.load("opponentScore.wav");
  gameLose.load("gameLose.wav");
  gameWin.load("gameWin.wav");
}

void Ball::draw() {
  ofFill();
  ofSetColor(this->color);
  ofSetRectMode(OF_RECTMODE_CENTER);
  ofDrawRectangle(this->position.x, this->position.y, this->width, this->height);
}

void Ball::move() {
  if (countStart == false) {
    this->color = ofColor(255, 255, 255, 255);
    this->position += this->velocity;
  }
}

void Ball::bounceWall() {
  if (this->position.y <= 0 || this->position.y >= ofGetHeight()) {
    this->velocity.y *= -1;
    wall.play();
  }
}

void Ball::bouncePlayer(float dir) {
  this->velocity = ofVec2f(this->speed, dir);
  player.play();
}

void Ball::bounceOpponent(float dir) {
  this->velocity = ofVec2f(this->speed, dir);
  this->velocity *= -1;
  opponent.play();
}

void Ball::soundPlayerScore() {
  playerScore.play();
}

void Ball::soundOpponentScore() {
  opponentScore.play();
}

float Ball::getX() {
  return this->position.x;
}

float Ball::getY() {
  return this->position.y;
}

ofRectangle Ball::getBoundingBox() {
  ofRectangle rect = ofRectangle(this->position.x, this->position.y, this->width, this->height);
  return rect;
}

void Ball::countDown() {
  if (this->countStart == true) {
    this->count--;
    if (this->count <= 0) {
      this->countStart = false;
      this->count = COUNT_VALUE;
    }
  }
}

void Ball::center() {
  this->position = ofVec2f((ofGetWidth()/2), (ofGetHeight()/2));
  this->serve();
}

void Ball::serve() {
  this->color = ofColor(255, 255, 255, 0);
  this->countStart = true;
  if (playerServe == true) {
    this->velocity = ofVec2f(this->speed, ofRandom(-3, 3));
  } else if (playerServe == false) {
    this->velocity = ofVec2f(this->speed, ofRandom(-3, 3));
    this->velocity *= -1;
  }
}

void Ball::serveChange() {
  if (playerServe == true) {
    playerServe = false;
  } else if (playerServe == false) {
    playerServe = true;
  }
}

bool Ball::test() {
  return this->playerServe;
}
