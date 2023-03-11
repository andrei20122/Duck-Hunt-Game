#include "object2D.h"


#include "core/engine.h"
#include "utils/gl_utils.h"



Mesh* object2D::CreateSquare(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    float length,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;


    std::vector<VertexFormat> vertices =
    {
        
        VertexFormat(glm::vec3(corner.x,corner.y,1), color),
        VertexFormat(corner + glm::vec3(length*1920, 0, 1), color),
        VertexFormat(corner + glm::vec3(length*1920, length, 1), color),
        VertexFormat(corner + glm::vec3(0, length, 1), color)
    };

    Mesh* square = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2, 3 };

    if (!fill) {
        square->SetDrawMode(GL_LINE_LOOP);
    }
    else {
        // Draw 2 triangles. Add the remaining 2 indices
        indices.push_back(0);
        indices.push_back(2);
    }

    square->InitFromData(vertices, indices);
    return square;
}

Mesh* object2D::CreateTriangle(std::string name, glm::vec3 leftCorner, float length, glm::vec3 color) {
    glm::vec3 corner = leftCorner;
    
    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner , color), // 2
        VertexFormat(corner + glm::vec3(length*2, length/2, 0), color), // 3
        VertexFormat(corner + glm::vec3(0  , length, 0), color), // 4

        //VertexFormat(corner + glm::vec3(length * 1.5 , length / 2 , 0), color), // 2
        //VertexFormat(corner + glm::vec3(length / 2, -length / 2, 0), color), // 3
        //VertexFormat(corner + glm::vec3(-length / 2 , -length / 2 , 0), color), // 4
    
    };


    std::vector<unsigned int> indices;
   
      indices.push_back(0);
      indices.push_back(1);
      indices.push_back(2);
    

    Mesh* arrowHead = new Mesh(name);
    arrowHead->SetDrawMode(GL_TRIANGLE_FAN);
    //arrowHead->SetDrawMode(GL_LINE_LOOP);
   
    arrowHead->InitFromData(vertices, indices);

    
    return arrowHead;
}

Mesh* object2D::CreateCircle(std::string name, glm::vec3 center, float length, glm::vec3 color) {
    std::vector<VertexFormat> vertices; //varfurile triunghiurilor
    std::vector<unsigned int> indices ; //indicii
    float u = 0; //unghiul curent

    //vertices.push_back(VertexFormat(leftBottomCorner, glm::vec3(1.0f, 0, 0))); //centrul ceruclui
    Mesh* cerc = new Mesh(name);
   
    cerc->SetDrawMode(GL_TRIANGLE_FAN);
     for (int i = 0; i <= 30; i++) {
        vertices.push_back(VertexFormat(center + glm::vec3(length * 0.5 * cos(u), length * 0.5 * sin(u), 0), color)); //pun punctul in functie de sin si cos de unghi
        indices.push_back(i); //pun indicele
        u = u + (GLfloat)M_PI * 2 / 30; //trec la urmatoarea perioada
     }
    
    cerc->InitFromData(vertices, indices);
    return cerc;
}

Mesh* object2D::CreateTinta(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    float length,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner, color),
        VertexFormat(corner + glm::vec3(length*2, 0, 0), color),
        VertexFormat(corner + glm::vec3(length*2, length*1.2, 0), color),
        VertexFormat(corner + glm::vec3(0, length*1.2, 0), color)
    };

    Mesh* square = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2, 3 };

    if (!fill) {
        square->SetDrawMode(GL_LINE_LOOP);
    }
    else {
        // Draw 2 triangles. Add the remaining 2 indices
        indices.push_back(0);
        indices.push_back(2);
    }

    square->InitFromData(vertices, indices);
    return square;


    

}

Mesh* object2D::CreateBaraScor(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    float length,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner, color),
        VertexFormat(corner + glm::vec3(length / 2, 0, 0), color),
        VertexFormat(corner + glm::vec3(length / 2, length /2, 0), color),
        VertexFormat(corner + glm::vec3(0, length /2, 0), color)
    };

    Mesh* square = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2, 3 };

    if (!fill) {
        square->SetDrawMode(GL_LINE_LOOP);
    }
    else {
        // Draw 2 triangles. Add the remaining 2 indices
        indices.push_back(0);
        indices.push_back(2);
    }

    square->InitFromData(vertices, indices);
    return square;
}

