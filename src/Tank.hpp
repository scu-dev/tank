#pragma once

namespace Tank {
    typedef uint8_t u8;

    enum struct GameStatus : u8 {
        Ready, InProgress, Stopped
    };

    extern GameStatus status;

    void launch() noexcept;
}