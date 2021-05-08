#version 330 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec3 normal;
layout(location = 2) in vec3 uv;

out vec3 vNormal;
out vec3 vUv;

uniform mat4 MVP;
uniform mat4 uModelPosition;

void main() {
  vUv = uv;
  vNormal = normal;
  gl_Position = MVP * uModelPosition * vec4(position, 1.0f);
}