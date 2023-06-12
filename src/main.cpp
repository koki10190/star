#include <functional>
#include <iostream>
#include "classes/star_sprite.hpp"
#include "window/star_window.hpp"

int main(int argc, char **argv) {
    star_window window("Test", 1280, 720);
    star_sprite sprite(glm::vec2(500, 0), glm::vec2(1, 1));

    window.Run([&] {
        window.set_color(25, 25, 100);
        sprite.show();
    });

    return 0;
}
