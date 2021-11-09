#include "Camera.h"
#include "Window.h"
#include <vector>

#include <glm/vec3.hpp>

#include <OBJLoader.h>
#include <glm/gtc/matrix_transform.hpp>

Camera::Camera() {
  position = glm::vec3(10.0f, 5.0f, 0.0f);
  origin = glm::vec3(0.0f, 2.0f, 0.0f);
}

glm::mat4 Camera::getProjectionMatrix() {
  WindowDimensions dimensions = Window::getDimensions();
  glm::mat4 Projection = glm::perspective(
      glm::radians(45.0f), (float)dimensions.width / (float)dimensions.height,
      0.1f, 60.0f);

  return Projection;
}

glm::mat4 Camera::getCameraMatrix() {
  glm::mat4 View =
      glm::lookAt(this->position, this->origin, glm::vec3(0, 1, 0));

  return View;
}

glm::mat4 Camera::getViewMatrix() {
  glm::mat4 mvp = this->getProjectionMatrix() * this->getCameraMatrix();

  return mvp;
}

glm::vec3 Camera::getPosition() { return this->position; }
void Camera::setPosition(glm::vec3 position) {
  this->position = position;
}