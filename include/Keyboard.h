#pragma once

#include <iostream>
#include <vector>

#include "Camera.h"
#include "Framebuffer.h"
#include "GLSLProgram.h"
#include "Mesh.h"
#include "Model.h"
#include "Window.h"

class Keyboard {
private:
  Window *window;

public:
  Keyboard(Window *window);
  void poll();
  bool isButtonPressed(unsigned int key);
};
