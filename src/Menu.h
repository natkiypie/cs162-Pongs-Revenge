#pragma once
#include "ofMain.h"

class Menu {

  public:
    Menu();
    void loadFont();
    void printTitle();
    void printPlay();
    void printInstructions();
    void barDraw();
    void barDown();
    void barUp();
    int getSelection();

  private:
    int barX;
    int barY;
    int titleX;
    int titleY;
    int playX;
    int playY;
    int instructionsX;
    int instructionsY;
    float width;
    float height;
    int selection;
    ofTrueTypeFont titleFont;
    ofTrueTypeFont menuFont;
};
