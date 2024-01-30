#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec4 aCol;
out vec4 vertexColor;
//out vec4 vertexPosition;
void main()
{
    gl_Position = vec4(aPos.xyz, 1.8);
    vertexColor = aCol; //=vec4 (0, 1, 0, 1) +vec4 (vertexPosition, 1) + 
    //vec4 (sin(time*50+vertexPosition.x*2 /2, cos, (time*5+vertexPosition.y*4)*2+1);


}