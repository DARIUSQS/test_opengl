#include "Renderer.h"
#include <iostream>

void GLClearError()
{
    while(glGetError());
}

bool GLLogError(const char* function, const char* file, int line)
{
    if(GLenum error = glGetError())
    {
        std::cout << "[Opengl Eroror](" << error << "): " << function << ' ' << file << ' ' << line << '\n'; 
        return 0;
    }
    return 1;
}
