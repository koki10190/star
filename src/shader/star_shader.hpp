#ifndef STAR_SHADER_HPP
#define STAR_SHADER_HPP

#include <cstdint>
class star_shader {
public:
    star_shader(const char *vertex_shader, const char *fragment_shader);

    void bind();

protected:
    uint32_t m_program;

    const char *m_vertex_shader;
    const char *m_fragment_shader;
};

class default_shader : public star_shader {
public:
    default_shader();
};

#endif