#include "star_text.hpp"
#include <imgui/imgui.h>

star_text::star_text(const std::string &text, glm::vec2 pos) {
    // Set text position
    ImGui::SetCursorPos(ImVec2(pos.x, pos.y));
    // Render the text
    ImGui::Text("%s", text.c_str());
}