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

class Texture {
private:
  unsigned int texture;

public:
  Texture(const char *filename);
  void draw();
  void update();
};
