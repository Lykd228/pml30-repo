/* GL headers */
#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

/* global variables for GL */
extern const GLchar* vertexShaderSource;
extern const GLchar* fragmentShaderSource;
extern GLuint VAO, shaderProgram;
void Initialization(void);
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
