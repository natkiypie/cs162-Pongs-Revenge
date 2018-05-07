#include "Player.h"

Player::Player() {
  this->position = ofVec2f(100, (ofGetHeight() / 2));
  this->width = 10;
  this->height = 60;
  this->velocity = 0;
  this->acceleration = 6;
  this->speed = 6;
  this->color = ofColor(255, 255, 255);
}

void Player::draw() {
  ofFill();
  ofSetColor(this->color);
  ofSetRectMode(OF_RECTMODE_CENTER);
  ofDrawRectangle(this->position.x, this->position.y, this->width, this->height);
}

void Player::move() {
  this->position.y += this->velocity;
  this->velocity *= 0.99;
}

void Player::up() {
  this->velocity -= this->acceleration;
  if(this->velocity <= -(this->speed)) {
    this->velocity = -(this->speed);
  }
}

void Player::down() {
  this->velocity += this->acceleration;
  if(this->velocity >= this->speed) {
    this->velocity = this->speed;
  }
}

void Player::release() {
  this->velocity = 0;
}

void Player::atBoundry() {
  if ((this->position.y - (this->height / 2)) <= 0) {
    this->position.y = (0 + (this->height / 2));
  } else if (this->position.y >= (ofGetHeight() - (this->height / 2))) {
    this->position.y = (ofGetHeight() - (this->height / 2));
  }
}

void Player::rectInside(Ball* ball) {
  ofRectangle segOne = ofRectangle(this->position.x, ((this->position.y - (this->height / 2)) + 6), this->width, 12);
  ofRectangle segTwo = ofRectangle(this->position.x, ((this->position.y - (this->height / 2)) + 18), this->width, 12);
  ofRectangle segThree = ofRectangle(this->position.x, ((this->position.y - (this->height / 2)) + 30), this->width, 12);
  ofRectangle segFour = ofRectangle(this->position.x, ((this->position.y - (this->height / 2)) + 42), this->width, 12);
  ofRectangle segFive = ofRectangle(this->position.x, ((this->position.y - (this->height / 2)) + 54), this->width, 12);

  if (segOne.intersects(ball->getBall()) == true) {
    ball->bounce(-3, -1);
  } else if (segTwo.intersects(ball->getBall()) == true) {
    ball->bounce(-0.5, -1);
  } else if (segThree.intersects(ball->getBall()) == true) {
    ball->bounce(0, -1);
  } else if (segFour.intersects(ball->getBall()) == true) {
    ball->bounce(0.5, -1);
  } else if (segFive.intersects(ball->getBall()) == true) {
    ball->bounce(3, -1);
  }
}

float Player::getY() {
  return this->position.y;
}

void drawLine(int y) {
  ofSetLineWidth(4);
  ofDrawLine((ofGetWidth() / 2), y, (ofGetWidth() / 2), (y + 8));
}
