#include "star_drag_int.hpp"
#include "imgui/imgui.h"

star_drag_int::star_drag_int(const std::string &label, int *m_integer, float v_speed, int v_min, int v_max, const char *format, star_slider_flags flags) {
    ImGui::DragInt(label.c_str(), m_integer, v_speed, v_min, v_max, format, flags);
}