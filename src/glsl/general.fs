#version 330 core

in vec3 vUv;
in vec3 vNormal;
in vec3 vPosition;

out vec4 color;

uniform sampler2D screenTexture;

vec3 lightPos = vec3(50.0f, 20.0f, 0.0f);

void main() {
  vec3 lightColor = vec3(1.0f, 1.0f, 1.0f);
  float ambientStrength = 0.1;
  vec3 ambient = ambientStrength * lightColor;

  vec3 texture = texture(screenTexture, vec2(vUv.x, abs(1.0f - vUv.y))).rgb;

  vec3 norm = normalize(vNormal);
  vec3 lightDir = normalize(lightPos - vPosition);

  float diff = max(dot(norm, lightDir), 0.0);
  vec3 diffuse = diff * lightColor;

  color = vec4(texture.rgb * (ambient + diffuse), 1.0f);
}
