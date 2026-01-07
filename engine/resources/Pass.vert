//Pass shaders are our basic "pass through" shaders, they dont do anything fancy they just get shit renderering

#version 400

in vec3 InPos;
in vec3 InColour;

out vec3 OutColour;

uniform mat4 MatWorld;
uniform mat4 MatView;
uniform mat4 MatProj;


void main(void)
{
	gl_Position = MatWorld * vec4(InPos, 1.f);
	gl_Position = MatView * gl_Position;
	gl_Position = MatProj * gl_Position;

	OutColour = InColour;
}