#include <glm/vec3.hpp>
#include <vector>

#include "GLSLProgram.h"
#include "Mesh.h"
#include "Model.h"
#include <OBJLoader.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/mat4x4.hpp>

Model::Model() {}
void Model::addMesh(Mesh *mesh) { meshes.push_back(mesh); }
void Model::addTexture(Texture *texture) { textures.push_back(texture); }

void Model::updateMeshes() {
  for (int i = 0; i < this->meshes.size(); i++) {
    meshes.at(i)->update();
  }
}
void Model::drawMeshes() {
  for (int i = 0; i < this->meshes.size(); i++) {
    meshes.at(i)->draw();
  }
}

void Model::updateTextures() {
  for (int i = 0; i < this->textures.size(); i++) {
    textures.at(i)->update();
  }
}

void Model::drawTextures() {
  for (int i = 0; i < this->textures.size(); i++) {
    textures.at(i)->draw();
  }
}

// Update model
void Model::update() {
  this->updateTextures();
  this->updateMeshes();
}

// Draw model
void Model::draw() {
  this->drawTextures();
  this->drawMeshes();
}
// Draw model
void Model::draw(GLSLProgram *shader) {
  shader->setUniform("uModelPosition", this->getModelMatrix());
  this->drawTextures();
  this->drawMeshes();
}

/**
 * Getting the model transformation matrix
 * @return (mat4) the model transformation matrix
 */
glm::mat4 Model::getModelMatrix() {
  return glm::translate(glm::mat4(1.0f), position) *
         glm::scale(glm::mat4(1.0f), scale) *
         glm::rotate(glm::mat4(1.0f), glm::radians(rotation.y),
                     glm::vec3(0.0f, 1.0f, 0.0f)) *
         glm::rotate(glm::mat4(1.0f), glm::radians(rotation.x),
                     glm::vec3(1.0f, 0.0f, 0.0f)) *
         glm::rotate(glm::mat4(1.0f), glm::radians(rotation.z),
                     glm::vec3(0.0f, 0.0f, 1.0f));
}

/**
 * Get the rotation of the model
 * @return (vec3) the model rotation
 */
glm::vec3 Model::getRotation() { return this->rotation; }

/**
 * Get the position of the model
 * @return (vec3) the model position
 */
glm::vec3 Model::getPosition() { return this->position; }

/**
 * Set the position of the model
 * @param position (vec3) the new position of the model
 * @return void
 */
void Model::setPosition(glm::vec3 newPosition) { this->position = newPosition; }

/**
 * Set the rotation of the model
 * @param rotation (vec3) the new rotation of the model
 * @return void
 */
void Model::setRotation(glm::vec3 newRotation) { this->rotation = newRotation; }

/**
 * Set the scale of the model
 * @param scale (vec3) the new scale of the model
 * @return void
 */
void Model::setScale(glm::vec3 newScale) { this->scale = newScale; }

/**
 * Set the scale of the model
 * @param scale (float) the new scale of the model
 * @return void
 */
void Model::setScale(float newScale) { this->scale = glm::vec3(newScale); }
