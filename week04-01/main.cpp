#include <GL/glut.h>///使用GLUT外掛
#include <math.h>///使用數學外掛
#include <stdio.h>///因為要printf
int N=0,vx[3000],vy[3000];
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);///清空
    glBegin(GL_LINE_STRIP);
    for(int i=0;i<N;i++){
        glVertex2f((vx[i]-150)/150.0,-(vy[i]-150)/150.0);
    }   ///減一半 除一半
    glEnd();
    glutSwapBuffers();
}

void motion(int x,int y)
{   ///左,中,右,上,下,x座標,y座標
    vx[N]=x; vy[N]=y;
    N++;
    display();
}
int main(int argc, char *argv[])///main()函式
{
    glutInit(&argc, argv);///(1)Init初始化GLUT
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);///(2)Init初始化 Display 的功能
    glutCreateWindow("08160075 吳英昭");///(3)建立GLUT視窗

    glutDisplayFunc(display);///(4)準備display()函式
    glutMotionFunc(motion);///註冊motion函式

    glutMainLoop();///(5)主要程式
}
