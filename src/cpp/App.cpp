#include "App.h"
#include "Camera.h"
#include "Framebuffer.h"
#include "GLSLProgram.h"
#include "Mesh.h"
#include "Model.h"
#include "Texture.h"
#include "Window.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

// Shaders
GLSLProgram *shader;
GLSLProgram *display;

// Render buffer
Framebuffer *framebuffer;

// Window and camera
Window *window = new Window(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT);
Camera *camera = new Camera();

// Model list
std::vector<Model *> models;

int main() {
  if (!window->isValid()) {
    return 1;
  }

  // Meshes
  Mesh *planeMesh = new Mesh("assets/models/plane/model.obj");
  Mesh *displayMesh = new Mesh("assets/models/display.obj");

  // Textures
  Texture *planeTexture = new Texture("assets/models/plane/diffuse.jpg");

  // Test model loader
  for (int i = 0; i < 50; i++) {
    Model *model;
    model = new Model();
    model->addMesh(planeMesh);
    model->addTexture(planeTexture);
    models.push_back(model);
  }

  // Load shaders
  shader = setupShader("src/glsl/general.vs", "src/glsl/general.fs");
  display = setupShader("src/glsl/display.vs", "src/glsl/display.fs");
  framebuffer = new Framebuffer(FRAMEBUFFER_DIMENSIONS, FRAMEBUFFER_DIMENSIONS);

  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LESS);

  // glEnable(GL_CULL_FACE);
  // glCullFace(GL_FRONT);
  // glFrontFace(GL_CW);

  // Game loop
  while (!window->shouldClose()) {
    RenderResult result = window->render();

    framebuffer->bind();
    window->clear();

    shader->use();
    shader->setUniform("MVP", camera->getViewMatrix());
    float angle = (float)result.currentTime * 10;

    for (int i = 0; i < models.size(); i++) {
      models.at(i)->setRotation(glm::vec3(0.0f, angle, 0.0f));
      models.at(i)->setPosition(glm::vec3((float)i * -16.0f, 0.0f, 0.0f));
      models.at(i)->draw(shader);
    }

    framebuffer->unbind();

    window->clean();
    display->use();
    framebuffer->use();
    displayMesh->draw();

    window->poll();
  }

  return 0;
}
