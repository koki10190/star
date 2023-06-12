#ifndef STAR_PANEL_HPP
#define STAR_PANEL_HPP

#include "imgui/imgui.h"
#include <functional>
#include <string>
#include <glm/ext.hpp>

#define star_panel_flags ImGuiWindowFlags

class star_panel {
public:
    star_panel(const std::string &title, std::function<void()> window_loop, star_panel_flags flags = 0);
};

#endif