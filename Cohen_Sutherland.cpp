// Cut2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <GL/glut.h>

#include <stdio.h>

#include <stdlib.h>

#define LEFT_EDGE 1
#define RIGHT_EDGE 2
#define BOTTOM_EDGE 4
#define TOP_EDGE 8
float ymin=100;int ymax=300;int xmin=100;int xmax=300;

struct Linea
{
	int x0;
	int y0;
	int x1;
	int y1;
};
Linea l1={l1.x0=450,l1.y0=0,l1.x1=0,l1.y1=450};
Linea l2={l2.x0=450,l2.y0=200,l2.x1=0,l2.y1=200};
Linea l3={l3.x0=200,l3.y0=0,l3.x1=200,l3.y1=450};

void LineGL(Linea &li)			//没有&，引用改变li的值
{
	glBegin(GL_LINES);
	glColor3f(1.0f,0.0f,0.0f);		glVertex2f(li.x0,li.y0);    
	glColor3f(0.0f,1.0f,0.0f);		glVertex2f(li.x1,li.y1);		//虽然两个点的颜色设置不同，但是最终线段颜色是绿色
	glEnd();												//因为glShadeModel(GL_FLAT)设置为最后一个顶点的颜色
}															//决定整个图元的颜色。

int CompCode(int x,int y)
{
	int code=0x00;	//此处是二进制
	if(y<ymin)
		code=code|4;
	if(y>ymax)
		code=code|8;
	if(x>xmax)
		code=code|2;
	if(x<xmin)
		code=code|1;
	return code;
}

int cohensutherlandlineclip(Linea &li)
{
	int accept=0,done=0;
	float x=0,y=0;
	
	int total=0,flag=0;			//total与flag是标志
	int code0,code1,codeout;
	code0=CompCode(li.x0,li.y0);
	//printf("code0=%d\n",code0);
	code1=CompCode(li.x1,li.y1);
	//printf("code1=%d\n",code1);
	do{
		if(!(code0|code1))		//code0&code1=0000B,线段完全在窗口内部，全部显示
		{
			accept=1;
			done=1;
		}
		else if(code0 & code1)
		{
			done=1;flag=1;
		}			
		else
		{
			if(code0!=0)
				codeout=code0;
			else
				codeout=code1;

			if(codeout&LEFT_EDGE)
			{
				
				y=li.y0+(li.y1-li.y0)*(xmin-li.x0)/(li.x1-li.x0);
				x=(float)xmin;
				
			}
			else if(codeout&RIGHT_EDGE)
			{	
				y=li.y0+(li.y1-li.y0)*(xmax-li.x0)/(li.x1-li.x0);
				x=(float)xmax;
			}
			else if(codeout&BOTTOM_EDGE)
			{
				x=li.x0+(li.x1-li.x0)*(ymin-li.y0)/(li.y1-li.y0);
				y=(float)ymin;
			}
			else if(codeout&TOP_EDGE)
			{
				x=li.x0+(li.x1-li.x0)*(ymax-li.y0)/(li.y1-li.y0);
				y=(float)ymax;
			}
			if(codeout==code0)
			{
				li.x0=x;	li.y0=y;
				code0=CompCode(li.x0,li.y0);
			}
			else
			{
				li.x1=x;	li.y1=y;
				code1=CompCode(li.x1,li.y1);
			}
			total++;
			if(total>3)				//total>3,执行两次后total又加一
			{
				done=1;flag=1;
			}
		}		
	}while(!done);
	if(accept)		//线段位于窗口内或者线段剪裁过accept=1;
	{
		LineGL(li);
	}	
	else
	{
		li.x0=0;li.y0=0;li.x1=0;li.y1=0;
		LineGL(li);
	}	
	return accept;
}

void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f,0.0f,0.0f);
	glBegin(GL_LINE_LOOP);
	glVertex2f(100,100);
	glVertex2f(300,100);
	glVertex2f(300,300);
	glVertex2f(100,300);
	glEnd();
	LineGL(l1);
	LineGL(l2);
	LineGL(l3);
	glFlush();
}

void Init()
{
	glClearColor(0.0,0.0,0.0,0.0);
	glShadeModel(GL_FLAT);
	printf("Press key 'c' to Clip!\nPress key 'r' to Restore!\n");
}

void Reshape(int w,int h)
{
	glViewport(0,0,(GLsizei) w,(GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,(GLdouble) w,0.0,(GLdouble) h);
	//printf("######Reshape\n");
}
void keyboard(unsigned char key,int x,int y)
{
	switch (key)
	{
		case 'c':
			cohensutherlandlineclip(l1);
			cohensutherlandlineclip(l2);
			cohensutherlandlineclip(l3);
			glutPostRedisplay();
			break;
		case 'r':
		l1.x0=450;l1.y0=0;l1.x1=0;l1.y1=450;
		l2.x0=450;l2.y0=200;l2.x1=0;l2.y1=200;
		l3.x0=200;l3.y0=0;l3.x1=200;l3.y1=450;
			Init();
			glutPostRedisplay();
			break;
		case 'x':
			exit(0);
			break;
		default:
			break;
	}
}

int main(int argc,char *argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(640,480);
	glutCreateWindow("Hello World");

	Init();
	glutDisplayFunc(myDisplay);
	glutReshapeFunc(Reshape);
	glutKeyboardFunc(&keyboard);//按下键盘后会调用该函数，键和鼠标点击位置作为变量传给keyboard函数
	glutMainLoop();
	
	return 0;
}

