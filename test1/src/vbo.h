#pragma once
#include <iostream>

class VBO
{
    private:
        unsigned int m_RendererID;
    public:
        VBO(const void* data, unsigned int size);
        ~VBO();

        void Bind();
        void unBind();
};
