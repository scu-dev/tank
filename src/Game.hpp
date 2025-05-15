#pragma once
#include <atomic>
#include <cstdint>

namespace Tank {
    typedef uint8_t u8;
    using std::atomic;

    extern atomic<bool> running;
    extern atomic<bool> gameStarted;

    void init() noexcept;
    void start() noexcept;
    void stop() noexcept;
    void shutdown() noexcept;
}