Mesh* object2D::CreateHeart(std::string name, glm::vec3 center, float width, glm::vec3 color)
 {
    

    float theta = 0;
    float x, y;
    float radius = width / 4;

    std::vector<VertexFormat> vertices;
    std::vector<unsigned int> indices;

    
    int left_semicircle_center_index = 0;
    glm::vec3 left_semicircle_center = center + glm::vec3(-radius, 0, 0);
    vertices.push_back(VertexFormat(left_semicircle_center, color));

    Mesh* heart = new Mesh(name);

    while (theta <= 3.14) {
        x = radius * cos(theta);
        y = radius * sin(theta);
        vertices.push_back(
            VertexFormat(glm::vec3(x, y, 0) + left_semicircle_center, color));
        theta += 0.1f;
    }

    for (auto i = left_semicircle_center_index + 1; i < (int)vertices.size() - 1; i++) {
        indices.push_back(left_semicircle_center_index);
        indices.push_back(i);
        indices.push_back(i + 1);
    }

    
    int right_semicircle_center_index = (int)vertices.size();
    glm::vec3 right_semicircle_center = center + glm::vec3(radius, 0, 0);
    vertices.push_back(VertexFormat(right_semicircle_center, color));

    theta = 0;
    while (theta <= 3.14) {
        x = radius * cos(theta);
        y = radius * sin(theta);
        vertices.push_back(
            VertexFormat(glm::vec3(x, y, 0) + right_semicircle_center, color));
        theta += 0.1f;
    }

    for (auto i = right_semicircle_center_index + 1; i < (int)vertices.size() - 1;
        i++) {
        indices.push_back(right_semicircle_center_index);
        indices.push_back(i);
        indices.push_back(i + 1);
    }

    
    int next_index = (int)vertices.size();
    glm::vec3 middle_left = center + glm::vec3(-width / 2, 0, 0);
    vertices.push_back(VertexFormat(middle_left, color));
    glm::vec3 middle_bottom = center + glm::vec3(0, -width / 2, 0);
    vertices.push_back(VertexFormat(middle_bottom, color));
    glm::vec3 middle_right = center + glm::vec3(width / 2, 0, 0);
    vertices.push_back(VertexFormat(middle_right, color));

    indices.push_back(next_index);
    indices.push_back(next_index + 1);
    indices.push_back(next_index + 2);

    heart -> InitFromData(vertices, indices);
    return heart;
}

Mesh* object2D::CreateConturBaraScor(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    float length,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner, color),
        VertexFormat(corner + glm::vec3(2.5*length , 0, 0), color),
        VertexFormat(corner + glm::vec3(2.5*length , length , 0), color),
        VertexFormat(corner + glm::vec3(0, length , 0), color)
    };

    Mesh* square = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2, 3 };

    if (!fill) {
        square->SetDrawMode(GL_LINE_LOOP);
    }
    else {
        // Draw 2 triangles. Add the remaining 2 indices
        indices.push_back(0);
        indices.push_back(2);
    }

    square->InitFromData(vertices, indices);
    return square;
}

Mesh* object2D::GuraSup(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    float length,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner, color),
        VertexFormat(corner + glm::vec3(3 * length , 0, 0), color),
        VertexFormat(corner + glm::vec3(3 * length , length/2 , 0), color),
        VertexFormat(corner + glm::vec3(0, length/2 , 0), color)
    };

    Mesh* square = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2, 3 };

    if (!fill) {
        square->SetDrawMode(GL_LINE_LOOP);
    }
    else {
        // Draw 2 triangles. Add the remaining 2 indices
        indices.push_back(0);
        indices.push_back(2);
    }

    square->InitFromData(vertices, indices);
    return square;
}

Mesh* object2D::CreateSmileyMouth(std::string name, glm::vec3 center, float length, glm::vec3 color) {
    std::vector<VertexFormat> vertices; //varfurile triunghiurilor
    std::vector<unsigned int> indices; //indicii
    float theta = 0; //unghiul curent

    //vertices.push_back(VertexFormat(leftBottomCorner, glm::vec3(1.0f, 0, 0))); //centrul ceruclui
    Mesh* semicerc = new Mesh(name);

    semicerc->SetDrawMode(GL_TRIANGLE_FAN);
    for (int i = 0; i <= 30; i++) {
        vertices.push_back(VertexFormat(center + glm::vec3(length * 0.5 * cos(theta), length * 0.5 * sin(theta), 0), color)); //pun punctul in functie de sin si cos de unghi
        indices.push_back(i); //pun indicele
        theta = theta + (GLfloat)M_PI *(-1) / 30; //trec la urmatoarea perioada
    }

    semicerc->InitFromData(vertices, indices);
    return semicerc;
}
