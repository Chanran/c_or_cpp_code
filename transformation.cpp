#include <GL/glut.h>
#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;

GLint winWidth=800,winHeight=800;

GLfloat tmatrix[3][3] = {{1,0,100},{0,1,100},{0,0,1}}; //平移矩阵,默认向右平移100
GLfloat smatrix[3][3] = {{2,0,0},{0,2,0},{0,0,1}};      //缩放矩阵,默认放大两倍
GLfloat rmatrix[3][3] = {{cos(60),-sin(60),0},{sin(60),cos(60),0},{0,0,1}}; //旋转矩阵,默认逆时针旋转60度
GLfloat tcoord[3][3] = {{100,100,150},{100,200,150},{1,1,1}}; //坐标组转置矩阵
//GLfloat scoord[3][3] = {{100,100,150},{100,200,150},{1,1,1}}; //坐标组转置矩阵
//GLfloat rcoord[3][3] = {{100,100,150},{100,200,150},{1,1,1}}; //坐标组转置矩阵

// 封装矩阵乘法
void matrixMultiple(GLfloat (&coord)[3][3],const GLfloat (&xmatrix)[3][3]){
    int i,j;
    GLfloat tmp[3][3];

    for (i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            tmp[i][j] = coord[i][j];
        }
    }

    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            cout << coord[0][0] << " " <<  coord[0][1] << " " << coord[0][2] << endl;
            cout << coord[1][0] << " " <<  coord[1][1] << " " << coord[1][2] << endl;
            cout << coord[2][0] << " " <<  coord[2][1] << " " << coord[2][2] << endl;
            coord[i][j] = xmatrix[i][0]*tmp[0][j]+xmatrix[i][1]*tmp[1][j]+xmatrix[i][2]*tmp[2][j];
            cout << coord[0][0] << " " <<  coord[0][1] << " " << coord[0][2] << endl;
            cout << coord[1][0] << " " <<  coord[1][1] << " " << coord[1][2] << endl;
            cout << coord[2][0] << " " <<  coord[2][1] << " " << coord[2][2] << endl;
        }
    }
}

// 画一个三角形
void drawTriangle(const GLfloat (&coord)[3][3]){
    glBegin(GL_TRIANGLES);
        glColor3f(1.0f,0.0f,0.0f);
        glVertex2f(coord[0][0],coord[1][0]);
        glVertex2f(coord[0][1],coord[1][1]);
        glVertex2f(coord[0][2],coord[1][2]);
    glEnd();
    glFlush();
}

// 平移
void translation(const GLfloat& xIncrement,const GLfloat& yIncrement){
    tmatrix[0][2] = xIncrement;
    tmatrix[1][2] = yIncrement;
    matrixMultiple(tcoord,tmatrix);
    drawTriangle(tcoord);
}

// 缩放
void scale(const GLfloat& xScaling,const GLfloat& yScaling){
    smatrix[0][0] = xScaling;
    smatrix[1][1] = yScaling;
    matrixMultiple(tcoord,smatrix);
    drawTriangle(tcoord);
}

// 旋转
void Rotate(const GLfloat& angle){
    int i,j;
    GLfloat tmp[3][3];
    for (i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            tmp[i][j] = tcoord[i][j];
        }
    }
    glTranslatef(tcoord[0][0],tcoord[1][0],0);
    rmatrix[0][0] = cos(angle);
    rmatrix[0][1] = -sin(angle);
    rmatrix[1][0] = sin(angle);
    rmatrix[1][1] = cos(angle);
    matrixMultiple(tcoord,rmatrix);
    glTranslatef(-tcoord[0][0],-tcoord[1][0],0);
    drawTriangle(tcoord);
}

// 菜单
void mymenu(int value){
    if (value == 0){
        drawTriangle(tcoord);
    }
    if (value == 1){
        GLfloat xIncrement,yIncrement;
        cout << "请输入,x和y的增量(空格分割):";
        cin >> xIncrement >> yIncrement;
        translation(xIncrement,yIncrement);
    };
    if (value == 2){
        GLfloat xScaling,yScaling;
        cout << "请输入沿x和y轴的缩放比例(空格分割):";
        cin >> xScaling >> yScaling;
        scale(xScaling,yScaling);
    };
    if (value == 3){
        GLfloat angle;
        cout << "请输入旋转角度:";
        cin  >> angle;
        Rotate(angle);
    }
}

// 初始化
void init(){
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,winWidth,0,winHeight);
}

// 展示
void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.0,1.0,1.0,0.0);
    drawTriangle(tcoord);
    glFlush();
}

// 主程序
int main(int argc,char *argv[]){

    glutInit(&argc,argv);
    glutInitWindowPosition(1000,0);
    glutInitWindowSize(winWidth,winHeight);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("plane transformation");
    init();
    glutCreateMenu(mymenu);
    glutAddMenuEntry("drawTriangle",0);
    glutAddMenuEntry("translation",1);
    glutAddMenuEntry("scale",2);
    glutAddMenuEntry("rotate",3);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
