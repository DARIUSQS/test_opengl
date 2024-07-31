#include <glad.h>

#include <GLFW/glfw3.h>
#include <GL/gl.h>
#include <cmath>
#include <iostream>
#include <glm/gtc/type_ptr.hpp>

#include "VertexBufferLayout.h"
#include "glm/detail/qualifier.hpp"
#include "glm/ext/quaternion_transform.hpp"
#include "glm/fwd.hpp"
#include "glm/trigonometric.hpp"
#include "shader.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "Texture.h"
#include "material.h"

#include <imgui/imgui.h>
#include <imgui/backends/imgui_impl_glfw.h>
#include <imgui/backends/imgui_impl_opengl3.h>

static void PrintMat(glm::mat4 trans)
{
    std::cout << trans[0].x << ' ' << trans[1].x << ' ' << trans[2].x << ' ' << trans[3].x << '\n';
    std::cout << trans[0].y << ' ' << trans[1].y << ' ' << trans[2].y << ' ' <<trans[3].y << '\n';
    std::cout << trans[0].z << ' ' << trans[1].z << ' ' << trans[2].z << ' ' <<trans[3].z << '\n';
    std::cout << trans[0].w << ' ' << trans[1].w << ' ' << trans[2].w <<' ' <<trans[3].w << '\n';
}

static void PrintVec(glm::vec3 vec)
{
    std::cout << vec.x << ' ' << vec.y << ' ' << vec.z << '\n';
}

static glm::vec3 CameraPos(0.0f, 0.0f, 3.0f);
static glm::vec3 CameraFront(0.0f, 0.0f, -1.0f);
static glm::vec3 CameraUp(0.0f, 1.0f, 0.0f);

bool cursor_disabled = 1;

double lastx = 480, lasty = 270;
double pitch = 0.0f, yaw = -90.0f;

double lastFrameTime = 0, deltaTime = 0;

static void keyboardcallback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    if(key == GLFW_KEY_P && action == GLFW_PRESS)
    {
        if(cursor_disabled) glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
        else glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
        cursor_disabled =! cursor_disabled;
    }
}

static void checkForInput(GLFWwindow *window)
{
    const float CameraSpeed = 2 * deltaTime;
    if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
    {
        CameraPos += CameraSpeed * CameraFront;
    }
    if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
    {
        CameraPos -= CameraSpeed * CameraFront;
    }
    if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
    {
        CameraPos += glm::normalize(glm::cross(CameraFront, CameraUp)) * CameraSpeed;
    }
    if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
    {
        CameraPos -= glm::normalize(glm::cross(CameraFront, CameraUp)) * CameraSpeed;
    }
}

static void cursor_position_callback(GLFWwindow *window, double xpos, double ypos)
{
    double xoffset = xpos - lastx;
    double yoffset = ypos - lasty;

    lastx = xpos;
    lasty = ypos;

    float sensitivity = 0.06f;
    xoffset *= sensitivity;
    yoffset *= sensitivity;

    if(cursor_disabled)
    {
        pitch -= yoffset;
        yaw += xoffset;
    }
    
    if(pitch > 89.0f) pitch = 89.0f;
    if(pitch < -89.0f) pitch = -89.0f;

    glm::vec3 angleVec;
    angleVec.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    angleVec.y = sin(glm::radians(pitch));
    angleVec.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));

    CameraFront = glm::normalize(angleVec);
}

