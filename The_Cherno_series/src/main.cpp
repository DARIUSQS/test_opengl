#include "../include/glad.c" 
#include "Renderer.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexBufferLayout.h"
#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <cstring>
#include <iostream>
#include <string> 
#include <sstream>
#include <fstream>
#include <strings.h>

static const unsigned int WIDTH = 1200;
static const unsigned int HEIGHT = 1200;

struct Shaders
{
    std::string Vertex, Fragment;
};

static float r = 0.5f;
static float g = 0.5;
static float b = 0.5;
static float increment = 0.10f;

static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
    r = xpos * 1.0f / WIDTH;
    g = ypos * 1.0f / HEIGHT;
}

static void mytarrowcallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if(key == GLFW_KEY_LEFT && action == GLFW_PRESS && r < 1.0f) r += increment;
    if(key == GLFW_KEY_RIGHT && action == GLFW_PRESS && r > 0.0f) r -= increment;
}

static unsigned int CompileShader(unsigned int type, const std::string& source)
{
    unsigned int id = glCreateShader(type);
    const char* src = source.c_str();
    GLCall(glShaderSource(id, 1, &src, nullptr));
    GLCall(glCompileShader(id));

    int result;
    GLCall(glGetShaderiv(id, GL_COMPILE_STATUS, &result));
    if(!result)
    {
        int len;
        GLCall(glGetShaderiv(id, GL_INFO_LOG_LENGTH, &len));
        char message[len];
        GLCall(glGetShaderInfoLog(id, len, &len, message));

        std::cout << "Failed to compile shader: " << (type == GL_VERTEX_SHADER ? "vertex\n" : "fragment\n"); 
        std::cout << message << '\n';
        GLCall(glDeleteShader(id));
        return 0;
    }

    return id;
}

static unsigned int CreateShader(const std::string& vertex, const std::string& fragment)
{
    unsigned int program = glCreateProgram();
    unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertex);
    unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragment);

    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);
    glValidateProgram(program);

    glDeleteShader(vs);
    glDeleteShader(fs);
    
    return program;
}


static Shaders ParseShader(const std::string& path)
{
    std::ifstream fin(path);

    enum class ShaderType
    {
        NONE = -1, VERTEX = 0, FRAGMENT = 1
    };
    
    std::stringstream ss[2];
    char line[100];
    ShaderType type = ShaderType::NONE;
    while(fin.getline(line, 100))
    {
        if(strstr(line, "#shader"))
        {
            if(strstr(line, "vertex")) type = ShaderType::VERTEX;
            else if(strstr(line, "fragment"))  type = ShaderType::FRAGMENT;
        }
        else 
        {
            ss[int(type)] << line << '\n';
        }
    }
    return {ss[0].str(), ss[1].str()};
}

int main(void)
{
    GLFWwindow* window;

    if (!glfwInit())
        return -1;


    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


    window = glfwCreateWindow(WIDTH, HEIGHT, "Hello World", NULL, NULL);

    glfwCreateWindow(int, int height, const char *title, GLFWmonitor *monitor, GLFWwindow *share)
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    int version = gladLoadGL();
    if (version == 0)
    {
        std::cout << "Failed to initialize OpenGL context" << std::endl;
        return -1;
    }


    std::cout << glGetString(GL_VERSION) << '\n';

    float positions[] = 
    {
       -0.5f, -0.5f,  // 0
        0.5f, -0.5f, // 1
        0.5f,  0.5f,   // 2
       -0.5f,  0.5f    // 3
    };
 
    unsigned int indices[] = 
    {
        0, 1, 2,
        2, 3, 0
    };   

    VertexArray va;
    VertexBufferClass vertexbuffer(positions, 4 * 2 * sizeof(float));
    
    VertexBufferLayout layout;
    layout.Push(GL_FLOAT, 2);
    va.AddBuffer(vertexbuffer, layout);

    GLCall(glEnableVertexAttribArray(0));
    GLCall(glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0));

    IndexBufferClass indexbuffer(indices, 6);

    Shaders shaders = ParseShader("res/shaders/Basic.shader");
    unsigned int shader = CreateShader(shaders.Vertex, shaders.Fragment);
    GLCall(glUseProgram(shader));

    GLCall(glBindVertexArray(0));
    GLCall(glUseProgram(0))
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));   
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));   

    glfwSetKeyCallback(window, mytarrowcallback);
    glfwSetCursorPosCallback(window, cursor_position_callback);

    while (!glfwWindowShouldClose(window))
    {
        GLCall(glClearColor(g, b, r, 1.0f));
        GLCall(glClear(GL_COLOR_BUFFER_BIT));

        GLCall(glUseProgram(shader))
        va.Bind();
        indexbuffer.Bind();

        std::cout << r << ' ' << g << ' ' << b << '\n';

        int location = glGetUniformLocation(shader, "u_Color");
        ASSERT(location != -1);
        glUniform4f(location, r, g , b, 1.0f);

        GLCall(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT , nullptr));

        glfwSwapBuffers(window);

        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}
