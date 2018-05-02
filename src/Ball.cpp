#include "ofMain.h"
#include "Ball.h"

Ball::Ball() {
  this->position = ofVec2f((ofGetWidth()/2), (ofGetHeight()/2));
  this->velocity = ofVec2f(2, 2);
  this->w = 8;
  this->h = 8;
  this->color = ofColor(255, 255, 255);
}

void Ball::draw() {
  ofFill();
  ofSetColor(this->color);
  ofSetRectMode(OF_RECTMODE_CENTER);
  ofDrawRectangle(this->position.x, this->position.y, this->w, this->h);
}

void Ball::move() {
  this->position += this->velocity;
  if (this->position.x <= 0 || this->position.x >= ofGetWidth()) {
    this->velocity.x *= -1;
  } else if (this->position.y <= 0 || this->position.y >= ofGetHeight()){
    this->velocity.y *= -1;
  }
}
