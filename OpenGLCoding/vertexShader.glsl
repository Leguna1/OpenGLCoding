#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec4 aCol;
layout (location = 2) in vec2 texCoord;

out vec4 vertexColor;
out vec4 vertexPosition;
out vec2 TexCoord;

uniform float time;
uniform float xOffset;

void main()
{
    vec4 movingColors = vec4(
        sin(time * 0.5),
        cos(time * 0.5),
        sin(time * 0.5 + 1.0),
        1.0
    );

    TexCoord = texCoord;
    
    vec4 color = texture(ourTexture, TexCoord) * vec4(aCol.rgb, 1.0);
    
    vertexColor = color + movingColors;
    
    gl_Position = vec4(aPos.x + xOffset - 0.7, aPos.y + 0.5, aPos.z + 0.2, 1.0);

    vertexPosition = gl_Position;
}
