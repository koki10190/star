#ifndef STAR_WINDOW_HPP
#define STAR_WINDOW_HPP
#include <glad/include/glad/glad.h>
#include <GLFW/glfw3.h>

#include <functional>
class star_window {
public:
    static inline void framebuffer_size_callback(GLFWwindow *window, int width, int height);
    star_window(char *title, int width, int height);
    ~star_window();
    void Run(std::function<void()> run_loop);

    // Get the private variables as a constant
    int get_width() const { return m_width; };
    int get_height() const { return m_height; };
    char *get_title() const { return m_title; };

    GLFWwindow *get_glfw_window() const { return m_window; };

    // GLFW Functions
    void set_color(float r, float g, float b);

private:
    int m_width, m_height;
    char *m_title;
    GLFWwindow *m_window;
};

#endif