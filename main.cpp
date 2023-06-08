#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "functions.hpp" 

float verticesRgbTriangle[] = {
    // positions         // colors
     0.5f, 0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // bottom right
    -0.5f, 0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // bottom left
     0.0f,  -0.5f, 0.0f,  0.0f, 0.0f, 1.0f    // top 
};  

int main(void)
{ 
    GLFWwindow* window;

    if (!glfwInit()) return -1;

    window = glfwCreateWindow(640, 480, "Shaders", NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK) std::cout << "Can't load GLEW\n";
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    unsigned int VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);  

    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(GL_ARRAY_BUFFER, sizeof(verticesRgbTriangle), verticesRgbTriangle, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    Shader myShader("shaders/3.3.shader.vshad", "shaders/3.3.shader.fshad");

    while (!glfwWindowShouldClose(window))
    {
        glClearColor (0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        myShader.UseProgram();

        DynamicFragmentShader(myShader.ID);
        
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

}