//Pass shaders are our basic "pass through" shaders, they dont do anything fancy they just get shit renderering
//Original plan was to call these ".fs" but apparently F# is a thing, so its .frag and .vert for vs now

#version 400

in vec3 InColour;
out vec4 OutColour; 

void main(void)
{
	OutColour = vec4(InColour, 1.0f);
}