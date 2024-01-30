#version 330 core
out vec4 pixelColor;
uniform vec4 tintColor;

in vec4 vertexColor;
in vec4 vertexPosition;

uniform float time;
uniform float xOffset;

void main()
{
    // Calculate a time-based effect with moving colors
    vec4 movingColors = vec4(
        sin(time * 0.5),
        cos(time * 0.5),
        sin(time * 0.5 + 1.0),
        1.0
    );

    // Combine vertex color, vertex position, and moving colors
    vec4 finalColor = vertexColor + vec4(vertexPosition.xyz, 0.0) + tintColor + movingColors;

    // Output the final color
    pixelColor = finalColor;
}
