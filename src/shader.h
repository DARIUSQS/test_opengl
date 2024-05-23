#pragma once
#include <iostream>

class Shader
{
    private:
        void Read(const std::string& path);
        int CompileShader(const std::string& shaderSource, unsigned int type);
        void CompileProgram();
    public:
        std::string VertexShader, FragmentShader;
        unsigned int ProgramID;
        Shader(const std::string& path);
        void Bind();
        void unBind();
};
