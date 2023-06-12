#include <functional>
#include <iostream>
#include <string>
#include "classes/star_sprite.hpp"
#include "input/star_input.hpp"
#include "overlay/star_overlay.hpp"
#include "ui/star_text.hpp"
#include "window/star_window.hpp"

int main(int argc, char **argv) {
    star_window window("Test", 1280, 720);
    star_sprite sprite("assets/cool.png", glm::vec2((1280.f / 2) - (200.f / 2), (720.f / 2) - (200.f / 2)), glm::vec2(200, 200));
    sprite.set_texture("assets/cool.png", false);

    double previousTime = glfwGetTime();
    int frameCount = 0;
    std::string fps_text;
    window.run([&] {
        window.set_color(25, 25, 100);
        sprite.show();

        // Measure speed
        double currentTime = glfwGetTime();
        frameCount++;
        // If a second has passed.
        if (currentTime - previousTime >= 1.0) {
            fps_text = "FPS: " + std::to_string(frameCount);
            frameCount = 0;
            previousTime = currentTime;
        }

        if (star_input::key_down(KEY_W)) {
            sprite.position.y -= 1;
        }

        if (star_input::key_down(KEY_S)) {
            sprite.position.y += 1;
        }

        if (star_input::key_down(KEY_D)) {
            sprite.position.x += 1;
        }

        if (star_input::key_down(KEY_A)) {
            sprite.position.x -= 1;
        }

        // star_overlay ui([&] {
        //     star_text text(fps_text, glm::vec2(5, 0));
        // });
    });

    return 0;
}
