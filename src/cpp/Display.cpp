#include "Display.h"

Display::Display(Window *window, int width, int height) {
  this->window = window;
  shader = setupShader("src/glsl/display.vs", "src/glsl/display.fs");
  colorbuffer = new Framebuffer(width, height);
  depthbuffer = new Framebuffer(width, height, 1);
  displayMesh = new Mesh("assets/models/display.obj");
}

Display::Display(Window *window, int dimensions) {
  this->window = window;
  shader = setupShader("src/glsl/display.vs", "src/glsl/display.fs");
  colorbuffer = new Framebuffer(dimensions, dimensions);
  depthbuffer = new Framebuffer(dimensions, dimensions, 1);
  displayMesh = new Mesh("assets/models/display.obj");
}

void Display::render() {
  // Setting polygon mode to fill
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  window->clean();
  shader->use();
  colorbuffer->use(0);
  depthbuffer->use(1, "depthTexture", shader);
  displayMesh->draw();
}

void Display::bindFramebuffer() {
  bindColorBuffer();
}
void Display::bindColorBuffer() {
  colorbuffer->bind();
  window->clear();
}
void Display::bindDepthBuffer() {
  depthbuffer->bind();
  window->clear();
}

void Display::unbindFramebuffer() { 
  colorbuffer->unbind();
  depthbuffer->unbind();
}
Window* Display::getWindow() { 
  return window;
}