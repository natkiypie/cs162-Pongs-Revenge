#include "ofMain.h"
#include "Ball.h"

Ball::Ball() {
  this->position = ofVec2f((ofGetWidth()/2), (ofGetHeight()/2));
  this->speed = 6;
  this->velocity = ofVec2f(this->speed, this->speed);
  this->width = 10;
  this->height = 10;
  this->color = ofColor(255, 255, 255);
}

void Ball::draw() {
  ofFill();
  ofSetColor(this->color);
  ofSetRectMode(OF_RECTMODE_CENTER);
  ofDrawRectangle(this->position.x, this->position.y, this->width, this->height);
}

void Ball::move() {
  this->position -= this->velocity;
  if (this->position.x <= 0 || this->position.x >= ofGetWidth()) {
    this->velocity.x *= -1;
  } else if (this->position.y <= 0 || this->position.y >= ofGetHeight()) {
    this->velocity.y *= -1;
  }
}

void Ball::bounce() {
  this->velocity *= -1;
}

float Ball::getX() {
  return this->position.x;
}

float Ball::getY() {
  return this->position.y;
}

ofRectangle Ball::getBall() {
  ofRectangle rect = ofRectangle(this->position.x, this->position.y, this->width, this->height);
  return rect;
}
