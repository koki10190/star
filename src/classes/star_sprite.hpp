#ifndef STAR_SPRITE_HPP
#define STAR_SPRITE_HPP

#include "../mesh/star_mesh.hpp"

class star_sprite : public star_mesh {
private:
    default_shader m_shader;

public:
    star_sprite(glm::vec2 pos, glm::vec2 scale);
    void show();
    void show(star_shader &shader);
};

#endif