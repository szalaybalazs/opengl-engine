#include "App.h"
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

Window *window;

// Displaying model
Model *displaymodel;

// Model list
std::vector<Model *> models;

// Last frame time
double lastFrame;

int main() {
  std::srand(static_cast<unsigned int>(std::time(nullptr)));

  if (!glfwInit()) {
    exit(1);
  }

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
    model = new Model("assets/models/plane.obj");
    models.push_back(model);
  }

  shader = setupShader("src/glsl/general.vs", "src/glsl/general.fs");
  display = setupShader("src/glsl/display.vs", "src/glsl/display.fs");
  framebuffer = new Framebuffer(FRAMEBUFFER_DIMENSIONS, FRAMEBUFFER_DIMENSIONS);

  glClearColor(0.5f, 0.1f, 0.1f, 1.0f);
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LESS);

  // Projection matrix : 45° Field of View, 4:3 ratio, display range : 0.1 unit
  // <-> 100 units
  glm::mat4 Projection = glm::perspective(
      glm::radians(45.0f),
      (float)DEFAULT_WINDOW_WIDTH / (float)DEFAULT_WINDOW_HEIGHT, 0.1f, 100.0f);

  // Camera matrix
  glm::mat4 View = glm::lookAt(
      glm::vec3(25, 5, 10), // Camera is at (4,3,3), in World Space
      glm::vec3(0, 0, 0),   // and looks at the origin
      glm::vec3(0, 1, 0)    // Head is up (set to 0,-1,0 to look upside-down)
  );
  glm::mat4 mvp =
      Projection *
      View; // Remember, matrix multiplication is the other way around

  while (!window->shouldClose()) {
    RenderResult result = window->render();

    framebuffer->bind();
    window->clear();

    shader->use();
    shader->setUniform("MVP", mvp);
    for (int i = 0; i < models.size(); i++) {
      models.at(i)->setRotation(
          glm::vec3(0.0f, (float)result.currentTime * 100 - 90, 0.0f));
      models.at(i)->setPosition(glm::vec3((float)i * -16.0f, 0.0f, 0.0f));
      shader->setUniform("uModelPosition", models.at(i)->getModelMatrix());
      models.at(i)->draw();
    }
    framebuffer->unbind();

    window->clear();
    display->use();
    framebuffer->use();
    displaymodel->draw();

    window->poll();
  }

  exit(0);
}
