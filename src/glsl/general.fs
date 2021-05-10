#version 330 core

in vec3 vUv;
in vec3 vNormal;
in vec3 vPosition;

out vec4 color;

struct PointLight {
  float constant;
  float linear;
  float quadratic;
};

uniform sampler2D screenTexture;

uniform vec3 u_light_positions[10];
uniform vec3 u_light_colors[10];
uniform float u_light_strengths[10];
uniform PointLight u_light_configs[10];

// vec3 lightPos = lightPositions[0]; // vec3(50.0f, 20.0f, 0.0f);

void main() {

  vec3 ambient = vec3(0.0);

  vec3 texture = texture(screenTexture, vec2(vUv.x, abs(1.0f - vUv.y))).rgb;

  vec3 norm = normalize(vNormal);
  vec3 diffuse = vec3(0.0);

  for (int i = 0; i < 2; i++) {
    vec3 lightColor = u_light_colors[i];
    float lightStrength = u_light_strengths[i];
    vec3 lightPos = u_light_positions[i];
    PointLight config = u_light_configs[i];

    vec3 lightDir = normalize(lightPos - vPosition);

    float ambientStrength = 1.0;

    float distance = length(lightPos - vPosition);

    float attenuation = 1.0 / (config.constant + config.linear * distance +
                               config.quadratic * (distance * distance));

    float diff = max(dot(norm, lightDir), 0.0);

    ambient += ambientStrength * lightColor * attenuation;
    diffuse += diff * lightColor * attenuation * lightStrength;
  }

  color = vec4(texture.rgb * (ambient + diffuse), 1.0f);
}
