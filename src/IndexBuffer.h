#pragma once

class IndexBuffer
{
    private:
        unsigned int m_RendererID;
    public:
        IndexBuffer(const unsigned int* data, unsigned int count, unsigned int mode);
        ~IndexBuffer();
        void Bind();
        void unBind();
};
