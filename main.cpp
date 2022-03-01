#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include <GL/glut.h>
#include "glm.h"
#include "CMP3_MCI.h"
#include <stdio.h>
CMP3_MCI mp3;///宣告變數
FILE * fout = NULL;
FILE * fin = NULL;
GLuint id1,id2,id3;
GLMmodel * body=NULL;
GLMmodel * head;
GLMmodel * arm1=NULL, * arm2=NULL;
GLMmodel * hand1=NULL, * hand2=NULL;
GLMmodel * bot=NULL;
GLMmodel * leg1=NULL, * leg2=NULL;
GLMmodel * knee1=NULL, * knee2=NULL;
GLMmodel * eye=NULL;
float oldX=0;
float angle[20]={}, angleOld[20], angleNew[20];///先都設成0
int angleID=1;///現在要動的關節是誰?
void timer(int t){
    glutTimerFunc( 50, timer, t+1);
    if(t%10==0){
        for(int i=0; i<20; i++) angleOld[i] = angleNew[i];

        if( fin==NULL ) fin = fopen("angle.txt", "r");
        for(int i=0; i<20; i++) fscanf(fin, "%f", &angleNew[i]);
        printf("read angle.txt\n");
    }
    float alpha = (t%10)/10.0;///介於 0.0 - 1.0 之間
    for(int i=0; i<20; i++) angle[i] = alpha*angleNew[i]+(1-alpha)*angleOld[i];
    glutPostRedisplay();///重畫畫面
}
void keyboard(unsigned char key, int x, int y){

    if(key=='1') angleID=1;
    if(key=='2') angleID=2;
    if(key=='3') angleID=3;
    if(key=='4') angleID=4;
    if(key=='5') angleID=5;
    if(key=='6') angleID=6;
    if(key=='7') angleID=7;
    if(key=='8') angleID=8;
    if(key=='9') angleID=9;
    if(key=='0') angleID=10;
    if(key=='-') angleID=11;
    if(key=='=') angleID=12;
    if(key=='/') angleID=13;
    if(key=='*') angleID=14;
    if(key=='s'){///存檔
        if( fout==NULL ) fout = fopen("angle.txt", "w+");
        for(int i=0; i<20; i++) fprintf(fout, "%.2f ", angle[i]);
        fprintf(fout, "\n");
        printf("save angle.txt\n");
    }else if(key=='r'){///讀檔 (不能和存檔同時做,因angle.txt不能開2次)
        if( fin==NULL ) fin = fopen("angle.txt", "r");
        for(int i=0; i<20; i++) fscanf(fin, "%f", &angle[i]);
        glutPostRedisplay();///重畫畫面
        printf("read angle.txt\n");
    }
    if(key=='p'){///Play播放
        glutTimerFunc(0, timer, 0);///一開始的第1個timer
        mp3.Play();
    }
}
void mouse(int button, int state, int x, int y){
    oldX = x;
}
void motion( int x, int y ){
    angle[angleID] += x-oldX;
    oldX = x;//小心,不要漏掉了
    glutPostRedisplay();///重畫畫面
}
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼圖參數, 縮小時的內插, 用最近點
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}



