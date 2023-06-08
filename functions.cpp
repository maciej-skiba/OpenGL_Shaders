#include "functions.hpp" 

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

// Change fragment shader's color by time
void DynamicFragmentShader(unsigned int &program)
{
    float divider = 3.0f;

    float timeValue = glfwGetTime();
    float redValue = fabs((float)(sin(timeValue)) / divider);
    float greenValue = fabs((float)(sin(timeValue)) / divider);
    float blueValue = fabs((float)(sin(timeValue)) / divider);

    int vertexColorLocation = glGetUniformLocation(program, "colorUniform");
    glUniform3f(vertexColorLocation, redValue, greenValue, blueValue);
}