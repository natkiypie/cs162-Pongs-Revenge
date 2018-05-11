#include "Ball.h"

static const int COUNT = 50;

Ball::Ball() {
  this->position = ofVec2f((ofGetWidth()/2), (ofGetHeight()/2));
  this->speed = 12;
  this->direction = 0;
  this->velocity = ofVec2f(this->speed, this->direction);
  this->width = 10;
  this->height = 10;
  this->color = ofColor(255, 255, 255);
  this->count = COUNT;
  this->countStart = false;
  this->serve = true;
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

void Ball::setup() {
  this->color = ofColor(255, 255, 255, 0);
  this->position = ofVec2f((ofGetWidth()/2), (ofGetHeight()/2));
  this->countStart = true;
}

void Ball::countDown() {
  if (this->countStart == true) {
    this->count--;
    if (this->count <= 0) {
      this->countStart = false;
      this->count = COUNT;
    }
  }
}

void Ball::setServe() {
  if (this->serve == true) {
    this->serve = false;
  } else if (this->serve == false) {
    this->serve = true;
  }
}

void Ball::changeServe() {
  if (this->serve == true) {
    this->setPlayerServe();
  } else if (this->serve == false) {
    this->setOpponentServe();
  }
}

void Ball::setPlayerServe() {
  this->velocity = ofVec2f(this->speed, ofRandom(-3, 3));
}

void Ball::setOpponentServe() {
  this->velocity = ofVec2f(this->speed, ofRandom(-3, 3));
  this->velocity *= -1;
}

void Ball::stop() {
  this->position = ofVec2f((ofGetWidth()/2), (ofGetHeight()/2));
  this->velocity *= 0;
}

bool Ball::testOne() {
  return this->serve;
}

