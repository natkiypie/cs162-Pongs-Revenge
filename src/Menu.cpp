#include "Menu.h"

Menu::Menu() {
  this->width = (ofGetWidth());
  this->height = 65;
  this->barX = (ofGetWidth() / 2);
  this->barY = (((ofGetHeight() / 2) + this->height));
  this->titleX = 240;
  this->titleY = (ofGetHeight() / 2);
  this->playX = ((ofGetWidth() / 2) - 30);
  this->playY = ((((ofGetHeight() / 2) + this->height)) + 15);
  this->instructionsX = ((ofGetWidth() / 2) - 90);
  this->instructionsY = ((((ofGetHeight() / 2) + (this->height * 2))) + 15);
  this->selection = 0;
}

void Menu::loadFont() {
  titleFont.load("vanadine.ttf", 80, true, true, true);
  menuFont.load("vanadine.ttf", 30, true, true, true);
}

void Menu::printTitle() {
  char title[255];
  ofSetColor(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255));
  sprintf(title, "Pong's Revenge");
  titleFont.drawString(title, this->titleX, this->titleY);
}

void Menu::printPlay() {
  char play[255];
  ofSetColor(0, 0, 0);
  sprintf(play, "Play");
  menuFont.drawString(play, this->playX, this->playY);
}

void Menu::printInstructions() {
  char instructions[255];
  ofSetColor(0, 0, 0);
  sprintf(instructions, "Instructions");
  menuFont.drawString(instructions, this->instructionsX, this->instructionsY);
}

void Menu::barDraw() {
  ofFill();
  ofSetColor(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255), 127);
  ofSetRectMode(OF_RECTMODE_CENTER);
  ofDrawRectangle(this->barX, this->barY, this->width, this->height);
}

void Menu::barDown() {
  this->selection = 1;
  this->barY += this->height;
  if (this->barY >= (((ofGetHeight() / 2) + (this->height * 2)))) {
    this->barY = (((ofGetHeight() / 2) + (this->height * 2)));
  }
}

void Menu::barUp() {
  this->selection = 0;
  this->barY -= this->height;
  if (this->barY <= (((ofGetHeight() / 2) + this->height))) {
    this->barY = (((ofGetHeight() / 2) + this->height));
  }
}

int Menu::getSelection() {
  return this->selection;
}
