#version 330 core

layout(location = 0) in vec2 inputVertices;
layout(location = 1) in vec2 inputCoord;
layout(location = 2) in vec4 inputColor;

out vec2 fCoord;
out vec4 fColor;

uniform mat3 projection;
uniform mat3 model;
uniform float time;

void main()
{
    vec3 pos = model * vec3(inputVertices, 1.0f);

    pos.x = pos.x + sin(pos.y * 2.0f + time * 3.0f) * 4.0f;
    pos.y = pos.y + sin(time * 2.0f) * 2.0f;

    gl_Position.xyz = projection * pos;
    gl_Position.z = 0.0f;
    gl_Position.w = 1.0f;
    fColor = inputColor;
    fCoord = inputCoord;
}