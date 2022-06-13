#pragma once

class Pit {
public:
    int pitId;
    int numberofPiyon;

    Pit(int pitId, int numberofPiyon);
    
    void move(Pit referanceArray[]);
    
    void deletePiyon();
    
    void drawPiyon();
};

void drawText(const char* text, int length, int x, int y);

void drawTable();

void drawPits();

void drawMenuButtons();

void drawMenu();
