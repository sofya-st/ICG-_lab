
#include <GL/glew.h>
#include <iostream>
#include <GL/freeglut.h>
#include <glm/vec3.hpp>

GLuint VBO;

static void RenderSceneCB()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glDrawArrays(GL_POINTS, 0, 1);
    glDisableVertexAttribArray(0);
    glutSwapBuffers();
}



int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(1024, 768);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Tutorial 01"); 
    glutDisplayFunc(RenderSceneCB);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    
  
    GLenum res = glewInit();
    if (res != GLEW_OK)
    {
        fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
        return 1;
    }

    GLfloat vertices[] = {
        0.0f, 0.0f, 0.0f,
    };

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
   
    glutMainLoop();

}

