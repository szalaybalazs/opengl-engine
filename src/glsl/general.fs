#version 330 core
in vec3 vUv;

out vec4 color;

void main() { color = vec4(vUv.x, vUv.y, 0.2f, 1.0f); }
