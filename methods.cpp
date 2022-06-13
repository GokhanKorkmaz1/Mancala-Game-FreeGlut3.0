#include "methods.h"
#include <GL/glut.h>
#include <iostream>

const float constantValue = 0.19f;
const int sizeArray = 14;
int a, b, c;


Pit::Pit(int pitId, int numberofPiyon) {
    this->pitId = pitId;
    this->numberofPiyon = numberofPiyon;
    drawPiyon();
}

void Pit::move(Pit referanceArray[]) {
    if (numberofPiyon == 0) {
        return;
    }
    else if (numberofPiyon == 1) {
        for (int i = 0; i < sizeArray; i++) {
            if (referanceArray[i].pitId == pitId) {
                referanceArray[i].deletePiyon();
                referanceArray[i].numberofPiyon = 0;
                referanceArray[i + 1].numberofPiyon += 1;
                referanceArray[i + 1].drawPiyon();
            }
        }
    }
    else if (numberofPiyon > 1) {
        for (int i = 0; i < sizeArray; i++) {
            if (referanceArray[i].pitId == pitId) {
                for (int j = 1; j < numberofPiyon; j++) {
                    int k = i + j;
                    k = (k > 13) ? (k % 13) - 1 : k;
                    referanceArray[k].numberofPiyon += 1;
                    referanceArray[k].drawPiyon();

                }
                int l = i + numberofPiyon - 1;
                l = (l > 13) ? (l % 13) - 1 : l;
                if (referanceArray[l].numberofPiyon % 2 == 0 && ((referanceArray[l].pitId > 6 &&
                    referanceArray[i].pitId < 6) || (referanceArray[l].pitId < 6 && referanceArray[i].pitId > 6))) {
                    if (referanceArray[i].pitId < 6) {
                        referanceArray[6].numberofPiyon += referanceArray[l].numberofPiyon;
                        referanceArray[6].drawPiyon();
                        referanceArray[l].deletePiyon();
                        referanceArray[l].numberofPiyon = 1;
                        referanceArray[l].deletePiyon();
                        referanceArray[l].numberofPiyon = 0;
                    }
                    else if (referanceArray[i].pitId > 6 && referanceArray[i].pitId < 13) {
                        referanceArray[13].numberofPiyon += referanceArray[l].numberofPiyon;
                        referanceArray[13].drawPiyon();
                        referanceArray[l].deletePiyon();
                        referanceArray[l].numberofPiyon = 1;
                        referanceArray[l].deletePiyon();
                        referanceArray[l].numberofPiyon = 0;
                    }
                }
                if ((referanceArray[i].pitId<6 && referanceArray[i+numberofPiyon-1].pitId<6) && 
                    referanceArray[i+numberofPiyon-1].numberofPiyon == 1 && referanceArray[13 - (i + numberofPiyon)].numberofPiyon>0) {
                    referanceArray[6].numberofPiyon += 1+ referanceArray[13-(i + numberofPiyon - 1)].numberofPiyon;
                    referanceArray[6].drawPiyon();
                    referanceArray[i+numberofPiyon-1].deletePiyon();
                    referanceArray[i+numberofPiyon-1].numberofPiyon = 0;
                    referanceArray[13-(i + numberofPiyon )].deletePiyon();
                    if (referanceArray[13 - (i + numberofPiyon )].numberofPiyon > 1) {
                        referanceArray[13 - (i + numberofPiyon )].numberofPiyon = 1;
                        referanceArray[13 - (i + numberofPiyon)].deletePiyon();
                    }
                    referanceArray[13 - (i + numberofPiyon )].deletePiyon();
                    referanceArray[13 - (i + numberofPiyon )].numberofPiyon = 0;
                }
                else if ((referanceArray[i].pitId > 6 && referanceArray[i].pitId < 13 &&
                         referanceArray[i + numberofPiyon - 1].pitId > 6 && referanceArray[i + numberofPiyon - 1].pitId < 13)&&
                         referanceArray[i + numberofPiyon - 1].numberofPiyon == 1 && referanceArray[13 - (i + numberofPiyon)].numberofPiyon > 0) {
                    referanceArray[13].numberofPiyon += 1+ referanceArray[(13 - (i + numberofPiyon - 1))].numberofPiyon;
                    referanceArray[13].drawPiyon();
                    referanceArray[i + numberofPiyon - 1].deletePiyon();
                    referanceArray[i + numberofPiyon - 1].numberofPiyon = 0;
                    referanceArray[13 - (i + numberofPiyon )].deletePiyon();
                    if (referanceArray[13 - (i + numberofPiyon )].numberofPiyon > 1) {
                        referanceArray[13 - (i + numberofPiyon )].numberofPiyon = 1;
                        referanceArray[13 - (i + numberofPiyon)].deletePiyon();
                    }
                    referanceArray[13 - (i + numberofPiyon )].deletePiyon();
                    referanceArray[13 - (i + numberofPiyon )].numberofPiyon = 0;
                }
                referanceArray[i].deletePiyon();
                referanceArray[i].numberofPiyon = 1;
            }
        }


    }
}

