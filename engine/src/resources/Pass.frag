//PASSTHROUGH PIXEL SHADER


//IN
in vec3 InCol;

//OUT
out vec3 OutCol;


void main(void)
{
	OutCol = vec4(InCol, 1.f);
}