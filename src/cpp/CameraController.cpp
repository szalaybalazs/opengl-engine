#include "CameraController.h"
#include "Window.h"
#include "Camera.h"
#include <vector>

#include <glm/vec3.hpp>

#include <OBJLoader.h>
#include <glm/gtc/matrix_transform.hpp>

CameraController::CameraController(Camera* camera, Window* window) {
  this->camera = camera;
  this->window = window;
}

void CameraController::update(double deltaTime){
  glm::vec3 position = camera->getPosition();
  if (window->getButtonState(GLFW_KEY_W)) {
    position.x += deltaTime / 10.0;
  }

  camera->setPosition(position);
}