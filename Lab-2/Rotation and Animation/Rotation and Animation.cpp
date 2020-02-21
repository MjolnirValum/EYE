// Rotation and Animation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>
#define GL_SILENCE_DEPRECATION
#include <gl/glut.h>

int angle = 0;

void singleRotation() {
    glRotatef(angle,0,1,0);
}

void voidRotation() { glRotatef(-angle, 0, 1, 0); }

void display() {    //NOTE!!!!:  The commented out methods will make all objects spin independently as well as
                    //grouped as it is now, commenting out the noted top and bottom of the methods tied to
                    //grouping will allow for independent rotations!
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
   
    
    singleRotation();  //rotates as a group, tied to the voidRotation() method towards the end of this method


    //MID-center, MAGENTA
    glColor3f(1.0, 0.0, 1.0);
    glTranslatef(0, 0, 0);
    //singleRotation();
    glutWireTeapot(0.17);
    //voidRotation();

    //BOT-left, RED
    glColor3f(1.0, 0.0, 0.0);
    glTranslatef(-.65, -.65, 0);
    //singleRotation();
    glutWireCone(.2, .2, 15, 5);
    //voidRotation();
    
    //MID-left, GREEN
    glColor3f(0.0, 1.0, 0.0);
    glTranslatef(0, .65, 0);
    //singleRotation();
    glutWireCube(.27);
    //voidRotation();

    //TOP-left, BLUE
    glColor3f(0.0, 0.0, 1.0);
    glTranslatef(0, .65, 0);
    //singleRotation();
    glutWireTorus(.05, .15, 5, 30);
    //voidRotation();
    
    //TOP-center, CYAN
    glColor3f(0.0, 1.0, 1.0);
    glTranslatef(.65, 0, 0);
    //singleRotation();
    glutWireSphere(.2, 20, 10);
    //voidRotation();
    
    //BOT-center, YELLOW
    glColor3f(1.0, 1.0, 0.0);
    glTranslatef(0, -1.3, 0);
    //singleRotation();
    glutWireCone(.2, .2, 15, 5);
    //voidRotation();    

    //BOT-right, LIGHT GRAY
    glColor3f(1, 1, 1);
    glTranslatef(.65, 0, 0);
    //singleRotation();
    glutWireCube(0.27);
    //voidRotation();
    
    //MID-right, MEDIUM GRAY
    glColor3f(0.6, 0.6, 0.6);
    glTranslatef(0, .65, 0);
    //singleRotation();
    glutWireTorus(.05, .15, 5, 30);
    //voidRotation();
    
    //TOP-right, DARK GRAY
    glColor3f(0.2, 0.2, 0.2);
    glTranslatef(0, .65, 0);
    //singleRotation();
    glutWireSphere(.2, 20, 10);
    //voidRotation();    


    voidRotation(); //rotates as a group, tied to the method at the beginning of this method


    //forces input to screen
    glFlush();

}













void display1() {
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT);
    glRotatef(angle,0,1,0);
    glutWireTeapot(0.5);
    glFlush();
}

void idle(void) {
    angle++;
    angle %= 360;
    glutPostRedisplay();
}

int main(int argc, char * argv[])
{
    glutInit(&argc, argv);
    glutCreateWindow("Animation 1");
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutMainLoop();

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
