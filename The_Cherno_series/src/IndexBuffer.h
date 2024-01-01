#pragma once

#include <memory_resource>
class IndexBufferClass
{
    private:
        unsigned int m_RendererID;
        unsigned int m_Count;
    public:
        IndexBufferClass(const void* data, unsigned int count);
        ~IndexBufferClass();

        void Bind() const;
        void UnBind() const;
        
        inline unsigned int GetCount() const {return m_Count;};
};
