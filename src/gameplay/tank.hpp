#pragma once
#include <cstdlib>
#include <cstdint>

#include "../graphic/Renderer.hpp"
#include "sprite.hpp"

namespace Tank {
    typedef uint8_t u8;
    using std::abort;

    enum struct TankType : u8 {
        Player, Enemy1, Enemy2, Enemy3, Enemy4
    };

    struct Tank_S : Directional {


        Tank_S(TankType type, Direction di = Direction::Up) noexcept : Directional(di) {
            switch (type) {
                case Tank::TankType::Player:
                    break;
                case Tank::TankType::Enemy1:
                    break;
                case Tank::TankType::Enemy2:
                    break;
                case Tank::TankType::Enemy3:
                    break;
                case Tank::TankType::Enemy4:
                    txid = Renderer::TX_ENEMY_4_U;
                    break;
                default: abort();
            }
        }
    };
}