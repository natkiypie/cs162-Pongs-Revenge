#include "Opponent.h"

Opponent::Opponent() {
  this->position = ofVec2f((ofGetWidth() - 100), (ofGetHeight() / 2));
  this->width = 10;
  this->height = 60;
  this->velocity = 0;
  this->acceleration = 6;
  this->speed = 6;
  this->offset = 3;
  this->score = 0;
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

void Opponent::collision(Ball* ball) {
  ofRectangle segOne = ofRectangle(this->position.x, ((this->position.y - (this->height / 2)) + 2.5), this->width, 5);
  ofRectangle segTwo = ofRectangle(this->position.x, ((this->position.y - (this->height / 2)) + 10), this->width, 10);
  ofRectangle segThree = ofRectangle(this->position.x, ((this->position.y - (this->height / 2)) + 20), this->width, 10);
  ofRectangle segFour = ofRectangle(this->position.x, ((this->position.y - (this->height / 2)) + 30), this->width, 10);
  ofRectangle segFive = ofRectangle(this->position.x, ((this->position.y - (this->height / 2)) + 40), this->width, 10);
  ofRectangle segSix = ofRectangle(this->position.x, ((this->position.y - (this->height / 2)) + 50), this->width, 10);
  ofRectangle segSeven = ofRectangle(this->position.x, ((this->position.y - (this->height / 2)) + 57.5), this->width, 5);

  if (segOne.intersects(ball->getBall()) == true) {
    ball->bounceOpponent(8);
  } else if (segTwo.intersects(ball->getBall()) == true) {
    ball->bounceOpponent(3);
  } else if (segThree.intersects(ball->getBall()) == true) {
    ball->bounceOpponent(0.5);
  } else if (segFour.intersects(ball->getBall()) == true) {
    ball->bounceOpponent(0);
  } else if (segFive.intersects(ball->getBall()) == true) {
    ball->bounceOpponent(-0.5);
  } else if (segSix.intersects(ball->getBall()) == true) {
    ball->bounceOpponent(-3);
  } else if (segSeven.intersects(ball->getBall()) == true) {
    ball->bounceOpponent(-8);
  }
}

int Opponent::getScore() {
  return this->score;
}

void Opponent::point(Ball* ball) {
  if (ball->getX() <= 0) {
    this->score++;
    ball->soundLose();
  }
}

void Opponent::loadFont() {
  notoSans.load("notoSans.ttf", 40, true, true, true);
}

void Opponent::printScore() {
  char score[255];
  if (this->getScore() < 10) {
   sprintf(score, "0%d", this->getScore());
   notoSans.drawString(score, (ofGetWidth() - ((ofGetWidth() / 4) + 60)), 100);
  } else {
   sprintf(score, "%d", this->getScore());
   notoSans.drawString(score, (ofGetWidth() - ((ofGetWidth() / 4) + 60)), 100);
  }
}
