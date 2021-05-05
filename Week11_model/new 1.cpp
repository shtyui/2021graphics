#include "glm.h"
GLMmodel* pmodel = NULL;
void
drawmodel(void)
{
    if (!pmodel) {
	pmodel = glmReadOBJ("data/porsche.obj");
	if (!pmodel) exit(0);
	glmUnitize(pmodel);
	glmFacetNormals(pmodel);
	glmVertexNormals(pmodel, 90.0);
    }

    glmDraw(pmodel, GLM_SMOOTH | GLM_MATERIAL);
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);///清空
    drawmodel();///glutSolidTeapot(0.3)
    glutSwapBuffers();
}
int main(int argc, char *argv[])///main()函式
{
    glutInit(&argc, argv);///(1)Init初始化GLUT
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);///(2)Init初始化 Display 的功能
    glutCreateWindow("Week11 3D模型");///(3)建立GLUT視窗

    glutDisplayFunc(display);///(4)準備display()函式
    glutMainLoop();///(5)主要程式
}

