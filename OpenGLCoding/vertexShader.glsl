#version 330 core
layout (location = 0) in vec3 aPos;
out vec4 helloWorld;
void main()
{
    gl_Position = vec4(aPos.xyz, 1.8);
    helloWorld = vec4(1.0, 0.0, 0.0, 1.0);
}