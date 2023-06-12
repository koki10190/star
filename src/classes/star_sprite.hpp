#ifndef STAR_SPRITE_HPP
#define STAR_SPRITE_HPP

#include "../mesh/star_mesh.hpp"
#include "../texture/star_texture.hpp"
#include <memory>
#include "star_material.hpp"

class star_sprite : public star_mesh {
private:
    default_shader m_shader;
    std::unique_ptr<star_texture> texture;

public:
    star_sprite(const char *texture_path, glm::vec2 pos, glm::vec2 scale);
    void show();
    void show(star_shader &shader);

    std::unique_ptr<star_texture> get_texture() { return std::move(texture); };
    void set_texture(const char *texture_path, bool nearest = true) {
        texture = std::make_unique<star_texture>(texture_path, nearest);
    }

    star_material material;
};

#endif