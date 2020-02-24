// Lab 2.1 - Projection Matrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>
#define GL_SILENCE_DEPRECATION
#include <gl/glut.h>




////////////////The following are used for "display12()" and the final exercise called "Rotation/Translation Exercise" which is at the bottom of the code
int angle = 0;
void idle(void) {
	angle++;
	angle %= 360;
	glutPostRedisplay();
}
void rotFor() {
	glRotatef(angle, 0, 1, 0);
}
void rotBack() {
	glRotatef(-angle, 0, 1, 0);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//this drawPlus() has its lines modified to be 5.0 and -5.0 instead of 0.5 and -0.5
void drawPlus() {
	glBegin(GL_LINES);
	glVertex2f(-5.0, 0.0);
	glVertex2f(5.0, 0.0);
	glVertex2f(0.0, -5.0);
	glVertex2f(0.0, 5.0);
	glEnd();
}
/*
void drawPlus() {
	glBegin(GL_LINES);
		glVertex2f(-5.0,0.0);
		glVertex2f(5.0,0.0);
		glVertex2f(0.0,-5.0);
		glVertex2f(0.0,5.0);
	glEnd();
}
*/

void drawPlusGroup() {
	glPushMatrix();
	
	glTranslatef(10.0,0.0,0.0);
	glColor3f(0.34, 0.87, 0.62);
	drawPlus();
	
	glPopMatrix();
	glPushMatrix();
	
	glTranslatef(-10.0, 0.0, 0.0);
	glColor3f(0.34, 0.87, 0.62);
	drawPlus();
	
	glPopMatrix();
	glPushMatrix();
	
	glTranslatef(0.0, 10.0, 0.0);
	glColor3f(0.34, 0.87, 0.62);
	drawPlus();

	glPopMatrix();
	glPushMatrix();

	glTranslatef(0.0, -10.0, 0.0);
	glColor3f(0.34, 0.87, 0.62);
	drawPlus();

	glPopMatrix();
}
void drawBigPlusGroup() {
	glPushMatrix();
	
	glTranslatef(0.0, 25.0, 0.0);
	drawPlusGroup();
	
	glPopMatrix();
	glPushMatrix();

	glTranslatef(0.0, -25.0, 0.0);
	drawPlusGroup();

	glPopMatrix();
	glPushMatrix();

	glTranslatef(25.0, 0.0, 0.0);
	drawPlusGroup();

	glPopMatrix();
	glPushMatrix();

	glTranslatef(-25.0, 0.0, 0.0);
	drawPlusGroup();

	glPopMatrix();
}

void display1() {   ////////////////////STARTS OFF WITH THIS
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glLoadIdentity();
	glFlush();
}
void display2() {   //////////////////ADDED glBegin, glVertex2f, and glEnd statements!!!!!
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glLoadIdentity();

	glBegin(GL_LINES);
		glVertex2f(-0.5, 0.0);
		glVertex2f(0.5, 0.0);
		glVertex2f(0.0, -0.5);
		glVertex2f(0.0, 0.5);
	glEnd();
	
	glFlush();
}
void display3() {   //////////////////ATTEMPTING glTranslatef statement!!!!
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glLoadIdentity();
	glTranslatef(10.0, 0.0, 0.0);  ////MUST COME AFTER glLoadIdentity()!!!!!
	glBegin(GL_LINES);
		glVertex2f(-0.5, 0.0);
		glVertex2f(0.5, 0.0);
		glVertex2f(0.0, -0.5);
		glVertex2f(0.0, 0.5);
	glEnd();

	glFlush();
}
void display4() {   //////////////////ATTEMPTING *SECOND* glTranslatef statement (which includes more drawing)!!!!
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glLoadIdentity();
	
	glTranslatef(10.0, 0.0, 0.0);
	
	glBegin(GL_LINES);
		glVertex2f(-0.5, 0.0);
		glVertex2f(0.5, 0.0);
		glVertex2f(0.0, -0.5);
		glVertex2f(0.0, 0.5);
	glEnd();
	
	glTranslatef(-20.0, 0.0, 0.0);
	
	glBegin(GL_LINES);
		glVertex2f(-0.5, 0.0);
		glVertex2f(0.5, 0.0);
		glVertex2f(0.0, -0.5);
		glVertex2f(0.0, 0.5);
	glEnd();

	glFlush();
}
void display5() {	////////////////Begin using PUSH() and POPMATRIX()
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glLoadIdentity();

	glPushMatrix();
	glTranslatef(10.0, 0.0, 0.0);
	glColor3f(0.0, 1.0, 0.0);
	drawPlus();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-10.0, 0.0, 0.0);
	glColor3f(0.0, 0.0, 1.0);
	drawPlus();
	glPopMatrix();

	glFlush();

}
void display6() {	////////////////USING drawPlusGroup()
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glLoadIdentity();
	
	drawPlusGroup();

	glFlush();

}




//////THE FOLLOWING ARE THE FIRST BATCHES OF "ATTEMPTS" AFTER MAKING THE FUNCTION drawPlusGroup()
void display7() {	////////////////****ATTEMPT "Modify display to draw the plusGroup centered at the global origin"
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, 0.0);
	drawPlusGroup();

	glFlush();
}
void display8() {	////////////////****ATTEMPT "Modify display to draw the plusGroup center at (-5,-5)"
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glLoadIdentity();
	glTranslatef(-5.0, -5.0, 0.0);
	drawPlusGroup();

	glFlush();
}
void display9() {	////////////////****ATTEMPT "Modify display to draw two different plusGroups at two different locations"
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glLoadIdentity();
	glTranslatef(-20.0, -20.0, 0.0);
	drawPlusGroup();
	glTranslatef(40.0, 40.0, 0.0);  //////   !!!!!!REMEMBER!!!!!  You have to make glTranslate statements RELATIVE to their PREVIOUS CALL!!!!!
	drawPlusGroup();

	glFlush();
}
/////////////////////////////////////////////////////////////////////////////////////////////////


