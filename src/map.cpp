#include "map.h"
#include <fstream>
#include <string>
#include <GL/gl.h>
#include "shader.h"

MapBuilder::MapBuilder(const std::string& path)
{
    std::string line;
    std::fstream in(path);
    while(std::getline(in, line))
    {
        map.push_back(line);
    }
    in.close();
}

void MapBuilder::Build(glm::mat4& model, Shader& sh)
{
    glm::mat4 original = model;
    unsigned int lineNumber = 0;
    for(std::string line : map)
    {
        lineNumber++;
        for(int i = 0; i < line.size(); i++)
        {
            for(int j = 1; j <= int(line[i] - '0'); j++)
            {
                model = original;
                model = glm::translate(model, glm::vec3(1.0f * i, 1.0f * (j - 1), 1.0f * lineNumber)); 
                sh.SetMat4("model", 1, 0, glm::value_ptr(model));
                glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
            }
        }
    }
}
