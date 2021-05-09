#include "App.h"
#include "Camera.h"
#include "Framebuffer.h"
#include "Model.h"
#include "Texture.h"
#include "Window.h"

#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GLSLProgram.h>

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

// Shaders
GLSLProgram *shader;
GLSLProgram *display;

// Render buffer
Framebuffer *framebuffer;

// Window and camera
Window *window;
Camera *camera;

// Displaying model
Model *displaymodel;
Texture *texture;
Texture *texture2;

// Model list
std::vector<Model *> models;

int main() {
  window = new Window(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT);

  if (!window->isValid()) {
    glfwTerminate();
    exit(1);
  }

  glewExperimental = GL_TRUE;

  if (glewInit() != GLEW_OK) {
    exit(1);
  }

  displaymodel = new Model("assets/models/display.obj");
  texture = new Texture("assets/models/plane/diffuse.jpg");
  texture2 = new Texture("assets/models/shuttle/diffuse.jpg");

  for (int i = 0; i < 2; i++) {
    std::cout << "Loading model: #" << i << std::endl;

    Model *model;
    model = new Model(i == 1 ? "assets/models/shuttle/model.obj"
                             : "assets/models/plane/model.obj");
    models.push_back(model);
  }

  shader = setupShader("src/glsl/general.vs", "src/glsl/general.fs");
  display = setupShader("src/glsl/display.vs", "src/glsl/display.fs");
  framebuffer = new Framebuffer(FRAMEBUFFER_DIMENSIONS, FRAMEBUFFER_DIMENSIONS);
  camera = new Camera();

  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LESS);

  // glEnable(GL_CULL_FACE);
  // glCullFace(GL_FRONT);
  // glFrontFace(GL_CCW);

  while (!window->shouldClose()) {
    RenderResult result = window->render();

    framebuffer->bind();
    window->clear();

    shader->use();
    shader->setUniform("MVP", camera->getViewMatrix());
    for (int i = 0; i < models.size(); i++) {
      if (i == 1) {
        models.at(i)->setScale(0.5);
        texture2->use();
      } else {
        texture->use();
      }
      models.at(i)->setRotation(
          glm::vec3(0.0f, (float)result.currentTime * 10 - 90, 0.0f));
      models.at(i)->setPosition(glm::vec3((float)i * -16.0f, 0.0f, 0.0f));
      shader->setUniform("uModelPosition", models.at(i)->getModelMatrix());
      models.at(i)->draw();
    }
    framebuffer->unbind();

    window->clean();
    display->use();
    framebuffer->use();
    displaymodel->draw();

    window->poll();
  }

  exit(0);
}
