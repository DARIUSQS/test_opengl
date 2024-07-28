#include "shader.h" 
#include <glad.h>
#include <sstream>
#include <string>
#include <fstream>
#include <iostream>

void Shader::Read(const std::string& path)
{
    std::string line;
    std::fstream fin(path);
    int type = -1;
    
    std::stringstream ss[2];

    while(std::getline(fin, line))
    {
        if(line.find("#shader") != std::string::npos)
        {
            if(line.find("vertex") != std::string::npos) type = 0;
            else if(line.find("fragment") != std::string::npos) type = 1;
        }
        else 
        {
            ss[type] << line <<'\n';
        }
        this->VertexShader = ss[0].str();
        this->FragmentShader= ss[1].str();
    }
}

int Shader::CompileShader(const std::string& shaderSource, unsigned int type)
{
    const char* src = shaderSource.c_str();
    unsigned int Shader;
    Shader = glCreateShader(type);
    glShaderSource(Shader, 1, &src, 0);
    glCompileShader(Shader);

    int success;
    char infoLog[512];
    glGetShaderiv(Shader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(Shader, 512, 0, infoLog);
        std::cout << "ERROR Shader" << ((type == GL_VERTEX_SHADER)? "VERTEX" : "FRAGMENT") <<  ' ' << infoLog << '\n';
        glDeleteShader(Shader);
        return 0;
    }
    return Shader;
}

void Shader::CompileProgram()
{
    unsigned int program = glCreateProgram();
    unsigned int vs = CompileShader(VertexShader, GL_VERTEX_SHADER);
    unsigned int fs = CompileShader(FragmentShader, GL_FRAGMENT_SHADER);

    glAttachShader(program, vs);
    glAttachShader(program, fs);

    glLinkProgram(program);

    glDeleteShader(vs);
    glDeleteShader(fs);

    ProgramID = program;
}

Shader::Shader(const std::string& path)
{
    Read(path);
    CompileProgram();
}


void Shader::SetInt(const std::string& str,int val)
{
    glUniform1i(glGetUniformLocation(ProgramID, str.c_str()), val);
}

void Shader::SetMat4(const std::string& str, unsigned int number, unsigned int transpose, float* data)
{
    glUniformMatrix4fv(glGetUniformLocation(ProgramID, str.c_str()), number, transpose, data);
}

void Shader::SetVec3(const std::string& str, float v1, float v2, float v3)
{
    glUniform3f(glGetUniformLocation(ProgramID, str.c_str()), v1, v2, v3);
}

void Shader::Bind()
{
    glUseProgram(ProgramID);
}

void Shader::unBind()
{
    glUseProgram(0);
}
