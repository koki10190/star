#ifndef STAR_TEXTURE_HPP
#define STAR_TEXTURE_HPP

#include <cstdint>
#include <string>
class star_texture {
public:
    star_texture(const char *img_path, bool nearest = true);
    uint32_t get_id() const;
    void bind(uint32_t slot);
    void unbind();

    const std::string path;

private:
    int width, height, nr_channels;
    uint32_t m_id;
};

#endif