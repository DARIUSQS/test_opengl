#shader vertex
#version 330 core

layout (location = 0) in vec4 aPos;
void main()
{
    gl_Position = aPos;
}

#shader fragment
#version 330 core

layout(location = 0) out vec4 FragColor;

void main()
{
   FragColor = vec4(.64f, 0.43f, 0.12f, 1.0f);
}


