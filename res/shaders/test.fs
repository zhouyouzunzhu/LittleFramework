#version 330 core

in vec2 fCoord;
in vec4 fColor;

out vec4 outColor;

uniform sampler2D texture0;

void main()
{
	outColor = texture(texture0, fCoord);
}
