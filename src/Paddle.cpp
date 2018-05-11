#include "Paddle.h"

Paddle::Paddle() {
  this->playerPosition = ofVec2f(100, (ofGetHeight() / 2));
  this->opponentPosition = ofVec2f((ofGetWidth() - 100), (ofGetHeight() / 2));
  this->width = 10;
  this->height = 60;
  this->playerVelocity = 0;
  this->opponentVelocity = 0;
  this->acceleration = 6;
  this->speed = 8;
  this->opponentOffset = 3;
  this->playerScore = 0;
  this->opponentScore = 0;
  this->color = ofColor(255, 255, 255);
}

void Paddle::loadFont() {
  notoSans.load("notoSans.ttf", 40, true, true, true);
}

void Paddle::playerPrintScore() {
  char score[255];
  ofSetColor(255, 255, 255);
  if (this->playerScore < 10) {
    sprintf(score, "0%d", this->playerScore);
    notoSans.drawString(score, (ofGetWidth() / 4), 100);
  } else {
    sprintf(score, "%d", this->playerScore);
    notoSans.drawString(score, (ofGetWidth() / 4), 100);
  }
}

void Paddle::opponentPrintScore() {
  char score[255];
  ofSetColor(255, 255, 255);
  if (this->opponentScore < 10) {
   sprintf(score, "0%d", this->opponentScore);
   notoSans.drawString(score, (ofGetWidth() - ((ofGetWidth() / 4) + 60)), 100);
  } else {
   sprintf(score, "%d", this->opponentScore);
   notoSans.drawString(score, (ofGetWidth() - ((ofGetWidth() / 4) + 60)), 100);
  }
}

void Paddle::draw() {
  ofFill();
  ofSetColor(this->color);
  ofSetRectMode(OF_RECTMODE_CENTER);
  ofDrawRectangle(this->playerPosition.x, this->playerPosition.y, this->width, this->height);
  ofDrawRectangle(this->opponentPosition.x, this->opponentPosition.y, this->width, this->height);
}

void Paddle::move() {
  this->playerPosition.y += this->playerVelocity;
  this->playerVelocity *= 0.99;
  this->opponentPosition.y += this->opponentVelocity;
  this->opponentVelocity *= 0.99;
}

void Paddle::playerUp() {
  this->playerVelocity -= this->acceleration;
  if(this->playerVelocity <= -(this->speed)) {
    this->playerVelocity = -(this->speed);
  }
}

void Paddle::opponentUp() {
  this->opponentVelocity -= this->acceleration;
  if(this->opponentVelocity <= -(this->speed)) {
    this->opponentVelocity = -(this->speed);
  }
}

void Paddle::playerDown() {
  this->playerVelocity += this->acceleration;
  if(this->playerVelocity >= this->speed) {
    this->playerVelocity = this->speed;
  }
}

void Paddle::opponentDown() {
  this->opponentVelocity += this->acceleration;
  if(this->opponentVelocity >= this->speed) {
    this->opponentVelocity = this->speed;
  }
}

void Paddle::boundry() {
  if ((this->playerPosition.y - (this->height / 2)) <= 0) {
    this->playerPosition.y = (0 + (this->height / 2));
  } else if (this->playerPosition.y >= (ofGetHeight() - (this->height / 2))) {
    this->playerPosition.y = (ofGetHeight() - (this->height / 2));
  } else if ((this->opponentPosition.y - (this->height / 2)) <= 0) {
    this->opponentPosition.y = (0 + (this->height / 2));
  } else if (this->opponentPosition.y >= (ofGetHeight() - (this->height / 2))) {
    this->opponentPosition.y = (ofGetHeight() - (this->height / 2));
  }
}

void Paddle::playerRelease() {
  this->playerVelocity = 0;
}

void Paddle::opponentCenter() {
  if (this->opponentPosition.y <= ((ofGetHeight() / 2) - this->opponentOffset)) {
    this->opponentDown();
  } else if (this->opponentPosition.y >= ((ofGetHeight() / 2) + this->opponentOffset)) {
    this->opponentUp();
  } else {
    this->opponentVelocity = 0;
  }
}

