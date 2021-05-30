#pragma once

#include <GL/glew.h>
#include <glm/gtx/transform.hpp>
#include <glm/mat4x4.hpp>
#include <iostream>
#include <string>

class Framebuffer {
private:
  unsigned int framebuffer;
  unsigned int colorbuffer;
  unsigned int rbo;
  unsigned int depthrenderbuffer;
  unsigned int depthMap;
  int width, height;

public:
  Framebuffer(int width, int height);
  void bind();
  void unbind();
  void use();
};
