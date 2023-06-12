#include "star_mesh.hpp"
#include "glm/fwd.hpp"
#include <cstdint>
#include <iostream>
#include <glad/include/glad/glad.h>
#include <GLFW/glfw3.h>

star_mesh::star_mesh(std::vector<Vertex> vertices, std::vector<uint32_t> indices) : m_vertices(vertices), m_indices(indices) {
    // generate VBO
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_DYNAMIC_DRAW);

    // generate EBO
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(uint32_t), indices.data(), GL_STATIC_DRAW);

    // generate VAO
    glGenVertexArrays(1, &VAO);

    glBindVertexArray(VAO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)0);
    glEnableVertexAttribArray(0);
}

// This function draws the mesh on the screen
void star_mesh::draw(star_shader &shader, GLFWwindow *window) {
    // Get the windows width and height
    int m_width, m_height;
    glfwGetWindowSize(window, &m_width, &m_height);

    // Copy the vertices into a new vector so we can transform it to a pixel based coordinates
    std::vector<Vertex> new_vertices(m_vertices);

    // Loop thru every vertex and divide it by the screens width and height
    for (Vertex &vertex : new_vertices) {
        vertex.position.x /= m_width;
        vertex.position.y /= m_height;
    }

    // Binds the shader
    shader.bind();

    // Check if the width or height was changed, if it was change the vertices (without this it'll kinda lag)
    if (m_width != old_width || m_height != old_height) {
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferSubData(GL_ARRAY_BUFFER, 0, new_vertices.size() * sizeof(Vertex), new_vertices.data());
    }
    old_width = m_width;
    old_height = m_height;

    glm::vec2 new_pos = position;
    // Divide the positions by width and height
    new_pos.x /= m_width;
    new_pos.y /= m_height;
    // Send the vector 2 to the shader
    shader.uniform_vec2("m_pos", new_pos);

    // Bind indices buffer and vertex array
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBindVertexArray(VAO);
    // Draw the vertices
    glDrawElements(GL_TRIANGLES, static_cast<uint32_t>(m_indices.size()), GL_UNSIGNED_INT, 0);
}