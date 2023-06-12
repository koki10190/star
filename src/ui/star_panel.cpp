#include "star_panel.hpp"
#include "../window/star_window.hpp"
#include "imgui/imgui.h"

star_panel::star_panel(const std::string &title, std::function<void()> window_loop, star_panel_flags flags) {
    if (star_gui::Begin(title.c_str(), NULL, flags)) {
        window_loop();
        star_gui::End();
    }
}