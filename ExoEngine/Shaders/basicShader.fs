#version 130

varying vec2 texCoord0;
varying vec3 normal0;

uniform sampler2D diffuse;

void main()
{
	gl_FragColor =  texture2D(diffuse, texCoord0)
		* clamp(dot(-vec3(1.5,-1.5,5), normal0), 0.0, 1.0);
}