#include <cstdlib>
#include <atomic>
#include <thread>
#include <chrono>
#include <iostream>
#include <memory>
#include <unordered_map>

#include "util.hpp"
#include "gameplay/index.hpp"
#include "Game.hpp"

namespace Tank {
    typedef uint8_t u8;
    typedef uint32_t u32;
    using std::abort, std::cout, std::endl, std::atomic, std::unique_ptr, std::make_unique, std::unordered_map, std::thread, std::chrono::steady_clock, std::chrono::microseconds;
    using namespace std::chrono_literals;

    atomic<bool> running(false);
    atomic<bool> gameStarted(false);
    atomic<bool> gameFinished(false);

    unordered_map<u32, unique_ptr<Sprite>> registry;
    Tank_S player(Tank::TankType::Player);
    Tank_S enemy(Tank::TankType::Enemy1);
    u8 enemyTanksLeft = 20;

    static void resetGame() noexcept;

    thread gameThread;
    static void gameLoop() noexcept;

    void init() noexcept {
        running = true;
    }

    void start() noexcept {
        if (!gameStarted) {
            gameStarted = true;
            gameThread = thread(&gameLoop);
        }
    }

    void stop() noexcept {
        if (gameStarted) {
            gameStarted = false;
            gameThread.join();
            resetGame();
        }
    }

    void shutdown() noexcept {
        if (gameStarted) stop();
        running = false;
    }

    static void resetGame() noexcept {

    }

    static void gameLoop() noexcept {
        while (gameStarted) {
            cout << "gaming " << endl;
            auto startTime = steady_clock::now();
            //todo
            auto endTime = steady_clock::now();
            auto elapsedTime = duration_cast<microseconds>(endTime - startTime);
            if (elapsedTime < 20000us) std::this_thread::sleep_for(20000us - elapsedTime);
        }
        cout << "Terminating game thread!" << endl;
    }
}