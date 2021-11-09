#include "Scene.h"

Scene *Scene::instance = 0;

Scene::Scene(GLSLProgram *shader) {
  this->shader = shader;
  this->camera = new Camera();
}

void Scene::update(double deltaTime) {
  for (int i = 0; i < models.size(); i++) {
    Model *model = models.at(i);
    model->update();
    glm::vec3 currentRotation = model->getRotation();
    currentRotation.y += deltaTime * 10;
    model->setRotation(currentRotation);
  }
}

bool Scene::compareLights(Light *l1, Light *l2) {
  return l1->getDistance() < l2->getDistance();
}

void Scene::renderLights() {
  int number = fmin(10, lights.size());
  glm::vec3 cameraPos = this->camera->getPosition();

  std::sort(lights.begin(), lights.end(), compareLights);

  float positions[number * 3];
  float colors[number * 3];
  float strengths[number];

  // Rendering lights, only one for now
  for (int i = 0; i < number; i++) {
    Light *light = lights.at(i);
    PointLight config = light->getPointLight();

    std::string strength = "u_light_strengths[" + std::to_string(i) + "]";
    std::string position = "u_light_positions[" + std::to_string(i) + "]";
    std::string color = "u_light_colors[" + std::to_string(i) + "]";
    std::string constant = "u_light_configs[" + std::to_string(i) + "].constant";
    std::string linear = "u_light_configs[" + std::to_string(i) + "].linear";
    std::string quadratic = "u_light_configs[" + std::to_string(i) + "].quadratic";

    shader->setUniform(position.c_str(), light->getPosition());
    shader->setUniform(color.c_str(), light->getColor());
    shader->setUniform(strength.c_str(), light->getStrength());
    shader->setUniform(constant.c_str(), config.constant);
    shader->setUniform(linear.c_str(), config.linear);
    shader->setUniform(quadratic.c_str(), config.quadratic);
  }
}

void Scene::draw() {
  for (int i = 0; i < models.size(); i++) {
    models.at(i)->draw(shader);
  }
}

void Scene::render(double deltaTime) {
  shader->use();
  shader->setUniform("MVP", camera->getViewMatrix());
  update(deltaTime);
  renderLights();
  draw();
}

void Scene::addModel(Model *model) { this->models.push_back(model); }
void Scene::addLight(Light *light) {
  light->setCamera(camera);
  this->lights.push_back(light);
}