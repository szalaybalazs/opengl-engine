#pragma once

#include <GL/glew.h>
#include <glm/gtx/transform.hpp>
#include <glm/mat4x4.hpp>
#include <iostream>
#include <sstream>
#include <string>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GLSLProgram.h>

struct RenderResult
{
  double deltaTime;
  double currentTime;
};
struct WindowDimensions
{
  int width;
  int height;
};

class Window
{
private:
  GLFWwindow *window;
  static int width;
  static int height;
  const char *title;
  int frames = 0;

public:
  Window(int width = 0, int height = 0, const char *title = "title");
  bool isValid();
  bool shouldClose();
  void poll();
  void setTitle(char *title);
  void clear();
  void clean();
  int getButtonState(int button);
  static void setDimensions(int width, int height);
  static void setDimensions(WindowDimensions dimensions);
  static WindowDimensions getDimensions();
  RenderResult render();
};
