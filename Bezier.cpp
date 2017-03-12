// Bezier.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<Windows.h>
#include<GL/glut.h>
#include<math.h>

using namespace std;

const int POINTNUM = 4;

struct Point {
	float x;
	float y;
};

Point polypoint[POINTNUM] = {
   
	110,359,
	221,251,
	362,497,
	534,334
};
Point vStart, vEnd;

void init() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 700, 0, 700);

}

//*********划线算法*****************************************************************
void drawOneLine1(int x1, int y1, int x2, int y2) {

	int dx, dy;
	dx = x2 - x1;
	dy = y2 - y1;

	int tempC = 2 * (dy - dx);
	int tempV = 2 * dy;
	int d = tempV - dx;

	for (int i = 0; i <= dx; i++) {

		glBegin(GL_POINTS);

		glVertex2f(x1, y1);

		x1++;
		if (d < 0) {
			d += tempV;
		}
		else {
			y1++;
			d += tempC;
		}

		glEnd();
	}

}

void drawOneLine2(int x1, int y1, int x2, int y2) {

	int dx, dy;
	dx = x2 - x1;
	dy = y2 - y1;

	int tempC = 2 * dx;
	int tempV = 2 * (dx - dy);

	int d = tempC - dy;

	for (int i = 0; i <= dy; i++) {

		glBegin(GL_POINTS);
		glVertex2f(x1, y1);

		y1++;
		if (d < 0) {
			d += tempC;

		}
		else {
			x1++;
			d += tempV;
		}
		glEnd();
	}


}

void drawOneLine3(int x1, int y1, int x2, int y2) {

	int dx, dy;
	dx = x2 - x1;
	dy = y2 - y1;

	int tempC = 2 * (-dy - dx);
	int tempV = 2 * (-dy);
	int d = tempV - dx;

	for (int i = 0; i <= dx; i++) {

		glBegin(GL_POINTS);

		glVertex2f(x1, y1);

		x1++;
		if (d < 0) {
			d += tempV;
		}
		else {
			y1--;
			d += tempC;
		}
		glEnd();
	}



}

void drawOneLine4(int x1, int y1, int x2, int y2) {

	int dx, dy;
	dx = x2 - x1;
	dy = y2 - y1;

	int tempC = 2 * (dx);
	int tempV = 2 * (dx + dy);

	int d = tempC - dy;

	for (int i = 0; i <= -dy; i++) {

		glBegin(GL_POINTS);
		glVertex2f(x1, y1);

		y1--;
		if (d < 0) {
			d += tempC;

		}
		else {
			x1++;
			d += tempV;
		}
		glEnd();
	}

}

void drawLine() {

	glPointSize(1.0);

	for (int i = 0; i < POINTNUM; i++) {

		int dx = abs(polypoint[(i + 1 + POINTNUM) % POINTNUM].x - polypoint[i].x);
		int dy = abs(polypoint[(i + 1 + POINTNUM) % POINTNUM].y - polypoint[i].y);

		if (polypoint[i].x < polypoint[(i + 1 + POINTNUM) % POINTNUM].x) {
			if (polypoint[(i + 1 + POINTNUM) % POINTNUM].y > polypoint[i].y) {
				if (dx > dy) {
					drawOneLine1(polypoint[i].x, polypoint[i].y, polypoint[(i + 1 + POINTNUM) % POINTNUM].x, polypoint[(i + 1 + POINTNUM) % POINTNUM].y);
				}
				else {
					drawOneLine2(polypoint[i].x, polypoint[i].y, polypoint[(i + 1 + POINTNUM) % POINTNUM].x, polypoint[(i + 1 + POINTNUM) % POINTNUM].y);
				}
			}
			else {
				if (dx > dy) {
					drawOneLine3(polypoint[i].x, polypoint[i].y, polypoint[(i + 1 + POINTNUM) % POINTNUM].x, polypoint[(i + 1 + POINTNUM) % POINTNUM].y);
				}
				else {
					drawOneLine4(polypoint[i].x, polypoint[i].y, polypoint[(i + 1 + POINTNUM) % POINTNUM].x, polypoint[(i + 1 + POINTNUM) % POINTNUM].y);
				}
			}
		}
		else {
			if (polypoint[(i + 1 + POINTNUM) % POINTNUM].y < polypoint[i].y) {
				if (dx > dy) {
					drawOneLine1(polypoint[(i + 1 + POINTNUM) % POINTNUM].x, polypoint[(i + 1 + POINTNUM) % POINTNUM].y, polypoint[i].x, polypoint[i].y);
				}
				else {
					drawOneLine2(polypoint[(i + 1 + POINTNUM) % POINTNUM].x, polypoint[(i + 1 + POINTNUM) % POINTNUM].y, polypoint[i].x, polypoint[i].y);
				}
			}
			else {
				if (dx > dy) {
					drawOneLine3(polypoint[(i + 1 + POINTNUM) % POINTNUM].x, polypoint[(i + 1 + POINTNUM) % POINTNUM].y, polypoint[i].x, polypoint[i].y);
				}
				else {
					drawOneLine4(polypoint[(i + 1 + POINTNUM) % POINTNUM].x, polypoint[(i + 1 + POINTNUM) % POINTNUM].y, polypoint[i].x, polypoint[i].y);
				}
			}
		}

	}

}

//***************************************************************************


void bezier() {
	double t = 0;
	Point p;

	while (t <= 1) {

		p.x = pow((1 - t), 3)*polypoint[0].x+3*t*pow((1-t),2)*polypoint[1].x+3*pow(t,2)*(1-t)*polypoint[2].x+pow(t,3)*polypoint[3].x;		
		p.y = pow((1 - t), 3)*polypoint[0].y + 3 * t*pow((1 - t), 2)*polypoint[1].y + 3 * pow(t, 2)*(1 - t)*polypoint[2].y + pow(t, 3)*polypoint[3].y;
		glBegin(GL_POINTS);
		glVertex2f(p.x,p.y);
		t += 0.001;

	}

	glEnd();
}

void display() {
	glClearColor(0.0, 0.0, 0.0, 0.0);//设置背景颜色
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0.0, 0.0, 1.0);//设置描点的颜色
	
	drawLine();
	bezier();

	glFlush();

}

int main(int argc,char* argv[])
{
	cout << "hello world" << endl;

	glutInit(&argc, argv);
	glutInitWindowPosition(50, 100);
	glutInitWindowSize(700, 700);
	glutCreateWindow("experiment");
	init();
	glutDisplayFunc(display);	

	glutMainLoop();

	system("pause");
    return 0;
}

