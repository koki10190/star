#ifndef STAR_DRAG_INT_HPP
#define STAR_DRAG_INT_HPP

#include "imgui/imgui.h"
#include <functional>
#include <string>
#include <glm/ext.hpp>

#define star_slider_flags ImGuiSliderFlags

class star_drag_int {
public:
    star_drag_int(const std::string &label, int *m_integer, float v_speed = 1.0f, int v_min = 0, int v_max = 0, const char *format = "%d", star_slider_flags flags = 0);
};

#endif