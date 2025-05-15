#pragma once
#include <atomic>
#include <queue>
#include <cstdint>

namespace Gui {
    typedef int32_t i32;
    using std::atomic, std::queue;

    struct Cache {
        i32 height;
        i32 width;
    };

    struct InputEvent {

    };

    extern Cache cache;
    extern queue<InputEvent> inputEventQueue;

    void init() noexcept;
    void processEvent(atomic<bool>& running) noexcept;
    void render() noexcept;
    void shutdown() noexcept;
}