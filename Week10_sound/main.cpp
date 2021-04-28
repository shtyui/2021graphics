#include <windows.h>
#include <GL/glut.h>///�ϥ�GLUT�~��
#include "CMP3_MCI.h"///�ɮש�bweek10_sound
CMP3_MCI mp3;///�ŧi�ܼ�
CMP3_MCI shot1,shot2,shot3;
static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);///�M�I��
    glutSolidTeapot(0.3);
    glutSwapBuffers();///��s�e��
}
void keyboard(unsigned char key,int x,int y)
{
    if(key=='1')PlaySound("do.wav",NULL,SND_ASYNC);
    if(key=='2')PlaySound("re.wav",NULL,SND_ASYNC);
    if(key=='3')PlaySound("mi.wav",NULL,SND_ASYNC);
    if(key=='4')PlaySound("fa.wav",NULL,SND_ASYNC);
    if(key=='5')PlaySound("so.wav",NULL,SND_ASYNC);
}
void mouse(int button, int state, int x, int y)
{
    if(state==GLUT_DOWN&&button==GLUT_LEFT_BUTTON) shot1.Play();
    if(state==GLUT_DOWN&&button==GLUT_MIDDLE_BUTTON) shot2.Play();
    if(state==GLUT_DOWN&&button==GLUT_RIGHT_BUTTON) shot3.Play();
}
int main(int argc, char *argv[])///main()�禡
{
    shot1.Load("1.wav");
    shot2.Load("2.wav");
    shot3.Load("3.wav");
    mp3.Load("music.mp3");///�ɮש����ؿ�freeglut/bin
    mp3.Play();///����
    glutInit(&argc, argv);///(1)Init��l��GLUT
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);///(2)Init��l�� Display ���\��
    glutCreateWindow("Week10 �d�^�L");///(3)�إ�GLUT����

    glutDisplayFunc(display);///(4)�ǳ�display()�禡
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMainLoop();///(5)�D�n�{��
}
