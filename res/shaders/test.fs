#version 330 core

in vec2 TexCoords;
in vec4 fColor;

out vec4 outColor;

// uniform sampler2D texture0;

void main()
{
	outColor = fColor;
}
