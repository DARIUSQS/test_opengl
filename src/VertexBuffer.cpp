#include "VertexBuffer.h"
#include "../include/glad.h"

VertexBuffer::VertexBuffer(const void* data, unsigned int size, unsigned int mode)
{
    glGenBuffers(1, &m_RendererID);
    glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
    glBufferData(GL_ARRAY_BUFFER, size, data, mode);
}

VertexBuffer::~VertexBuffer()
{
    glDeleteBuffers(1, &m_RendererID);
}
void VertexBuffer::Bind()
{
    glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
}
void VertexBuffer::unBind()
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
