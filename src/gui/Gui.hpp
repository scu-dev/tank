#pragma once
#include <cstdint>

namespace Gui {
    typedef int32_t i32;

    struct Cache {
        i32 height;
        i32 width;
    };

    extern Cache cache;

    void init() noexcept;
    void processEvent(bool& running) noexcept;
    void render() noexcept;
    void shutdown() noexcept;
}