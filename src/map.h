#pragma once
#include <string>
#include "../include/glad.h"
#include <vector>
#include "../include/glm/glm.hpp"
#include "../include/glm/gtc/matrix_transform.hpp"
#include "../include/glm/gtc/type_ptr.hpp"
#include "shader.h"

class MapBuilder
{
    public:
        MapBuilder(const std::string& path);
        void Build(glm::mat4& mat, Shader& sh);
    private:
        std::vector<std::string> map;
};
