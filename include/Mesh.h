#pragma once

#include <GL/glew.h>
#include <glm/gtx/transform.hpp>
#include <glm/mat4x4.hpp>
#include <string>

class Mesh {
private:
  // Buffers
  GLuint VAO, positionsVBO, normalsVBO, uvsVBO;
  unsigned int vertexCount;

public:
  Mesh(const std::string &fileName);
  void update();
  void draw();
};
