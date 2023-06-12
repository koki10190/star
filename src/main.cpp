#include <functional>
#include <iostream>
#include "classes/star_sprite.hpp"
#include "overlay/star_overlay.hpp"
#include "window/star_window.hpp"

int main(int argc, char **argv) {
    star_window window("Test", 1280, 720);

    star_sprite sprite(glm::vec2(500, 0), glm::vec2(1, 1));

    star_overlay ui([&] {
        ImGui::DragFloat2("Position", &sprite.position.x);
    });

    window.Run([&] {
        window.set_color(25, 25, 100);
        sprite.show();

        ui.show();
    });

    return 0;
}
