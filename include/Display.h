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
  Framebuffer *framebuffer;
  Mesh *displayMesh;
  Window *window;
  int framebufferDimensions = 12000;

public:
  Display(Window *window, int width, int height);
  Display(Window *window, int dimensions);
  void render();
  void bindFramebuffer();
  void unbindFramebuffer();
  Window* getWindow();
};
