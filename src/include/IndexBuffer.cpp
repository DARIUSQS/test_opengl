#include "IndexBuffer.h"
#include <glad.h>

IndexBuffer::IndexBuffer(const unsigned int* data, unsigned int count, unsigned int mode)
{
    glGenBuffers(1, &m_RendererID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, mode);
}

IndexBuffer::~IndexBuffer()
{
    glDeleteBuffers(1, &m_RendererID);
}
void IndexBuffer::Bind()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
}
void IndexBuffer::unBind()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
