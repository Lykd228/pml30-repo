#include "main.h"

/* main function */
int main( int argc, char **argv )
{	
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

  GLFWwindow* window = glfwCreateWindow(800, 600, "CGSG Task 0", nullptr, nullptr);
  if (window == nullptr)
  {
    std::cout << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    return -1;
  }
  glfwMakeContextCurrent(window);
  glfwSetKeyCallback(window, key_callback); 

  glewExperimental = GL_TRUE;
  if (glewInit() != GLEW_OK)
  {
    std::cout << "Failed to initialize GLEW" << std::endl;
    return -1;
  }

  int width, height;
  glfwGetFramebufferSize(window, &width, &height);
  glViewport(0, 0, width, height);

  /* apply some vertices to VAO */
  Initialization();

  /* play cycle */
  while(!glfwWindowShouldClose(window))
  {
    glfwPollEvents();

    glClearColor(0.5f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    /* use shader program */
    glUseProgram(shaderProgram);
    /* use VAO as vertex massive */
    glBindVertexArray(VAO); 
    /* rendering itself */
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    /* unbind VAO after rendering */
    glBindVertexArray(0); 
    
    glfwSwapBuffers(window);
  }

  glfwTerminate();
  return 0;
}
