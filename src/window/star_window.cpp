#include "star_window.hpp"
#include "../mesh/star_mesh.hpp"
#include <iostream>

void star_window::framebuffer_size_callback(GLFWwindow *window, int width, int height) {
    glViewport(-(width / 2), (height / 2), width, height);
}

// Create star_window class and initialize OpenGL
star_window::star_window(char *title, int width, int height) : m_title(title), m_width(width), m_height(height) {
    instance = this;
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
    glfwSetWindowAttrib(m_window, GLFW_RESIZABLE, false);

    glfwMakeContextCurrent(m_window);
    // Load GLAD
    gladLoadGL();
    glViewport(0, 0, width, height);
    // Enable VSync
    glfwSwapInterval(1);
    // Set callback so that we resize the viewport when the window gets resized
    glfwSetFramebufferSizeCallback(m_window, framebuffer_size_callback);

    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;

    ImGui::StyleColorsDark();

    ImGuiStyle &style = ImGui::GetStyle();
    style.WindowBorderSize = 0.0f;

    // ImGui::StyleColorsLight();

    ImGui_ImplGlfw_InitForOpenGL(m_window, true);
    ImGui_ImplOpenGL3_Init("#version 330");

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

// The game loop
void star_window::run(std::function<void()> run_loop) {
    // Run the while loop until the window should close
    while (!glfwWindowShouldClose(m_window)) {
        // clear the buffer bit
        // run the user handled run loop
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        // mesh.draw(m_shader, this->get_glfw_window());

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        run_loop();
        // ImGui::DragFloat2("Position", &mesh.position.x);

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

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