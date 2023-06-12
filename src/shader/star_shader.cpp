#include "star_shader.hpp"
#include <cstdint>
#include <iostream>
#include <glad/include/glad/glad.h>
#include <GLFW/glfw3.h>

star_shader::star_shader(const char *vertex_shader, const char *fragment_shader) : m_vertex_shader(vertex_shader), m_fragment_shader(fragment_shader) {
    // Create temporary vertex shader
    uint32_t temp_vertex_shader;
    temp_vertex_shader = glCreateShader(GL_VERTEX_SHADER);

    glShaderSource(temp_vertex_shader, 1, &m_vertex_shader, NULL);
    glCompileShader(temp_vertex_shader);

    int success;
    char infoLog[512];
    glGetShaderiv(temp_vertex_shader, GL_COMPILE_STATUS, &success);

    if (!success) {
        glGetShaderInfoLog(temp_vertex_shader, 512, NULL, infoLog);
        std::cout << "Vertex Shader Compilation Failed\n"
                  << infoLog << std::endl;
    }

    // Create temporary fragment (pixel) shader
    uint32_t temp_fragment_shader;
    temp_fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(temp_fragment_shader, 1, &m_fragment_shader, NULL);
    glCompileShader(temp_fragment_shader);

    // Create the shader program
    m_program = glCreateProgram();

    // Attach vertex and fragment shaders to the program
    glAttachShader(m_program, temp_vertex_shader);
    glAttachShader(m_program, temp_fragment_shader);
    glLinkProgram(m_program);

    // Bind the shader
    glUseProgram(m_program);

    // Delete the compiled shaders
    glDeleteShader(temp_vertex_shader);
    glDeleteShader(temp_fragment_shader);
}

void star_shader::bind() {
    glUseProgram(m_program);
}

void star_shader::uniform_int(const char *name, const int &val) {
    bind();
    glUniform1i(glGetUniformLocation(m_program, name), val);
}

void star_shader::uniform_float(const char *name, const float &val) {
    bind();
    glUniform1f(glGetUniformLocation(m_program, name), val);
}

void star_shader::uniform_mat4(const char *name, const glm::mat4 &val) {
    bind();
    glUniformMatrix4fv(glGetUniformLocation(m_program, name), 1, GL_FALSE, glm::value_ptr(val));
}

void star_shader::uniform_vec2(const char *name, const glm::vec2 &val) {
    bind();
    glUniform2f(glGetUniformLocation(m_program, name), val.x, val.y);
}

void star_shader::uniform_vec3(const char *name, const glm::vec3 &val) {
    bind();
    glUniform3f(glGetUniformLocation(m_program, name), val.x, val.y, val.z);
}

void star_shader::uniform_vec4(const char *name, const glm::vec4 &val) {
    bind();
    glUniform4f(glGetUniformLocation(m_program, name), val.x, val.y, val.z, val.w);
}

// This is a default shader the library uses, you can create your own shaders if you want
default_shader::default_shader() : star_shader(
                                       // vertex shader
                                       R"(#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 texCoord;
uniform vec2 m_pos;
out vec2 tex_coords;
void main()
{
   gl_Position = vec4(aPos.x + (m_pos.x * 2), aPos.y + -(m_pos.y * 2), aPos.z, 1.0);
   tex_coords = texCoord;
})",
                                       // fragment shader
                                       R"(#version 330 core
out vec4 FragColor;

in vec2 tex_coords;
uniform sampler2D sprite;

void main()
{
    vec4 tex = texture(sprite, tex_coords);
    if(tex.a < 0.1) discard;
    FragColor = tex;
})") {}