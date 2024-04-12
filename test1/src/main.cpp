#define STB_IMAGE_IMPLEMENTATION
#include "../include/glad.c" 
#include <GLFW/glfw3.h>

#include <GL/gl.h>

#include <iostream>
#include <cmath>
#include <fstream>
#include <sstream>
#include <cmath>

#include "stb_image.h"

/// Initializing


void key_callback(GLFWwindow *window, float& mix);

struct ShaderProgramSource
{
    std::string VertexSource;
    std::string FragmentSource;
};

ShaderProgramSource ParseShaders(const std::string& filepath)
{
    std::ifstream in(filepath);
    std::string line;
    std::stringstream ss[2];
    
    int type = -1;

    while(getline(in, line))
    {
        if(line.find("#shader") != std::string::npos)
        {
            if(line.find("vertex") != std::string::npos) type = 0;
            else if(line.find("fragment") != std::string::npos) type = 1;
        }
        else 
        {
            ss[type] << line << '\n';
        }
    }
    return {ss[0].str(), ss[1].str()};
}

static unsigned int CompileShaders(const std::string& shaderSource, unsigned int type)
{
    const char* src = shaderSource.c_str();
    unsigned int Shader;
    Shader = glCreateShader(type);
    glShaderSource(Shader, 1, &src, 0);
    glCompileShader (Shader);

    int success;
    char infolog[512];
    glGetShaderiv(Shader, GL_COMPILE_STATUS, &success);
    if(!success) 
    {
        glGetShaderInfoLog(Shader, 512, 0, infolog);
        std::cout << "ERROR SHADER VERTEX :: " << infolog << '\n';
        glDeleteShader(Shader);
        return 0;
    }
    return Shader;
}

static unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader)
{
    unsigned int program = glCreateProgram();
    unsigned int vs = CompileShaders(vertexShader, GL_VERTEX_SHADER);
    unsigned int fs = CompileShaders(fragmentShader, GL_FRAGMENT_SHADER);

    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);

    glDeleteShader(vs);
    glDeleteShader(fs);

    return program;
}

unsigned int GenerateTexture(const std::string& path)
{
    int width, height, nrChannels;
    const char* filepath = path.c_str();
    unsigned char *data = stbi_load(filepath, &width, &height, &nrChannels, 0);

    unsigned int texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);

    stbi_image_free(data);
    return texture;
}

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    stbi_set_flip_vertically_on_load(1);



    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    int version = gladLoadGL();
    if (version == 0)
    {
        std::cout << "Failed to initialize OpenGL context" << std::endl;
        return -1;
    }
 
    /// Texture settings

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);


    float positions[] = 
    {   // position      // colors          //texture coords
        0.5f, 0.5f,      1.0f, 0.0f, 0.0f,   1.0f, 1.0f,
        0.5f, -0.5f,    0.0f, 1.0f, 0.5f,    1.0f, 0.0f,
        -0.5f, -0.5f,     0.0f, 0.5f, 1.0f,  0.0f, 0.0f,
        -0.5f, 0.5f,     1.0f, 1.0f, 0.0f,   0.0f, 1.0f
    };

    unsigned int indices[] = 
    {
        0, 1, 2,
        2, 3, 0
    };
    
    glPolygonMode( GL_FRONT_AND_BACK, GL_FILL);

    unsigned int VBO;
    glGenBuffers(1, &VBO);


    unsigned int VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(GL_ARRAY_BUFFER, sizeof(positions), positions, GL_STATIC_DRAW);

    unsigned int IBO;
    glGenBuffers(1, &IBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (void*)(2 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (void*)(5 * sizeof(float)));
    glEnableVertexAttribArray(2);

 
    ShaderProgramSource ShaderSources = ParseShaders("basic.shader");

    unsigned int shaderProgram = CreateShader(ShaderSources.VertexSource, ShaderSources.FragmentSource);


    unsigned int texture1 = GenerateTexture("container.jpg");
    unsigned int texture2 = GenerateTexture("happyface.jpg");

    glUseProgram(shaderProgram);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture1);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, texture2);

    glUniform1i(glGetUniformLocation(shaderProgram, "texture1"), 0);
    glUniform1i(glGetUniformLocation(shaderProgram, "texture2"), 1);


    float mixprecentage = 0.5f;
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        key_callback(window, mixprecentage);

        glUniform1f(glGetUniformLocation(shaderProgram, "mixfloat"), mixprecentage);

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

void key_callback(GLFWwindow *window, float& mix)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) glfwSetWindowShouldClose(window, 1);
    if(glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) mix = std::min(1.0f, mix + 0.01f);
    if(glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) mix = std::max(0.0f, mix - 0.01f);
}
