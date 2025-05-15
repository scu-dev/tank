#pragma once
#include <SDL3/SDL.h>

namespace Renderer {
    typedef uint16_t u16;
    typedef int32_t i32;
    typedef uint8_t TextureID;

    inline constexpr u16 baseDim = 630;
    inline constexpr u16 barHeight = 100;
    inline constexpr SDL_FRect bgRectS{ 0, 0, baseDim, baseDim };

    extern SDL_Window* window;
    extern SDL_Renderer* renderer;
    extern i32 realWidth;
    extern i32 realHeight;
    extern float scale;

    void init() noexcept;
    void render() noexcept;
    void shutdown() noexcept;

    struct Texture {
        SDL_Surface* surface;
        SDL_Texture* texture;
    };

    inline constexpr TextureID TX_APPEAR_0       = 0;
    inline constexpr TextureID TX_APPEAR_1       = 1;
    inline constexpr TextureID TX_APPEAR_2       = 2;

    inline constexpr TextureID TX_BOOM_0         = 3;
    inline constexpr TextureID TX_BOOM_1         = 4;
    inline constexpr TextureID TX_BOOM_2         = 5;
    inline constexpr TextureID TX_BOOM_3         = 6;
    inline constexpr TextureID TX_BOOM_4         = 7;
    inline constexpr TextureID TX_BOOM_5         = 8;

    inline constexpr TextureID TX_BRICK          = 9;

    inline constexpr TextureID TX_BULLET_U       = 10;
    //inline constexpr TextureID TX_BULLET_D       = 11;
    //inline constexpr TextureID TX_BULLET_L       = 12;
    //inline constexpr TextureID TX_BULLET_R       = 13;

    inline constexpr TextureID TX_ENEMY_1_U      = 14;
    //inline constexpr TextureID TX_ENEMY_1_D      = 15;
    //inline constexpr TextureID TX_ENEMY_1_L      = 16;
    //inline constexpr TextureID TX_ENEMY_1_R      = 17;

    inline constexpr TextureID TX_ENEMY_2_U      = 18;
    //inline constexpr TextureID TX_ENEMY_2_D      = 19;
    //inline constexpr TextureID TX_ENEMY_2_L      = 20;
    //inline constexpr TextureID TX_ENEMY_2_R      = 21;

    inline constexpr TextureID TX_ENEMY_3_U      = 22;
    //inline constexpr TextureID TX_ENEMY_3_D      = 23;
    //inline constexpr TextureID TX_ENEMY_3_L      = 24;
    //inline constexpr TextureID TX_ENEMY_3_R      = 25;

    inline constexpr TextureID TX_ENEMY_4_U      = 26;
    //inline constexpr TextureID TX_ENEMY_4_D      = 27;
    //inline constexpr TextureID TX_ENEMY_4_L      = 28;
    //inline constexpr TextureID TX_ENEMY_4_R      = 29;

    inline constexpr TextureID TX_DROP_SPEED     = 30;
    inline constexpr TextureID TX_DROP_MAG       = 31;
    inline constexpr TextureID TX_DROP_UPGRADE   = 32;
    inline constexpr TextureID TX_DROP_TANK      = 33;
    inline constexpr TextureID TX_HOME           = 34;
    inline constexpr TextureID TX_HOME_DESTROYED = 35;
    inline constexpr TextureID TX_IRONWALL       = 36;
    inline constexpr TextureID TX_RIVER          = 37;
    inline constexpr TextureID TX_TANK_1_U       = 38;
    //inline constexpr TextureID TX_TANK_1_D       = 39;
    //inline constexpr TextureID TX_TANK_1_L       = 40;
    //inline constexpr TextureID TX_TANK_1_R       = 41;
    inline constexpr TextureID TX_TANK_2_U       = 42;
    //inline constexpr TextureID TX_TANK_2_D       = 43;
    //inline constexpr TextureID TX_TANK_2_L       = 44;
    //inline constexpr TextureID TX_TANK_2_R       = 45;
    inline constexpr TextureID TX_TANK_3_U       = 46;
    //inline constexpr TextureID TX_TANK_3_D       = 47;
    //inline constexpr TextureID TX_TANK_3_L       = 48;
    //inline constexpr TextureID TX_TANK_3_R       = 49;
    inline constexpr TextureID TX_TREE           = 50;

    inline constexpr TextureID TX_BACKGROUND     = 51;
    inline constexpr TextureID TX_GAMEOVER       = 52;

    inline constexpr TextureID TX_INVALID        = 255;
}