#pragma execution_character_set(push, "utf-8")
#include <locale>
#include <SDL3/SDL_main.h>

#include "debug/Debug.hpp"
#include "gui/Gui.hpp"
#include "graphic/Renderer.hpp"
#include "Game.hpp"

#define SDL_MAIN_HANDLED
int SDL_main(int argc, char** argv) {
    using std::locale;

    locale::global(locale("zh_CN.UTF-8"));
    { //todo: checkbox
        Debug::spawnConsole();
    }
    Renderer::init();
    Tank::init();
    while (Tank::running) {
        Gui::processEvent(Tank::running);
        Renderer::render();
    }
    Tank::shutdown();
    Renderer::shutdown();
    return 0;
}