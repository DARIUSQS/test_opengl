#include "VertexBuffer.h"
#include "Renderer.h"

VertexBufferClass::VertexBufferClass(const void* data, unsigned int size)
{
    GLCall(glGenBuffers(1, &m_RendererID));
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_RendererID));
    GLCall(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
}

VertexBufferClass::~VertexBufferClass()
{
    GLCall(glDeleteBuffers(1, &m_RendererID))
}

void VertexBufferClass::Bind() const
{
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_RendererID));
}

void VertexBufferClass::UnBind() const
{
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
}

