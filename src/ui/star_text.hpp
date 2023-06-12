#ifndef STAR_TEXT_HPP
#define STAR_TEXT_HPP

#include <string>
#include <glm/ext.hpp>

class star_text {
public:
    star_text(const std::string &text, glm::vec2 pos = glm::vec2(0, 0), bool set_pos = true);
};

#endif