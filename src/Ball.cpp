#include "ofMain.h"
#include "Ball.h"

Ball::Ball() {
  this->position = ofVec2f((ofGetWidth()/2), (ofGetHeight()/2));
  this->velocity = ofVec2f(4, 4);
  this->width = 8;
  this->height = 8;
  this->color = ofColor(255, 255, 255);
}

void Ball::draw() {
  ofFill();
  ofSetColor(this->color);
  ofSetRectMode(OF_RECTMODE_CENTER);
  ofDrawRectangle(this->position.x, this->position.y, this->width, this->height);
}

void Ball::move() {
  this->position += this->velocity;
  if (this->position.x <= 0 || this->position.x >= ofGetWidth()) {
    this->velocity.x *= -1;
  } else if (this->position.y <= 0 || this->position.y >= ofGetHeight()) {
    this->velocity.y *= -1;
  }
}

ofVec2f Ball::getPosition() {
  return this->position;
}

void Ball::bounce() {
  this->velocity.x *= -1;
}
