#include <windows.h>
#include <GL/glut.h>///使用GLUT外掛
#include "CMP3_MCI.h"///檔案放在week10_sound
CMP3_MCI mp3;///宣告變數
CMP3_MCI shot1,shot2,shot3;
static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);///清背景
    glutSolidTeapot(0.3);
    glutSwapBuffers();///更新畫面
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
int main(int argc, char *argv[])///main()函式
{
    shot1.Load("1.wav");
    shot2.Load("2.wav");
    shot3.Load("3.wav");
    mp3.Load("music.mp3");///檔案放執行目錄freeglut/bin
    mp3.Play();///播放
    glutInit(&argc, argv);///(1)Init初始化GLUT
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);///(2)Init初始化 Display 的功能
    glutCreateWindow("Week10 吳英昭");///(3)建立GLUT視窗

    glutDisplayFunc(display);///(4)準備display()函式
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMainLoop();///(5)主要程式
}
