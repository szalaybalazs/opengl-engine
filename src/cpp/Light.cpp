#include "Light.h"

Light::Light() {
  position = glm::vec3(0.0f);
  color = glm::vec3(1.0f);
  strength = 1.0f;

  constant = 1.0;
  linear = 0.045;
  quadratic = 0.0032;
}

void Light::render(GLSLProgram *shader) {
  //
}

void Light::setPosition(glm::vec3 position) { this->position = position; }
void Light::setColor(glm::vec3 color) { this->color = color; }
void Light::setStrength(float strength) { this->strength = strength; }

glm::vec3 Light::getPosition() { return position; }
glm::vec3 Light::getColor() { return color; }
float Light::getStrength() { return strength; }
float Light::getDistance() {
  return glm::distance(this->position, this->camera->getPosition());
}

void Light::setCamera(Camera *camera) { this->camera = camera; }

PointLight Light::getPointLight() {
  PointLight pointLight;
  pointLight.constant = this->constant;
  pointLight.linear = this->linear;
  pointLight.quadratic = this->quadratic;

  return pointLight;
};