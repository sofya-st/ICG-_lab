
#include <GL/glew.h>
#include <iostream>
#include <GL/freeglut.h>
#include <glm/vec3.hpp>

GLuint VBO;

static void RenderSceneCB()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0f, 0.2f, 0.0f);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glDrawArrays(GL_TRIANGLES, 0, 3);
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

    glm::vec3 vertices[3];
    vertices[0] = glm::vec3(-0.3f, 0.4f, 0.0f);
    vertices[1] = glm::vec3(1.0f, -0.4f, 0.0f);
    vertices[2] = glm::vec3(0.0f, 1.0f, 0.0f);

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
   
    glutMainLoop();

}

