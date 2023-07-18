#include "glstor.h"

/* global variables for GL */
const GLchar* vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 position;\n"
    "void main()\n"
    "{\n"
    "gl_Position = vec4(position.x, position.y, position.z, 1.0);\n"
    "}\0";
const GLchar* fragmentShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 position;\n"
    "out vec4 color;\n"
    "void main()\n"
    "{\n"
    "color = vec4(position.x + 0.5f, position.y + 0.5f, 0.2f, 0.8f);\n"
    "}\n\0";
GLuint VAO, shaderProgram;
/* end of global variables */
