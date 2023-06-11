#include "star_shader.hpp"
#include <cstdint>
#include <iostream>
#include <glad/include/glad/glad.h>
#include <GLFW/glfw3.h>

star_shader::star_shader(const char *vertex_shader, const char *fragment_shader) : m_vertex_shader(vertex_shader), m_fragment_shader(fragment_shader) {
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

    uint32_t temp_fragment_shader;
    temp_fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(temp_fragment_shader, 1, &m_fragment_shader, NULL);
    glCompileShader(temp_fragment_shader);

    m_program = glCreateProgram();

    glAttachShader(m_program, temp_vertex_shader);
    glAttachShader(m_program, temp_fragment_shader);
    glLinkProgram(m_program);

    glUseProgram(m_program);

    glDeleteShader(temp_vertex_shader);
    glDeleteShader(temp_fragment_shader);
}

void star_shader::bind() {
    glUseProgram(m_program);
}

default_shader::default_shader() : star_shader(
                                       // vertex shader
                                       R"(#version 330 core
layout (location = 0) in vec3 aPos;
void main()
{
   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
})",
                                       // fragment shader
                                       R"(#version 330 core
out vec4 FragColor;

void main()
{
    FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);
})") {}