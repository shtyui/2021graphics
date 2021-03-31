#include <GL/glut.h>///使用GLUT外掛
float angle=0;
void hand()
{
    glPushMatrix();///備份矩陣
        glScalef(0.5,0.1,0.1);///長條狀
        glColor3f(0,0,1);///藍色的
        glutSolidCube(1);///畫個方塊
    glPopMatrix();///還原矩陣
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);///清空
    glColor3f(1,1,1);
    glutSolidCube(0.5);///大身體
    glPushMatrix();///備份矩陣 右半邊
        glTranslatef(0.25,0.25,0);///整個移到右上角掛著
        glRotatef(angle,0,0,1);///對中心旋轉
        glTranslatef(0.25,0,0);///把關節移到中心
        hand();///上手臂
        glPushMatrix();
            glTranslatef(0.25,0,0);///往右拉過去
            glRotatef(angle,0,0,1);///對中心旋轉
            glTranslatef(0.25,0,0);///把關節移到中心
            hand();///下手臂
        glPopMatrix();
    glPopMatrix();///還原矩陣

    glPushMatrix();///備份矩陣 左半邊
        glTranslatef(-0.25,0.25,0);///整個移到左上角掛著
        glRotatef(-angle,0,0,1);///對中心旋轉
        glTranslatef(-0.25,0,0);///把關節移到中心
        hand();///上手臂
        glPushMatrix();
            glTranslatef(-0.25,0,0);///往左拉過去
            glRotatef(-angle,0,0,1);///對中心旋轉
            glTranslatef(-0.25,0,0);///把關節移到中心
            hand();///下手臂
        glPopMatrix();
    glPopMatrix();///還原矩陣
    glutSwapBuffers();
    angle++;
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

