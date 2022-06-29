#version 330 core

layout(location = 0) in vec2 vertices;
layout(location = 1) in vec4 vColor;

out vec4 fColor;
uniform mat3 projection;
uniform mat3 model;

void main()
{
    gl_Position.xyz = projection * model * vec3(vertices, 1.0f);
    gl_Position.z = 0.0f;
    gl_Position.w = 1.0f;
    fColor = vColor;
}