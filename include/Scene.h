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
#include "CameraController.h"
#include "Light.h"
#include "Model.h"

class Scene {
private:
  std::vector<Model *> models;
  std::vector<Light *> lights;

  Camera *camera;
  CameraController *cameraController;
  GLSLProgram *shader;

  static Scene *instance;
  static bool compareLights(Light *l1, Light *l2);

public:
  Scene(GLSLProgram *shader);

  static Scene *getInstance(GLSLProgram *shader) {
    if (!instance) {
      instance = new Scene(shader);
    }
    return instance;
  }

  void addModel(Model *model);
  void addLight(Light *light);
  void update(double deltaTime);
  void draw();
  void render(double deltaTime);
  void renderLights();

private:
  float runningTime;
};