void Paddle::opponentInPossession(Ball* ball) {
  if (ball->getX() > (ofGetWidth() / 2) && this->playerPosition.y < this->opponentPosition.y) {
    this->opponentTrack(ball, -40);
  } else if (ball->getX() > (ofGetWidth() / 2) && this->playerPosition.y > this->opponentPosition.y) {
    this->opponentTrack(ball, 40);
  } else if (ball->getX() > (ofGetWidth() / 2) && this->playerPosition.y == this->opponentPosition.y) {
    this->opponentTrack(ball, 0);
  } else {
    this->opponentCenter();
  }
}

void Paddle::opponentTrack(Ball* ball, int max) {
  float direction = ((ball->getY() + ofRandom(0, max)) - this->opponentPosition.y);
  float distance = ofDist(this->opponentPosition.x, this->opponentPosition.y, ball->getX(), ball->getY());
  direction /= distance;
  this->opponentVelocity += direction *= this->acceleration;
  if(this->opponentVelocity <= -(this->speed)) {
    this->opponentVelocity = -(this->speed);
  } else if(this->opponentVelocity >= this->speed) {
    this->opponentVelocity = this->speed;
  }
}

void Paddle::collisionInitialize(Ball* ball) {
  this->collision(ball, 2.5, 5, -8);
  this->collision(ball, 10, 10, -3);
  this->collision(ball, 20, 10, -0.5);
  this->collision(ball, 30, 10, 0);
  this->collision(ball, 40, 10, 0.5);
  this->collision(ball, 50, 10, 3);
  this->collision(ball, 57.5, 5, 8);
}

void Paddle::collision(Ball* ball, float r, int n, float s) {
  ofRectangle rectPlayer = ofRectangle(this->playerPosition.x, ((this->playerPosition.y - (this->height / 2)) + r), this->width, n);
  ofRectangle rectOpponent = ofRectangle(this->opponentPosition.x, ((this->opponentPosition.y - (this->height / 2)) + r), this->width, n);
  if (rectPlayer.intersects(ball->getBoundingBox()) == true) {
    ball->bouncePlayer(s);
  } else if (rectOpponent.intersects(ball->getBoundingBox()) == true) {
    ball->bounceOpponent(-s);
  }
}

void Paddle::point(Ball* ball) {
  if (ball->getX() >= ofGetWidth()) {
    ball->soundPlayerScore();
    this->playerScore++;
    ball->setup();
    this->setServe(ball);
    ball->changeServe();
    this->gameEnd(ball);
  } else if (ball->getX() <= 0) {
    ball->soundOpponentScore();
    this->opponentScore++;
    ball->setup();
    this->setServe(ball);
    ball->changeServe();
    this->gameEnd(ball);
  }
}

void Paddle::setServe(Ball* ball) {
  if ((this->playerScore + this->opponentScore) % 5 == 0) {
    ball->setServe();
  }
}

void Paddle::gameEnd(Ball* ball) {
  if (this->playerScore >= 11 || this->opponentScore >= 11) {
    if (this->playerScore - this->opponentScore >= 2 || this->opponentScore - this->playerScore >= 2) {
      this->gameOver(ball);
    } else {
      this->gamePoint(ball);
    }
  }
}

void Paddle::gamePoint(Ball* ball) {
  if (this->playerScore <= this->opponentScore) {
    ball->setPlayerServe();
  } else if (this->opponentScore <= this->playerScore) {
    ball->setOpponentServe();
  } else if (this->playerScore - this->opponentScore >= 2 || this->opponentScore - this->playerScore >= 2) {
    this->gameOver(ball);
  }
}

void Paddle::gameOver(Ball* ball) {
  this->color = ofColor(255, 0, 0);
  ball->stop();
}

int Paddle::testOne() {
  return (this->playerScore + this->opponentScore);
}

float Paddle::testTwo() {
  return ((this->playerScore + this->opponentScore) % 5);
}

