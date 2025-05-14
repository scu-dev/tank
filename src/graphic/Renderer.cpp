#include <cstdlib>
#include <string>
#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

#include "../util.hpp"
#include "../gui/Gui.hpp"
#include "Renderer.hpp"

namespace Renderer {
    typedef int32_t i32;
    typedef uint32_t u32;
    using std::abort, std::cout, std::endl;

    SDL_Window* window;
    SDL_Renderer* renderer;
    i32 realDim = baseDim;
    float scale = 1.0f;

    //ID = Ordered, 51, 52
    Texture atlas, background, gameover;
    SDL_FRect bgRect;

    void init() noexcept {
        if (!SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO)) abort();
        cout << "Creating window..." << endl;
        if (!SDL_CreateWindowAndRenderer(CJK(u8"坦克大战"), baseDim, baseDim, SDL_WINDOW_HIGH_PIXEL_DENSITY, &window, &renderer)) abort();
        SDL_SetRenderVSync(renderer, 1);
        SDL_SetWindowPosition(window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
        scale = SDL_GetWindowDisplayScale(window);
        cout << scale << endl;
        realDim = baseDim * scale;
        bgRect = SDL_FRect{ 0, 0, static_cast<float>(realDim), static_cast<float>(realDim) };
        SDL_SetWindowSize(window, realDim, realDim);
        atlas.surface = IMG_Load("images/texture_atlas.png");
        background.surface = IMG_Load("images/background.png");
        gameover.surface = IMG_Load("images/gameover.png");
        if (!atlas.surface || !background.surface || !gameover.surface) std::abort();
        atlas.texture = SDL_CreateTextureFromSurface(renderer, atlas.surface);
        SDL_SetTextureScaleMode(atlas.texture, SDL_SCALEMODE_NEAREST);
        background.texture = SDL_CreateTextureFromSurface(renderer, background.surface);
        SDL_SetTextureScaleMode(background.texture, SDL_SCALEMODE_NEAREST);
        gameover.texture = SDL_CreateTextureFromSurface(renderer, gameover.surface);
        SDL_SetTextureScaleMode(gameover.texture, SDL_SCALEMODE_NEAREST);
        if (!atlas.texture || !background.texture || !gameover.texture) std::abort();
        Gui::init();
        SDL_ShowWindow(window);
    }

    void render() noexcept {
        SDL_RenderClear(Renderer::renderer);
        SDL_RenderTexture(renderer, background.texture, &bgRect, &bgRect);
        SDL_RenderTexture(renderer, atlas.texture, NULL, NULL);
        Gui::render();
        SDL_RenderPresent(Renderer::renderer);
    }

    void shutdown() noexcept {
        Gui::shutdown();
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
}