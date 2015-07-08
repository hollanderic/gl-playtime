#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include<stdio.h>
void setup() {   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); }

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(0.5f, 0.5f, 0.5f);
    glBegin(GL_LINE_STRIP);
        glVertex2f(0.0f,0.0f);
        glVertex2f(0.5f,0.5f);
        glVertex2f(0.5f,-0.5f);
    glEnd();
    //glRectf(-0.5f,0.5f, 0.5f, -0.5f);
    glutSwapBuffers();
    printf("Drew a new frame\n");
}



int main(int argc, char *argv[])
  {
     glutInit(&argc, argv);
     glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
     glutInitWindowSize(800,600);
     glutCreateWindow("Hello World");

     setup();
     glutDisplayFunc(display);
     glutMainLoop();
     return 0;
  }