void Pit::deletePiyon() {
    glColor3f(0.1f, 0.87f, 0.2f);
    if (numberofPiyon == 1) {
        if (pitId < 6) {
            glBegin(GL_POINTS);
            glVertex2f(0.5f - pitId * constantValue, 0.05f);
            glEnd();
        }
        else if (pitId > 6 && pitId < 13) {
            c = pitId % 7;
            glBegin(GL_POINTS);
            glVertex2f(-0.5f + c * constantValue, -0.25f);
            glEnd();
        }
    }
    else if (numberofPiyon > 1) {

        for (int i = 1; i < numberofPiyon; i++) {
            a = i / 2;
            b = i % 2;
            c = pitId;

            if (pitId < 6) {
                glBegin(GL_POINTS);
                glVertex2f((0.5f - pitId * constantValue) - b * 0.05f, 0.05f + a * 0.08f);
                glEnd();

            }
            else if (pitId > 6 && pitId < 13) {
                c %= 7;
                glBegin(GL_POINTS);
                glVertex2f((-0.5f + c * constantValue) + b * 0.05f, -0.25f - a * 0.08f);
                glEnd();

            }
        }
    }
}

void Pit::drawPiyon() {
    if (numberofPiyon == 0 && !(pitId == 13 || pitId == 6)) {
        return;
    }

    if (numberofPiyon == 0 && pitId == 6) {
        glColor3f(0.1f, 0.87f, 0.2f);
        glBegin(GL_QUADS);
        glVertex2f(-0.6f, 0.5f);
        glVertex2f(-0.6f, -0.7f);
        glVertex2f(-0.8f, -0.7f);
        glVertex2f(-0.8f, 0.5f);
        glEnd();
    }
    else if (numberofPiyon == 0 && pitId == 13) {
        glColor3f(0.1f, 0.87f, 0.2f);
        glBegin(GL_QUADS);
        glVertex2f(0.6f, 0.5f);
        glVertex2f(0.6f, -0.7f);
        glVertex2f(0.8f, -0.7f);
        glVertex2f(0.8f, 0.5f);
        glEnd();
    }

    glColor3f(0.0f, 0.0f, 1.0f);

    for (int i = 0; i < numberofPiyon; i++) {
        a = i / 2;
        b = i % 2;
        c = pitId;

        if (pitId < 6) {
            glBegin(GL_POINTS);
            glVertex2f((0.5f - pitId * constantValue) - b * 0.05f, 0.05f + a * 0.08f);
            glEnd();

        }
        else if (pitId == 6) {
            a = i / 3;
            b = i % 3;


            glBegin(GL_POINTS);
            glVertex2f(-0.75f + b * 0.05f, 0.455f - a * 0.074f);
            glEnd();

        }
        else if (pitId > 6 && pitId < 13) {
            c %= 7;
            glBegin(GL_POINTS);
            glVertex2f((-0.5f + c * constantValue) + b * 0.05f, -0.25f - a * 0.08f);
            glEnd();
        }
        else {
            a = i / 3;
            b = i % 3;
            glBegin(GL_POINTS);
            glVertex2f(0.65f + b * 0.05f, -0.655f + a * 0.074f);
            glEnd();
        }
    }
}

void drawText(const char* text, int length, int x, int y) {
    glMatrixMode(GL_PROJECTION);
    double* matrix = new double[16];
    glGetDoublev(GL_PROJECTION_MATRIX, matrix);
    glLoadIdentity();
    glOrtho(0, 1080, 0, 720, -5, 5);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRasterPos2i(x, y);
    for (int i = 0; i < length; i++) {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, (int)text[i]);
    }
    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glLoadMatrixd(matrix);
    glMatrixMode(GL_MODELVIEW);
}

