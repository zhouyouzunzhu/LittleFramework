#version 330 core

layout(location = 0) in vec4 vColor;
layout(location = 1) in vec2 vertices;
layout(location = 2) in vec2 vCoords;

out vec2 TexCoords;
out vec4 fColor;
out vec2 fEffect;
uniform mat3 projection;

void main()
{
    gl_Position.xyz = projection * vec3(vertices, 1.0f);
    gl_Position.z = 0.0f;
    gl_Position.w = 1.0f;
    TexCoords = vCoords;
    fColor = vColor;
}