#include <GL/glut.h>
#include <iostream>
#include"methods.h"

  // A macro for unused variables (to bypass those pesky G++ warnings)
#define UNUSED(param) (void)(param)

const char title[] = "Mancala Game";
const int sizeArray = 14;
bool tmp = true, tmp2 = false;
bool* turn = &tmp;
bool* play = &tmp2;
int mouseX, mouseY;
std::string text;

Pit pit0(0, 4); Pit pit1(1, 4); Pit pit2(2, 4); Pit pit3(3, 4); Pit pit4(4, 4); Pit pit5(5, 4); Pit pit6(6, 0);

Pit pit7(7, 4); Pit pit8(8, 4); Pit pit9(9, 4); Pit pit10(10, 4); Pit pit11(11, 4); Pit pit12(12, 4); Pit pit13(13, 0);

Pit referanceList[sizeArray] = { pit0, pit1, pit2, pit3, pit4, pit5, pit6, pit7, pit8, pit9, pit10, pit11, pit12, pit13 };

void draw() {
    for (int i = 0; i < sizeArray; i++) {
        referanceList[i].drawPiyon();
    }
}

void finishGame(Pit a[]) {
        if (a[0].numberofPiyon == 0 && a[1].numberofPiyon == 0 && a[2].numberofPiyon == 0 && a[3].numberofPiyon == 0 && a[4].numberofPiyon == 0 && a[5].numberofPiyon == 0 ) {
            for (int i = 7; i < 13; i++) {
                a[6].numberofPiyon += a[i].numberofPiyon;
                a[i].numberofPiyon = 1; a[i].deletePiyon(); a[i].numberofPiyon = 0;
            }
            a[6].drawPiyon();

            if (a[13].numberofPiyon > a[6].numberofPiyon)
                text = "PLAYER 1 WIN";
            else if (a[13].numberofPiyon < a[6].numberofPiyon)
                text = "PLAYER 2 WIN";
            else
                text = "DRAW";
            drawText(text.data(), text.size(), 480, 320);
        }
        else if (a[7].numberofPiyon == 0 && a[8].numberofPiyon == 0 && a[9].numberofPiyon == 0 && a[10].numberofPiyon == 0 && a[11].numberofPiyon == 0 && a[12].numberofPiyon == 0) {
            for (int i = 0; i < 6; i++) {
                a[13].numberofPiyon += a[i].numberofPiyon;
                a[i].numberofPiyon = 1; a[i].deletePiyon(); a[i].numberofPiyon = 0;
            }
            a[13].drawPiyon();

            if (a[13].numberofPiyon > a[6].numberofPiyon)
                text = "PLAYER 1 WIN";
            else if (a[13].numberofPiyon < a[6].numberofPiyon)
                text = "PLAYER 2 WIN";
            else
                text = "DRAW";
            drawText(text.data(), text.size(), 480, 320);
        }

}

void resetGame(Pit referanceArray[]) {
    for (int i = 0; i < sizeArray; i++) {
        if (referanceArray[i].pitId == 6 || referanceArray[i].pitId == 13) {
            referanceArray[i].numberofPiyon = 0;
            referanceArray[i].drawPiyon();
        }
        else {
            referanceArray[i].deletePiyon();
            referanceArray[i].numberofPiyon = 4;
            referanceArray[i].drawPiyon();
            
        }
    }
    *turn = true;
    draw();
}

