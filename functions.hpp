#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>
#include "shader.hpp" 

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void DynamicFragmentShader(unsigned int &program);