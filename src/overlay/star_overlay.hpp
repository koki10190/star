#ifndef STAR_OVERLAY_HPP
#define STAR_OVERLAY_HPP

#include <functional>
class star_overlay {
public:
    star_overlay(std::function<void()> overlay_loop);
};

#endif