#pragma once

#include <GL/glew.h>
#include <glm/gtx/transform.hpp>
#include <glm/mat4x4.hpp>
#include <string>

class Model {
private:
  // Buffers
  GLuint VAO, positionsVBO, normalsVBO, uvsVBO;
  unsigned int vertexCount;

  // Matrix
  glm::mat4 modelMatrix = glm::mat4(1.0f);

  glm::vec3 position = glm::vec3(0.0f);
  glm::vec3 rotation = glm::vec3(0.0f);
  glm::vec3 scale = glm::vec3(1.0f);

public:
  Model(const std::string &fileName);
  void update();
  void draw();
  glm::mat4 getModelMatrix();

  glm::vec3 getRotation();
  glm::vec3 getPosition();

  void setPosition(glm::vec3 newPosition);
  void setRotation(glm::vec3 newRotation);
  void setScale(float scale);
  void setScale(glm::vec3 newRotation);
};
