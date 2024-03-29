#pragma once

#include "glm/mat4x2.hpp"
#include <GL/glew.h>
#include <string>

using std::string;

class GLSLProgram {
private:
  int handle;
  bool linked;
  string logString;
  int getUniformLocation(const char *name);
  bool fileExists(const string &fileName);

public:
  GLSLProgram();
  bool compileShaderFromString(const string &source, GLuint type);
  bool compileShaderFromFile(const char *fileName, GLuint type);
  bool link();
  void use();
  string log();
  int getHandle();
  bool isLinked();
  void bindAttribLocation(GLuint location, const char *name);
  void bindFragDataLocation(GLuint location, const char *name);
  void setUniform(const char *name, float x, float y);
  void setUniform(const char *name, float x, float y, float z);
  void setUniform(const char *name, const glm::vec3 &v);
  void setUniform(const char *name, const float v[]);
  void setPositionsUniform(const char *name, const float v[]);
  void setUniform(const char *name, const glm::vec4 &v);
  void setUniform(const char *name, const glm::mat4 &m);
  void setUniform(const char *name, const glm::mat3 &m);
  void setUniform(const char *name, float val);
  void setUniform(const char *name, int val);
  void setUniformi(const char *name, int val);
  void setUniform(const char *name, bool val);
  void printActiveUniforms();
  void printActiveAttribs();
};
GLSLProgram *setupShader(const char *shaderVSSource,
                         const char *shaderFSSource);
