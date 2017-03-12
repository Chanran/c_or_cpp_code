#include <GL/glut.h>
#include <iostream>

using namespace std;

void init();
void dragToNewLine(int button,int state,GLint x, GLint y);
void drawLine(GLint x1,GLint y1,GLint x2,GLint y2);
void boundaryFill8(GLint x,GLint y);
void setpixel(GLint x,GLint y,GLubyte color[]);
void display();

GLint winWidth=600,winHeight=600;
GLint x1 = 0,y1 = 0;
GLubyte fillColor[3] = {255,0,0};
GLubyte borderColor[3] = {0,0,0};

// 主程序
int main(int argc,char *argv[]){

    glutInit(&argc,argv);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(winWidth,winHeight);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("draw a line");
    init();
    glutDisplayFunc(display);
    glutMouseFunc(dragToNewLine);
    glutMainLoop();

    return 0;
}

// 初始化
void init(){
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,winWidth,0,winHeight);
}

// 点击拖动后出现直线
void dragToNewLine(int button,int state,GLint x,GLint y){
    y = winHeight - y;
    if (button == GLUT_LEFT_BUTTON){
        if (state == GLUT_DOWN){
            cout << x  << "  " << y << endl;
            x1 = x;
            y1 = y;
        }else if (state == GLUT_UP){
            cout << x  << "  " << y << endl;
            drawLine(x1,y1,x,y);
            glFlush();
        }
    }else{
        cout << "x:" << x << "  y:" << y << endl;
        boundaryFill4(x,y);

    }
}

// 画直线
void drawLine(GLint x1,GLint y1,GLint x2,GLint y2){
    glColor3f(borderColor[0],borderColor[1],borderColor[2]);
    glLineWidth(5.0f);
    glBegin(GL_LINES);
    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
    glEnd();
}

// 种子填充算法：八连通
void boundaryFill8(GLint x,GLint y){
    GLubyte interiorColor[3];
    glReadPixels(x,y,1,1,GL_RGB,GL_UNSIGNED_BYTE,&interiorColor);
    if ((interiorColor[0] != borderColor[0] || interiorColor[1] != borderColor[1] || interiorColor[2] != borderColor[2])&&(interiorColor[0] != fillColor[0] || interiorColor[1] != fillColor[1] || interiorColor[2] != fillColor[2])){
        cout  << "fill" << endl;
        setpixel(x,y,fillColor);
        boundaryFill8(x+1,y);  //右
        boundaryFill8(x+1,y+1);//右上
        boundaryFill8(x-1,y);  //左
        boundaryFill8(x-1,y-1);//左下
        boundaryFill8(x,y+1);  //上
        boundaryFill8(x-1,y+1);//左上
        boundaryFill8(x,y-1);  //下
        boundaryFill8(x+1,y-1); //右下
    }
}

// 画点
void setpixel(GLint x,GLint y,GLubyte color[]){
    glBegin(GL_POINTS);
    glColor3f(color[0],color[1],color[2]);
    glVertex2i(x,y);
    glEnd();
    glFlush();
}

// 展示
void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}
