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
#include <Camera.h>
#include <Window.h>


class CameraController {
private:
  Camera *camera;
  Window *window;

public:
  CameraController(Camera *camera, Window *window);
  void update(double deltaTime);
};
