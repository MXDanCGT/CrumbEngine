//PASSTHROUGH PIXEL SHADER

#version 400

//IN
in vec3 OutCol;
in vec2 OutUV;


//OUT
out vec3 PrintCol;

uniform sampler2D TexSampl; //Again this will be the "atlas" (spritesheet) that blocks draw from, based on our input blockID we will offset the uvs by an amount here...


void main()
{
	PrintCol = texture(TexSampl, OutUV).rgb;
}

//So the problem  with this ALL along was that the inputs and outputs between each shader need to have the same name
//I cant fucking believe I didnt think of that, I lost so much time I do not have to this