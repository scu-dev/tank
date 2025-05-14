#include <cstdlib>
#include <iostream>

#include "gui/Gui.hpp"
#include "graphic/Renderer.hpp"
#include "Tank.hpp"

namespace Tank {
    using std::abort, std::cout, std::endl;

    GameStatus status = GameStatus::Ready;

    void launch() noexcept {
        Renderer::init();
        bool running = true;
        while (running) {
            Gui::processEvent(running);
            Renderer::render();
        }
        Renderer::shutdown();
    }
}