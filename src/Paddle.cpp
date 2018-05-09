#include "Paddle.h"

Paddle::Paddle() {
  this->positionPlayer = ofVec2f(100, (ofGetHeight() / 2));
  this->positionOpponent = ofVec2f((ofGetWidth() - 100), (ofGetHeight() / 2));
  this->width = 10;
  this->height = 60;
  this->velocityPlayer = 0;
  this->velocityOpponent = 0;
  this->acceleration = 6;
  this->speed = 6;
  this->offset = 3;
  this->scorePlayer = 0;
  this->scoreOpponent = 0;
  this->color = ofColor(255, 255, 255);
}

void Paddle::loadFont() {
  notoSans.load("notoSans.ttf", 40, true, true, true);
}

void Paddle::printScorePlayer() {
  char score[255];
  if (this->scorePlayer < 10) {
    sprintf(score, "0%d", this->scorePlayer);
    notoSans.drawString(score, (ofGetWidth() / 4), 100);
  } else {
    sprintf(score, "%d", this->scorePlayer);
    notoSans.drawString(score, (ofGetWidth() / 4), 100);
  }
}

void Paddle::printScoreOpponent() {
  char score[255];
  if (this->scoreOpponent < 10) {
   sprintf(score, "0%d", this->scoreOpponent);
   notoSans.drawString(score, (ofGetWidth() - ((ofGetWidth() / 4) + 60)), 100);
  } else {
   sprintf(score, "%d", this->scoreOpponent);
   notoSans.drawString(score, (ofGetWidth() - ((ofGetWidth() / 4) + 60)), 100);
  }
}

void Paddle::draw() {
  ofFill();
  ofSetColor(this->color);
  ofSetRectMode(OF_RECTMODE_CENTER);
  ofDrawRectangle(this->positionPlayer.x, this->positionPlayer.y, this->width, this->height);
  ofDrawRectangle(this->positionOpponent.x, this->positionOpponent.y, this->width, this->height);
}

void Paddle::move() {
  this->positionPlayer.y += this->velocityPlayer;
  this->velocityPlayer *= 0.99;
  this->positionOpponent.y += this->velocityOpponent;
  this->velocityOpponent *= 0.99;
}

void Paddle::upPlayer() {
  this->velocityPlayer -= this->acceleration;
  if(this->velocityPlayer <= -(this->speed)) {
    this->velocityPlayer = -(this->speed);
  }
}

void Paddle::upOpponent() {
  this->velocityOpponent -= this->acceleration;
  if(this->velocityOpponent <= -(this->speed)) {
    this->velocityOpponent = -(this->speed);
  }
}

void Paddle::downPlayer() {
  this->velocityPlayer += this->acceleration;
  if(this->velocityPlayer >= this->speed) {
    this->velocityPlayer = this->speed;
  }
}

void Paddle::downOpponent() {
  this->velocityOpponent += this->acceleration;
  if(this->velocityOpponent >= this->speed) {
    this->velocityOpponent = this->speed;
  }
}

void Paddle::boundry() {
  if ((this->positionPlayer.y - (this->height / 2)) <= 0) {
    this->positionPlayer.y = (0 + (this->height / 2));
  } else if (this->positionPlayer.y >= (ofGetHeight() - (this->height / 2))) {
    this->positionPlayer.y = (ofGetHeight() - (this->height / 2));
  } else if ((this->positionOpponent.y - (this->height / 2)) <= 0) {
    this->positionOpponent.y = (0 + (this->height / 2));
  } else if (this->positionOpponent.y >= (ofGetHeight() - (this->height / 2))) {
    this->positionOpponent.y = (ofGetHeight() - (this->height / 2));
  }
}

void Paddle::release() {
  this->velocityPlayer = 0;
}

void Paddle::center() {
  if (this->positionOpponent.y <= ((ofGetHeight() / 2) - this->offset)) {
    this->downOpponent();
  } else if (this->positionOpponent.y >= ((ofGetHeight() / 2) + this->offset)) {
    this->upOpponent();
  } else {
    this->velocityOpponent = 0;
  }
}

void Paddle::inPossession(Ball* ball) {
  if (ball->getX() >= (ofGetWidth() / 4) && this->positionPlayer.y < this->positionOpponent.y) {
    this->track(ball, -40);
  } else if (ball->getX() >= (ofGetWidth() / 4) && this->positionPlayer.y > this->positionOpponent.y) {
    this->track(ball, 40);
  } else if (ball->getX() >= (ofGetWidth() / 4) && this->positionPlayer.y == this->positionOpponent.y) {
    this->track(ball, 0);
  } else {
    this->center();
  }
}

void Paddle::track(Ball* ball, int max) {
  float direction = ((ball->getY() + ofRandom(0, max)) - this->positionOpponent.y);
  float distance = ofDist(this->positionOpponent.x, this->positionOpponent.y, ball->getX(), ball->getY());
  direction /= distance;
  this->velocityOpponent += direction *= this->acceleration;
  if(this->velocityOpponent <= -(this->speed)) {
    this->velocityOpponent = -(this->speed);
  } else if(this->velocityOpponent >= this->speed) {
    this->velocityOpponent = this->speed;
  }
}

void Paddle::collisionInitialize(Ball* ball) {
  this->collision(ball, 2.5, 5, -8);
  this->collision(ball, 10, 10, -3);
  this->collision(ball, 20, 10, -0.5);
  this->collision(ball, 30, 10, 0);
  this->collision(ball, 40, 10, 0.5);
  this->collision(ball, 50, 10, 3);
  this->collision(ball, 57.5, 5, 8);
}

void Paddle::collision(Ball* ball, float r, int n, float s) {
  ofRectangle rectPlayer = ofRectangle(this->positionPlayer.x, ((this->positionPlayer.y - (this->height / 2)) + r), this->width, n);
  ofRectangle rectOpponent = ofRectangle(this->positionOpponent.x, ((this->positionOpponent.y - (this->height / 2)) + r), this->width, n);
  if (rectPlayer.intersects(ball->getBoundingBox()) == true) {
    ball->bouncePlayer(s);
  } else if (rectOpponent.intersects(ball->getBoundingBox()) == true) {
    ball->bounceOpponent(-s);
  }
}

void Paddle::point(Ball* ball) {
  if (ball->getX() >= ofGetWidth()) {
    ball->setCountStart();
    ball->setVelocity();
    ball->soundWin();
    this->scorePlayer++;
  } else if (ball->getX() <= 0) {
    ball->setCountStart();
    ball->setVelocity();
    this->scoreOpponent++;
    ball->soundLose();
  }
}

