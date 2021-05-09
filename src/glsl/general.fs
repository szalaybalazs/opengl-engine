#version 330 core
in vec3 vUv;

out vec4 color;

uniform sampler2D screenTexture;

void main() {
  vec3 textureColor =
      texture(screenTexture, vec2(vUv.x, abs(1.0f - vUv.y))).rgb;
  color = vec4(textureColor.rgb, 1.0f);
}
