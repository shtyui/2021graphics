#include <GL/glut.h>///使用GLUT外掛
#include <math.h>///使用數學外掛
static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);///清背景

    glColor3f(1,0,0);
    glBegin(GL_POLYGON);
    for(int i=0;i<30;i++){
        float a=3.1415926*2/30*i;
        glVertex2f(0.5+0.1*cos(a),0.7*sin(a));
    }
    glEnd();


    ///glutSolidTeapot(0.3);
    glutSwapBuffers();///更新畫面
}
int main(int argc, char *argv[])///main()函式
{
    glutInit(&argc, argv);///(1)Init初始化GLUT
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);///(2)Init初始化 Display 的功能
    glutCreateWindow("Week03_circle");///(3)建立GLUT視窗
    glutDisplayFunc(display);///(4)準備display()函式
    glutMainLoop();///(5)主要程式
}
