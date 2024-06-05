#include "VertexBufferLayout.h"
template<>
void VertexBufferLayout::Push<float>(unsigned int count)
{
    m_Elements.push_back({count, GL_FLOAT, 0});
    m_Stride += count * VertexBufferLayoutElement::GetSize(GL_FLOAT);
}

template<>
void VertexBufferLayout::Push<unsigned int>(unsigned int count)
{
    m_Elements.push_back({count, GL_UNSIGNED_INT, 0});
    m_Stride += count * VertexBufferLayoutElement::GetSize(GL_UNSIGNED_INT);
}

template<>
void VertexBufferLayout::Push<unsigned char>(unsigned int count)
{
    m_Elements.push_back({count, GL_UNSIGNED_BYTE, 1});
    m_Stride += count * VertexBufferLayoutElement::GetSize(GL_UNSIGNED_BYTE);
}
