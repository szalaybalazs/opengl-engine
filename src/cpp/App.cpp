#include "App.h"
#include "Display.h"
#include "GLSLProgram.h"
#include "Mesh.h"
#include "Model.h"
#include "Scene.h"
#include "Texture.h"
#include "Window.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

// Global scene
Scene *scene;

// Shaders
GLSLProgram *shader;
GLSLProgram *display;

// Window and camera
Window *window;
Camera *camera = new Camera();

int main() {
  window = new Window(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT);

  if (!window->isValid()) {
    return 1;
  }

  // Load shaders
  shader = setupShader("src/glsl/general.vs", "src/glsl/general.fs");

  // Setting scene
  scene = scene->getInstance(shader);

  // Load data
  Mesh *planeMesh = new Mesh("assets/models/plane/model.obj");
  Texture *planeTexture = new Texture("assets/models/plane/diffuse.jpg");
  // Load data
  Mesh *groundMesh = new Mesh("assets/models/ground/model.obj");
  Texture *groundTexture = new Texture("assets/models/ground/diffuse.jpg");

  // Display
  Display *display = new Display(window, FRAMEBUFFER_DIMENSIONS);

  Model *ground = new Model();
  ground->addMesh(groundMesh);
  ground->addTexture(groundTexture);
  scene->addModel(ground);

  // Test model loader
  for (int i = 0; i < 50; i++) {
    Model *model = new Model();
    model->addMesh(planeMesh);
    model->addTexture(planeTexture);
    model->setPosition(glm::vec3((float)i * -16.0f, 0.0f, 0.0f));
    model->setScale(0.4f);
    scene->addModel(model);
  }

  while (!window->shouldClose()) {
    RenderResult result = window->render();

    display->bindFramebuffer();
    scene->render(result.deltaTime);
    display->unbindFramebuffer();

    display->render();
    window->poll();
  }

  return 0;
}
