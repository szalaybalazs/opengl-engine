#version 330 core
in vec3 vUv;

out vec4 color;

uniform sampler2D screenTexture;

void main() {
  vec2 st = gl_FragCoord.xy / vec2(800.0f);
  float pct = distance(st, vec2(0.5));
  vec3 _color = texture(screenTexture, vec2(vUv.x, abs(1.0f - vUv.y))).rgb;
  color = vec4(vec3(_color.r), 1.0);
}
