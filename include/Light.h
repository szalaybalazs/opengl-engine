#pragma once

#include <iostream>
#include <vector>

#include "Camera.h"
#include "Framebuffer.h"
#include "GLSLProgram.h"
#include "Mesh.h"
#include "Model.h"
#include "Window.h"

struct PointLight {
  float constant;
  float linear;
  float quadratic;
};

class Light {
private:
  glm::vec3 position = glm::vec3(0.0f);
  glm::vec3 color = glm::vec3(1.0f);
  float strength = 1.0f;
  Camera *camera;

  float constant = 1.0;
  float linear = 0.045;
  float quadratic = 0.0032;

public:
  Light();
  void setCamera(Camera *camera);
  void render(GLSLProgram *shader);
  void setPosition(glm::vec3 position);
  void setColor(glm::vec3 color);
  void setStrength(float strength);
  glm::vec3 getPosition();
  glm::vec3 getColor();
  float getStrength();
  float getDistance();

  PointLight getPointLight();
};
