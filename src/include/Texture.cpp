#include "Texture.h"
#include <glad.h>
#define STB_IMAGE_IMPLEMENTATION
#include "../include/stb_image.h"

Texture::Texture()
{
    glGenTextures(1, &m_RendererID);
}

Texture::~Texture()
{
    glDeleteTextures(1, &m_RendererID);
}

void Texture::GenerateTexture(const std::string& path, unsigned int target)
{
    stbi_set_flip_vertically_on_load(1);
    int width, height, nrChannels;
    unsigned char* data = stbi_load(path.c_str(), &width, &height, &nrChannels, 0);
    Bind(target, GL_TEXTURE0);
    glTexParameteri(target, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(target, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(target, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(target, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(target);
    stbi_image_free(data);
}

void Texture::Bind(unsigned int target, unsigned int TextureUnit) const
{
    glActiveTexture(TextureUnit);
    glBindTexture(target, m_RendererID);
}

void Texture::unBind(unsigned int target, unsigned int TextureUnit) const
{
    glActiveTexture(TextureUnit);
    glBindTexture(target, 0);
}
