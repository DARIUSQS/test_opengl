#pragma once
#include "../include/glad.h"
#include <vector>

struct VertexBufferLayoutElement
{
    unsigned int count;
    unsigned int type;
    bool normalized;

    static unsigned int GetSize(unsigned int type)
    {
        switch (type) 
        {
            case GL_FLOAT: return 4;
            case GL_UNSIGNED_INT: return 4;
            case GL_UNSIGNED_BYTE: return 1;
        }
        return 0;
    }
};

class VertexBufferLayout
{
    private:
        std::vector<VertexBufferLayoutElement> m_Elements;
        unsigned int m_Stride = 0;
    public:
        template<typename T> void Push(unsigned int count);

        
        inline const std::vector<VertexBufferLayoutElement>& GetElements() const {return m_Elements;}
        inline unsigned int GetStride() const {return m_Stride;}
};

template<>void VertexBufferLayout::Push<float>(unsigned int count);
template<>void VertexBufferLayout::Push<unsigned int>(unsigned int count);
template<> void VertexBufferLayout::Push<unsigned char>(unsigned int count);
