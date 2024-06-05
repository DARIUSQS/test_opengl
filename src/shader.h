#pragma once
#include <iostream>

class Shader
{
    private:
        void Read(const std::string& path);
        int CompileShader(const std::string& shaderSource, unsigned int type);
        void CompileProgram();
        unsigned int ProgramID;
    public:
        std::string VertexShader, FragmentShader;
        Shader(const std::string& path);
        void SetInt(const std::string& str, int val);
        void Bind();
        void unBind();
};
