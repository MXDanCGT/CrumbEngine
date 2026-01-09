//PASSTHROUGH PIXEL SHADER

#version 400

in vec3 InCol;

//OUT
out vec4 OutCol;


void main(void)
{
	OutCol = vec4(1.f,0.f,0.f, 1.f);
}