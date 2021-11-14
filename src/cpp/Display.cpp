#include "Display.h"

Display::Display(Window *window, int width, int height) {
  this->window = window;
  shader = setupShader("src/glsl/display.vs", "src/glsl/display.fs");
  framebuffer = new Framebuffer(width, height);
  displayMesh = new Mesh("assets/models/display.obj");
}

Display::Display(Window *window, int dimensions) {
  this->window = window;
  shader = setupShader("src/glsl/display.vs", "src/glsl/display.fs");
  framebuffer = new Framebuffer(dimensions, dimensions);
  displayMesh = new Mesh("assets/models/display.obj");
}

void Display::render() {
  // Setting polygon mode to fill
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  window->clean();
  shader->use();
  framebuffer->use();
  displayMesh->draw();
}

void Display::bindFramebuffer() {
  // TESTING
  {
    int state = window->getButtonState(GLFW_KEY_1);
    framebuffer->setType(state == GLFW_PRESS ? 1 : 0);
  }
  framebuffer->bind();
  window->clear();
}

void Display::unbindFramebuffer() { 
  framebuffer->unbind();
}
Window* Display::getWindow() { 
  return window;
}