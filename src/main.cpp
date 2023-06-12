#include <functional>
#include <iostream>
#include <string>
#include "classes/star_sprite.hpp"
#include "input/star_input.hpp"
#include "overlay/star_overlay.hpp"
#include "ui/star_text.hpp"
#include "window/star_window.hpp"
#include "classes/star_graphic.hpp"

int main(int argc, char **argv) {
    star_window window("Test", 1280, 720);
    std::vector<star_sprite *> sprites = {
        new star_sprite("assets/logo.png", glm::vec2(0, 200), glm::vec2(512, 512)),
        new star_sprite("assets/logo.png", glm::vec2(-15 + 150, 200), glm::vec2(512, 512)),
        new star_sprite("assets/logo.png", glm::vec2(-15 + 150 * 2, 200), glm::vec2(512, 512)),
        new star_sprite("assets/logo.png", glm::vec2(-15 + 150 * 3, 200), glm::vec2(512, 512)),
        new star_sprite("assets/logo.png", glm::vec2(-15 + 150 * 4, 200), glm::vec2(512, 512)),
        new star_sprite("assets/logo.png", glm::vec2(-15 + 150 * 5, 200), glm::vec2(512, 512)),
        new star_sprite("assets/logo.png", glm::vec2(-15 + 150 * 6, 200), glm::vec2(512, 512)),
        new star_sprite("assets/logo.png", glm::vec2(-15 + 150 * 7, 200), glm::vec2(512, 512)),
    };
    star_graphic graphic(glm::vec4(255, 0, 0, 255), glm::vec2(0, 0), glm::vec2(125, 125));

    double previousTime = glfwGetTime();
    int frameCount = 0;
    std::string fps_text;
    window.run([&] {
        window.set_color(25, 25, 100);
        for (star_sprite *sprite : sprites) {
            sprite->show();
        }

        graphic.show();

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

    for (star_sprite *sprite : sprites) {
        delete sprite;
    }

    sprites.clear();

    return 0;
}
