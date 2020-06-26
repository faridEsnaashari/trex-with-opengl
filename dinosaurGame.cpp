#include <GL/glut.h>
#include <iostream>

using namespace std;


const int dinosaurSquareOne_x[4] = {-310, -310, -305, -305};
const int dinosaurSquareOne_y[4] = {10, 0, 0, 10};

const int dinosaurSquareTow_x[4] = {-290, -290, -285, -285};
const int dinosaurSquareTow_y[4] = {10, 0, 0, 10};

const int dinosaurSquareThree_x[4] = {-310, -310, -280, -280};
const int dinosaurSquareThree_y[4] = {30, 10, 10, 30};

const int dinosaurSquareFour_x[4] = {-280, -280, -275, -275};
const int dinosaurSquareFour_y[4] = {20, 15, 15, 20};

const int dinosaurSquareFive_x[4] = {-280, -280, -275, -275};
const int dinosaurSquareFive_y[4] = {28, 23, 23, 28};

const int dinosaurSquareSix_x[4] = {-290, -290, -270, -270};
const int dinosaurSquareSix_y[4] = {45, 30, 30, 45};


const int cacrusSquareOne_x[4] = {300, 300, 320, 320};
const int cacrusSquareOne_y[4] = {40, 20, 20, 40};

const int cacrusSquareTow_x[4] = {325, 325, 345, 345};
const int cacrusSquareTow_y[4] = {50, 0, 0, 50};

const int cacrusSquareThree_x[4] = {350, 350, 370, 370};
const int cacrusSquareThree_y[4] = {60, 30, 30, 60};

const int cacrusSquareFour_x[4] = {320, 320, 330, 330};
const int cacrusSquareFour_y[4] = {30, 20, 20, 30};

const int cacrusSquareFive_x[4] = {345, 345, 355, 355};
const int cacrusSquareFive_y[4] = {40, 30, 30, 40};





const int plainSquare_x[4] = {500, 500, -500, -500};
const int plainSquare_y[4] = {0, -10, -10, 0};



void start();
void cactusMoveLoop();
void dinosaurJumpLoop();
void gameOver();

void cactusInit();
void dinosaurInit();
void cactusMove();
void dinosaurJump();
void collisionDetection();
void jumpDetection(unsigned char key, int x, int y);
void countScore();
void plainInit();

