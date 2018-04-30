#include "ofMain.h"
#include "Ball.h"

Ball::Ball() {
  this->x = 200;
  this->y = (ofGetHeight()/2);
  this->w = 10;
  this->h = 10;
  this->color = ofColor(255, 255, 255);
}

void Ball::draw() {
  ofFill();
  ofSetColor(this->color);
  ofSetRectMode(OF_RECTMODE_CENTER);
  ofDrawRectangle(this->x, this->y, this->w, this->h);

//  ofPushMatrix();
//  ofTranslate(this->xt, this->yt);
//  ofRotateDeg(this->d);
//  ofSetRectMode(OF_RECTMODE_CENTER);
//  ofDrawRectangle(this->x, this->y, this->w, this->h);
//  ofPopMatrix();
}

void Ball::move() {
}
