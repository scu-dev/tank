#pragma once
#include <cstdlib>
#include <cstdint>
#include <iostream>

#include "../graphic/Renderer.hpp"

namespace Tank {
    typedef uint8_t u8;
    using std::abort, std::cout, std::endl, std::cerr, Renderer::TextureID, std::move;

    inline constexpr u8 spriteDim = 30;

    enum struct Direction : u8 {
        Up, Down, Left, Right
    };

    struct Sprite {
        TextureID txid;

        Sprite& operator=(const Sprite& copy) noexcept {
            if (this == &copy) return *this;
            txid = copy.txid;
        }
        Sprite& operator=(Sprite&& _move) noexcept {
            if (this == &_move) return *this;
            txid = _move.txid;
        }
        Sprite() noexcept : txid(Renderer::TX_INVALID) {}
        Sprite(TextureID id) noexcept : txid(id) {}
        Sprite(const Sprite& copy) noexcept { operator=(copy); }
        Sprite(Sprite&& _move) noexcept { operator=(move(_move)); }
        virtual void render() noexcept {
            cerr << "Base class's virtual function get called!" << endl;
            abort();
        }
        ~Sprite() noexcept {}
    };

    struct Directional : Sprite {
        Direction direc;

        Directional(Direction di = Direction::Up) noexcept : Sprite(), direc(di) {}
        Directional(TextureID id, Direction di = Direction::Up) noexcept : Sprite(id), direc(di) {}
    };
}