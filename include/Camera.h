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

class Camera {
private:
  glm::vec3 position;
  glm::vec3 origin;

public:
  Camera();
  glm::mat4 getCameraMatrix();
  glm::mat4 getProjectionMatrix();
  glm::mat4 getViewMatrix();
};
