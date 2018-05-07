#include "Opponent.h"

Opponent::Opponent() {
  this->position = ofVec2f((ofGetWidth() - 100), (ofGetHeight() / 2));
  this->width = 10;
  this->height = 60;
  this->velocity = 0;
  this->acceleration = 6;
  this->speed = 6;
  this->offset = 3;
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
  if (this->position.y <= ((ofGetHeight() / 2) - this->offset)) {
    this->down();
  } else if (this->position.y >= ((ofGetHeight() / 2) + this->offset)) {
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

void Opponent::inPossession(Ball* ball, Player* player) {
  if (ball->getX() >= (ofGetWidth() / 2) && player->getY() < this->position.y) {
    this->track(ball, -40);
  } else if (ball->getX() >= (ofGetWidth() / 2) && player->getY() > this->position.y) {
    this->track(ball, 40);
  } else if (ball->getX() >= (ofGetWidth() / 2) && player->getY() == this->position.y) {
    this->track(ball, 0);
  } else {
    this->center();
  }
}

void Opponent::track(Ball* ball, int max) {
  float direction = ((ball->getY() + ofRandom(0, max)) - this->position.y);
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
  ofRectangle segOne = ofRectangle(this->position.x, ((this->position.y - (this->height / 2)) + 6), this->width, 12);
  ofRectangle segTwo = ofRectangle(this->position.x, ((this->position.y - (this->height / 2)) + 18), this->width, 12);
  ofRectangle segThree = ofRectangle(this->position.x, ((this->position.y - (this->height / 2)) + 30), this->width, 12);
  ofRectangle segFour = ofRectangle(this->position.x, ((this->position.y - (this->height / 2)) + 42), this->width, 12);
  ofRectangle segFive = ofRectangle(this->position.x, ((this->position.y - (this->height / 2)) + 54), this->width, 12);

  if (segOne.intersects(ball->getBall()) == true) {
    ball->bounce(3, 1);
  } else if (segTwo.intersects(ball->getBall()) == true) {
    ball->bounce(0.5, 1);
  } else if (segThree.intersects(ball->getBall()) == true) {
    ball->bounce(0, 1);
  } else if (segFour.intersects(ball->getBall()) == true) {
    ball->bounce(-0.5, 1);
  } else if (segFive.intersects(ball->getBall()) == true) {
    ball->bounce(-3, 1);
  }
}
