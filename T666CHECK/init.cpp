#include "glstor.h"

/* vertices coordinates */
GLfloat vertices[] = {
  0.5f,  0.5f, 0.0f,  /* 0 - top right */
  0.6f, -0.6f, 0.0f,  /* 1 - bottom right */
 -0.5f, -0.5f, 0.0f,  /* 2 - bottom left */
 -0.6f,  0.6f, 0.0f   /* 3 - top left */
};
GLuint indices[] = {
  0, 1, 3,   /* first triangle */
  1, 2, 3    /* second triangle */
};  

/* initialization function */
void Initialization(void)
{
  /* working with vertices */
  /* points buffer */
  GLuint VBO, EBO;
  glGenBuffers(1, &VBO);
  glGenBuffers(1, &EBO);
  glGenVertexArrays(1, &VAO);

  /* bind VBO's to VAO */
  glBindVertexArray(VAO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  /* bind EBO's to VAO */
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

  /* set format of shader data - 3 float number per vector */
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
  glEnableVertexAttribArray(0);

  /* unbind VAO */
  glBindVertexArray(0);
  /* end of vertices */

  /* working with shaders */
  /* create vertex shader */
  GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
  glCompileShader(vertexShader);

  /* create fragment shader */
  GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
  glCompileShader(fragmentShader);

  /* build & use shader program */
  shaderProgram = glCreateProgram();
  glAttachShader(shaderProgram, vertexShader);
  glAttachShader(shaderProgram, fragmentShader);
  glLinkProgram(shaderProgram);

  /* clear shaders */
  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);
  /* end of shaders */
}