void drawTable() {
    float boardX = 0.9f;
    float boardY = 0.6f;

    glLoadIdentity();

    glBegin(GL_QUADS);
    glColor3f(0.62f, 0.37f, 0.26f);
    glVertex2d(boardX, boardY);

    glColor3f(0.43f, 0.29f, 0.2f);
    glVertex2d(boardX, -boardY - 0.2f);

    glColor3f(0.52f, 0.37f, 0.26f);
    glVertex2d(-boardX, -boardY - 0.2f);

    glColor3f(0.53f, 0.29f, 0.2f);
    glVertex2d(-boardX, boardY);
    glEnd();
}

void drawPits() {
    glLoadIdentity();
    glColor3f(0.1f, 0.87f, 0.2f);

    //top pits
    for (float i = -0.550f; i < 0.525f; i += 0.19f) {
        glBegin(GL_QUADS);
        glVertex2f(i + 0.15f, 0.5f);
        glVertex2f(i + 0.15f, 0.0f);
        glVertex2f(i, 0.0f);
        glVertex2f(i, 0.5f);
        glEnd();
    }

    //bottom pits
    for (float i = -0.550f; i < 0.525f; i += 0.19f) {
        glBegin(GL_QUADS);
        glVertex2f(i + 0.15f, -0.7f);
        glVertex2f(i + 0.15f, -0.2f);
        glVertex2f(i, -0.2f);
        glVertex2f(i, -0.7f);
        glEnd();
    }

    //left pit
    glBegin(GL_QUADS);
    glVertex2f(-0.6f, 0.5f);
    glVertex2f(-0.6f, -0.7f);
    glVertex2f(-0.8f, -0.7f);
    glVertex2f(-0.8f, 0.5f);
    glEnd();

    //right pit
    glBegin(GL_QUADS);
    glVertex2f(0.6f, 0.5f);
    glVertex2f(0.6f, -0.7f);
    glVertex2f(0.8f, -0.7f);
    glVertex2f(0.8f, 0.5f);
    glEnd();
}

void drawMenuButtons() {
    glColor3f(0.0f, 0.0f, 1.0f);

    //play button
    glBegin(GL_QUADS);
    glVertex2f(-0.1f, 0.975f);
    glVertex2f(-0.1f, 0.825f);
    glVertex2f(0.1f, 0.825f);
    glVertex2f(0.1f, 0.975f);
    glEnd();

    //reset button
    glBegin(GL_QUADS);
    glVertex2f(0.575f, 0.975f);
    glVertex2f(0.575f, 0.825f);
    glVertex2f(0.775f, 0.825f);
    glVertex2f(0.775f, 0.975f);
    glEnd();

    //player vs player button
    glBegin(GL_QUADS);
    glVertex2f(-0.675f, 0.975f);
    glVertex2f(-0.675f, 0.825f);
    glVertex2f(-0.775f, 0.825f);
    glVertex2f(-0.775f, 0.975f);
    glEnd();

    //player vs computer button
    glBegin(GL_QUADS);
    glVertex2f(-0.550f, 0.975f);
    glVertex2f(-0.550f, 0.825f);
    glVertex2f(-0.650f, 0.825f);
    glVertex2f(-0.650f, 0.975f);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);
    std::string text;

    text = "Play Game";
    drawText(text.data(), text.size(), 500, 680);

    text = "Reset";
    drawText(text.data(), text.size(), 880, 680);

    text = "PvP";
    drawText(text.data(), text.size(), 135, 680);

    text = "PvE";
    drawText(text.data(), text.size(), 205, 680);
}

void drawMenu() {
    float menuX = 0.8f;
    float menuY1 = 0.8f;
    float menuY2 = 1.0f;

    glColor3f(1.0f, 0.0f, 0.0f);

    glBegin(GL_QUADS);
    glColor3f(0.62f, 0.37f, 0.26f);
    glVertex2f(-menuX, menuY2);

    glColor3f(0.43f, 0.29f, 0.2f);
    glVertex2f(-menuX, menuY1);

    glColor3f(0.52f, 0.37f, 0.26f);
    glVertex2f(menuX, menuY1);

    glColor3f(0.53f, 0.29f, 0.2f);
    glVertex2f(menuX, menuY2);
    glEnd();

    drawMenuButtons();
}