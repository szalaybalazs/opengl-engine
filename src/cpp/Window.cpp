#include "Window.h"
#include <vector>

#include <glm/vec3.hpp>

#include <OBJLoader.h>
#include <glm/gtc/matrix_transform.hpp>

double WINDOW_LAST_FRAME = 0;
int WINDOW_WIDTH = 0, WINDOW_HEIGHT = 0;

// void framebuffer_size_callback(GLFWwindow *, int new_screen_width,
//                                int new_screen_height) {
//   Window::setDimensions(new_screen_width, new_screen_height);
//   glViewport(0, 0, new_screen_width, new_screen_height);
// }

Window::Window(int width, int height, const char *title)
{
  if (!glfwInit())
  {
    assert(1);
  }

  WINDOW_WIDTH = width;
  WINDOW_HEIGHT = height;
  this->title = title;

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

#ifdef __APPLE__
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#endif

  window = glfwCreateWindow(width, height, this->title, NULL, NULL);
  // glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
  glfwMakeContextCurrent(window);
  glfwSwapInterval(0);

  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LESS);

  // glEnable(GL_CULL_FACE);
  // glCullFace(GL_FRONT);
  // glFrontFace(GL_CW);
}

void Window::poll()
{
  glfwGetWindowSize(window, &WINDOW_WIDTH, &WINDOW_HEIGHT);
  glfwSwapBuffers(window);
  glfwPollEvents();
}

RenderResult Window::render()
{
  this->clear();

  frames++;

  double currentTime = glfwGetTime();
  double deltaTime = currentTime - WINDOW_LAST_FRAME;
  WINDOW_LAST_FRAME = currentTime;

  RenderResult result;
  result.deltaTime = deltaTime;
  result.currentTime = currentTime;

  if (deltaTime > 100.)
  {
    std::ostringstream outs;
    outs.precision(3);
    outs << std::fixed << this->title << "  "
         << "FPS: " << (int)ceil(1 / deltaTime) << "  "
         << "FrameTime: " << deltaTime << "ms";
    glfwSetWindowTitle(window, outs.str().c_str());
  }
  return result;
}

bool Window::isValid()
{
  glewExperimental = GL_TRUE;
  if (glewInit() != GLEW_OK || !window)
  {
    glfwTerminate();
    return false;
  }
  return true;
}
bool Window::shouldClose() { return glfwWindowShouldClose(window); }
void Window::setTitle(char *title) { this->title = title; }
void Window::clear()
{
  glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
void Window::clean()
{
  this->clear();
  glViewport(0, 0, WINDOW_WIDTH * 2, WINDOW_HEIGHT * 2);
}

void Window::setDimensions(int width, int height)
{
  WINDOW_WIDTH = width;
  WINDOW_HEIGHT = height;
}

void Window::setDimensions(WindowDimensions dimensions)
{
  WINDOW_WIDTH = dimensions.width;
  WINDOW_HEIGHT = dimensions.height;
}

WindowDimensions Window::getDimensions()
{
  WindowDimensions dimensions;
  dimensions.width = WINDOW_WIDTH;
  dimensions.height = WINDOW_HEIGHT;

  return dimensions;
}

int Window::getButtonState(int button)
{
  int state = glfwGetKey(window, button);

  return state;
}