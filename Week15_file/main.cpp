#include <stdio.h>///�i�Υi��
#include <GL/glut.h>
float angle[20]={},diff=2;
int angleID=0;
void timer(int t)
{
    glutTimerFunc(30,timer,t+1);
    angle[angleID]+=diff;
    if(angle[angleID]>90) diff=-2;
    if(angle[angleID]<0) diff=+2;
    glutPostRedisplay();
}
void keyboard(unsigned char key,int x,int y)
{
    if(key=='0')angleID=0;
    if(key=='1')angleID=1;
    if(key=='2')angleID=2;
    if(key=='3')angleID=3;
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glutSolidTeapot( 0.3 );///����
        glPushMatrix();///���b��
            glTranslatef(-0.3,0,0);///���b���T���a��
            glRotatef(angle[0],0,0,1);///����
            glTranslatef(-0.3,0,0);///���त�ߩ��e������
            glutSolidTeapot( 0.3 );///�����u
            glPushMatrix();
                glTranslatef(-0.3,0,0);///���b���T���a��
                glRotatef(angle[1],0,0,1);///����
                glTranslatef(-0.3,0,0);///���त�ߩ��e������
                glutSolidTeapot( 0.3 );///����y
            glPopMatrix();
        glPopMatrix();
        glPushMatrix();///�k�b��
            glTranslatef(0.3,0,0);///���b���T���a��
            glRotatef(-angle[2],0,0,1);///����
            glTranslatef(0.3,0,0);///���त�ߩ��e������
            glutSolidTeapot( 0.3 );///�k���u
            glPushMatrix();
                glTranslatef(0.3,0,0);///���b���T���a��
                glRotatef(-angle[3],0,0,1);///����
                glTranslatef(0.3,0,0);///���त�ߩ��e������
                glutSolidTeapot( 0.3 );///�k��y
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
}
int main( int argc, char ** argv )
{
    glutInit( &argc, argv );
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week15 file");

    glutKeyboardFunc(keyboard);
    glutTimerFunc(0,timer,0);
    glutDisplayFunc(display);
    glutMainLoop();
}
