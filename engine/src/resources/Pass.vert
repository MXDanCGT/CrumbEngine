//PASSTHROUGH VERTEX SHADER

#version 400

//IN
layout(location = 0) in vec3 InPos;
layout(location = 1) in vec2 InUV;

//OUT
out vec3 OutCol;
out vec2 OutUV;

//UNIFORM
uniform mat4 MatWorld;
uniform mat4 MatView;
uniform mat4 MatProj;


void main()
{
	//Just like it was in 301
	gl_Position = MatWorld * vec4(InPos, 1.f);
	gl_Position = MatView * gl_Position;
	gl_Position = MatProj * gl_Position;

	OutCol = vec3(1.f,0.f,1.f);

	OutUV = InUV; //TODO OFFSET UV HERE!
}