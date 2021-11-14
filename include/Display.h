#pragma once

#include <iostream>
#include <vector>

#include "Camera.h"
#include "Framebuffer.h"
#include "GLSLProgram.h"
#include "Mesh.h"
#include "Model.h"
#include "Window.h"

class Display {
private:
  GLSLProgram *shader;
  Framebuffer *colorbuffer;
  Framebuffer *depthbuffer;
  Mesh *displayMesh;
  Window *window;

public:
  Display(Window *window, int width, int height);
  Display(Window *window, int dimensions);
  void render();
  void bindFramebuffer();
  void bindColorBuffer();
  void bindDepthBuffer();
  void unbindFramebuffer();
  Window* getWindow();
};
