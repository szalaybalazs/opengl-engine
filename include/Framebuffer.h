#pragma once

#include <GL/glew.h>
#include <glm/gtx/transform.hpp>
#include <glm/mat4x4.hpp>
#include <iostream>
#include <string>
#include "GLSLProgram.h"

class Framebuffer {
private:
  int width, height;
  unsigned int type; // 0: COLOUR, 1: DEPTH 
  
  unsigned int framebuffer;
  unsigned int framebuffer_depth;
  unsigned int framebuffer_colour;
  unsigned int colorbuffer;
  
  unsigned int rbo;
  unsigned int depthrenderbuffer;
  unsigned int depthMap;

  void init(int width, int height);

  void initColourBuffer();
  void initDepthBuffer();
public:
  Framebuffer(int width, int height, int type = 0);
  void bind();
  void unbind();
  void use(unsigned int unit = GL_TEXTURE0);
  void use(unsigned int unit, char *uniform, GLSLProgram *shader);

  void setType(int type);
  unsigned int getType();
};
