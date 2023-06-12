#ifndef STAR_SHADER_HPP
#define STAR_SHADER_HPP

#include <cstdint>
#include <glm/ext.hpp>

class star_shader {
public:
    star_shader(const char *vertex_shader, const char *fragment_shader);

    void bind();
    void uniform_mat4(const char *name, const glm::mat4 &val);
    void uniform_float(const char *name, const float &val);
    void uniform_int(const char *name, const int &val);
    void uniform_vec2(const char *name, const glm::vec2 &val);
    void uniform_vec3(const char *name, const glm::vec3 &val);
    void uniform_vec4(const char *name, const glm::vec4 &val);

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