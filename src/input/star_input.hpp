#ifndef STAR_INPUT_HPP
#define STAR_INPUT_HPP
#include "star_keys.hpp"
#include "../window/star_window.hpp"

class star_input {
public:
    static inline bool key_down(int key) {
        int state = glfwGetKey(star_window::instance->get_glfw_window(), key);
        if (state == GLFW_PRESS) {
            return true;
        }

        return false;
    }

    static inline bool key_up(int key) {
        int state = glfwGetKey(star_window::instance->get_glfw_window(), key);
        if (state == GLFW_RELEASE) {
            return true;
        }

        return false;
    }
};

#endif