float cactus_x = .1;
float dinosaur_y = .1;
bool dinosaurMax_yReached;
int score = 0;
int numberCount = 0;
int main(int argc , char* argv[])
{
    glutInit(&argc , argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(0 , 0);
    glutInitWindowSize(900 , 600);
    glutCreateWindow("DinosaurGame");
    glMatrixMode(GL_PROJECTION);
    glClearColor(1 , 1 , 1 , 1);
    gluOrtho2D(-450 , 450 , -300 , 300);
    glutDisplayFunc(start);
    glutKeyboardFunc(jumpDetection);
    glutMainLoop();


    return 0;
}

void plainInit()
{
    for(int i = 0; i<4; i++)
    {
        glVertex2i(plainSquare_x[i], plainSquare_y[i]);
    }
}
void gameOver()
{
    cout << "your score is : " << score << endl;
}
void countScore()
{
    score += (cactus_x/100);
    cout << score << endl;
}

void collisionDetection()
{
    if((dinosaurSquareOne_x[1] < cacrusSquareThree_x[3] - cactus_x) && (dinosaurSquareSix_x[3] > cacrusSquareOne_x[0] - cactus_x) && (dinosaurSquareOne_y[1] + dinosaur_y < cacrusSquareThree_y[0]))
    {
        glutDisplayFunc(gameOver);
        glutPostRedisplay();
    }
}
void dinosaurJump()
{
    //squareOne
    for(int i = 0; i<4; i++)
    {
        glVertex2i(dinosaurSquareOne_x[i], dinosaurSquareOne_y[i] + dinosaur_y);
    }

    //squareTwo
    for(int i = 0; i<4; i++)
    {
        glVertex2i(dinosaurSquareTow_x[i], dinosaurSquareTow_y[i] + dinosaur_y);
    }

    //squareThree
    for(int i = 0; i<4; i++)
    {
        glVertex2i(dinosaurSquareThree_x[i], dinosaurSquareThree_y[i] + dinosaur_y);
    }

    //squareFour
    for(int i = 0; i<4; i++)
    {
        glVertex2i(dinosaurSquareFour_x[i], dinosaurSquareFour_y[i] + dinosaur_y);
    }

    //squareFive
    for(int i = 0; i<4; i++)
    {
        glVertex2i(dinosaurSquareFive_x[i], dinosaurSquareFive_y[i] + dinosaur_y);
    }

    //squareSix
    for(int i = 0; i<4; i++)
    {
        glVertex2i(dinosaurSquareSix_x[i], dinosaurSquareSix_y[i] + dinosaur_y);
    }

    if(dinosaur_y < 150 && !dinosaurMax_yReached)
    {
        dinosaur_y += .2;
    }
    else
    {
        dinosaurMax_yReached = true;
        dinosaur_y -= .2;

        if(dinosaur_y < .1)
        {
            dinosaurMax_yReached = false;
            glutDisplayFunc(cactusMoveLoop);
            glutPostRedisplay();
        }
    }
}
void cactusMove()
{
    //squareOne
    for(int i = 0; i<4; i++)
    {
        glVertex2i(cacrusSquareOne_x[i] - cactus_x, cacrusSquareOne_y[i]);
    }

    //squareTwo
    for(int i = 0; i<4; i++)
    {
        glVertex2i(cacrusSquareTow_x[i] - cactus_x, cacrusSquareTow_y[i]);
    }

    //squareThree
    for(int i = 0; i<4; i++)
    {
        glVertex2i(cacrusSquareThree_x[i] - cactus_x, cacrusSquareThree_y[i]);
    }

    //squareFour
    for(int i = 0; i<4; i++)
    {
        glVertex2i(cacrusSquareFour_x[i] - cactus_x, cacrusSquareFour_y[i]);
    }

    //squareFive
    for(int i = 0; i<4; i++)
    {
        glVertex2i(cacrusSquareFive_x[i] - cactus_x, cacrusSquareFive_y[i]);
    }

    if(cactus_x < 850)
    {
        cactus_x += .2;
        countScore();
    }
    else
    {
        cactus_x = .1;
    }
}
void dinosaurInit()
{
    //squareOne
    for(int i = 0; i<4; i++)
    {
        glVertex2i(dinosaurSquareOne_x[i], dinosaurSquareOne_y[i]);
    }

    //squareTwo
    for(int i = 0; i<4; i++)
    {
        glVertex2i(dinosaurSquareTow_x[i], dinosaurSquareTow_y[i]);
    }

    //squareThree
    for(int i = 0; i<4; i++)
    {
        glVertex2i(dinosaurSquareThree_x[i], dinosaurSquareThree_y[i]);
    }

    //squareFour
    for(int i = 0; i<4; i++)
    {
        glVertex2i(dinosaurSquareFour_x[i], dinosaurSquareFour_y[i]);
    }

    //squareFive
    for(int i = 0; i<4; i++)
    {
        glVertex2i(dinosaurSquareFive_x[i], dinosaurSquareFive_y[i]);
    }

    //squareSix
    for(int i = 0; i<4; i++)
    {
        glVertex2i(dinosaurSquareSix_x[i], dinosaurSquareSix_y[i]);
    }
}
void cactusInit()
{
    //squareOne
    for(int i = 0; i<4; i++)
    {
        glVertex2i(cacrusSquareOne_x[i], cacrusSquareOne_y[i]);
    }

    //squareTwo
    for(int i = 0; i<4; i++)
    {
        glVertex2i(cacrusSquareTow_x[i], cacrusSquareTow_y[i]);
    }

    //squareThree
    for(int i = 0; i<4; i++)
    {
        glVertex2i(cacrusSquareThree_x[i], cacrusSquareThree_y[i]);
    }

    //squareFour
    for(int i = 0; i<4; i++)
    {
        glVertex2i(cacrusSquareFour_x[i], cacrusSquareFour_y[i]);
    }

    //squareFive
    for(int i = 0; i<4; i++)
    {
        glVertex2i(cacrusSquareFive_x[i], cacrusSquareFive_y[i]);
    }
}
void jumpDetection(unsigned char key, int x, int y)
{
    if(key == 'j')
    {
        glutDisplayFunc(dinosaurJumpLoop);
        glutPostRedisplay();
    }
}
void start()
{
    glBegin(GL_QUADS);
        plainInit();
        cactusInit();
        dinosaurInit();
    glEnd();

    glFlush();

    glutDisplayFunc(cactusMoveLoop);
    glutPostRedisplay();
}
void cactusMoveLoop()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3ub(1 , 1 , 1);
    glBegin(GL_QUADS);
        plainInit();
        dinosaurInit();
        cactusMove();
    glEnd();

    collisionDetection();

    glFlush();

    glutPostRedisplay();
    // game.Update();
}
void dinosaurJumpLoop()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3ub(1 , 1 , 1);
    glBegin(GL_QUADS);
        plainInit();
        dinosaurJump();
        cactusMove();
    glEnd();

    collisionDetection();

    glFlush();

    glutPostRedisplay();
}
