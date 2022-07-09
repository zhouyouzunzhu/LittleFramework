#version 330 core

in vec2 fCoord;

out vec4 outColor;

uniform vec4 color;
uniform sampler2D texture0;

void main()
{
	outColor = texture(texture0, fCoord) * color;
}
