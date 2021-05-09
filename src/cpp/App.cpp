#include "App.h"
#include "Camera.h"
#include "Framebuffer.h"
#include "Model.h"
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

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

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

  for (int i = 0; i < 2; i++) {
    std::cout << "Loading model: #" << i << std::endl;

    Model *model;
    model = new Model("assets/models/plane/model.obj");
    models.push_back(model);
  }

  shader = setupShader("src/glsl/general.vs", "src/glsl/general.fs");
  display = setupShader("src/glsl/display.vs", "src/glsl/display.fs");
  framebuffer = new Framebuffer(FRAMEBUFFER_DIMENSIONS, FRAMEBUFFER_DIMENSIONS);
  camera = new Camera();

  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LESS);

  while (!window->shouldClose()) {
    RenderResult result = window->render();

    framebuffer->bind();
    window->clear();

    shader->use();
    shader->setUniform("MVP", camera->getViewMatrix());
    for (int i = 0; i < models.size(); i++) {
      models.at(i)->setRotation(
          glm::vec3(0.0f, (float)result.currentTime * 100 - 90, 0.0f));
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
