#include <GL/glut.h>///使用GLUT外掛
float angle=0;
float ang=0;
float angl=0;
float a=0.4;
void hand()
{
    glPushMatrix();///備份矩陣
        glScalef(a,0.1,0.1);///長條狀
        glColor3f(0,0,1);///藍色的
        glutSolidCube(1);///畫個方塊
    glPopMatrix();///還原矩陣
}
void g()
{
    glPushMatrix();///備份矩陣
        glScalef(a/2,0.1,0.1);///長條狀
        glColor3f(0,1,0);///藍色的
        glutSolidCube(1);///畫個方塊
    glPopMatrix();///還原矩陣
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);///清空
    glColor3f(1,1,1);

    glPushMatrix();///備份矩陣
        glScalef(0.5,0.7,0.5);///長條狀
        glColor3f(1,1,1);///藍色的
        glutSolidCube(1);///畫個方塊
    glPopMatrix();///還原矩陣

    glPushMatrix();///備份矩陣
        glTranslatef(0,0.4,0);///整個移到右上角掛著
        glScalef(0.4,0.4,0.5);///長條狀
        glColor3f(1,1,1);///藍色的
        glutSolidCube(1);///畫個方塊
    glPopMatrix();///還原矩陣

    glPushMatrix();///備份矩陣
        glTranslatef(0.1,0.5,0);///整個移到右上角掛著
        glScalef(0.1,0.1,0.1);///長條狀
        glColor3f(0,0,1);///藍色的
        glutSolidCube(1);///畫個方塊
    glPopMatrix();///還原矩陣

    glPushMatrix();///備份矩陣
        glTranslatef(-0.1,0.5,0);///整個移到右上角掛著
        glScalef(0.1,0.1,0.1);///長條狀
        glColor3f(0,0,0);///藍色的
        glutSolidCube(1);///畫個方塊
    glPopMatrix();///還原矩陣

    glPushMatrix();///備份矩陣
        glTranslatef(0,0.38,0);///整個移到右上角掛著
        glScalef(0.3,0.05,0.05);///長條狀
        glColor3f(0,0,1);///藍色的
        glutSolidCube(1);///畫個方塊
    glPopMatrix();///還原矩陣

    glPushMatrix();///備份矩陣 1
        glTranslatef(0.25,0.35,0);///整個移到右上角掛著
        glRotatef(ang,0,0,1);///對中心旋轉
        glTranslatef(a/2,0,0);///把關節移到中心
        hand();///1手臂
        glPushMatrix();
            glTranslatef(a/2,0,0);///往右拉過去
            glRotatef(angl,0,0,1);///對中心旋轉
            glTranslatef(a/2,0,0);///把關節移到中心
            hand();///2手臂
            glPushMatrix();
                glTranslatef(a/2,0,0);///往右拉過去
                glRotatef(angle,0,0,1);///對中心旋轉
                glTranslatef(a/2,0,0);///把關節移到中心
                hand();///3手臂
                glPushMatrix();///備份矩陣 轉
                    glRotatef(-90,0,0,1);///對中心旋轉
                    glTranslatef(0,0.1,0);///整個移到右上角掛著
                    glRotatef(ang,0,1,0);///對中心旋轉
                    glTranslatef(0,a/4,0);
                    g();
                    glPushMatrix();///備份矩陣 底座
                        glTranslatef(a/4,0.15,0);
                        glRotatef(90,0,0,1);
                        g();
                    glPopMatrix();///還原矩陣
                    glPushMatrix();///備份矩陣 底座
                        glTranslatef(-a/4,0.15,0);
                        glRotatef(90,0,0,1);
                        g();
                    glPopMatrix();///還原矩陣
                glPopMatrix();///還原矩陣
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();///還原矩陣

    glPushMatrix();///備份矩陣 1
        glTranslatef(-0.25,0.35,0);///整個移到右上角掛著
        glRotatef(-ang,0,0,1);///對中心旋轉
        glTranslatef(-a/2,0,0);///把關節移到中心
        hand();///1手臂
        glPushMatrix();
            glTranslatef(-a/2,0,0);///往右拉過去
            glRotatef(-angl,0,0,1);///對中心旋轉
            glTranslatef(-a/2,0,0);///把關節移到中心
            hand();///2手臂
            glPushMatrix();
                glTranslatef(-a/2,0,0);///往右拉過去
                glRotatef(-angle,0,0,1);///對中心旋轉
                glTranslatef(-a/2,0,0);///把關節移到中心
                hand();///3手臂
                glPushMatrix();///備份矩陣 轉
                    glRotatef(90,0,0,1);///對中心旋轉
                    glTranslatef(0,0.1,0);///整個移到右上角掛著
                    glRotatef(ang,0,1,0);///對中心旋轉
                    glTranslatef(0,a/4,0);
                    g();
                    glPushMatrix();///備份矩陣 底座
                        glTranslatef(a/4,0.15,0);
                        glRotatef(90,0,0,1);
                        g();
                    glPopMatrix();///還原矩陣
                    glPushMatrix();///備份矩陣 底座
                        glTranslatef(-a/4,0.15,0);
                        glRotatef(90,0,0,1);
                        g();
                    glPopMatrix();///還原矩陣
                glPopMatrix();///還原矩陣
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();///還原矩陣

    glPushMatrix();///備份矩陣 1
        glTranslatef(-0.25,-0.35,0);///整個移到右上角掛著
        glRotatef(ang,0,0,1);///對中心旋轉
        glTranslatef(-a/2,0,0);///把關節移到中心
        hand();///1手臂
        glPushMatrix();
            glTranslatef(-a/2,0,0);///往右拉過去
            glRotatef(angl,0,0,1);///對中心旋轉
            glTranslatef(-a/2,0,0);///把關節移到中心
            hand();///2手臂
        glPopMatrix();
    glPopMatrix();///還原矩陣

    glPushMatrix();///備份矩陣 1
        glTranslatef(0.25,-0.35,0);///整個移到右上角掛著
        glRotatef(ang,0,0,1);///對中心旋轉
        glTranslatef(-a/2,0,0);///把關節移到中心
        hand();///1手臂
        glPushMatrix();
            glTranslatef(-a/2,0,0);///往右拉過去
            glRotatef(angl,0,0,1);///對中心旋轉
            glTranslatef(-a/2,0,0);///把關節移到中心
            hand();///2手臂
        glPopMatrix();
    glPopMatrix();///還原矩陣

    glutSwapBuffers();
    angle+=0.01;
    ang+=-0.01;
    angl+=-0.01;
}
int main(int argc, char *argv[])///main()函式
{
    glutInit(&argc, argv);///(1)Init初始化GLUT
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);///(2)Init初始化 Display 的功能
    glutCreateWindow("08160075 吳英昭");///(3)建立GLUT視窗

    glutDisplayFunc(display);///(4)準備display()函式
    glutIdleFunc(display);///TODO 重看畫面

    glutMainLoop();///(5)主要程式
}
