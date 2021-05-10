#pragma once

#include <GL/glew.h>
#include <glm/gtx/transform.hpp>
#include <glm/mat4x4.hpp>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GLSLProgram.h>

#include "Camera.h"
#include "Model.h"

class Scene {
private:
  std::vector<Model *> models;

  Camera *camera;
  GLSLProgram *shader;

  static Scene *instance;

public:
  Scene(GLSLProgram *shader);

  static Scene *getInstance(GLSLProgram *shader) {
    if (!instance) {
      instance = new Scene(shader);
    }
    return instance;
  }

  void addModel(Model *model);
  void update(double deltaTime);
  void draw();
  void render(double deltaTime);
};