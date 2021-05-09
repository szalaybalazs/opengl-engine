#include <glm/vec3.hpp>
#include <vector>

#include "Mesh.h"
#include <OBJLoader.h>
#include <glm/gtc/matrix_transform.hpp>

Mesh::Mesh(const std::string &fileName) {

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
void Mesh::update() {
  //
}

// Draw model
void Mesh::draw() {
  glBindVertexArray(VAO);
  glDrawArrays(GL_TRIANGLES, 0, vertexCount);
  glBindVertexArray(0);
}
