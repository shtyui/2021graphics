#include <Gl/glut.h>
float angle=0;
void drawArm1()
{
    glPushMatrix();
        glScalef(1,0.5,0.5);///�ܲӪ�
        glColor3f(0,1,0);
        glutSolidCube(0.2);///�����u
    glPopMatrix();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
/// glutSolidSphere(0.3,30,30);///���
    glPushMatrix();
        ///glutWireCube(0.3);///�u��
        glColor3f(1,1,1);
        glutSolidCube(0.4);///�զ⨭��
        glPushMatrix();
            glTranslatef(-0.2,0.2,0);///���W�ӻH
            glRotatef(angle,0,0,1);///���
            glTranslatef(-0.1,0,0);///���ʨ줤��
            drawArm1();///�����u
        glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
}
int diff=2;
void timer(int t)///timer�T�_��,���ݭn������
{
    ///20:50 fps ,30:33fps, 50:20fps
    glutTimerFunc(20,timer,t+1);///�_�ɰO�x��
    glClearColor(1,0,0,0);///�M�I����:����
    if(angle>90)diff=-2;
    if(angle<0) diff=+2;
    angle+=diff;
    display();///���e�e��
}
int main(int agrc,char **argv)
{
    glutInit(&agrc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Week14_timer");

    glutDisplayFunc(display);
    glutTimerFunc(3000,timer,0);///(0,0,���h�[)
    glutMainLoop();
}
