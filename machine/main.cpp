#include <GL/glut.h>///�ϥ�GLUT�~��
float angle=0;
float ang=0;
float angl=0;
float a=0.4;
void hand()
{
    glPushMatrix();///�ƥ��x�}
        glScalef(a,0.1,0.1);///������
        glColor3f(0,0,1);///�Ŧ⪺
        glutSolidCube(1);///�e�Ӥ��
    glPopMatrix();///�٭�x�}
}
void g()
{
    glPushMatrix();///�ƥ��x�}
        glScalef(a/2,0.1,0.1);///������
        glColor3f(0,1,0);///�Ŧ⪺
        glutSolidCube(1);///�e�Ӥ��
    glPopMatrix();///�٭�x�}
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);///�M��
    glColor3f(1,1,1);

    glPushMatrix();///�ƥ��x�}
        glScalef(0.5,0.7,0.5);///������
        glColor3f(1,1,1);///�Ŧ⪺
        glutSolidCube(1);///�e�Ӥ��
    glPopMatrix();///�٭�x�}

    glPushMatrix();///�ƥ��x�}
        glTranslatef(0,0.4,0);///��Ӳ���k�W������
        glScalef(0.4,0.4,0.5);///������
        glColor3f(1,1,1);///�Ŧ⪺
        glutSolidCube(1);///�e�Ӥ��
    glPopMatrix();///�٭�x�}

    glPushMatrix();///�ƥ��x�}
        glTranslatef(0.1,0.5,0);///��Ӳ���k�W������
        glScalef(0.1,0.1,0.1);///������
        glColor3f(0,0,1);///�Ŧ⪺
        glutSolidCube(1);///�e�Ӥ��
    glPopMatrix();///�٭�x�}

    glPushMatrix();///�ƥ��x�}
        glTranslatef(-0.1,0.5,0);///��Ӳ���k�W������
        glScalef(0.1,0.1,0.1);///������
        glColor3f(0,0,0);///�Ŧ⪺
        glutSolidCube(1);///�e�Ӥ��
    glPopMatrix();///�٭�x�}

    glPushMatrix();///�ƥ��x�}
        glTranslatef(0,0.38,0);///��Ӳ���k�W������
        glScalef(0.3,0.05,0.05);///������
        glColor3f(0,0,1);///�Ŧ⪺
        glutSolidCube(1);///�e�Ӥ��
    glPopMatrix();///�٭�x�}

    glPushMatrix();///�ƥ��x�} 1
        glTranslatef(0.25,0.35,0);///��Ӳ���k�W������
        glRotatef(ang,0,0,1);///�襤�߱���
        glTranslatef(a/2,0,0);///�����`���줤��
        hand();///1���u
        glPushMatrix();
            glTranslatef(a/2,0,0);///���k�ԹL�h
            glRotatef(angl,0,0,1);///�襤�߱���
            glTranslatef(a/2,0,0);///�����`���줤��
            hand();///2���u
            glPushMatrix();
                glTranslatef(a/2,0,0);///���k�ԹL�h
                glRotatef(angle,0,0,1);///�襤�߱���
                glTranslatef(a/2,0,0);///�����`���줤��
                hand();///3���u
                glPushMatrix();///�ƥ��x�} ��
                    glRotatef(-90,0,0,1);///�襤�߱���
                    glTranslatef(0,0.1,0);///��Ӳ���k�W������
                    glRotatef(ang,0,1,0);///�襤�߱���
                    glTranslatef(0,a/4,0);
                    g();
                    glPushMatrix();///�ƥ��x�} ���y
                        glTranslatef(a/4,0.15,0);
                        glRotatef(90,0,0,1);
                        g();
                    glPopMatrix();///�٭�x�}
                    glPushMatrix();///�ƥ��x�} ���y
                        glTranslatef(-a/4,0.15,0);
                        glRotatef(90,0,0,1);
                        g();
                    glPopMatrix();///�٭�x�}
                glPopMatrix();///�٭�x�}
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();///�٭�x�}

    glPushMatrix();///�ƥ��x�} 1
        glTranslatef(-0.25,0.35,0);///��Ӳ���k�W������
        glRotatef(-ang,0,0,1);///�襤�߱���
        glTranslatef(-a/2,0,0);///�����`���줤��
        hand();///1���u
        glPushMatrix();
            glTranslatef(-a/2,0,0);///���k�ԹL�h
            glRotatef(-angl,0,0,1);///�襤�߱���
            glTranslatef(-a/2,0,0);///�����`���줤��
            hand();///2���u
            glPushMatrix();
                glTranslatef(-a/2,0,0);///���k�ԹL�h
                glRotatef(-angle,0,0,1);///�襤�߱���
                glTranslatef(-a/2,0,0);///�����`���줤��
                hand();///3���u
                glPushMatrix();///�ƥ��x�} ��
                    glRotatef(90,0,0,1);///�襤�߱���
                    glTranslatef(0,0.1,0);///��Ӳ���k�W������
                    glRotatef(ang,0,1,0);///�襤�߱���
                    glTranslatef(0,a/4,0);
                    g();
                    glPushMatrix();///�ƥ��x�} ���y
                        glTranslatef(a/4,0.15,0);
                        glRotatef(90,0,0,1);
                        g();
                    glPopMatrix();///�٭�x�}
                    glPushMatrix();///�ƥ��x�} ���y
                        glTranslatef(-a/4,0.15,0);
                        glRotatef(90,0,0,1);
                        g();
                    glPopMatrix();///�٭�x�}
                glPopMatrix();///�٭�x�}
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();///�٭�x�}

    glPushMatrix();///�ƥ��x�} 1
        glTranslatef(-0.25,-0.35,0);///��Ӳ���k�W������
        glRotatef(ang,0,0,1);///�襤�߱���
        glTranslatef(-a/2,0,0);///�����`���줤��
        hand();///1���u
        glPushMatrix();
            glTranslatef(-a/2,0,0);///���k�ԹL�h
            glRotatef(angl,0,0,1);///�襤�߱���
            glTranslatef(-a/2,0,0);///�����`���줤��
            hand();///2���u
        glPopMatrix();
    glPopMatrix();///�٭�x�}

    glPushMatrix();///�ƥ��x�} 1
        glTranslatef(0.25,-0.35,0);///��Ӳ���k�W������
        glRotatef(ang,0,0,1);///�襤�߱���
        glTranslatef(-a/2,0,0);///�����`���줤��
        hand();///1���u
        glPushMatrix();
            glTranslatef(-a/2,0,0);///���k�ԹL�h
            glRotatef(angl,0,0,1);///�襤�߱���
            glTranslatef(-a/2,0,0);///�����`���줤��
            hand();///2���u
        glPopMatrix();
    glPopMatrix();///�٭�x�}

    glutSwapBuffers();
    angle+=0.01;
    ang+=-0.01;
    angl+=-0.01;
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
