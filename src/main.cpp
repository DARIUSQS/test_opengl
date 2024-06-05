#include "../include/glad.c"
#include <GLFW/glfw3.h>
#include <GL/gl.h>

#include <iostream>

#include "VertexBufferLayout.h"
#include "shader.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "Texture.h"

int main(void)
{
    GLFWwindow* window;

    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
 
    int version = gladLoadGL();
    if (version == 0)
    {
        std::cout << "Failed to initialize OpenGL context" << std::endl;
        return -1;
    }

    float indices[] = 
    {

        //positions     //colors            //TexCoords
        -0.5f, -0.5f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,
        -0.5f, 0.5f,    0.0f, 1.0f, 0.0f,   0.0f, 1.0f,
        0.5f, 0.5f,     1.0f, 0.0f, 0.0f,   1.0f, 1.0f,
        0.5f, -0.5f,    0.5f, 0.5f, 0.5f,   1.0f, 0.0f
    };
    
    unsigned int order[] = 
    {
        0, 1, 2, 
        0, 2, 3
    };

    VertexArray vao;
    vao.Bind();
    
    VertexBuffer vb(indices, sizeof(indices), GL_STATIC_DRAW);
    vb.Bind();
    
    VertexBufferLayout layout;
    layout.Push<float>(2);
    layout.Push<float>(3);
    layout.Push<float>(2);
    vao.AddBuffer(vb, layout);

    IndexBuffer ib(order, 6, GL_STATIC_DRAW);
    ib.Bind();

    Shader sh("basic.shader");
    sh.Bind();

    Texture texture1, texture2;
    texture1.GenerateTexture("Textures/wood.jpg", GL_TEXTURE_2D);
    texture2.GenerateTexture("Textures/smile.jpg", GL_TEXTURE_2D);

    texture2.Bind(GL_TEXTURE_2D, GL_TEXTURE0);
    texture1.Bind(GL_TEXTURE_2D, GL_TEXTURE1);
    sh.SetInt("Texture1", 0);
    sh.SetInt("Texture2", 1);

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
