#include "VertexArray.h"
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"

VertexArray::VertexArray()
{
    glGenVertexArrays(1, &m_RendererID);
}

VertexArray::~VertexArray()
{
    glDeleteVertexArrays(1, &m_RendererID);
}

void VertexArray::AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout)
{
    Bind();
    vb.Bind();
    std::vector<VertexBufferLayoutElement> elements = layout.GetElements();
    unsigned long offset = 0;
    for(int i = 0; i < elements.size(); i++)
    {
        glEnableVertexAttribArray(i);
        glVertexAttribPointer(i, elements[i].count, elements[i].type, elements[i].normalized, layout.GetStride(), (void*) offset);
        offset += elements[i].count * VertexBufferLayoutElement::GetSize(elements[i].type);
    }
}

void VertexArray::Bind() const
{
    glBindVertexArray(m_RendererID);
}

void VertexArray::unBind() const
{
    glBindVertexArray(0);
}
