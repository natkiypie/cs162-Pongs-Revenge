#include "Opponent.h"

Opponent::Opponent() {
  this->position = ofVec2f((ofGetWidth() - 100), (ofGetHeight() / 2));
  this->width = 10;
  this->height = 60;
  this->velocity = 0;
  this->acceleration = 6;
  this->speed = 6;
  this->color = ofColor(255, 255, 255);
}

void Opponent::draw() {
  ofFill();
  ofSetColor(this->color);
  ofSetRectMode(OF_RECTMODE_CENTER);
  ofDrawRectangle(this->position.x, this->position.y, this->width, this->height);
}

void Opponent::move() {
  this->position.y += this->velocity;
  this->velocity *= 0.99;
}

void Opponent::up() {
  this->velocity -= this->acceleration;
  if (this->velocity <= -(this->speed)) {
    this->velocity = -(this->speed);
  }
}

void Opponent::down() {
  this->velocity += this->acceleration;
  if (this->velocity >= this->speed) {
    this->velocity = this->speed;
  }
}

void Opponent::center() {
  if (this->position.y <= ((ofGetHeight() / 2) - 2)) {
    this->down();
  } else if (this->position.y >= ((ofGetHeight() / 2) + 2)) {
    this->up();
  } else {
    this->velocity = 0;
  }
}

void Opponent::atBoundry() {
  if ((this->position.y - (this->height / 2)) <= 0) {
    this->position.y = (0 + (this->height / 2));
  } else if (this->position.y >= (ofGetHeight() - (this->height / 2))) {
    this->position.y = (ofGetHeight() - (this->height / 2));
  }
}

void Opponent::inPossession(Ball* ball) {
  if (ball->getX() >= (ofGetWidth() / 2)) {
    this->track(ball);
  } else {
    this->center();
  }
}

void Opponent::track(Ball* ball) {
  float direction = (ball->getY() - this->position.y);
  float distance = ofDist(this->position.x, this->position.y, ball->getX(), ball->getY());
  direction /= distance;
  this->velocity += direction *= this->acceleration;
  if(this->velocity <= -(this->speed)) {
    this->velocity = -(this->speed);
  } else if(this->velocity >= this->speed) {
    this->velocity = this->speed;
  }
}

void Opponent::rectInside(Ball* ball) {
  ofRectangle rect = ofRectangle(this->position.x, this->position.y, this->width, this->height);
  if (rect.intersects(ball->getBall()) == true) {
    ball->bounce();
  }
}
