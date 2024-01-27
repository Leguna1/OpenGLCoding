#pragma once
#include "Shader.h"
#include "glad/glad.h"

class Material
{
	unsigned int orangeShaderProgram;

public:
	Material(Shader, vertexShader, shader fragmentShader)
	{
		orangeShaderProgram = glCreateProgram();
		glAttachShader(orangeShaderProgram, vertexShader.shaderId);
		glAttachShader(orangeShaderProgram, orangeShader.shaderId);
		glLinkProgram(orangeShaderProgram);
	}
	void use()
	{
		glUseProgram(orangeShaderProgram);

	}
};