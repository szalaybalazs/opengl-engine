#include "Framebuffer.h"
#include <vector>

#include <glm/vec3.hpp>

#include <OBJLoader.h>
#include <glm/gtc/matrix_transform.hpp>

Framebuffer::Framebuffer(int width, int height, int type) {
  this->type = type;
  this->init(width, height);
}

// Init the framebuffer
void Framebuffer::init(int width, int height) {
  this->width = width;
  this->height = height;

  initColourBuffer();
  initDepthBuffer();
}

void Framebuffer::initColourBuffer() {
  glGenFramebuffers(1, &framebuffer_colour);
  glBindFramebuffer(GL_FRAMEBUFFER, framebuffer_colour);

  // COLOUR
  glGenTextures(1, &colorbuffer);
  glBindTexture(GL_TEXTURE_2D, colorbuffer);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
  glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, colorbuffer, 0);
  glGenRenderbuffers(1, &rbo);
  glBindRenderbuffer(GL_RENDERBUFFER, rbo);
  glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, width, height);
  glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, rbo);

  if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) {
    std::cout << "ERROR::FRAMEBUFFER:: Framebuffer is not complete!" << std::endl;
  }

  // Unbind framebuffer
  glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void Framebuffer::initDepthBuffer() {
  glGenFramebuffers(1, &framebuffer_depth);
  glBindFramebuffer(GL_FRAMEBUFFER, framebuffer_depth);

  glGenTextures(1, &depthMap);
  glBindTexture(GL_TEXTURE_2D, depthMap);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, width, height, 0,GL_DEPTH_COMPONENT, GL_FLOAT, NULL);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
  glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, depthMap, 0);


  if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) {
    std::cout << "ERROR::FRAMEBUFFER:: Framebuffer is not complete!" << std::endl;
  }

  // Unbind framebuffer
  glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

// Bind the framebuffer to draw to it
void Framebuffer::bind() {
  glBindFramebuffer(GL_FRAMEBUFFER, type == 1 ? framebuffer_depth : framebuffer_colour);
  glViewport(0, 0, this->width, this->height);
}

// Unbind the framebuffer
void Framebuffer::unbind() { glBindFramebuffer(GL_FRAMEBUFFER, 0); }

// Bind the texture of the framebuffer
void Framebuffer::use(unsigned int unit) { 
  glActiveTexture(unit);
  glBindTexture(GL_TEXTURE_2D, type == 1 ? depthMap : colorbuffer);
}

unsigned int units[5] = {
  GL_TEXTURE0, GL_TEXTURE1, GL_TEXTURE2, GL_TEXTURE3, GL_TEXTURE4
};

void Framebuffer::use(unsigned int unit, char *uniform, GLSLProgram *shader) { 
  glActiveTexture(units[unit]);
  glBindTexture(GL_TEXTURE_2D, type == 1 ? depthMap : colorbuffer);
  shader->setUniformi(uniform, unit);
}

void Framebuffer::setType(int type) {
  this->type = type;
};
unsigned int Framebuffer::getType() {
  return type;
};