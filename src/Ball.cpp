#include "Ball.h"

Ball::Ball() {
  this->position = ofVec2f((ofGetWidth()/2), (ofGetHeight()/2));
  this->speed = 10;
  this->direction = 0;
  this->velocity = ofVec2f(this->speed, this->direction);
  this->width = 10;
  this->height = 10;
  this->color = ofColor(255, 255, 255);
}

void Ball::soundLoad() {
  player.load("ping.wav");
  opponent.load("pong.wav");
  wall.load("blip.wav");
  win.load("win.wav");
  lose.load("lose.wav");
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
    this->soundWall();
  }
}

void Ball::bouncePlayer(float dir) {
  this->velocity = ofVec2f(this->speed, dir);
  this->velocity *= -1;
  this->soundPlayer();
}

void Ball::bounceOpponent(float dir) {
  this->velocity = ofVec2f(this->speed, dir);
  this->soundOpponent();
}

void Ball::soundPlayer() {
  player.play();
}

void Ball::soundOpponent() {
  opponent.play();
}

void Ball::soundWall() {
  wall.play();
}

void Ball::soundWin() {
  win.play();
}

void Ball::soundLose() {
  lose.play();
}

float Ball::getX() {
  return this->position.x;
}

float Ball::getY() {
  return this->position.y;
}

ofRectangle Ball::getBoundingBox() {
  ofRectangle rect = ofRectangle(this->position.x, this->position.y, this->width, this->height);
  return rect;
}
