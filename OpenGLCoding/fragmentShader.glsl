#version 330 core
out vec4 pixelColor;
uniform vec4 tintColor;
in vec4 vertexColor;
//in vec3 vertexPosition;
//unform float time;
void main()
{                  //  r     g     b     a
    pixelColor = vertexColor;  //+vec4(position, 0);
}