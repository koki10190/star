#include "star_sprite.hpp"
#include <iostream>
#include "../window/star_window.hpp"

star_sprite::star_sprite(glm::vec2 pos, glm::vec2 scale) : star_mesh(
                                                               {Vertex{glm::vec3(-(star_window::instance->get_width()) + 50, star_window::instance->get_height(), 0.0f)},      // top right
                                                                Vertex{glm::vec3(-(star_window::instance->get_width()) + 50, star_window::instance->get_height() - 50, 0.0f)}, // bottom right
                                                                Vertex{glm::vec3(-(star_window::instance->get_width()), star_window::instance->get_height() - 50, 0.0f)},      // bottom left
                                                                Vertex{glm::vec3(-(star_window::instance->get_width()), star_window::instance->get_height(), 0.0f)}},
                                                               {0, 1, 3,
                                                                1, 2, 3}) {
    this->position = pos;
    this->scale = scale;
}

void star_sprite::show() {
    this->draw(m_shader, star_window::instance->get_glfw_window());
}

void star_sprite::show(star_shader &shader) {
    this->draw(shader, star_window::instance->get_glfw_window());
}