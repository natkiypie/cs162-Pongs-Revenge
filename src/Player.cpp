#include "Player.h"

Player::Player() {
  this->x = 0;
  this->y = 0;
  this->xt = (ofGetWidth() / 2);
  this->yt = (ofGetHeight() - 160);
  this->w = 60;
  this->h = 8;
  this->d = 0;
  this->ps = 6;
  this->color = ofColor(255, 255, 255);
}

void Player::draw() {
  ofSetColor(this->color);
  ofPushMatrix();
  ofTranslate(this->xt, this->yt);
  ofRotateDeg(this->d);
  ofSetRectMode(OF_RECTMODE_CENTER);
  ofDrawRectangle(this->x, this->y, this->w, this->h);
  ofPopMatrix();
}

void Player::move() {
  if (ofGetMouseX() == 0) {
    this->xt = (ofGetWidth() / 2);
  } else {
    this->xt = ofGetMouseX();
  }
}

void Player::left() {
  this->d -= ps;
}

void Player::right() {
  this->d += ps;
}

void Player::atBoundry() {
  if ((this->xt - (this->w / 2)) <= 0) {
    this->xt = (0 + (this->w / 2));
  } else if (this->xt >= ofGetWidth() - (this->w / 2)) {
    this->xt = (ofGetWidth() - (this->w / 2));
  }
}