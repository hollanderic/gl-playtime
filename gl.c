#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include<stdio.h>
struct point_node {
    float x;
    float y;
    struct point_node *next;
};

typedef struct point_node point_t;


point_t * point_list_p = NULL;
point_t * point_list_tail_p = NULL;



void setup() {   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); }

void display()
{
    point_t * point_p;

    point_p = point_list_p;

    //printf("point_p=tx%016lx\n",(unsigned long)point_p);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(0.5f, 0.5f, 0.5f);
    glBegin(GL_LINE_STRIP);
        while (point_p != NULL) {
            glVertex2f( point_p->x, point_p->y);
            //printf("%f\n",(float)point_p->x/800.0);
            point_p = point_p->next;
        }
    glEnd();
    glutSwapBuffers();
    glutPostRedisplay();
    glFlush();
}

void rat_handler(int button, int state, int x, int y){
    printf("Mouse click %d with state %d at %d:%d\n",button,state,x,y);
}

void rat_run(int x, int y){
    if (point_list_p == NULL) {
        point_list_p = (point_t *) malloc( sizeof(point_t));
        point_list_tail_p = point_list_p;
    } else {
        point_list_tail_p->next = (point_t *) malloc(sizeof(point_t));
        point_list_tail_p = point_list_tail_p->next;
    }
    int width,height;
    width = glutGet(GLUT_WINDOW_WIDTH);
    height = glutGet(GLUT_WINDOW_HEIGHT);
    point_list_tail_p->x = (float)(x-width/2)/(width/2);
    point_list_tail_p->y = (float)((height/2-y))/(height/2);
    point_list_tail_p->next = NULL;

}


int main(int argc, char *argv[])
{



    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB |  GLUT_DOUBLE);
    glutInitWindowSize(800,600);
    glutCreateWindow("GL Playtime for Eric");

    setup();
    glutDisplayFunc(display);
    glutMouseFunc(rat_handler);
    glutMotionFunc(rat_run);
    glutMainLoop();
     return 0;
}

