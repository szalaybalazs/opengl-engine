#include "App.h"
#include "Display.h"
#include "GLSLProgram.h"
#include "Light.h"
#include "Mesh.h"
#include "Model.h"
#include "Scene.h"
#include "Texture.h"
#include "Window.h"
#include "Keyboard.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

// #define DEBUG_SHADER;

// Global scene
Scene *scene;

// Shaders
GLSLProgram *shader;
GLSLProgram *display;

// Window and camera
Window *window;

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

  Light *light1 = new Light();
  light1->setPosition(glm::vec3(5.0f, 5.0f, -10.0f));
  Light *light2 = new Light();
  light2->setPosition(glm::vec3(-20.0f, 15.0f, 0.0f));
  light2->setColor(glm::vec3(0.4f, 1.0f, 0.8f));

  scene->addLight(light1);
  scene->addLight(light2);

  // Test model loader
  for (int i = 0; i < 5; i++) {
    Model *model = new Model();
    model->addMesh(planeMesh);
    model->addTexture(planeTexture);
    model->setPosition(glm::vec3((float)i * -16.0f, 0.0f, 0.0f));
    model->setRotation(glm::vec3(0.0f, 135.0f, 0.0f));
    model->setScale(0.4f);
    scene->addModel(model);
  }

  while (!window->shouldClose()) {
    RenderResult result = window->render();

    display->bindFramebuffer();
    scene->render(result.deltaTime);
    display->bindDepthBuffer();
    scene->render(result.deltaTime);
    display->unbindFramebuffer();
    
    glDisable(GL_ALPHA_TEST);
    display->render();
    glEnable(GL_ALPHA_TEST);
    
    window->poll();
  }

  return 0;
}
