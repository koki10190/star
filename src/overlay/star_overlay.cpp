#include "star_overlay.hpp"
#include <imgui/imgui.h>
#include "../window/star_window.hpp"

star_overlay::star_overlay(std::function<void()> overlay_loop) {
    // Set the overlay size
    ImGui::SetNextWindowSize(ImVec2(star_window::instance->get_width(), star_window::instance->get_height()));
    // Make the overlay transparent
    ImGui::SetNextWindowBgAlpha(0);
    // Set the overlays position
    ImGui::SetNextWindowPos(ImVec2(0, 0));
    if (ImGui::Begin("Main Canvas", NULL, ImGuiWindowFlags_NoTitleBar)) {
        overlay_loop();
        ImGui::End();
    }
}
