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
    star_sprite sprite("assets/logo.png", glm::vec2(0, 200), glm::vec2(512, 512));
    star_sprite sprite2("assets/logo.png", glm::vec2(-15 + 150, 200), glm::vec2(512, 512));
    star_sprite sprite3("assets/logo.png", glm::vec2(-15 + 150 * 2, 200), glm::vec2(512, 512));
    star_sprite sprite4("assets/logo.png", glm::vec2(-15 + 150 * 3, 200), glm::vec2(512, 512));
    star_sprite sprite5("assets/logo.png", glm::vec2(-15 + 150 * 4, 200), glm::vec2(512, 512));
    star_sprite sprite6("assets/logo.png", glm::vec2(-15 + 150 * 5, 200), glm::vec2(512, 512));
    star_sprite sprite7("assets/logo.png", glm::vec2(-15 + 150 * 6, 200), glm::vec2(512, 512));
    star_sprite sprite8("assets/logo.png", glm::vec2(-15 + 150 * 7, 200), glm::vec2(512, 512));

    double previousTime = glfwGetTime();
    int frameCount = 0;
    std::string fps_text;
    window.run([&] {
        window.set_color(25, 25, 100);
        sprite.show();
        sprite2.show();
        sprite3.show();
        sprite4.show();
        sprite5.show();
        sprite6.show();
        sprite7.show();
        sprite8.show();

        double currentTime = glfwGetTime();
        frameCount++;

        if (currentTime - previousTime >= 1.0) {
            fps_text = "FPS: " + std::to_string(frameCount);
            frameCount = 0;
            previousTime = currentTime;
        }

        star_overlay ui([&] {
            star_text text(fps_text, glm::vec2(5, 0));
        });
    });

    return 0;
}
