#include <glm/vec3.hpp>
#include <vector>

#include "Model.h"
#include <OBJLoader.h>
#include <glm/gtc/matrix_transform.hpp>

Model::Model(const std::string &fileName) {

  /* Load the model's mesh. */

  std::vector<glm::vec3> modelVertices, modelNormals, modelUvs;
  OBJLoader::loadOBJ(fileName, modelVertices, modelNormals, modelUvs);

  vertexCount = modelVertices.size();

  /* Create the OpenGL data structures for the geometric data. */

  glGenVertexArrays(1, &VAO);
  glBindVertexArray(VAO);

  glGenBuffers(1, &positionsVBO);
  glBindBuffer(GL_ARRAY_BUFFER, positionsVBO);
  glBufferData(GL_ARRAY_BUFFER, modelVertices.size() * sizeof(glm::vec3),
               modelVertices.data(), GL_STATIC_DRAW);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), 0);
  glEnableVertexAttribArray(0);

  glGenBuffers(1, &normalsVBO);
  glBindBuffer(GL_ARRAY_BUFFER, normalsVBO);
  glBufferData(GL_ARRAY_BUFFER, modelNormals.size() * sizeof(glm::vec3),
               modelNormals.data(), GL_STATIC_DRAW);
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), 0);
  glEnableVertexAttribArray(1);

  glGenBuffers(1, &uvsVBO);
  glBindBuffer(GL_ARRAY_BUFFER, uvsVBO);
  glBufferData(GL_ARRAY_BUFFER, modelUvs.size() * sizeof(glm::vec3),
               modelUvs.data(), GL_STATIC_DRAW);
  glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), 0);
  glEnableVertexAttribArray(2);

  glBindVertexArray(0);
}

// Update model
void Model::update() {
  //
}

// Draw model
void Model::draw() {
  glBindVertexArray(VAO);
  glDrawArrays(GL_TRIANGLES, 0, vertexCount);
  glBindVertexArray(0);
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
