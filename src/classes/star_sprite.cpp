#include "star_sprite.hpp"
#include <iostream>
#include <memory>
#include "../window/star_window.hpp"
#include "glm/ext/matrix_transform.hpp"
#include "glm/trigonometric.hpp"

star_sprite::star_sprite(const char *texture_path, glm::vec2 pos, glm::vec2 scale) : star_mesh(
                                                                                         {Vertex{
                                                                                              glm::vec3(-(star_window::instance->get_width()) + scale.x, star_window::instance->get_height(), 0.0f),
                                                                                              glm::vec2(1, 1)}, // top right
                                                                                          Vertex{
                                                                                              glm::vec3(-(star_window::instance->get_width()) + scale.x, star_window::instance->get_height() - scale.y, 0.0f),
                                                                                              glm::vec2(1, 0)}, // bottom right
                                                                                          Vertex{
                                                                                              glm::vec3(-(star_window::instance->get_width()), star_window::instance->get_height() - scale.y, 0.0f),
                                                                                              glm::vec2(0, 0)}, // bottom left
                                                                                          Vertex{
                                                                                              glm::vec3(-(star_window::instance->get_width()), star_window::instance->get_height(), 0.0f),
                                                                                              glm::vec2(0, 1)}},
                                                                                         {0, 1, 3,
                                                                                          1, 2, 3}) {
    set_texture(texture_path, false);
    this->position = pos;
    this->scale = scale;
}

void star_sprite::show() {
    m_shader.bind();
    texture->bind(0);
    m_shader.uniform_int("sprite", 0);

    glm::mat4 mat(0);
    mat = glm::rotate(mat, glm::radians(this->rotation), glm::vec3(0, 0, 1)) * glm::scale(mat, glm::vec3(1, 1, 1));
    m_shader.uniform_mat4("model", mat);

    m_shader.uniform_vec4("m_color", material.color);

    this->draw(m_shader, star_window::instance->get_glfw_window());
}

void star_sprite::show(star_shader &shader) {
    this->draw(shader, star_window::instance->get_glfw_window());
}