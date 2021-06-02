#include <Gl/glut.h>
float angle=0;
void drawArm1()
{
    glPushMatrix();
        glScalef(1,0.5,0.5);///變細長
        glColor3f(0,1,0);
        glutSolidCube(0.2);///綠色手臂
    glPopMatrix();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
/// glutSolidSphere(0.3,30,30);///實心
    glPushMatrix();
        ///glutWireCube(0.3);///線框
        glColor3f(1,1,1);
        glutSolidCube(0.4);///白色身體
        glPushMatrix();
            glTranslatef(-0.2,0.2,0);///掛上肩膀
            glRotatef(angle,0,0,1);///轉動
            glTranslatef(-0.1,0,0);///移動到中間
            drawArm1();///綠色手臂
        glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
}
int diff=2;
void timer(int t)///timer響起時,做需要做的事
{
    ///20:50 fps ,30:33fps, 50:20fps
    glutTimerFunc(20,timer,t+1);///起床記鬧鐘
    glClearColor(1,0,0,0);///清背景色:紅色
    if(angle>90)diff=-2;
    if(angle<0) diff=+2;
    angle+=diff;
    display();///重畫畫面
}
int main(int agrc,char **argv)
{
    glutInit(&agrc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Week14_timer");

    glutDisplayFunc(display);
    glutTimerFunc(3000,timer,0);///(0,0,等多久)
    glutMainLoop();
}
