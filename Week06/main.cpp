#include <GL/glut.h>///�ϥ�GLUT�~��
float angle=0;
void hand()
{
    glPushMatrix();///�ƥ��x�}
        glScalef(0.5,0.1,0.1);///������
        glColor3f(0,0,1);///�Ŧ⪺
        glutSolidCube(1);///�e�Ӥ��
    glPopMatrix();///�٭�x�}
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);///�M��
    glColor3f(1,1,1);
    glutSolidCube(0.5);///�j����
    glPushMatrix();///�ƥ��x�} �k�b��
        glTranslatef(0.25,0.25,0);///��Ӳ���k�W������
        glRotatef(angle,0,0,1);///�襤�߱���
        glTranslatef(0.25,0,0);///�����`���줤��
        hand();///�W���u
        glPushMatrix();
            glTranslatef(0.25,0,0);///���k�ԹL�h
            glRotatef(angle,0,0,1);///�襤�߱���
            glTranslatef(0.25,0,0);///�����`���줤��
            hand();///�U���u
        glPopMatrix();
    glPopMatrix();///�٭�x�}

    glPushMatrix();///�ƥ��x�} ���b��
        glTranslatef(-0.25,0.25,0);///��Ӳ��쥪�W������
        glRotatef(-angle,0,0,1);///�襤�߱���
        glTranslatef(-0.25,0,0);///�����`���줤��
        hand();///�W���u
        glPushMatrix();
            glTranslatef(-0.25,0,0);///�����ԹL�h
            glRotatef(-angle,0,0,1);///�襤�߱���
            glTranslatef(-0.25,0,0);///�����`���줤��
            hand();///�U���u
        glPopMatrix();
    glPopMatrix();///�٭�x�}
    glutSwapBuffers();
    angle++;
}
int main(int argc, char *argv[])///main()�禡
{
    glutInit(&argc, argv);///(1)Init��l��GLUT
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);///(2)Init��l�� Display ���\��
    glutCreateWindow("08160075 �d�^�L");///(3)�إ�GLUT����

    glutDisplayFunc(display);///(4)�ǳ�display()�禡
    glutIdleFunc(display);///TODO ���ݵe��

    glutMainLoop();///(5)�D�n�{��
}

