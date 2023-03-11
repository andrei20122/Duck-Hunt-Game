#pragma once

#include <string>

#include "core/gpu/mesh.h"
#include "utils/glm_utils.h"





namespace object2D
{

    // Create square with given bottom left corner, length and color
    Mesh* CreateSquare(const std::string& name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill = false);
    Mesh* CreateTriangle(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color);
    Mesh* CreateCircle(std::string name, glm::vec3 center, float length, glm::vec3 color);
    Mesh* CreateTinta(const std::string& name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill = false);
    Mesh* CreateBaraScor(const std::string& name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill = false);
    Mesh* CreateHeart(std::string name, glm::vec3 center, float width, glm::vec3 color);
    Mesh* CreateConturBaraScor(const std::string& name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill = false);
    Mesh* GuraSup(const std::string& name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill = false);
    Mesh* CreateSmileyMouth(std::string name, glm::vec3 center, float length, glm::vec3 color);
}
