#include "Player.h"

Player::Player() {
  this->x = 0;
  this->y = 0;
  this->xt = (ofGetWidth() / 2);
  this->yt = (ofGetHeight() - 160);
  this->w = 60;
  this->h = 8;
  this->d = 0;
  this->ps = 8;
  this->ball = 0;
  this->color = ofColor(255, 255, 255);
}

void Player::draw() {
  ofFill();
  ofSetColor(this->color);
  ofPushMatrix();
  ofTranslate(this->xt, this->yt);
  ofRotateDeg(this->d);
  ofSetRectMode(OF_RECTMODE_CENTER);
  ofDrawRectangle(this->x, this->y, this->w, this->h);
  ofPopMatrix();
}

void Player::move() {
  if (ofGetMouseX() == 0 || ofGetMouseY() == 0) {
    this->xt = (ofGetWidth() / 2);
    this->yt = (ofGetHeight() - 160);
  } else {
    this->xt = ofGetMouseX();
    this->yt = ofGetMouseY();
  }
}

void Player::left() {
  this->d -= this->ps;
}

void Player::right() {
  this->d += this->ps;
}

void Player::atBoundry() {
  if ((this->xt - (this->w / 2)) <= 0) {
    this->xt = (0 + (this->w / 2));
  } else if (this->xt >= (ofGetWidth() - (this->w / 2))) {
    this->xt = (ofGetWidth() - (this->w / 2));
  } else if (this->yt <= (ofGetHeight() - 160)) {
    this->yt = (ofGetHeight() - 160);
  } else if (this->yt >= (ofGetHeight() - (this->h / 2))) {
    this->yt = (ofGetHeight() - (this->h / 2));
  }
}

float Player::getD() {
  return this->ball;
}

void Player::storeAngle() {
  this->ball = this->d;
}

void print_values(Player* player) {
  ofSetColor(255, 255, 255);
  ofDrawBitmapString("paddle angle: ", 40, (ofGetHeight() - 40));
  ofDrawBitmapString(ofToString(player->getD()), 150, (ofGetHeight() - 40));
}
