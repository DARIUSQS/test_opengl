#pragma once

class VertexBuffer
{
    private:
        unsigned int m_RendererID;
    public:
        VertexBuffer(const void* data, unsigned int size, unsigned int mode);
        ~VertexBuffer();
        void Bind();
        void unBind();
};
