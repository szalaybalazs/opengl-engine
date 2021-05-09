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
  window->clean();
  shader->use();
  framebuffer->use();
  displayMesh->draw();
}

void Display::bindFramebuffer() {
  framebuffer->bind();
  window->clear();
}
void Display::unbindFramebuffer() { framebuffer->unbind(); }