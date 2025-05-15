#include <iostream>
#include <Windows.h>
#include <io.h>
#include <fcntl.h>

#include "Debug.hpp"

namespace Debug {
    using std::cout, std::endl;

    bool haveConsole = false;

    bool spawnConsole() noexcept {
        if (!haveConsole) {
            AllocConsole();
            #pragma warning(suppress: 6031)
            freopen("CONIN$", "r", stdin);
            #pragma warning(suppress: 6031)
            freopen("CONOUT$", "w", stdout);
            #pragma warning(suppress: 6031)
            freopen("CONOUT$", "w", stderr);
            std::ios::sync_with_stdio(false);
            return true;
        }
        else return false;
    }

    bool despawnConsole() noexcept {
        if (haveConsole) {
            FreeConsole();
            CloseHandle(GetStdHandle(STD_OUTPUT_HANDLE));
            CloseHandle(GetStdHandle(STD_ERROR_HANDLE));
            CloseHandle(GetStdHandle(STD_INPUT_HANDLE));
            #pragma warning(suppress: 6031)
            freopen("NUL", "r", stdin);
            #pragma warning(suppress: 6031)
            freopen("NUL", "w", stdout);
            #pragma warning(suppress: 6031)
            freopen("NUL", "w", stderr);
            return true;
        }
        else return false;
    }
}