void clicks(int x, int y, Pit referanceArray[],bool *turn,bool *play) {
    if ((mouseX > 486 && mouseX < 594) && (mouseY > 10 && mouseY < 60)) {
        *play = true;
    }
    else if ((mouseX > 850 && mouseX < 958) && (mouseY > 10 && mouseY < 60)) {
        resetGame(referanceArray);
    }
    else if ((mouseX > 755 && mouseX < 837) && (mouseY > 180 && mouseY < 360 && !(*turn)) && *play) {//pit0
        *turn = true;
        if (referanceArray[0].numberofPiyon == 7)
            *turn = false;
        referanceArray[0].move(referanceArray);
        
    }
    else if ((mouseX > 653 && mouseX < 733) && (mouseY > 180 && mouseY < 360 && !(*turn)) && *play) {//pit1
        *turn = true;
        if (referanceArray[1].numberofPiyon == 6)
            *turn = false;
        referanceArray[1].move(referanceArray);
    }
    else if ((mouseX > 550 && mouseX < 630) && (mouseY > 180 && mouseY < 360 && !(*turn)) && *play) {//pit2
        *turn = true;
        if (referanceArray[2].numberofPiyon == 5)
            *turn = false;
        referanceArray[2].move(referanceArray);
    }
    else if ((mouseX > 448 && mouseX < 530) && (mouseY > 180 && mouseY < 360 && !(*turn)) && *play) {//pit3
        *turn = true;
        if (referanceArray[3].numberofPiyon == 4)
            *turn = false;
        referanceArray[3].move(referanceArray);
    }
    else if ((mouseX > 345 && mouseX < 427) && (mouseY > 180 && mouseY < 360 && !(*turn)) && *play) {//pit4
        *turn = true;
        if (referanceArray[4].numberofPiyon == 3)
            *turn = false;
        referanceArray[4].move(referanceArray);
    }
    else if ((mouseX > 242 && mouseX < 324) && (mouseY > 180 && mouseY < 360 && !(*turn)) && *play) {//pit5
        *turn = true;
        if (referanceArray[5].numberofPiyon == 2 || referanceArray[5].numberofPiyon == 1)
            *turn = false;
        referanceArray[5].move(referanceArray);
    } 
    else if ((mouseX > 242 && mouseX < 324) && (mouseY > 430 && mouseY < 612) && *turn && *play) {//pit7
        *turn = false;
        if (referanceArray[7].numberofPiyon == 7)
            *turn = true;
        referanceArray[7].move(referanceArray);
    }
    else if ((mouseX > 345 && mouseX < 427) && (mouseY > 430 && mouseY < 612) && *turn && *play) {//pit8
        *turn = false;
        if (referanceArray[8].numberofPiyon == 6)
            *turn = true;
        referanceArray[8].move(referanceArray);
    }
    else if ((mouseX > 448 && mouseX < 530) && (mouseY > 430 && mouseY < 612) && *turn && *play) {//pit9
        *turn = false;
        if (referanceArray[9].numberofPiyon == 5)
            *turn = true;
        referanceArray[9].move(referanceArray);
    }
    else if ((mouseX > 550 && mouseX < 630) && (mouseY > 430 && mouseY < 612) && *turn && *play) {//pit10
        *turn = false;
        if (referanceArray[10].numberofPiyon == 4)
            *turn = true;
        referanceArray[10].move(referanceArray);
    }
    else if ((mouseX > 653 && mouseX < 733) && (mouseY > 430 && mouseY < 612) && *turn && *play) {//pit11
        *turn = false;
        if (referanceArray[11].numberofPiyon == 3)
            *turn = true;
        referanceArray[11].move(referanceArray);
    }
    else if ((mouseX > 755 && mouseX < 837) && (mouseY > 430 && mouseY < 612) && *turn && *play) {//pit12
        *turn = false;
        if (referanceArray[12].numberofPiyon == 2|| referanceArray[12].numberofPiyon == 1)
            *turn = true;
        referanceArray[12].move(referanceArray);
    }
}

void playGame() {
    
    draw();

    clicks(mouseX, mouseY, referanceList,turn,play);

    text = (*turn == true) ? "Turn P1" : "Turn P2";
    drawText(text.data(), text.size(), 20,20);

    finishGame(referanceList);  
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        mouseX = x;
        mouseY = y;
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    
    drawTable();
    drawPits();
    drawMenu();
    playGame();

    glutSwapBuffers();
}


void initGL() {
    glMatrixMode(GL_PROJECTION);
    gluPerspective(76.0f, 1.0f, 0.0f, 0.0f);

    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glPointSize(20.0);
}

void reshape(GLsizei width, GLsizei height) {
    UNUSED(width);
    UNUSED(height);
    // Make the window non-resizable so we don't have to worry about size changes
    glutReshapeWindow(1080, 720);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);

    glutInitWindowSize(1080, 720);
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) - 1080) / 2,(glutGet(GLUT_SCREEN_HEIGHT) - 720) / 2);
    glutCreateWindow(title);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouse);

    //srand(time(NULL));

    initGL();
    glutMainLoop();

    return 0;
}