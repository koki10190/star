#ifndef STAR_MESH_HPP
#define STAR_MESH_HPP

#include <cstdint>
#include <vector>
#include <glm/ext.hpp>
#include "../shader/star_shader.hpp"

struct Vertex {
    glm::vec3 position;
};

class star_mesh {
public:
    star_mesh(std::vector<Vertex> &vertices, std::vector<uint32_t> &indices);
    void draw(star_shader &shader);

private:
    uint32_t VBO, VAO, EBO;
    std::vector<Vertex> &m_vertices;
    std::vector<uint32_t> m_indices;
};

#endif