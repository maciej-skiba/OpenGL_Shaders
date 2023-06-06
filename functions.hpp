#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
unsigned int ShadersProgram(unsigned int &VAO);
void DynamicFragmentShader(unsigned int &program);
void CheckShaderCompilation(unsigned int vertexShader);
void CheckShaderLink(unsigned int shaderProgram);