int main(void)
{
    GLFWwindow* window;

    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(1280, 720, "Hello World", NULL, NULL);

    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetCursorPosCallback(window, cursor_position_callback);
    glfwSetKeyCallback(window, keyboardcallback);
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
    
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glEnable(GL_DEPTH_TEST);

    float indices[] = 
    {
        -0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f,
        0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f,
        0.5f, 0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 1.0f, 1.0f,
        0.5f, 0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 1.0f, 1.0f,
        -0.5f, 0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f,
        -0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
        0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f,
        0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f,
        0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f,
        -0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f,
        -0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
        -0.5f, 0.5f, 0.5f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
        -0.5f, 0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 1.0f, 1.0f,
        -0.5f, -0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
        -0.5f, -0.5f, 0.5f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
        -0.5f, 0.5f, 0.5f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
        0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
        0.5f, 0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f,
        0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
        0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
        0.5f, -0.5f, 0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
        0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
        -0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f,
        0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f, 1.0f, 1.0f,
        0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f,
        0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f,
        -0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f,
        -0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
        0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f,
        0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
        0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
        -0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f,
        -0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f
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
    layout.Push<float>(3);
    layout.Push<float>(2);
    vao.AddBuffer(vb, layout);

    Shader sh("resources/shaders/basic.shader");
    sh.Bind();

    Texture texture;
    texture.GenerateTexture("Textures/crate.jpg", GL_TEXTURE_2D);
    Texture specularTexture;
    specularTexture.GenerateTexture("Textures/crateSpecularMap.jpg", GL_TEXTURE_2D);

    sh.SetInt("material.diffuse", 0);
    texture.Bind(GL_TEXTURE_2D, GL_TEXTURE0);

    sh.SetInt("material.specular", 1);
    specularTexture.Bind(GL_TEXTURE_2D, GL_TEXTURE1);
    
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable; 
    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 100");

    bool show_demo_window = false;
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
    Light light;
    light.color = glm::vec3(1.0f);
    Material material;
    material.shininess = 16.0f;
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        checkForInput(window);

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        if(show_demo_window) ImGui::ShowDemoWindow(&show_demo_window);

        glDrawArrays(GL_TRIANGLES, 0, 36);

        {
            static float f = 0.0f;
            static int counter = 0;

            ImGui::Begin("Hello, world!");

            ImGui::Text("This is some useful text.");
            ImGui::Checkbox("Demo Window", &show_demo_window);

            ImGui::SliderFloat("float", &material.shininess, 1.0f, 512.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
            ImGui::ColorEdit3("clear color", (float*)&light.color); // Edit 3 floats representing a color

            ImGui::SameLine();
            ImGui::Text("counter = %d", counter);

            ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / io.Framerate, io.Framerate);
            ImGui::End();
        }

        deltaTime = glfwGetTime() - lastFrameTime;
        lastFrameTime = glfwGetTime();

        glm::mat4 model = glm::mat4(1.0f);
        model = glm::rotate(model, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
        glm::mat4 view = glm::mat4(1.0f);
        view = glm::translate(view, -CameraPos);
        view = glm::lookAt(CameraPos, CameraPos + CameraFront, CameraUp);
        glm::mat4 projection;
        projection = glm::perspective(glm::radians(45.0f), 960.0f / 540.0f, 0.1f, 100.0f);

        sh.SetMat4("model", 1, GL_FALSE, glm::value_ptr(model));
        sh.SetMat4("view", 1, GL_FALSE, glm::value_ptr(view));
        sh.SetMat4("projection", 1, GL_FALSE, glm::value_ptr(projection));

        sh.SetVec3("CameraPos", CameraPos.x, CameraPos.y, CameraPos.z);       

        sh.SetFloat("material.shininess", material.shininess);

        light.diffuse = light.color * glm::vec3(0.5f);
        light.ambient = light.color * glm::vec3(0.2f);

        sh.SetVec3("light.ambient", light.ambient.x, light.ambient.y,light.ambient.z);
        sh.SetVec3("light.diffuse", light.diffuse.x, light.diffuse.y, light.diffuse.z);
        sh.SetVec3("light.specular", 1.0f, 1.0f, 1.0f);
        sh.SetVec3("light.position", 2.5f, 1.2f, 0.0f);


        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        glfwSwapBuffers(window);

        glfwPollEvents();
    }


    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwTerminate();
    return 0;
}
