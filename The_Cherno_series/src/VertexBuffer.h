#pragma once

class VertexBufferClass
{
    private:
        unsigned int m_RendererID;
    public:
        VertexBufferClass(const void* data, unsigned int size);
        ~VertexBufferClass();

        void Bind() const;
        void UnBind() const;
};
