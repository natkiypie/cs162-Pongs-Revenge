#include "Player.h"

Player::Player() {
  this->position = ofVec2f(ofGetMouseX(), (ofGetHeight() - 100));
  this->width = 60;
  this->height = 8;
  this->degree = 0;
  this->speed = 8;
  this->ballAngle = 0;
  this->color = ofColor(255, 255, 255);
  this->rect = ofRectangle(this->position.x, this->position.y, this->width, this->height);
}

void Player::draw() {
  ofFill();
  ofSetColor(this->color);
  ofDrawRectangle(this->rect);
}

void Player::move() {
  this->position.x = ofGetMouseX();
}

void Player::left() {
  this->position.x -= this->speed;
}

void Player::right() {
  this->position.x += this->speed;
}

void Player::atBoundry() {
  if ((this->position.x - (this->width / 2)) <= 0) {
    this->position.x = (0 + (this->width / 2));
  } else if (this->position.x >= (ofGetWidth() - (this->width / 2))) {
    this->position.x = (ofGetWidth() - (this->width / 2));
  }
}

bool Player::rectInside(ofVec2f ball) {
  rect = ofRectangle(this->position.x, this->position.y, this->width, this->height);
  if (rect.inside(ball) == true) {
    this->color = ofColor(255, 0, 0);
    return true;
  } else {
    this->color = ofColor(255, 255, 255);
    return false;
  }
}
