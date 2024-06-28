#include "../include/glad.c"
#include <GLFW/glfw3.h>
#include <GL/gl.h>

#include <iostream>

/* #include "../include/glm/glm.hpp" */
/* #include "../include/glm/gtc/matrix_transform.hpp" */
#include "../include/glm/gtc/type_ptr.hpp"

#include "VertexBufferLayout.h"
#include "shader.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "Texture.h"

static void PrintMat(glm::mat4 trans)
{
    std::cout << trans[0].x << ' ' << trans[1].x << ' ' << trans[2].x << ' ' << trans[3].x << '\n';
    std::cout << trans[0].y << ' ' << trans[1].y << ' ' << trans[2].y << ' ' <<trans[3].y << '\n';
    std::cout << trans[0].z << ' ' << trans[1].z << ' ' << trans[2].z << ' ' <<trans[3].z << '\n';
    std::cout << trans[0].w << ' ' << trans[1].w << ' ' << trans[2].w <<' ' <<trans[3].w << '\n';
}

static void PrintVec(glm::vec4 vec)
{
    std::cout << vec.x << ' ' << vec.y << ' ' << vec.z << ' ' << vec.w << '\n';
}

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

    glEnable(GL_DEPTH_TEST);

    float indices[] = 
    {
        //positions    //TexCoords
         /*1 1 */ -0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 
         /*2 2 center */ -0.5f, -0.5f, -0.5f, 0.0f, 0.0f,
         /*3 2 down right*/ -0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 
         /*4 2 up left*/ -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
         /*5 3 right up*/ 0.5f, -0.5f, -0.5f, 1.0f, 1.0f,
         /*6 3 right down*/ 0.5f, -0.5f, -0.5f, 1.0f, 0.0f,
         /*7 4 right down*/ 0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
         /*8 4 center*/ 0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
         /*9 5 left up*/ -0.5f, 0.5f, 0.5f, 0.0f, 1.0f,
         /*10 5 center*/ -0.5f, 0.5f, 0.5f, 0.0f, 0.0f,
         /*11 6 right down*/ 0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
         /*12 6 right up*/ 0.5f, 0.5f, 0.5f, 1.0f, 1.0f,
         /*13 6 left up*/ 0.5f, 0.5f, 0.5f, 0.0f, 1.0f,
         /*14 7 right up*/ 0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
         /*15 8 left up*/ -0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 
         /*16 8 right up*/ -0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
        /* -0.5f, -0.5f,  0.0f, 0.0f, */
        /* -0.5f, 0.5f,   0.0f, 1.0f, */
        /* 0.5f, 0.5f,    1.0f, 1.0f, */
        /* 0.5f, -0.5f,   1.0f, 0.0f */
    };
    
    unsigned int order[] = 
    {
        0, 8, 6,
        8, 11, 6,
        0, 3, 6,
        3, 4, 6,
        0, 8, 2, 
        8, 15, 2,
        1, 14, 5, 
        14, 5, 13,
        7, 12, 5, 
        12, 5, 13,
        9, 14, 10,
        14, 10, 13
    };

    VertexArray vao;
    vao.Bind();
    
    VertexBuffer vb(indices, sizeof(indices), GL_STATIC_DRAW);
    vb.Bind();
    
    VertexBufferLayout layout;
    layout.Push<float>(3);
    layout.Push<float>(2);
    vao.AddBuffer(vb, layout);

    IndexBuffer ib(order, 36, GL_STATIC_DRAW);
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

    glm::mat4 model = glm::mat4(1.0f);
    model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    glm::mat4 view = glm::mat4(1.0f);
    view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));

    glm::mat4 projection;
    projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
    
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


        model = glm::rotate(model, glm::radians(.1f), glm::vec3(1.0f, 0.0f, 0.0f));
        model = glm::rotate(model, glm::radians(.1f), glm::vec3(0.0f, 1.0f, 0.0f));
        model = glm::rotate(model, glm::radians(.1f), glm::vec3(0.0f, 0.0f, 1.0f));
        sh.SetMat4("model", 1, GL_FALSE, glm::value_ptr(model));
        sh.SetMat4("view", 1, GL_FALSE, glm::value_ptr(view));
        sh.SetMat4("projection", 1, GL_FALSE, glm::value_ptr(projection));

        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
