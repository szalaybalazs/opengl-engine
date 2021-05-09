#version 330 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec3 normal;
layout(location = 2) in vec3 uv;

out vec3 vNormal;
out vec3 vUv;
out vec3 vPosition;

uniform mat4 MVP;
uniform mat4 uModelPosition;

void main() {
  vUv = uv;
  vNormal = mat3(transpose(inverse(uModelPosition))) * normal;
  vPosition = vec3(uModelPosition * vec4(position, 1.0));

  gl_Position = MVP * uModelPosition * vec4(position, 1.0f);
}