void display10() {  //////USING drawBigPlusGroup() function
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glLoadIdentity();

	drawBigPlusGroup();

	glFlush();
}


///////THE FOLLOWING IS THE SECOND BATCH OF "ATTEMPTS" AFTER MAKING THE FUNCTION drawBigPlusGroup()
void display11() {  //////ATTEMPT "Drawing the bigPlusGroup() to the screen in multiple locations"
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glLoadIdentity();

	drawBigPlusGroup();

	glTranslatef(25.0, 0.0, 0.0);

	drawBigPlusGroup();

	glTranslatef(-50.0, 0.0, 0.0);

	drawBigPlusGroup();

	glTranslatef(25.0, 25.0, 0.0);

	drawBigPlusGroup();

	glTranslatef(0.0, -50.0, 0.0);

	drawBigPlusGroup();


	glFlush();
}/////this makes a diamond out of pluses
void display12() {  //////ATTEMPT "Drawing the bigPlusGroup() to the screen in multiple locations" !!!!!AND!!!! ATTEMPT "rotating the plus groups"
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glLoadIdentity();

	/*--------------------------THIS SECTION OF CODE VERIFIES THAT THE ROTATION WORKS (using the modified drawPlus() method above)
	rotFor();
	
	glTranslatef(0.0, 0.0, 0.0);
	drawBigPlusGroup();
	
	rotBack();
	*/
	
	rotFor();

	drawBigPlusGroup();
	glTranslatef(25.0, 0.0, 0.0);
	drawBigPlusGroup();
	glTranslatef(-50.0, 0.0, 0.0);
	drawBigPlusGroup();
	glTranslatef(25.0, 25.0, 0.0);
	drawBigPlusGroup();
	glTranslatef(0.0, -50.0, 0.0);
	drawBigPlusGroup();
	
	rotBack();
	
	glFlush();
}
/////////////////////////////////////////////////////////////////////////////////////////////////////

//////////The following "main" method including the "idle," "rotFor," and "rotBack" above are used ONLY FOR "display12()"//////////////
/*
int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutCreateWindow("All Too Much Lab");
	glutDisplayFunc(display12);
	glMatrixMode(GL_PROJECTION);
	//glOrtho(-20.0, 20.0, -20.0, 20.0, -1.0, 1.0);
	glOrtho(-650.0, 650.0, -650.0, 650.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glutIdleFunc(idle);
	glutMainLoop();
	return 0;
}
/////////////////////////////////////////////////////////////////////////////////
*/


//////////The following "main" method was used for all methods above except for the "idle," "rotFor," "rotBack," and second "main" methods///////////
/*
int main(int argc, char * argv[])
{
	glutInit(&argc, argv);
	glutCreateWindow("All Too Much Lab");
	glutDisplayFunc(display11);
	glMatrixMode(GL_PROJECTION);
	//glOrtho(-20.0, 20.0, -20.0, 20.0, -1.0, 1.0);
	glOrtho(-65.0, 65.0, -65.0, 65.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glutMainLoop();
	return 0;
}
*/


//////////The following methods and the "main" method below them all were used for the "Rotation/Translation Exercise" at the end of the lab

void drawTea() {
	glutWireTeapot(3.0);
}

void zRotF() {
	glRotatef(angle, 0, 0, 1);
}
void zRotB() {
	glRotatef(-angle, 0, 0, 1);
}
void zRotTea() {
	zRotF();
	drawTea();
	zRotB();
}

float wut = 13.7638192047;
float lilWut = (wut / 2.0);
void drawTeaGroup() {/////////////////////The zRotF() and zRotB() can be applied to change direction after glPushMatrix() is called each time**NOT REALLY,
	//////////////////////////////////////when I tried to interchange, things stayed put singularly, but still rotated together in group form (maybe an array of different angles for the idle method?????
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glPushMatrix();

	zRotF();
	glTranslatef(0.0, wut, 0.0);
	glColor3f(1.0, 0.0, 0.0);
	glRotatef(90, 0, 0, 1);
	zRotTea();


	glPopMatrix();
	glPushMatrix();

	zRotF();
	glTranslatef(wut, lilWut, 0.0);
	glColor3f(0.5, 0.5, 0.0);
	glRotatef(18, 0, 0, -1);
	zRotTea();


	glPopMatrix();
	glPushMatrix();

	zRotF();
	glTranslatef(lilWut, -wut, 0.0);
	glColor3f(0.0, 1.0, 0.0);
	glRotatef(306, 0, 0, 1);
	zRotTea();

	glPopMatrix();
	glPushMatrix();

	zRotF();
	glTranslatef(-lilWut, -wut, 0.0);
	glColor3f(0.0, 0.5, 0.5);
	glRotatef(234, 0, 0, 1);
	zRotTea();


	glPopMatrix();
	glPushMatrix();

	zRotF();
	glTranslatef(-wut, lilWut, 0.0);
	glColor3f(0.0, 0.0, 1.0);
	glRotatef(162, 0, 0, 1);
	zRotTea();

	glPopMatrix();

	zRotB();
}


void display13() {
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	zRotB();
	drawTeaGroup();
	zRotB();

	glFlush();
}


void display14() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(0.0, 0.0, 0.0);
	glutWireTeapot(2.0);
	glFlush();
}


int main(int argc, char * argv[])
{
	glutInit(&argc, argv);
	glutCreateWindow("All Too Much Lab");
	glutDisplayFunc(display13);
	glMatrixMode(GL_PROJECTION);
	glOrtho(-20.0, 20.0, -20.0, 20.0, -20.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
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
