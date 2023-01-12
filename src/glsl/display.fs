#version 330 core
in vec3 vUv;

out vec4 color;

uniform sampler2D screenTexture;
uniform sampler2D depthTexture;

void main() {
  vec3 _color = texture(screenTexture, vec2(vUv.x, abs(1.0f - vUv.y))).rgb;
  vec3 _depth = texture(depthTexture, vec2(vUv.x, abs(1.0f - vUv.y))).rgb;

  color = vec4(vec3(_color), 1.0);
}
