#include "Player.h"

Player::Player() {
  this->position = ofVec2f(0, 0);
  this->translation = ofVec2f((ofGetWidth() / 2), (ofGetHeight() - 160));
  this->width = 60;
  this->height = 8;
  this->degree = 0;
  this->size = 8;
  this->ball = 0;
  this->color = ofColor(255, 255, 255);
}

void Player::draw() {
  ofFill();
  ofSetColor(this->color);
  ofPushMatrix();
  ofTranslate(this->translation.x, this->translation.y);
  ofRotateDeg(this->degree);
  ofSetRectMode(OF_RECTMODE_CENTER);
  ofDrawRectangle(this->position.x, this->position.y, this->width, this->height);
  ofPopMatrix();
}

void Player::move() {
  if (ofGetMouseX() == 0 || ofGetMouseY() == 0) {
    this->translation.x = (ofGetWidth() / 2);
    this->translation.y = (ofGetHeight() - 160);
  } else {
    this->translation.x = ofGetMouseX();
    this->translation.y = ofGetMouseY();
  }
}

void Player::left() {
  this->degree -= this->size;
}

void Player::right() {
  this->degree += this->size;
}

void Player::atBoundry() {
  if ((this->translation.x - (this->width / 2)) <= 0) {
    this->translation.x = (0 + (this->width / 2));
  } else if (this->translation.x >= (ofGetWidth() - (this->width / 2))) {
    this->translation.x = (ofGetWidth() - (this->width / 2));
  } else if (this->translation.y <= (ofGetHeight() - 160)) {
    this->translation.y = (ofGetHeight() - 160);
  } else if (this->translation.y >= (ofGetHeight() - (this->height / 2))) {
    this->translation.y = (ofGetHeight() - (this->height / 2));
  }
}

float Player::getAngle() {
  return this->degree;
}

void Player::setAngle() {
  this->ball = this->degree;
}

void print_values(Player* player) {
  ofSetColor(255, 255, 255);
  ofDrawBitmapString("paddle angle: ", 40, (ofGetHeight() - 40));
  ofDrawBitmapString(ofToString(player->getAngle()), 150, (ofGetHeight() - 40));
}

