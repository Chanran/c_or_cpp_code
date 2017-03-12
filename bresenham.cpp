#include <GL/glut.h>
#include <iostream>

using namespace std;

void init();
void drawPoint(GLint x,GLint y);
void dragToNewLine(int button,int state,GLint x, GLint y);
void swap (GLint *a,GLint *b);
void drawLine(GLint x1,GLint y1,GLint x2,GLint y2);
void display();

GLint winWidth=600,winHeight=600;
GLint x1 = 0,y1 = 0;
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

void init(){
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,winWidth,0,winHeight);
}

void drawPoint(GLint x,GLint y){
    glBegin(GL_POINTS);
    glColor3f(0.0,0.0,0.0);
    glVertex2i(x,y);
    glEnd();
    glFlush();
}

void dragToNewLine(int button,int state,GLint x,GLint y){
    y = winHeight - y;
    if (button == GLUT_LEFT_BUTTON){
        if (state == GLUT_DOWN){
            cout << x  << "  " << y << endl;
            x1 = x;
            y1 = y;
        }else if (state == GLUT_UP){
            cout << x  << "  " << y << endl;
            glColor3f(0.0,0.0,0.0);
            drawLine(x1,y1,x,y);
            glFlush();
        }
    }
}

void swap(GLint *a,GLint *b){
    GLint* tmp;
    tmp = a;
    a = b;
    b = tmp;
}

void drawLine(GLint x1,GLint y1,GLint x2,GLint y2){
    int x,y;
    if (x1 > x2){
        swap(x1,x2);
        swap(y1,y2);
    }

    x = x1;
    y = y1;
    drawPoint(x1,y1);

    /*平行的情况*/
    //平行y轴的情况
    if (x1 == x2){
        while(y < y2){
            y++;
            drawPoint(x,y);
        }
        return;
    }
    //平行x轴的情况
    if (y1 == y2){
        while(x < x2){
            x++;
            drawPoint(x,y);
        }
        return;
    }

    /*不平行的情况*/
    int deltaX = x2 - x1,deltaY = y2 - y1; //△x,△y
    double k = (double)deltaY / (double)deltaX; //斜率
    int di; //初始值d0

    //0<斜率k<1的情况
    if (k > 0 && k < 1){
        di = 2*deltaY - deltaX;  //初始值是d0
        while(x < x2){
            if (di < 0){
                di += 2 * deltaY;
            }else{
                di += 2 * (deltaY - deltaX);
                y++;
            }
            x++;
            drawPoint(x,y); //画第二个点
        }
    }

    //斜率k>=1的情况
    if(k >= 1)
    {
        di = deltaY;
        while(y<y2){
            if(di < 0){
                di += 2 * deltaX;
            }else{
                di += 2 * (deltaX - deltaY);
                x++;
            }
            y++;
            drawPoint(x,y);
        }
    }

    //-1<斜率k<0的情况
    if ( -1 < k && k < 0){
        di = 2 * deltaY + deltaX;
        while( x < x2){
            if(di >= 0){
                di += 2 * deltaY;
            }
            else{
                di += 2 * (deltaY + deltaX);
                y--;
            }
            x++;
            drawPoint(x,y);
        }
    }

    //斜率k<-1的情况
    if ( k < -1){
        di= 2 * deltaX - deltaY;
        while( y > y2){
            y--;
            if( di >= 0)
                di -= 2 * deltaX;
            else{
                di -= 2 * (deltaY + deltaX);
                x++;
            }
            drawPoint(x,y);
        }
    }
}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}
