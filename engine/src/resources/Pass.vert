//PASSTHROUGH VERTEX SHADER

#version 400

//IN
in vec3 InPos;
in vec3 InCol;


//OUT
out vec3 OutCol;


//UNIFORM
uniform mat4 MatWorld;
uniform mat4 MatView;
uniform mat4 MatProj;

void main(void)
{
	//Just like it was in 301
	gl_Position = MatWorld * vec4(InPos, 1.f);
	gl_Position = MatView * gl_Position;
	gl_Position = MatProj * gl_Position;


	OutCol = InCol;
}