#include "star_window.hpp"
#include "../mesh/star_mesh.hpp"
#include <iostream>

void star_window::framebuffer_size_callback(GLFWwindow *window, int width, int height) {
    glViewport(-(width / 2), (height / 2), width, height);
}

// Create star_window class and initialize OpenGL
star_window::star_window(char *title, int width, int height) : m_title(title), m_width(width), m_height(height) {
    // Initialize GLFW
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create GLFWwindow
    m_window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (m_window == NULL) {
        std::cout << "Failed to create GLFW m_window" << std::endl;
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(m_window);
    // Load GLAD
    gladLoadGL();
    glViewport(-(width / 2), (height / 2), width, height);
    // Enable VSync
    glfwSwapInterval(1);
    // Set callback so that we resize the viewport when the window gets resized
    glfwSetFramebufferSizeCallback(m_window, framebuffer_size_callback);
}

// The game loop
void star_window::Run(std::function<void()> run_loop) {
    // std::vector<Vertex> vertices = {
    //     Vertex{glm::vec3(0.0f / 800, -500.0f / 600, 0.0f)},
    //     Vertex{glm::vec3(500.0f / 800, -500.0f / 600, 0.0f)},
    //     Vertex{glm::vec3(250.0f / 800, 0.0f / 600, 0.0f)}};
    std::vector<Vertex> vertices = {
        Vertex{glm::vec3(0.5f, 0.5f, 0.0f)},   // top right
        Vertex{glm::vec3(0.5f, -0.5f, 0.0f)},  // bottom right
        Vertex{glm::vec3(-0.5f, -0.5f, 0.0f)}, // bottom left
        Vertex{glm::vec3(-0.5f, 0.5f, 0.0f)}};

    std::vector<uint32_t>
        indices{0, 1, 3, // first Triangle
                1, 2, 3};

    star_mesh mesh(vertices, indices);
    default_shader m_shader;

    // Run the while loop until the window should close
    while (!glfwWindowShouldClose(m_window)) {
        // clear the buffer bit
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        // run the user handled run loop
        run_loop();
        mesh.draw(m_shader);

        glfwSwapBuffers(m_window);
        glfwPollEvents();
    }
}

void star_window::set_color(float r, float g, float b) {
    // Set the background color
    glClearColor(r / 255, g / 255, b / 255, 1);
}

star_window::~star_window() {
    glfwTerminate();
}