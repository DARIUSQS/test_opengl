#pragma once
#include <string>
#include <glm/glm.hpp>

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
        void SetFloat(const std::string& str, float val);
        void SetMat4(const std::string& str, unsigned int number, unsigned int transpose, float* data);
        void SetVec3(const std::string& str, float v1, float v2, float v3);
        void Bind();
        void unBind();
};
