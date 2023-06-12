#include "star_text.hpp"
#include <imgui/imgui.h>

star_text::star_text(const std::string &text, glm::vec2 pos) {
    ImGui::SetCursorPos(ImVec2(pos.x, pos.y));
    ImGui::Text("%s", text.c_str());
}