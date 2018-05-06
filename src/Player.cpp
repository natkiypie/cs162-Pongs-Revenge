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
  ofRectangle rect = ofRectangle(this->position.x, this->position.y, this->width, this->height);
  if (rect.intersects(ball->getBall()) == true) {
    ball->bounce();
  }
}
