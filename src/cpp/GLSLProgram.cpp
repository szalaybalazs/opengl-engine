#include "GLSLProgram.h"
#include "glm/gtc/type_ptr.hpp"
#include <fstream>
#include <iostream>
#include <vector>

using glm::mat3;
using glm::mat4;
using glm::vec3;
using glm::vec4;

GLSLProgram::GLSLProgram()
{
  handle = glCreateProgram();
  linked = false;
}

bool GLSLProgram::compileShaderFromString(const string &source, GLuint type)
{
  GLuint shaderID = glCreateShader(type);

  // Compile Shader
  char const *SourcePointer = source.c_str();
  glShaderSource(shaderID, 1, &SourcePointer, nullptr);
  glCompileShader(shaderID);

  // Check if the compilation worked
  GLint isCompiled = 0;
  glGetShaderiv(shaderID, GL_COMPILE_STATUS, &isCompiled);

  if (isCompiled == GL_TRUE)
  {
    glAttachShader(handle, shaderID);
#if defined(DEBUG_SHADER)
    printf("Shader compiled successfully.\n");
#endif
  }
  else
  {
    GLint maxLength = 0;
    glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &maxLength);

    if (maxLength > 0)
    {
      std::vector<char> infoLog(maxLength + 1);
      glGetShaderInfoLog(shaderID, maxLength, nullptr, infoLog.data());
      logString = string(std::begin(infoLog), std::end(infoLog));
      printf("One or more errors were encountered while compiling this shader.\n");
    }
  }

  return isCompiled == GL_TRUE;
}

bool GLSLProgram::compileShaderFromFile(const char *fileName, GLuint type)
{
  if (fileExists(fileName))
  {
    string shaderCode;
    std::ifstream ShaderStream(fileName, std::ios::in);
    if (ShaderStream.is_open())
    {
      std::string Line = "";
      while (getline(ShaderStream, Line))
        shaderCode += "\n" + Line;
      ShaderStream.close();

      return compileShaderFromString(shaderCode, type);
    }
  }

  logString = "The specified shader file was not found.";
  return false;
}

bool GLSLProgram::link()
{
  glLinkProgram(handle);

  // Check if the linking worked
  GLint isLinked = 0;
  glGetProgramiv(handle, GL_LINK_STATUS, &isLinked);
  if (isLinked == GL_TRUE)
  {
    linked = true;
#if defined(DEBUG_SHADER)
    printf("Shader program linked successfully.\n");
#endif
  }
  else
  {
    GLint maxLength = 0;
    glGetProgramiv(handle, GL_INFO_LOG_LENGTH, &maxLength);

    std::vector<char> infoLog(maxLength);
    glGetShaderInfoLog(handle, maxLength, NULL, infoLog.data());
    logString = string(begin(infoLog), end(infoLog));

    // The program is useless now.
    glDeleteProgram(handle);
  }

  return linked;
}

void GLSLProgram::use()
{
  if (linked)
    glUseProgram(handle);
}

string GLSLProgram::log() { return logString; }

int GLSLProgram::getHandle() { return handle; }

bool GLSLProgram::isLinked() { return linked; }

void GLSLProgram::bindAttribLocation(GLuint location, const char *name)
{
  glBindAttribLocation(handle, location, name);
}

void GLSLProgram::bindFragDataLocation(GLuint location, const char *name)
{
  glBindFragDataLocation(handle, location, name);
}

void GLSLProgram::setUniform(const char *name, float x, float y)
{
  GLint location = getUniformLocation(name);

  if (location != -1)
    glUniform2f(location, x, y);
}

void GLSLProgram::setUniform(const char *name, float x, float y, float z)
{
  GLint location = getUniformLocation(name);

  if (location != -1)
    glUniform3f(location, x, y, z);
}

void GLSLProgram::setPositionsUniform(const char *name, const float v[])
{
  GLint location = getUniformLocation(name);

  if (location != -1)
    glUniform3fv(location, sizeof(v) / sizeof(v[0]), v);
}

void GLSLProgram::setUniform(const char *name, const vec3 &v)
{
  GLint location = getUniformLocation(name);
  if (location != -1)
    glUniform3fv(location, 1, value_ptr(v));
}

void GLSLProgram::setUniform(const char *name, const vec4 &v)
{
  GLint location = getUniformLocation(name);

  if (location != -1)
    glUniform4fv(location, 1, value_ptr(v));
}

