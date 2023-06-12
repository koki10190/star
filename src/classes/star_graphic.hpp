#ifndef STAR_GRAPHIC_HPP
#define STAR_GRAPHIC_HPP

#include "../mesh/star_mesh.hpp"
#include "../texture/star_texture.hpp"
#include <memory>
#include "star_material.hpp"

class star_graphic : public star_mesh {
private:
    default_shader m_shader;

public:
    star_graphic(glm::vec4 color = glm::vec4(255, 255, 255, 255), glm::vec2 pos = glm::vec2(0, 0), glm::vec2 scale = glm::vec2(50, 50));
    void show();
    void show(star_shader &shader);

    star_material material;
};

#endif