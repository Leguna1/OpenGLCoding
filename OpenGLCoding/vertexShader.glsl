#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec4 aCol;
out vec4 vertexColor;
out vec4 vertexPosition;

uniform float time;
uniform float xOffset;

void main()
{
    // Calculate a time-based effect with moving colors
    vec4 movingColors = vec4(
        sin(time * 0.9),
        cos(time * 0.9),
        sin(time * 0.5 + 1.0),
        1.0
    );

    // Combine vertex color, vertex position, and moving colors
    vertexColor = aCol + movingColors;
    gl_Position = vec4(aPos.x + xOffset-0.5, aPos.y-0.2, aPos.z+0.2, 1.0);

    // Pass the modified position to the fragment shader
    vertexPosition = gl_Position;
}
