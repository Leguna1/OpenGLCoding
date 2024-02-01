#version 330 core
out vec4 pixelColor;
uniform vec4 tintColor;

in vec4 vertexColor;
in vec4 vertexPosition;

uniform float time;
uniform sampler2D ourTexture;
in vec2 TexCoord; 
uniform sampler2D diffuseTexture;
uniform sampler2D blendTExture;


void main()
{
    vec4 movingColors = vec4(
        sin(time * 0.5),
        cos(time * 0.5),
        sin(time * 0.2 + 1.0),
        1.0
    );

    vec4 finalColor = vertexColor + vec4(vertexPosition.xyz, 0.0) + tintColor + movingColors;

    pixelColor = mix(texture(diffuseTexture, texCoord), texture(blendTexture, texCoord), 0.5;

}