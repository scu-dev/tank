#pragma once

#include "Sprite.hpp"

namespace Tank {
    struct Appear : Sprite {

        Appear() noexcept {

        }

        virtual void render() noexcept override {

        }
    };

    struct Explosion : Sprite {
        Explosion() noexcept {

        }
    };

    struct Bullet : Directional {
        Bullet() noexcept {

        }
    };
}