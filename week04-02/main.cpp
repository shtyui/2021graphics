#include <GL/glut.h>///�ϥ�GLUT�~��
#include <math.h>///�ϥμƾǥ~��
#include <stdio.h>///�]���nprintf
int N=0,vx[3000],vy[3000];
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);///�M��
    glBegin(GL_LINE_STRIP);
    for(int i=0;i<N;i++){
        glVertex2f((vx[i]-150)/150.0,-(vy[i]-150)/150.0);
    }   ///��@�b ���@�b
    glEnd();
    glutSwapBuffers();
}

void motion(int x,int y)
{   ///��,��,�k,�W,�U,x�y��,y�y��
    vx[N]=x; vy[N]=y;
    N++;
    display();
}
int main(int argc, char *argv[])///main()�禡
{
    glutInit(&argc, argv);///(1)Init��l��GLUT
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);///(2)Init��l�� Display ���\��
    glutCreateWindow("08160075 �d�^�L");///(3)�إ�GLUT����

    glutDisplayFunc(display);///(4)�ǳ�display()�禡
    glutMotionFunc(motion);///���Umotion�禡

    glutMainLoop();///(5)�D�n�{��
}
