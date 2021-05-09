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

void Scene::draw() {
  for (int i = 0; i < models.size(); i++) {
    models.at(i)->draw(shader);
  }
}

void Scene::render(double deltaTime) {
  shader->use();
  shader->setUniform("MVP", camera->getViewMatrix());
  update(deltaTime);
  draw();
}

void Scene::addModel(Model *model) { this->models.push_back(model); }