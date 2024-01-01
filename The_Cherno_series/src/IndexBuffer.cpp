#include "IndexBuffer.h"
#include "Renderer.h"
#include <iterator>

IndexBufferClass::IndexBufferClass(const void* data, unsigned int count)
{
    GLCall(glGenBuffers(1, &m_RendererID));
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID));
    GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW));
}

IndexBufferClass::~IndexBufferClass()
{
    GLCall(glDeleteBuffers(1, &m_RendererID))
}

void IndexBufferClass::Bind() const
{
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID));
}

void IndexBufferClass::UnBind() const 
{
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}