void display()
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBindTexture(GL_TEXTURE_2D, id1);

    glPushMatrix();
        glRotatef(180,0,1,0);
        glRotatef(angle[12],0,1,0);
        glTranslatef(0.00, -0.95, 0.00);
        glRotatef(-90,1,0,0);
        glScalef(1/100.0,1/100.0,1/100.0);

        glPushMatrix();
            glTranslatef(0,0,89);
            glRotatef(angle[1],0,0,1);
            glTranslatef(0,0,-89);
            glmDraw(body, GLM_SMOOTH|GLM_TEXTURE);

            glPushMatrix();
                glTranslatef(0,2,140);
                glRotatef(angle[2],0,0,1);
                glTranslatef(0,-2,-140);
                glmDraw(head, GLM_SMOOTH|GLM_TEXTURE);
            glPopMatrix();

            glPushMatrix();
                glTranslatef(-15,0,128);
                glRotatef(angle[3],0,1,0);
                glRotatef(angle[13],1,0,0);
                glTranslatef(15,0,-128);
                glmDraw(arm1, GLM_SMOOTH|GLM_TEXTURE);
                glPushMatrix();
                    glTranslatef(-35,0,109);
                    glRotatef(angle[4],0,1,0);
                    glTranslatef(35,0,-109);
                    glmDraw(hand1, GLM_SMOOTH|GLM_TEXTURE);
                glPopMatrix();
            glPopMatrix();


            glPushMatrix();
                glTranslatef(15,0,128);
                glRotatef(angle[5],0,1,0);
                glRotatef(angle[14],1,0,0);
                glTranslatef(-15,0,-128);
                glmDraw(arm2, GLM_SMOOTH|GLM_TEXTURE);
                glPushMatrix();
                    glTranslatef(35,0,109);
                    glRotatef(angle[6],0,1,0);
                    glTranslatef(-35,0,-109);
                    glmDraw(hand2, GLM_SMOOTH|GLM_TEXTURE);
                glPopMatrix();
            glPopMatrix();
        glPopMatrix();

        glPushMatrix();
            glTranslatef(0,0,90);
            glRotatef(angle[7],0,0,1);
            glTranslatef(0,0,-90);
            glmDraw(bot, GLM_SMOOTH|GLM_TEXTURE);

            glPushMatrix();
                glTranslatef(-10,0,80);
                glRotatef(angle[8],0,1,0);
                glTranslatef(10,0,-80);
                glmDraw(leg1, GLM_SMOOTH|GLM_TEXTURE);
                glPushMatrix();
                    glTranslatef(-17,0,45);
                    glRotatef(angle[9],1,0,0);
                    glTranslatef(17,0,-45);
                    glmDraw(knee1, GLM_SMOOTH|GLM_TEXTURE);
                glPopMatrix();
            glPopMatrix();
            glPushMatrix();
                glTranslatef(10,0,80);
                glRotatef(angle[10],0,1,0);
                glTranslatef(-10,0,-80);
                glmDraw(leg2, GLM_SMOOTH|GLM_TEXTURE);
                glPushMatrix();
                    glTranslatef(17,0,45);
                    glRotatef(angle[11],1,0,0);
                    glTranslatef(-17,0,-45);
                    glmDraw(knee2, GLM_SMOOTH|GLM_TEXTURE);
                glPopMatrix();
            glPopMatrix();
        glPopMatrix();

    glPopMatrix();

    glBindTexture(GL_TEXTURE_2D, id3);
    glPushMatrix();
        glRotatef(180,0,1,0);
        glRotatef(angle[12],0,1,0);
        glTranslatef(0.00, -0.95, 0.00);
        glRotatef(-90,1,0,0);
        glScalef(1/100.0,1/100.0,1/100.0);
        glPushMatrix();
            glTranslatef(0,0,89);
            glRotatef(angle[1],0,0,1);
            glTranslatef(0,0,-89);
             glPushMatrix();
                glTranslatef(0,2,140);
                glRotatef(angle[2],0,0,1);
                glTranslatef(0,-2,-140);
                glPushMatrix();
                    glTranslatef(0,0,153);
                    glRotatef(0,1,0,0);
                    glTranslatef(0,0,-153);
                    glmDraw(eye, GLM_SMOOTH|GLM_TEXTURE);
                glPopMatrix();
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();

    glBindTexture(GL_TEXTURE_2D, id2);
    glBegin(GL_POLYGON);
        glTexCoord2f( 1 , 1 ); glVertex3f( -1, -1,+0.9);
        glTexCoord2f( 1 , 0 ); glVertex3f( -1, +1,+0.9);
        glTexCoord2f( 0 , 0 ); glVertex3f( +1, +1,+0.9);
        glTexCoord2f( 0 , 1 ); glVertex3f( +1, -1,+0.9);
    glEnd();
    glutSwapBuffers();
}
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, -5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };
int main(int argc, char** argv)
{
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutCreateWindow("08160075 HW4 ");

    mp3.Load("music.mp3");
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutDisplayFunc(display);
    glutIdleFunc(display);
    id1 = myTexture("ntxr001.png");
    id2 = myTexture("bg.jpg");
    id3 = myTexture("ntxr004.png");
    body = glmReadOBJ("body2.obj");
    head = glmReadOBJ("head2.obj");
    arm1 = glmReadOBJ("rightarm.obj");
    arm2 = glmReadOBJ("leftarm.obj");
    hand1 = glmReadOBJ("righth.obj");
    hand2 = glmReadOBJ("lefth.obj");
    bot = glmReadOBJ("butt.obj");
    leg1 = glmReadOBJ("rightknee.obj");
    leg2 = glmReadOBJ("leftknee.obj");
    knee1 = glmReadOBJ("rightfoot.obj");
    knee2 = glmReadOBJ("leftfoot.obj");
    eye = glmReadOBJ("eye.obj");

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
    glutMainLoop();
}
