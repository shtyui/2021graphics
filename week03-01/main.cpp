#include <GL/glut.h>///�ϥ�GLUT�~��
#include <math.h>///�ϥμƾǥ~��
static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);///�M�I��

    glColor3f(1,0,0);
    glBegin(GL_POLYGON);
    for(int i=0;i<30;i++){
        float a=3.1415926*2/30*i;
        glVertex2f(0.5+0.1*cos(a),0.7*sin(a));
    }
    glEnd();


    ///glutSolidTeapot(0.3);
    glutSwapBuffers();///��s�e��
}
int main(int argc, char *argv[])///main()�禡
{
    glutInit(&argc, argv);///(1)Init��l��GLUT
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);///(2)Init��l�� Display ���\��
    glutCreateWindow("Week03_circle");///(3)�إ�GLUT����
    glutDisplayFunc(display);///(4)�ǳ�display()�禡
    glutMainLoop();///(5)�D�n�{��
}
