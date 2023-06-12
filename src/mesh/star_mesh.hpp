#ifndef STAR_MESH_HPP
#define STAR_MESH_HPP

#include <cstdint>
#include <vector>
#include <glm/ext.hpp>
#include "../shader/star_shader.hpp"
#include <glad/include/glad/glad.h>
#include <GLFW/glfw3.h>

// Vertex structure
struct Vertex {
    glm::vec3 position;
    glm::vec2 tex_coords;
};

class star_mesh {
public:
    // Basic mesh variables
    glm::vec2 scale{1280 / 2, 720 / 2};
    glm::vec2 position{0, 0};
    float rotation = 45;

    star_mesh(std::vector<Vertex> vertices, std::vector<uint32_t> indices);
    void draw(star_shader &shader, GLFWwindow *window);

private:
    glm::mat4 m_model;
    uint32_t VBO, VAO, EBO;

    int old_width, old_height;

    std::vector<Vertex> m_vertices;
    std::vector<uint32_t> m_indices;
};

#endif