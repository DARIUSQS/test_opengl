#pragma once

#include <string>
class Texture
{
private:
    unsigned int m_RendererID;
public:
    Texture();
    ~Texture();
    void GenerateTexture(const std::string& path, unsigned int target);  
    void Bind(unsigned int target, unsigned int TextureUnit) const;
    void unBind(unsigned int target, unsigned int TextureUnit) const;
};
