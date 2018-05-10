#include "Ball.h"

static const int COUNT_VALUE = 180;

Ball::Ball() {
  this->position = ofVec2f((ofGetWidth()/2), (ofGetHeight()/2));
  this->speed = 10;
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
  this->player.load("ping.wav");
  this->opponent.load("pong.wav");
  this->wall.load("blip.wav");
  this->playerScore.load("playerScore.wav");
  this->opponentScore.load("opponentScore.wav");
  this->gameLose.load("gameLose.wav");
  this->gameWin.load("gameWin.wav");
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
    this->wall.play();
  }
}

void Ball::bouncePlayer(float dir) {
  this->velocity = ofVec2f(this->speed, dir);
  this->player.play();
}

void Ball::bounceOpponent(float dir) {
  this->velocity = ofVec2f(this->speed, dir);
  this->velocity *= -1;
  this->opponent.play();
}

void Ball::soundPlayerScore() {
  this->playerScore.play();
}

void Ball::soundOpponentScore() {
  this->opponentScore.play();
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
  if (this->playerServe == true) {
    this->playerServe = false;
  } else if (playerServe == false) {
    this->playerServe = true;
  }
}
