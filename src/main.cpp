#include <functional>
#include <iostream>
#include "window/star_window.hpp"

int main(int argc, char **argv) {
    star_window window("Test", 800, 600);

    window.Run([&] {
        window.set_color(25, 25, 100);
    });

    return 0;
}