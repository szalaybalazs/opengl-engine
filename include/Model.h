#pragma once

#include "GLSLProgram.h"
#include "Mesh.h"
#include "Texture.h"
#include <GL/glew.h>
#include <glm/gtx/transform.hpp>
#include <glm/mat4x4.hpp>
#include <iostream>
#include <string>
#include <vector>

class Model {
private:
  Mesh *mesh;
  std::vector<Mesh *> meshes;
  std::vector<Texture *> textures;

  // Matrix
  glm::mat4 modelMatrix = glm::mat4(1.0f);

  glm::vec3 position = glm::vec3(0.0f);
  glm::vec3 rotation = glm::vec3(0.0f);
  glm::vec3 scale = glm::vec3(1.0f);

public:
  Model();
  void update();
  void draw();
  void draw(GLSLProgram *shader);

  void updateMeshes();
  void updateTextures();
  void drawMeshes();
  void drawTextures();

  void addMesh(Mesh *mesh);
  void addTexture(Texture *texture);

  glm::mat4 getModelMatrix();

  glm::vec3 getRotation();
  glm::vec3 getPosition();

  void setPosition(glm::vec3 newPosition);
  void setRotation(glm::vec3 newRotation);
  void setScale(float scale);
  void setScale(glm::vec3 newRotation);
};