void GLSLProgram::setUniform(const char *name, const mat4 &m)
{
  GLint location = getUniformLocation(name);

  if (location != -1)
    glUniformMatrix4fv(location, 1, GL_FALSE, value_ptr(m));
}

void GLSLProgram::setUniform(const char *name, const mat3 &m)
{
  GLint location = getUniformLocation(name);

  if (location != -1)
    glUniformMatrix3fv(location, 1, GL_FALSE, value_ptr(m));
}

void GLSLProgram::setUniform(const char *name, float val)
{
  GLint location = getUniformLocation(name);

  if (location != -1)
    glUniform1f(location, val);
}

void GLSLProgram::setUniformi(const char *name, int val)
{
  GLint location = getUniformLocation(name);

  if (location != -1)
    glUniform1i(location, val);
}
void GLSLProgram::setUniform(const char *name, int val)
{
  GLint location = getUniformLocation(name);

  if (location != -1)
    glUniform1i(location, val);
}

void GLSLProgram::setUniform(const char *name, bool val)
{
  GLint location = getUniformLocation(name);

  if (location != -1)
    glUniform1i(location, val);
}
void GLSLProgram::setUniform(const char *name, const float v[])
{
  GLint location = getUniformLocation(name);

  if (location != -1)
    glUniform1fv(location, sizeof(v) / sizeof(v[0]), v);
}
void GLSLProgram::printActiveUniforms()
{
  GLint i;
  GLint count;

  GLint size;  // size of the variable
  GLenum type; // type of the variable (float, vec3 or mat4, etc)

  const GLsizei bufSize = 32; // maximum name length
  GLchar name[bufSize];       // variable name in GLSL
  GLsizei length;             // name length

  glGetProgramiv(handle, GL_ACTIVE_UNIFORMS, &count);
#if defined(DEBUG_SHADER)
  printf("Active Uniforms: %d\n", count);
#endif

  for (i = 0; i < count; i++)
  {
    glGetActiveUniform(handle, (GLuint)i, bufSize, &length, &size, &type, name);
#if defined(DEBUG_SHADER)
    printf("Uniform #%d Type: %u Name: %s\n", i, type, name);
#endif
  }
}

void GLSLProgram::printActiveAttribs()
{
  GLint i;
  GLint count;

  GLint size;  // size of the variable
  GLenum type; // type of the variable (float, vec3 or mat4, etc)

  const GLsizei bufSize = 32; // maximum name length
  GLchar name[bufSize];       // variable name in GLSL
  GLsizei length;             // name length

  glGetProgramiv(handle, GL_ACTIVE_ATTRIBUTES, &count);
#if defined(DEBUG_SHADER)
  printf("Active Attributes: %d\n", count);
#endif

  for (i = 0; i < count; i++)
  {
    glGetActiveAttrib(handle, (GLuint)i, bufSize, &length, &size, &type, name);
#if defined(DEBUG_SHADER)
    printf("Attribute #%d Type: %u Name: %s\n", i, type, name);
#endif
  }
}

bool GLSLProgram::fileExists(const string &fileName)
{
  std::ifstream infile(fileName);
  return infile.good();
}

int GLSLProgram::getUniformLocation(const char *name)
{
  return glGetUniformLocation(handle, name);
}

GLSLProgram *setupShader(const char *shaderVSSource,
                         const char *shaderFSSource)
{
  GLSLProgram *shaderProgram = new GLSLProgram();

  if (!shaderProgram->compileShaderFromFile(shaderVSSource, GL_VERTEX_SHADER))
  {
    printf("Vertex shader failed to compile! %s\n",
           shaderProgram->log().c_str());
    delete shaderProgram;
    exit(1);
  }

  if (!shaderProgram->compileShaderFromFile(shaderFSSource,
                                            GL_FRAGMENT_SHADER))
  {
    printf("Fragment shader failed to compile! %s\n",
           shaderProgram->log().c_str());
    delete shaderProgram;
    exit(1);
  }

  if (!shaderProgram->link())
  {
    printf("Shader program failed to link! %s\n", shaderProgram->log().c_str());
    delete shaderProgram;
    exit(1);
  }

  shaderProgram->printActiveUniforms();
  shaderProgram->printActiveAttribs();

  return shaderProgram;
}
