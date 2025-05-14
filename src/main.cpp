#pragma execution_character_set(push, "utf-8")
#include <locale>
#include <SDL3/SDL_main.h>

#include "Tank.hpp"

#define SDL_MAIN_HANDLED
int SDL_main(int argc, char** argv) {
    using std::locale;

    locale::global(locale("zh_CN.UTF-8"));
    Tank::launch();
    return 0;
}